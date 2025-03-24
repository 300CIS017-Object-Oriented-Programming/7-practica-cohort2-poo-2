#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <vector>
#include "Producto.h"

class Cliente;
class Venta {
private:
    int id;
    Cliente* cliente;
    std::vector<std::pair<Producto*, int>> productosVendidos;

public:
    Venta(int id, Cliente* cliente);
    ~Venta();

    void agregarProductoVendido(Producto* producto, int cantidad);
    float calcularTotal() const;
    void mostrarDetalleVenta() const;
};

#endif
