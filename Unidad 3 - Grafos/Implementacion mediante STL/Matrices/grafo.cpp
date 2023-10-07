#include "grafo.hpp"

Grafo::Grafo(bool esDiri) : esDirigido(esDiri) {}

Grafo::~Grafo() {}

bool Grafo::agregarVertice(Estudiante v) {
    if (v_a_i.find(v) != v_a_i.end()) return false;
    int index = i_a_v.size();
    v_a_i[v] = index;
    i_a_v.push_back(v);
    for (auto& fila : matriz) fila.push_back(0);
    matriz.push_back(std::vector<int>(i_a_v.size(), 0));
    return true;
}

bool Grafo::agregarArista(Estudiante va, Estudiante vb, int peso) {
    if (v_a_i.find(va) == v_a_i.end() || v_a_i.find(vb) == v_a_i.end()) return false;
    int fila = v_a_i[va];
    int columna = v_a_i[vb];
    matriz[fila][columna] = peso;
    if (!esDirigido) matriz[columna][fila] = peso;
    return true;
}

void Grafo::obtenerAdyacentes(Estudiante v, std::vector<std::pair<Estudiante, int>>& adyacentes) const {
    adyacentes.clear();
    if (v_a_i.find(v) == v_a_i.end()) return;
    int index = v_a_i.at(v);
    for (int i = 0; i < matriz[index].size(); ++i) {
        if (matriz[index][i] != 0) adyacentes.push_back({i_a_v[i], matriz[index][i]});
    }
}

void Grafo::obtenerIncidentes(Estudiante v, std::vector<std::pair<Estudiante, int>>& incidentes) const {
    incidentes.clear();
    if (v_a_i.find(v) == v_a_i.end()) return;
    int index = v_a_i.at(v);
    for (int i = 0; i < matriz.size(); ++i) {
        if (matriz[i][index] != 0) incidentes.push_back({i_a_v[i], matriz[i][index]});
    }
}

