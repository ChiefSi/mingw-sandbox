cmake_minimum_required(VERSION 3.16)

project(hello-world)

add_executable(hello-world hello-world.cpp)
install(TARGETS hello-world DESTINATION ${CMAKE_INSTALL_BINDIR})
