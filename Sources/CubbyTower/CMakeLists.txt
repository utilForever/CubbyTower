# Target name
set(target CubbyTower)

# Set architecture
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
    set(ARCHITECTURE x86)
else()
    set(ARCHITECTURE x64)
endif()

# Define dependencies
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(SFML_LIBRARY_DEPENDENCIES sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SFML_EXTLIBS_PATH ${CMAKE_SOURCE_DIR}/Libraries/SFML/extlibs/libs-msvc/${ARCHITECTURE})
    set(SFML_OPENAL_DEPENDENCIES openal32)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SFML_OPENAL_DEPENDENCIES openal)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(SFML_OPENAL_DEPENDENCIES ${OPENAL_LIBRARY})
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
