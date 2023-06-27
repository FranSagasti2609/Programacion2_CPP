#include <iostream>
#include <time.h> //Librerias para numeros random
#include <stdlib.h>
#include <algorithm> //Para std distance y max_element
#include <vector>

//Definicion de estructura empleado.
 typedef struct{
        std::string nombre;
        int edad;
        int CI;
        int dias_trabajados; //para gestion del contrato
        bool activo_hoy; //para determinar cantidad de trabajadores activos en un dia
        bool dato_activo; //Para activar o desactivar un dato de un vector
    } Empleado;

//Funcion que muestra un vector.
void mostrar_vector(std::vector <Empleado> vec){
    for(int i=0; i<vec.size(); i++){
        //Muestro solo los empleados activos en la empresa, aquellos que estan desactivados no.
        if(vec.at(i).dato_activo==true){
        std::cout << "Nombre: " << vec.at(i).nombre << " CI: " << vec.at(i).CI << " Edad: " << vec.at(i).edad 
        << " Dias trabajados: " << vec.at(i).dias_trabajados << " Activo Hoy: " << vec.at(i).activo_hoy << std::endl; 
        std::cout << "--------------------------------" << std::endl;
        }
    }
}
//Funcion que cuenta cantidad de datos activos.
int contar_activos (std::vector <Empleado> vec){
    int activos = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec.at(i).dato_activo == true) activos ++;
    }
    return activos;
}
//Funcion que desactiva empleados al llegar a 89 dias trabajados.
void desactivar_empleados(std::vector <Empleado> * vec){
    for(int i=0; i<vec->size(); i++){
        if(vec->at(i).dias_trabajados==89){
            std::cout << "Empleado con 89 dias encontrado: " << vec->at(i).nombre <<std::endl << "------------------" <<std::endl ;
            vec->at(i).dato_activo = false;
        }
    }

}
//Funcion que BORRA informacion de un empleado para siempre. 
void despedir (std::vector <Empleado> * vec, Empleado emp, std::vector <Empleado> * respaldo){
    
    for(int i=0; i<vec->size(); i++){
        if(vec->at(i).nombre==emp.nombre) {
            respaldo->push_back(emp);
            vec->erase(vec->begin()+i); //En ves de struc fantasma lo borramos directamente.
        }
    }
}

//Funcion que borra al empleado con mas dias si en un mismo dia hay 90 o mas
void noventa_activos(std::vector <Empleado> * vec){
    int contador = 0;
    int maximo = 0; 
    for(int i=0; i < vec->size(); i++){
        if(vec->at(i).activo_hoy==true) contador++;
        if(vec->at(i).dias_trabajados > maximo) maximo = vec->at(i).dias_trabajados;
    }   //Al finalizar el for, maximo almacena el mayor numero de dias. 
    
    //Ubicamos al empleado con el mayor numero de dias si hay mas de 89 empleados HOY
    if(contador >89){
        for(int i=0; i < vec->size(); i++){
            if(vec->at(i).dias_trabajados==maximo) {
                vec->erase(vec->begin()+i);
                break;
                }
       }
    } else {
        std::cout << "El empleado con mas dias trabajados es: " << maximo << std::endl;
        std::cout << "Hoy no hay mas de 90 empleados trabajando." <<std::endl;
        }
}

//Funcion principal
int main(){
    //Inicio semilla de tiempo.
    srand(time(NULL));
    
    //Defino mi vector de empleados
    std::vector <Empleado>trabajadores;

    //Variable que cuenta empleados activos en mi empresa
    int activos;

    //Ya no llenamos mi vector con cosas, ya que no habra elementos con datos randoms. Al tener la posibilidad de agregar o eliminar a gusto.
        //trabajadores.fill({"Unsigned",0,0,0,false,false}); //Activo los espacios fantasma con tal de probar la funcion.

    //Definimos algunos empleados de prueba.
    Empleado Emilio, Juan, Fede;
     Emilio = {"Emilio", 23, 12345678, rand() % 90, true,true};
     Juan = {"Juan", 37,87654321, rand() % 90,false,true};
     Fede = {"Federico",21, 12348765, rand() % 90,true,true};
        trabajadores.push_back(Emilio);
        trabajadores.push_back(Juan);
        trabajadores.push_back(Fede);
    
    //Desactivo todo empleado con mas de 89 dias de trabajo.
    desactivar_empleados(&trabajadores);
    
    //Prueba de despido
    std::vector <Empleado> despidos;
    //despedir(&trabajadores, Emilio, &despidos);

    //Cuento cuantos activos hay.
    activos = contar_activos(trabajadores);
    std::cout << "Empleados activos: " << activos << std::endl;    

    //Noventa activos hoy?
    noventa_activos(&trabajadores);
    mostrar_vector(trabajadores);
    return 0;
}