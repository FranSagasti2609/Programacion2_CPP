#include <iostream>
#include "grafo.hpp"
#include "estudiante.hpp"

int main() {
    std::cout << "Hola Grafo!\n";
    Grafo miGrafo = Grafo(true);
    Estudiante estudiante1 = Estudiante(111, "Carlos", 26, Sexo::MASCULINO);
    Estudiante estudiante2 = Estudiante(222, "Stephen", 30, Sexo::MASCULINO);
    Estudiante estudiante3 = Estudiante(333, "Jennifer", 90, Sexo::FEMENINO);
    Estudiante estudiante4 = Estudiante(444, "August", 43, Sexo::MASCULINO);

    miGrafo.agregarVertice(estudiante1);
    miGrafo.agregarVertice(estudiante2);
    miGrafo.agregarVertice(estudiante3);
    miGrafo.agregarVertice(estudiante4);

    miGrafo.agregarArista(estudiante3, estudiante4);
    miGrafo.agregarArista(estudiante4, estudiante1);
    miGrafo.agregarArista(estudiante2, estudiante3);
    miGrafo.agregarArista(estudiante1, estudiante3);

    //Mostramos los adyacentes a un cierto vertice.
    Estudiante vertice = estudiante3;
    std::list<std::pair<Estudiante, int>> adyacentes;
    miGrafo.obtenerAdyacentes(vertice, adyacentes);
    std::list<std::pair<Estudiante, int>>::iterator it = adyacentes.begin();
  
    std::cout << "Adyacentes de " << vertice.getNombre() << std::endl;
    while (it != adyacentes.end()) {
        std::cout << it->first.getNombre() << "\t";
        it++;
    }
    std::cout << std::endl;

    //Mostramos los incidentes a un cierto vertice.
    std::list<std::pair<Estudiante, int>> incidentes;
    miGrafo.obtenerIncidentes(vertice, incidentes);
    std::list<std::pair<Estudiante, int>>::iterator it2 = incidentes.begin();

    std::cout << "Incidentes de " << vertice.getNombre() << std::endl;
    while (it2 != incidentes.end()) {
        std::cout << it2->first.getNombre() << "\t";
        it2++;
    }
    std::cout << std::endl;
  
    return 0;
}
