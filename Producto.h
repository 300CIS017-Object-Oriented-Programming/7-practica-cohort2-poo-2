#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>

class Producto {
private:
    std::string codigo;
    std::string nombre;
    float precio;
    int stock;

public:
    Producto(std::string codigo, std::string nombre, float precio, int stock);
    ~Producto(); //destructor

    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    void mostrarInformacion() const;


    std::string getCodigo() const;
    std::string getNombre() const;
    float getPrecio() const;
    int getStock() const;
};

#endif
