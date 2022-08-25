# Target name
set(target CubbyTower)

# Set architecture
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
    set(ARCHITECTURE x86)
else()
    set(ARCHITECTURE x64)
endif()

# Includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Links
link_directories(${SFML_EXTLIBS_PATH})

# Sources
file(GLOB header_dir
    ${root_dir}/Includes)

file(GLOB_RECURSE headers
    ${header_dir}/*.hpp)

file(GLOB_RECURSE sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build library
add_executable(${target}
    ${sources})

# Project options
set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

# Compile options
target_compile_options(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)
target_compile_definitions(${target}
    PRIVATE
    RESOURCES_DIR="${RESOURCES_DIR}"
)

target_link_libraries(${target}
    PRIVATE
    ${SFML_LIBRARY_DEPENDENCIES}
    ${SFML_OPENAL_DEPENDENCIES}
    gl3w
    OpenGL::GL
    ${CMAKE_DL_LIBS}

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}
	${DEFAULT_LIBRARIES}

    INTERFACE
)
