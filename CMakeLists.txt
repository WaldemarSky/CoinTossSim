cmake_minimum_required(VERSION 3.28)

project(TossCoinSimulator VERSION 1.0 LANGUAGES C)


add_library(coin_module STATIC coin_module.c)

add_executable(tosscoin main.c)

target_link_libraries(tosscoin PRIVATE coin_module)
