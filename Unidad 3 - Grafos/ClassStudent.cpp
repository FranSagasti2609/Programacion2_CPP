#include <iostream>
#include <vector>
//Declaracion de estructura "Estudiante"
struct Estudiante{
    std::string nombre;
    int calificacion_final;
};

//Declaracion de estructura "Arista"
struct Arista{
    //Una Arista une dos vertices (estudiantes):
    Estudiante est1, est2;
};

//Declaracion de class Grafo
class Grafo_Estudiantes{
public:
    // un vector de vectores para representar una lista de adyacencia
    std::vector<std::vector<Estudiante>> lista_estudiante;

    //Constructor de la clase
    Grafo_Estudiantes(std::vector <Arista> Aristas, int x){
        // Cambiar el tamaño del vector para contener "X" elementos de tipo `vector<int>`
        lista_estudiante.resize(x);
        // Agrega aristas al grafo dirigido
        for (auto &Arista: Aristas){
                // insertar al final
                lista_estudiante[Arista.est1].push_back(Arista.est2);
            

            // elimine el comentario del siguiente código para el graph no dirigido
            //lista[Arista.vertice2].push_back(Arista.vertice1);
        }
    }
}; //Salgo de la definicion de clase

// Función para imprimir la representación de la lista de adyacencia de un grafo
void mostrar_Grafo(Grafo_Estudiantes grafo1, int n)
{
    for (int i = 0; i < n; i++)
    {
        // imprime el número de vértice actual
        std::cout << i << " ——> ";
 
        // imprime todos los vértices vecinos de un vértice `i`
        for (Estudiante v: grafo1.lista_estudiante[i]) {
            std::cout << v.nombre << " ";
        }
        std::cout << std::endl;
    }
}


int main(){
    //{"Francisco", 12345678, 8}
    std::vector<Arista> alumnos2023 = {{{"Francisco", 8},{"Federico",12}}, {{"Marta",9}, {"Cristian",7}}};
 
    // número total de nodos en el graph (etiquetados de 0 a 3)
    int n = 1;
 
    // construir grafo
    Grafo_Estudiantes grafito(alumnos2023, n);
 
    // imprime la representación de la lista de adyacencia de un graph
    mostrar_Grafo(grafito, n);
    
    return 0;
}