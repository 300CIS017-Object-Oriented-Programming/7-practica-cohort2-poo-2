#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "Venta.h"

class Cliente {
private:
    int id;
    std::string nombre;
    std::vector<Venta*> compras; //puntero a objetos de tipo Venta

public:
    Cliente(int id, std::string nombre);
    ~Cliente();

    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras() const;


    int getId() const;
    std::string getNombre() const;
    // aca se usan getters para acceder al id y nombre.

};

#endif
