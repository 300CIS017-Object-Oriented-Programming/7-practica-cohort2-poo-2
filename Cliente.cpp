#include "Cliente.h"

Cliente::Cliente(int id, std::string nombre) : id(id), nombre(nombre) {}

Cliente::~Cliente() {
    for (Venta* venta : compras) {
        delete venta;
    }
}

void Cliente::agregarCompra(Venta* venta) {
    compras.push_back(venta);
}

void Cliente::mostrarHistorialCompras() const {
    std::cout << "Historial de compras de " << nombre << ":\n";
    for (const Venta* venta : compras) {
        venta->mostrarDetalleVenta();
    }
}

int Cliente::getId() const {
    return id;
}

std::string Cliente::getNombre() const {
    return nombre;
}
