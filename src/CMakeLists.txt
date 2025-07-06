cmake_minimum_required(VERSION 3.10)
project(HyprDELauncher)

set(CMAKE_CXX_STANDARD 17)

# Habilita geração automática de código MOC do Qt (necessário por causa do Q_OBJECT)
set(CMAKE_AUTOMOC ON)

# Procura e configura Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Adiciona o executável com todos os arquivos
add_executable(HyprDE
    main.cpp
    WaybarConfig/WaybarConfig.cpp
    WaybarConfig/WaybarConfig.h
)

# Inclui o diretório onde está o cabeçalho
target_include_directories(HyprDE PRIVATE WaybarConfig)

# Liga com as bibliotecas do Qt
target_link_libraries(HyprDE Qt5::Widgets)
