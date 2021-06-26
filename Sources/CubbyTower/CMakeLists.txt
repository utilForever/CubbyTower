# Target name
set(target CubbyTower)

# Define
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

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

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}
	${DEFAULT_LIBRARIES}

    INTERFACE
)