#include "Producto.h"

Producto::Producto(std::string codigo, std::string nombre, float precio, int stock)
    : codigo(codigo), nombre(nombre), precio(precio), stock(stock) {}

Producto::~Producto() {}

bool Producto::descontarStock(int cantidad) {
    if (cantidad > stock) {
        std::cout << "Stock insuficiente para " << nombre << ".\n";
        return false;
    }
    stock -= cantidad;
    return true;
}

void Producto::agregarStock(int cantidad) {
    stock += cantidad;
}

void Producto::mostrarInformacion() const {
    std::cout << "Código: " << codigo << " | Nombre: " << nombre
              << " | Precio: $" << precio << " | Stock: " << stock << "\n";
}

std::string Producto::getCodigo() const {
    return codigo;
}

std::string Producto::getNombre() const {
    return nombre;
}

float Producto::getPrecio() const {
    return precio;
}

int Producto::getStock() const {
    return stock;
}
