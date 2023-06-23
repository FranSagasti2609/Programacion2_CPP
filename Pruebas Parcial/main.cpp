#include <iostream>
#include <vector>

typedef struct {
    std::string nombre;
    int cantidad;
} Producto;

int main(){
    std::vector <Producto> inventarios; 
    //Prueba de como buscar un elemento de un vector y eliminarlo.
    Producto banana, pera, manzana;
    banana.nombre = "Banana";
    banana.cantidad = 20;
    pera.nombre = "Pera";
    pera.cantidad = 34;
    manzana.nombre = "Manzana";
    manzana.cantidad = 45;
    inventarios.push_back(banana);
    inventarios.push_back(pera);
    inventarios.push_back(manzana);
    /*Recorro el array o vector.

        for(int i=0; i<inventarios.size(); i++){
            if(inventarios[i].nombre == manzana.nombre){
                inventarios.erase(inventarios.begin() + i);
            }
        } */
        inventarios.erase(inventarios.end()-2);
 
        for (int i = 0; i < inventarios.size(); i++) {
        std::cout << "Nombre del producto: " << inventarios.at(i).nombre << " Cantidad: " << inventarios.at(i).cantidad << std::endl;
    }

    return 0;
}