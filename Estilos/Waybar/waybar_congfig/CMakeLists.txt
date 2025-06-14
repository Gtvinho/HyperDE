cmake_minimum_required(VERSION 3.10)
project(HyperDE_WaybarConfig LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)  # Necessário para o Qt processar Q_OBJECT

add_executable(HyperDE_WaybarConfig
    main.cpp
    WaybarConfig.cpp
)

target_link_libraries(HyperDE_WaybarConfig Qt6::Widgets)

