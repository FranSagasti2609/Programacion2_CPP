/*
 * Usa un std::map para contar la frecuencia de palabras en un texto.
*/

#include <iostream>
#include <map>
#include <forward_list>

//Funcion para dividir string y ingresar palabras separadas en una forward_list
std::forward_list <std::string> dividirString (std::string text){

    //String que reconocere como mi palabra "separada"
    std::string split;

    //Lista para almacenar palabras.
    std::forward_list <std::string> splitString;
    
    //Usaremos substr (para tomar subcadenas de un str), find para el delimitador (espacios).
    std::string limitador = " ";
    int indexEspacio = text.find(limitador); // .find() en string retorna un indice (int) donde se encuentra el char ingresado. Sino esta retorna -1
   
    while(indexEspacio!=-1){
        //Asigno a mi palabra separada a split
        split = text.substr(0,indexEspacio);

        //Encuentro una coma en mi palabra. Si find retorna -1, no habria una coma.
        if(split.find(',')!=-1)split.erase(split.find(','));  //Ubico a la coma, esta funcion find retorna la ubicacion. Luego borro el caracter de esa posicion.
        //Realizo lo mismo pero con los puntos.
        if(split.find('.')!=-1)split.erase(split.find('.'));
    
        //Agrego mi palabra a la lista y sigo recorriendo.
        splitString.push_front(split);
        text.erase(text.begin(), text.begin() + indexEspacio + 1); //Borro los caracteres leidos (la palabra y el espacio)
        indexEspacio = text.find(limitador); //Vuelvo a buscar un espacio para reingresar al while.

    } //Salgo del while y de la funcion.
    return splitString;
}

int main(){
    //Creamos el std::map y un iterador
    std::map <std::string, int> contador_palabras;
    std::map <std::string, int>::iterator it_cont;
    
    //Creamos una forward_list para almacenar las palabras separadas
    std::forward_list <std::string> palabras;
    std::forward_list <std::string>::iterator it;
    
    std::string text = "Hola Carlos, hoy hace un dia muy soleado. Carlos, manana no sabremos si estara soleado";
    palabras = dividirString(text); //Llamo a la funcion para hacer la division de las palabras.

    //Agrego mis palabras al diccionario
    it = palabras.begin();
    while(it!= palabras.end()){
        //std::cout << "Palabra: " << *it << std::endl; 
        if(contador_palabras.contains(*it)){
            contador_palabras[*it]=contador_palabras[*it]+1; 
        } else {
            contador_palabras.insert({*it, 1});
        }
        it++;
    }

    //Mostrar diccionario
    it_cont = contador_palabras.begin();
    while(it_cont!= contador_palabras.end()){
        std::cout << "Palabra: " << it_cont->first << " Cantidad: " << it_cont->second << std::endl;
        it_cont++;
    }
    return 0;
}