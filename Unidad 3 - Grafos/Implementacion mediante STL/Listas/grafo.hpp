#include <vector>
#include <map>
#include <list>
#include "estudiante.hpp"

class Grafo {
private:
  //Declaracion de atributos
    bool esDirigido;
  /*Creamos un map que reconoce a un vertice ESTUDIANTE, con una lista de pares de otros vectores que 
  son adyacentes al primero. Ademas el peso de la arista.*/
    std::map<Estudiante, std::list<std::pair<Estudiante, int>>> listaDeAdyacencia;
    std::map<Estudiante, int> v_a_i; // Vértices a índices
    std::vector<Estudiante> i_a_v; // Índices a vértices

public:
    Grafo(bool esDiri = true);
    virtual ~Grafo(); //Deconstructor de la clase

//Declaracion de metodos
    virtual bool agregarVertice(Estudiante v);
    virtual bool agregarArista(Estudiante va, Estudiante vb, int peso = 1);
//Debemos cambiar: vector de pares de vertices adyacentes a la lista (list)
    virtual void obtenerAdyacentes(Estudiante v, std::list<std::pair<Estudiante, int>>& adyacentes) const; //Modificamos vector por list
		virtual void obtenerIncidentes(Estudiante v, std::list<std::pair<Estudiante, int>>& incidentes) const;

};