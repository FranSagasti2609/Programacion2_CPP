#include <iostream>
#include <forward_list>
#include <time.h> //Librerias para numeros random
#include <stdlib.h>
#include <algorithm> //Libreria para hallar el empleado con mas dias trabajados
#include <numeric>

//Definicion de estructura empleado (la usaremos para el ejemplo)
    typedef struct{
        std::string name;
        int age;
        int CI;
        int dias_trabajados; //para gestion del contrato
        bool activo_hoy; //para determinar cantidad de empleados activos en un dia
    } Empleado;

//Funcion que borra un empleado con 89 dias trabajados.
bool demasiados_dias(Empleado emp){
    if(emp.dias_trabajados==89) return true;
        else return false;
}

//Funcion que nos retorna el numero del empleado con mas dias trabajados
bool fecha_mas_alta(Empleado emp){
    
}
    



// Si tengo más de 90 empleados en simultáneo en mi empresa expulsaré al más cercano de ser efectivo.
void muchos_empleados(std::forward_list <Empleado> lista){
    std::forward_list <Empleado>::iterator it = lista.begin();
    int x = 0; //Pensemos que ningun empleado va, iremos sumandolos mediante un iterador.
    for(it; it!=lista.end(); it++){
        if(it->activo_hoy = true) x++; //Recorro mi lista, sumando la cantidad de empleados activos HOY.
    }
        if(x>89) {
            //lista.remove_if(fecha_mas_alta);
            }
        else std::cout << "Menos de 90 empleados activos hoy." <<std::endl;

    std::cout << "Empleados activos hoy: " << x << std::endl;
} 

int main(){
    //Inicio semilla para tiempos aleatorio.
    srand(time(NULL));

    std::forward_list <Empleado> trabajadores2023; //Defino lista
    std::forward_list <Empleado>::iterator it; //Definimos el iterador it de la lista.


    Empleado Emilio, Juan, Fede;
        //Definiremos los datos de los empleados
        Emilio = {"Emilio", 23, 12345678, rand() % 90, true};
        Juan = {"Juan", 37,87654321, rand() % 90,false};
        Fede = {"Federico",21, 12348765, rand() % 90,true};

    trabajadores2023.push_front(Emilio);
    trabajadores2023.insert_after(trabajadores2023.begin(), Juan);
    trabajadores2023.push_front(Fede);
    //Cuantos empleados trabajan hoy, expulsion del que posee mas dias
     //fecha_mas_alta(trabajadores2023);
     muchos_empleados(trabajadores2023);

     //Verificacion de operaciones.
        //Expulsar empleado antes de renovar contrato:
     trabajadores2023.remove_if(demasiados_dias);

        //Reingresar.



     //Como mostrar elementos de mi lista.
       /*for(it = trabajadores2023.begin(); it != trabajadores2023.end(); it++){
        std::cout << "Nombre: " << it->name << std::endl;
        std::cout << "CI: " << it->CI << std::endl;
        std::cout << "Edad: " << it->age << std::endl;
        std::cout << "Dias totales trabajados: " << it->dias_trabajados << std::endl;
        std::cout << "Activo hoy: " << it->activo_hoy << std::endl;
        std::cout << "---------------------" << std::endl;
       } */


    return 0;
}

