cmake_minimum_required(VERSION 3.10)

project(HyprDE LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)

add_executable(HyprDE
	main.cpp
	WaybarConfig/WaybarConfig.cpp
)

target_link_libraries(HyprDE Qt6::Widgets)
