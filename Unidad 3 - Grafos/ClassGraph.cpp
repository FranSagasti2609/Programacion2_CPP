#include <iostream>
#include <vector>
//Declaracion de estructura "Arista"
struct Arista{
    //Una Arista une dos vertices:
    int vertice1, vertice2;
};

//Declaracion de class Grafo
class Grafo{
public:
    // un vector de vectores para representar una lista de adyacencia
        //Usamos el tipo int ya que nuestros vertices tienen numeros, si fueran estudiantes usamos struct Estudiante.
    std::vector<std::vector<int>> lista;

    //Constructor de la clase
    Grafo(std::vector <Arista> Aristas, int x){
        // Cambiar el tamaño del vector para contener "X" elementos de tipo `vector<int>`
        lista.resize(x);

        // Agrega bordes al grafo dirigido
        for (auto &Arista: Aristas){
            // insertar al final
            lista[Arista.vertice1].push_back(Arista.vertice2);
 
            // elimine el comentario del siguiente código para el graph no dirigido
            lista[Arista.vertice2].push_back(Arista.vertice1);
        }

    }
}; //Salgo de la definicion de clase

// Función para imprimir la representación de la lista de adyacencia de un grafo
void mostrar_Grafo(Grafo grafo1, int n){
    for (int i = 0; i < n; i++){
        // imprime el número de vértice actual
        std::cout << i << " ——> ";
 
        // imprime todos los vértices vecinos de un vértice `i`
        for (int v: grafo1.lista[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}


int main(){
    std::vector<Arista> aristas ={{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
    // número total de nodos en el graph (etiquetados de 0 a 5)
    int n = 6;
    // construir grafo
    Grafo grafito(aristas, n);
    // imprime la representación de la lista de adyacencia de un graph
    mostrar_Grafo(grafito, n);
    
    return 0;
}