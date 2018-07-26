# src is an "include" directory because Hello.h is used in HelloBDDSteps.cpp
include_directories(${CMAKE_SOURCE_DIR}/src)

# create HelloBDDSteps executable: compile HelloBDDSteps.cpp and link it with cucumber-cpp googletest and $
add_executable(UsersSteps step_definitions/UsersSteps)
target_link_libraries(UsersSteps cucumber-cpp rocksdb GTest::GTest ${Boost_LIBRARIES})
