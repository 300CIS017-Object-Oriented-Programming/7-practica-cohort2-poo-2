#include "Tienda.h"

Tienda::Tienda() : siguienteIdVenta(1) {}

Tienda::~Tienda() {
    for (auto producto : productos) delete producto;
    for (auto cliente : clientes) delete cliente;
    for (auto venta : ventas) delete venta;
}

void Tienda::agregarProducto(const std::string& codigo, const std::string& nombre, float precio, int stockInicial) {
    productos.push_back(new Producto(codigo, nombre, precio, stockInicial));
}

void Tienda::registrarCliente(int id, const std::string& nombre) {
    clientes.push_back(new Cliente(id, nombre));
}

void Tienda::registrarVenta(int idCliente) {
    Cliente* cliente = buscarCliente(idCliente);
    if (!cliente) {
        std::cout << "Cliente no encontrado.\n";
        return;
    }

    Venta* nuevaVenta = new Venta(siguienteIdVenta++, cliente);
    std::string codigoProducto;
    int cantidad;

    std::cout << "Ingrese el código del producto (o 'fin' para terminar): ";
    while (std::cin >> codigoProducto && codigoProducto != "fin") {
        Producto* producto = buscarProducto(codigoProducto);
        if (!producto) {
            std::cout << "Producto no encontrado.\n";
            continue;
        }

        std::cout << "Ingrese la cantidad: ";
        std::cin >> cantidad;

        if (producto->descontarStock(cantidad)) {
            nuevaVenta->agregarProductoVendido(producto, cantidad);
        } else {
            std::cout << "Stock insuficiente.\n";
        }

        std::cout << "Ingrese el código del producto (o 'fin' para terminar): ";
    }

    if (nuevaVenta->calcularTotal() > 0) {
        ventas.push_back(nuevaVenta);
        cliente->agregarCompra(nuevaVenta);
        std::cout << "Venta registrada con éxito.\n";
    } else {
        delete nuevaVenta;
        std::cout << "Venta cancelada.\n";
    }
}

void Tienda::reabastecerProducto(const std::string& codigoProducto, int cantidad) {
    Producto* producto = buscarProducto(codigoProducto);
    if (producto) {
        producto->agregarStock(cantidad);
        std::cout << "Stock actualizado.\n";
    } else {
        std::cout << "Producto no encontrado.\n";
    }
}

Producto* Tienda::buscarProducto(const std::string& codigo) {
    for (auto producto : productos) {
        if (producto->getCodigo() == codigo) return producto;
    }
    return nullptr;
}

Cliente* Tienda::buscarCliente(int idCliente) {
    for (auto cliente : clientes) {
        if (cliente->getId() == idCliente) return cliente;
    }
    return nullptr;
}

void Tienda::listarProductos() const {
    std::cout << "Productos en la tienda:\n";
    for (const auto& producto : productos) {
        std::cout << "Código: " << producto->getCodigo()
                  << " | Nombre: " << producto->getNombre()
                  << " | Precio: $" << producto->getPrecio()
                  << " | Stock: " << producto->getStock() << "\n";
    }
}

void Tienda::mostrarVentas() const {
    std::cout << "Historial de ventas:\n";
    for (const auto& venta : ventas) {
        venta->mostrarDetalleVenta();
        std::cout << "--------------------------\n";
    }
}

float Tienda::calcularValorInventario() const {
    float total = 0.0;
    for (const auto& producto : productos) {
        total += producto->getPrecio() * producto->getStock();
    }
    return total;
}
