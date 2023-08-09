#include <iostream>
#include <set>
#include <math.h>
#include <stdlib.h> 
#include <set> 
//Elaborar un programa que utilice el TAD sobre conjuntos, set, en C++ que permita probar todo lo aprendido sobre el tema en la asignatura Matematica Discreta.
//Esto es union, interseccion, etc. Definan en principio un objeto a trabajar, por ejemplo el conjunto de los numeros enteros.

/* Bibliografia
https://aprende.olimpiada-informatica.org/cpp-set
https://es.cppreference.com/w/cpp/container/set
*/

//Definicion sustituta a contains.
void contiene(std::set <int> conj, int x){
  std::set <int>::iterator busqueda = conj.find(x);
  	if(busqueda!= conj.end()) std::cout << "Elemento encontrado. " << *busqueda << std::endl;
    else std::cout << "Elemento NO encontrado." << std::endl;
}

int main(){
  //Semilla de numero aleatorio
   srand(time(NULL));

  //Inicio del programa principal.
  std::cout << "Bienvenidos a Conjuntos!\n";
  //Definicion del conjunto de Enteros, aunque esta vacio.
	std::set <int> Enteros;
  //Iterador para recorrer el conjunto
  std::set <int>::iterator it;

  //Variables
  int intentos = 0;
  bool control = true;
  int n; //Numeros a ingresar a mi conjunto.
  
  while(control == true){
    n = 1 + rand() % 10;
		Enteros.insert(n);
		intentos ++;
    if(Enteros.size()==10) control = false;
  } 
	
	std::cout << "Cantidad de elementos: " <<Enteros.size() << 
    " \nCantidad de intentos: " <<intentos<< std::endl;
  
  //Muestro mis elementos. Recorriendo mi lista.
  for(it=Enteros.begin(); it!=Enteros.end(); it++){
    std::cout << "" << *it << std::endl;
  }
  
  //Enteros.contains(10); NO funciona por la version del compilador, la cual es 11.3.0. NECESITO LA 20+
	
    //Defino el iterador que retorna la funcion miembro .find(n)
  /*
  std::set <int>::iterator busqueda = Enteros.find(3);
	if(busqueda!= Enteros.end()) std::cout << "Elemento encontrado. " << *busqueda << std::endl;
    else std::cout << "Elemento NO encontrado." << std::endl;
 */
  contiene(Enteros, 145);
  contiene(Enteros, 3);
  
}