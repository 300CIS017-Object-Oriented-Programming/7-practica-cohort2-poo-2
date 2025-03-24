#include <iostream>
#include "Tienda.h"

void mostrarMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Agregar producto\n";
    std::cout << "2. Registrar cliente\n";
    std::cout << "3. Registrar venta\n";
    std::cout << "4. Reabastecer producto\n";
    std::cout << "5. Listar productos\n";
    std::cout << "6. Mostrar historial de ventas\n";
    std::cout << "7. Calcular valor del inventario\n";
    std::cout << "8. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    Tienda tienda;
    int opcion;

    // Agregar productos iniciales
    tienda.agregarProducto("P001", "Botella de agua reciclable", 5.99, 100);
    tienda.agregarProducto("P002", "Bolsa biodegradable", 2.49, 200);

    // Agregar clientes iniciales
    tienda.registrarCliente(1, "Juan Pérez");
    tienda.registrarCliente(2, "María López");

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string codigo, nombre;
                float precio;
                int stock;

                std::cout << "Código: ";
                std::cin >> codigo;
                std::cout << "Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Precio: ";
                std::cin >> precio;
                std::cout << "Stock inicial: ";
                std::cin >> stock;

                tienda.agregarProducto(codigo, nombre, precio, stock);
                std::cout << "Producto agregado con éxito.\n";
                break;
            }
            case 2: {
                int id;
                std::string nombre;

                std::cout << "ID del cliente: ";
                std::cin >> id;
                std::cout << "Nombre del cliente: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);

                tienda.registrarCliente(id, nombre);
                std::cout << "Cliente registrado con éxito.\n";
                break;  // 🔹 ESTE BREAK FALTABA
            }
            case 3: {
                int idCliente;
                std::cout << "ID del cliente: ";
                std::cin >> idCliente;

                tienda.registrarVenta(idCliente);
                break;
            }
            case 4: {
                std::string codigoProducto;
                int cantidad;

                std::cout << "Código del producto: ";
                std::cin >> codigoProducto;
                std::cout << "Cantidad a agregar: ";
                std::cin >> cantidad;

                tienda.reabastecerProducto(codigoProducto, cantidad);
                break;
            }
            case 5:
                tienda.listarProductos();
                break;
            case 6:
                tienda.mostrarVentas();
                break;
            case 7:
                std::cout << "Valor total del inventario: $" << tienda.calcularValorInventario() << "\n";
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 8);

    return 0;
}
