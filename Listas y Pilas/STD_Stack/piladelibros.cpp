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
    Libro prog_1, mate1, bio4to; //Ingresamos algunos ejemplos
     prog_1 = {"Programacion en C - Tomo 1", 1, 500};
     mate1 = {"Fundamentos de la Matematica. Edicion 2008", 2, 350};
     bio4to = {"Biologia 4to Año", 3, 470};

    stacklibros.push(prog_1);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;
    stacklibros.push(mate1);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;
    stacklibros.push(bio4to);
     //std::cout << "Nombre del libro agregado al sistema: " << stacklibros.top().nombre << std::endl;

    //Como mostrar mi pila.
    std::stack <Libro> stackCopia = stacklibros;
    while(!stackCopia.empty()) {
        std::cout << "Nombre del libro: " << stackCopia.top().nombre << std::endl;
        std::cout << "ID del libro: " << stackCopia.top().ID_libro << std::endl;
        std::cout << "Precio del libro: " << stackCopia.top().precio << std::endl;
        std::cout << "------------------------" << std::endl;
        stackCopia.pop();
    }   
    std::cout << "Longitud de la pila original: " << stacklibros.size() <<std::endl;
    std::cout << "Longitud de la pila copia: " << stackCopia.size() <<std::endl;

    return 0;  
}