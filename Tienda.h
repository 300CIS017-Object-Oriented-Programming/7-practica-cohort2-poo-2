#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

class Tienda {
private:
    std::vector<Producto*> productos;
    std::vector<Cliente*> clientes;
    std::vector<Venta*> ventas;
    int siguienteIdVenta;

public:
    Tienda();
    ~Tienda();

    void agregarProducto(const std::string& codigo, const std::string& nombre, float precio, int stockInicial);
    void registrarCliente(int id, const std::string& nombre);
    void registrarVenta(int idCliente);
    void reabastecerProducto(const std::string& codigoProducto, int cantidad);
    Producto* buscarProducto(const std::string& codigo);
    Cliente* buscarCliente(int idCliente);
    void listarProductos() const;
    void mostrarVentas() const;
    float calcularValorInventario() const;
};

#endif // TIENDA_H
