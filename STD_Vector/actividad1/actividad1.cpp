#include <string>
#include <iostream>
#include <vector>

typedef struct {
    std::string nombre;
    int cantidad;
} Producto;

std::vector <Producto> inventario; 
int inventario_size = 0;

//Funcion que agrega un producto a un vector de productos
void agregar_producto(Producto p){
    inventario.at(inventario.size())=p; //Agrego al ultimo lugar mediante "size" el producto p
    inventario_size++; 
}
//Funcion que muestra cada producto del vector, detallando nombre y cantidad
void print_inventario() {
    //En este for podriamos utilizar como limite "inventario.size()"
    for (int i = 0; i < inventario_size; i++) {
        std::cout << "Nombre del producto: ", inventario.at(i).nombre," Cantidad: ", inventario.at(i).cantidad;
    }
}
//Funcion que elimina un producto del vector
void eliminar_producto(Producto p){
    //Podemos usar la funcion "erase", se utiliza "nombre".erase(indice_elemento_a_borrar);
    //Solucion Llevar a p a la ultima posicion y borrarlo, usando push_back
    inventario.push_back(p);
    inventario.erase(inventario.end()); //Borro el ultimo elemento, que es p.
    inventario_size--;
}
//Funcion que busca un producto en el vector
void buscar_producto(Producto p){
    for(int i = 0; i<inventario_size; i++){

    }

}

//Funcion principal
int main() {
    inventario.resize(0); //Inicializo mi vector "vacio"

    Producto pera, banana;
    pera.cantidad = 20;
    pera.nombre = "Pera";
    banana.cantidad=23;
    banana.nombre = "Banana";
    agregar_producto(pera);
    agregar_producto(banana);
    print_inventario();
    return 0;
}

