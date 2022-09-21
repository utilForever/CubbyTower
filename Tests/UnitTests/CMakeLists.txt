# Target name
set(target UnitTests)

# Set architecture
if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
    set(ARCHITECTURE x86)
else()
    set(ARCHITECTURE x64)
endif()

# Define dependencies
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
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Links
link_directories(${SFML_EXTLIBS_PATH})

# Sources
file(GLOB_RECURSE sources
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Sources/CubbyTower/Helpers/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Sources/CubbyTower/Systems/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build executable
add_executable(${target}
    ${sources})

# Project options
set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

# Compile options
# GCC and Clang compiler options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        -Wno-unused-variable
        )
endif()
target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)
target_compile_definitions(${target}
    PRIVATE
)

# Link libraries
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
