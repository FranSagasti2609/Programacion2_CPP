#include <iostream>
#include <stack>

//Definicion de estructura libro (la usaremos para el ejemplo)
    typedef struct{
        std::string nombre;
        int ID_libro;
        int precio;
    } Libro;

int main(){
    std::stack <Libro> stacklibros; //Definimos una pila de libros
    
    Libro Prog_1, Mate1, bio4to; //Ingresamos algunos ejemplos
    Prog_1.nombre = "Programacion en C - Tomo 1";
    Mate1.nombre = "Fundamentos de la Matematica. Edicion 2008";
    bio4to.nombre = "Biologia 4to Año";

    stacklibros.push(Prog_1);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;
    stacklibros.push(Mate1);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;
    stacklibros.push(bio4to);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;
      
      
        std::cout << "Primer elemento en mi lista: " << stacklibros.top().nombre << std::endl;
        std::cout << "Cant. De libros: " << stacklibros.size() << std::endl;
        std::cout << "Caja de libros vacía? " << stacklibros.empty() << std::endl;
        
    return 0;  
}