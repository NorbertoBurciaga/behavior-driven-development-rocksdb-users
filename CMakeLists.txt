cmake_minimum_required(VERSION 3.11)

project(Users)

# find boost
find_package(Boost 1.67 REQUIRED COMPONENTS
    filesystem
    program_options
    regex
)

# find google test 
enable_testing()
find_package(GTest REQUIRED)

# Output directory settings
set(output_dir ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${output_dir})


# add the CMakeLists.txt located in tests/features to create cucumber-cpp server executable
add_subdirectory(tests/features)
