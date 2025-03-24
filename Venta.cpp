#include "Venta.h"
#include "Cliente.h"

Venta::Venta(int id, Cliente* cliente) : id(id), cliente(cliente) {}

Venta::~Venta() {}

void Venta::agregarProductoVendido(Producto* producto, int cantidad) {
    productosVendidos.push_back({producto, cantidad});
}

float Venta::calcularTotal() const {
    float total = 0.0;
    for (const auto& par : productosVendidos) {
        total += par.first->getPrecio() * par.second;
    }
    return total;
}

void Venta::mostrarDetalleVenta() const {
    std::cout << "Venta ID: " << id << "\nCliente: " << cliente->getNombre() << "\nProductos vendidos:\n";
    for (const auto& par : productosVendidos) {
        std::cout << "- " << par.first->getNombre() << " | Cantidad: " << par.second << " | Precio: $" << par.first->getPrecio() << "\n";
    }
    std::cout << "Total: $" << calcularTotal() << "\n";
}
