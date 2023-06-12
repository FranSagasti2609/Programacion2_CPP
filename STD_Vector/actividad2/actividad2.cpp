#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

    typedef struct {
     std::string name;
     int nota;
    } estudiante;

    std::vector <float> calificaciones;
    std::vector <estudiante> alumnos;

//Funciones sobre vector "calificaciones"
    //Agregar nota al vector usando push_back
void agregar_calificacion(int nota){
    calificaciones.push_back(nota);
 }
    //Usando min_element, distance y erase para eliminar la calificación más baja
void eliminar_nota_baja(std::vector <float> calificaciones){
    auto min = std::min_element(calificaciones.begin(), calificaciones.end());
    std::cout << "min element at: " << std::distance(calificaciones.begin()-1, min); //Retorna el indice de la nota mas baja
    
}

//Funcion main
int main() {
    calificaciones.resize(0);
    alumnos.resize(0);

    // Añadir una calificación al vector usando push_back
    agregar_calificacion(10);
    agregar_calificacion(7);
    agregar_calificacion(3);
    agregar_calificacion(12);
    agregar_calificacion(5);
// Encontrar y eliminar la calificación más baja usando min_element, distance y erase
    eliminar_nota_baja(calificaciones);

    // Calcular el promedio de las calificaciones al final del semestre



return 0;
}

/*
Cuando un estudiante se une a la clase, añades una calificación inicial de 0 al final del vector. Cuando un
estudiante deja la clase, eliminas todas sus calificaciones del vector. Al final del semestre, calculas el promedio
de las calificaciones de cada estudiante, pero antes de hacerlo, eliminas su calificación más baja. Para ello, te
gustaría utilizar las funciones push_back, erase, std::min_element, std::distance, std::accumulate y std::size.

finalmente std::accumulate y std::size
para calcular el promedio de las calificaciones al final del semestre.

*/