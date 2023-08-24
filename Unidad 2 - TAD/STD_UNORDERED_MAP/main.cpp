#include <iostream>
#include <unordered_map>

//Definicion sustituta a contains.
void contiene(std::unordered_map <int, std::string> map, int key){
  std::unordered_map <int, std::string>::iterator busqueda = map.find(key);
  	if(busqueda!= map.end()) std::cout << "Elemento encontrado con la key ingresada. " << busqueda->second << std::endl;
    else std::cout << "Elemento NO encontrado con la key ingresada." << std::endl;
}


int main(){
    //Declaracion de mi diccionario
    std::unordered_map <int, std::string> Libros;
    std::unordered_map <int, std::string>::iterator it;

    //Agregar elementos.
    Libros.insert({01, "Poesia Greco-Romana"});
    Libros.insert({02, "Matematica Discreta"});
        //Suplantar elemento en una cierta key
    Libros.insert_or_assign(02, "Programacion con Juancho");
        //Y si intento insertar en una key ya asignada?
    Libros.insert({02, "Recetas 2023."}); //R: No se asigna!

    //Probamos otras cosas
        //Uso de count,
    std::cout << "Tengo el elemento con la key 01, " << Libros.count(01) << std::endl;
    std::cout << "Tengo el elemento con la key 076, " << Libros.count(076) << std::endl;
        //Uso de contains (usamos funcion definida por el programador)
    contiene(Libros, 03);
    contiene(Libros, 01);
    
    //Muestro elementos.
    std::cout << "Libro con indice 02 es llamado: " << Libros.at(02) << std::endl;
        //y si busco algo que no pertenece a mi unordered_map?
     //std::cout << "Libro con indice 04 es llamado: " << Libros.at(04) << std::endl; //R: Se lanza una ekeycepcion.

    //Mostrar mediante for, veamos como el iterador tiene first y second para acceder a la key y elemento.
    for(it = Libros.begin(); it!= Libros.end(); it++){
        std::cout << "" << it->first << " "; //Muestro la key
        std::cout << "" << it->second << std::endl; //Muestro el primer elemento.
    }
    




}