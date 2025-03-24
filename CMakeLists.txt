cmake_minimum_required(VERSION 3.16)
project(POOSistemaGestionVentas)

set(CMAKE_CXX_STANDARD 17)

add_executable(POOSistemaGestionVentas main.cpp Tienda.cpp Producto.cpp Cliente.cpp Venta.cpp)
