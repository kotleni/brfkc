project(brfkc)
cmake_minimum_required(VERSION 3.0)

include_directories(include/)
add_executable(brfkc main.c argsparser.c)