#include "grafo.hpp"

Grafo::Grafo(bool esDiri) : esDirigido(esDiri) {}

Grafo::~Grafo() {}

bool Grafo::agregarVertice(Estudiante v) {
    if (v_a_i.find(v) != v_a_i.end()) return false;
    int index = i_a_v.size();
    v_a_i[v] = index;
    i_a_v.push_back(v);
    listaDeAdyacencia[v] = std::list<std::pair<Estudiante, int>>();
    return true;
}

bool Grafo::agregarArista(Estudiante va, Estudiante vb, int peso) {
    if (v_a_i.find(va) == v_a_i.end() || v_a_i.find(vb) == v_a_i.end()) return false;
    listaDeAdyacencia[va].push_back({vb, peso});
    if (!esDirigido) listaDeAdyacencia[vb].push_back({va, peso});
    return true;
}

void Grafo::obtenerAdyacentes(Estudiante v, std::list<std::pair<Estudiante, int>>& adyacentes) const {
    adyacentes.clear();
    if (v_a_i.find(v) == v_a_i.end()) return;
    adyacentes = listaDeAdyacencia.at(v);
}

void Grafo::obtenerIncidentes(Estudiante v, std::list<std::pair<Estudiante, int>>& incidentes) const {
    incidentes.clear();
  
    if (v_a_i.find(v) == v_a_i.end()) return;

    for(const auto& entrada : listaDeAdyacencia) {
        for (const auto& par : entrada.second) {
            if (par.first == v) {
                incidentes.push_back({entrada.first, par.second});
            }
        }
    }
}
