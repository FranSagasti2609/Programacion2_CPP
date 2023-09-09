#include <iostream>
#include <vector>
using namespace std;
 
// Estructura de datos para almacenar un borde de graph
struct Edge {
    int src, dest;
};
 
// Una clase para representar un objeto graph
class Graph{
public:
    // un vector de vectores para representar una lista de adyacencia
    vector<vector<int>> adjList;
 
    // Constructor de graph
    Graph(vector<Edge> const &edges, int n)
    {
        // cambiar el tamaño del vector para contener `n` elementos de tipo `vector<int>`
        adjList.resize(n);
 
        // agrega bordes al grafo dirigido
        for (auto &edge: edges)
        {
            // insertar al final
            adjList[edge.src].push_back(edge.dest);
 
            // elimine el comentario del siguiente código para el graph no dirigido
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Función para imprimir la representación de la lista de adyacencia de un graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // imprime el número de vértice actual
        cout << i << " ——> ";
 
        // imprime todos los vértices vecinos de un vértice `i`
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
 
// Implementación de graph usando STL
int main(){
    // vector de los bordes del graph según el diagrama anterior.
    // Tenga en cuenta que el vector de inicialización en el siguiente formato
    // funciona bien en C++11, C++14, C++17 pero fallará en C++98.
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
 
    // número total de nodos en el graph (etiquetados de 0 a 5)
    int n = 6;
 
    // construir grafo
    Graph graph(edges, n);
 
    // imprime la representación de la lista de adyacencia de un graph
    printGraph(graph, n);
 
    return 0;
}