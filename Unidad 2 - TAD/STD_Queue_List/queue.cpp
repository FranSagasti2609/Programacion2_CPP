/*Atención a clientes de Banco "La Unión", a medida que el cliente ingresa toma
   un número y espera ser atendido. El cajero irá llamando en orden creciente.

*/
#include <deque> //Libreria para trabajar con colaDobles con nodos al inicio y al final
#include <iostream>

// Definicion de estructura empleado
typedef struct {
  std::string nombre;
  int numero;
  // bool atendido;
} Cliente;

void cargarcolaDoble(std::deque <Cliente> *colaDobleClientes) {
    
  colaDobleClientes->push_back({"A", 1});
  colaDobleClientes->push_back({"B", 2});
  colaDobleClientes->push_back({"C", 3});
  colaDobleClientes->push_front({"D",4});
  
}
//Funcion principal
int main() {
  //Definicion de mi deque y su iterador.
  std::deque<Cliente> colaDobleClientes;
  std::deque<Cliente>::iterator it; // Iterador de mi deque

  cargarcolaDoble(&colaDobleClientes);
  std::cout << "Bienvenidos al Banco la Unión, espere ser atendido por el "
               "personal." << std::endl;
  
  // Recorro mi deque
  for (it = colaDobleClientes.begin(); it != colaDobleClientes.end(); it++) {
    std::cout << "Nombre de mi cliente actual: " << it->nombre << std::endl;
  }

  //Pruebas extra.
  std::cout << "Cantidad de elementos: " << colaDobleClientes.size() << std::endl;
  //Resize.
  colaDobleClientes.resize(6);
  std::cout << "Cantidad de elementos luego del resize a 6: " << colaDobleClientes.size() << std::endl;

  //Acceso al primer y ultimo elemento (2 extra)
  std::cout << "Nombre 1er: " << colaDobleClientes.front().nombre << " Nombre Ultimo: " << colaDobleClientes.back().nombre << std::endl;
  //Observacion: Los elementos nuevos generados por el resize son agregados al back.
}