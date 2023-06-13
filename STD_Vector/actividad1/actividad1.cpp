#include <string>
#include <iostream>
#include <vector>

typedef struct {
    std::string nombre;
    int cantidad;
} Producto;

std::vector <Producto> inventario; 

//Funcion que agrega un producto a un vector de productos
void agregar_producto(Producto p){
    inventario.push_back(p); //Agrego al ultimo lugar mediante "push_back" el producto p
}

//Funcion que muestra cada producto del vector, detallando nombre y cantidad
void print_inventario() {
    //En este for podriamos utilizar como limite "inventario.size()"
    for (int i = 0; i < inventario.size(); i++) {
        std::cout << "Nombre del producto: " << inventario.at(i).nombre << " Cantidad: " << inventario.at(i).cantidad << std::endl;
    }
}

//Funcion que elimina un producto del vector
void eliminar_producto(Producto p){
    for (int i = 0; i < inventario.size(); i++) {
        if(p.nombre == inventario.at(i).nombre){
            inventario.erase(inventario.begin() + i);
            std::cout << "Producto eliminado con exito." <<std::endl;
            break;
        }
    }
}

//Funcion que busca un producto en el vector
bool buscar_producto(Producto p){
    for (int i = 0; i < inventario.size(); i++) {
        if(p.nombre == inventario.at(i).nombre){
            std::cout << "Producto encontrado." << std::endl;
            return true;
        }
    } 
    std::cout << "Producto NO encontrado." << std::endl;
    return false;
}

//Funcion principal
int main() {
    inventario.resize(0); //Inicializo mi vector "vacio"

    Producto banana, pera, manzana;
    banana.nombre = "Banana";
    banana.cantidad = 20;
    pera.nombre = "Pera";
    pera.cantidad = 34;
    manzana.nombre = "Manzana";
    manzana.cantidad = 45;

    agregar_producto(banana);
    agregar_producto(pera);
    agregar_producto(manzana);
    print_inventario(); 
    eliminar_producto(pera);
    print_inventario(); 


    return 0;
}

