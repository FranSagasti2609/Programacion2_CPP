#include <vector>
#include <map>
#include "estudiante.hpp"

class Grafo {
private:
    bool esDirigido;
    std::vector<std::vector<int>> matriz; // Matriz de adyacencia
    std::map<Estudiante, int> v_a_i; // Vértices a índices
    std::vector<Estudiante> i_a_v; // Índices a vértices

public:
    Grafo(bool esDiri = true);
    virtual ~Grafo();

    virtual bool agregarVertice(Estudiante v);
    virtual bool agregarArista(Estudiante va, Estudiante vb, int peso = 1);
    virtual void obtenerAdyacentes(Estudiante v, std::vector<std::pair<Estudiante, int>>& adyacentes) const;
		virtual void obtenerIncidentes(Estudiante v, std::vector<std::pair<Estudiante, int>>& incidentes) const;
};
