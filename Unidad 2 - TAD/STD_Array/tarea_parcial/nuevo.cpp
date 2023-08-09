#include <iostream>
#include <array>
#include <time.h> //Librerias para numeros random
#include <stdlib.h>
#include <algorithm> //PAra std distance y max_element
#include <vector>

//Definicion de estructura empleado.
 typedef struct{
        std::string nombre;
        int edad;
        int CI;
        int dias_trabajados; //para gestion del contrato
        bool activo_hoy; //para determinar cantidad de trabajadores activos en un dia
        bool dato_activo; //Para activar o desactivar un dato de un array
    } Empleado;

//Funcion que muestra un array.
void mostrar_array(std::array <Empleado,100> arr){
    for(int i=0; i<arr.size(); i++){
        //Muestro solo los empleados activos en la empresa, aquellos que estan desactivados no.
        if(arr[i].dato_activo==true){
        std::cout << "Nombre: " << arr[i].nombre << " CI: " << arr[i].CI << " Edad: " << arr[i].edad 
        << " Dias trabajados: " << arr[i].dias_trabajados << " Activo Hoy: " << arr[i].activo_hoy << std::endl; 
        std::cout << "--------------------------------" << std::endl;
        }
    }
}
//Funcion que cuenta cantidad de datos activos.
int contar_activos (std::array <Empleado,100> arr){
    int activos = 100;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].dato_activo == false) activos --;
    }
    return activos;
}
//Funcion que desactiva empleados al llegar a 89 dias trabajados.
std::array <Empleado,100> desactivar_empleados(std::array <Empleado,100> arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i].dias_trabajados==89){
            std::cout << "Empleado con 89 dias encontrado: " << arr[i].nombre <<std::endl << "------------------" <<std::endl ;
            arr[i].dato_activo = false;
        }
    }
    return arr;
}
//Funcion que BORRA informacion de un empleado para siempre. 
std::array <Empleado,100> despedir(std::array <Empleado,100> arr, Empleado emp, std::vector <Empleado> * vec){
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i].nombre==emp.nombre) {
            vec->push_back(emp);
            arr[i] = {"Unsigned",0,0,0,false,false};
        }
    }
    return arr;
}
//Funcion que activa empleado 
void activar_empleado(Empleado * emp){
    emp->dato_activo = true;
}

//Funcion que borra al empleado con mas dias si en un mismo dia hay 90 o mas
std::array <Empleado,100> noventa_activos(std::array <Empleado,100> arr){
    int contador = 0;
    int maximo = 0; 
    for(int i=0; i < arr.size(); i++){
        if(arr[i].activo_hoy==true) contador++;
        if(arr[i].dias_trabajados > maximo) maximo = arr[i].dias_trabajados;
    }   //Al finalizar el for, maximo almacena el mayor numero de dias. 
    
    //Ubicamos al empleado con el mayor numero de dias si hay mas de 89 empleados HOY
    if(contador >89){
        for(int i=0; i < arr.size(); i++){
            if(arr[i].dias_trabajados==maximo) {
                std::cout <<"Maximo " << maximo << std::endl;
                arr[i] = {"Unsigned",0,0,0,false,false};}
       }
    }
    return arr;
}
//Funcion principal
int main(){
    //Inicio semilla de tiempo.
    srand(time(NULL));
    
    //Defino mi array de empleados
    std::array <Empleado,100> trabajadores;

    //Variable que cuenta empleados activos en mi empresa
    int activos;

    //Lleno mi array con elementos inicializados a cero. (evitando numeros feos)
        trabajadores.fill({"Unsigned",0,0,0,false,false}); //Activo los espacios fantasma con tal de probar la funcion.

    //Definimos algunos empleados de prueba.
    Empleado Emilio, Juan, Fede;
     Emilio = {"Emilio", 23, 12345678, rand()%90, true,true};
     Juan = {"Juan", 37,87654321, rand()% 90,false,true};
     Fede = {"Federico",21, 12348765, rand() % 90,true,true};
        trabajadores.at(0) = Emilio;
        trabajadores.at(1) = Juan;
        trabajadores.at(2) = Fede;
    
    //Desactivo todo empleado con mas de 89 dias de trabajo.
    trabajadores = desactivar_empleados(trabajadores);

    //Cuento cuantos activos hay.
    activos = contar_activos(trabajadores);
    std::cout << "Empleados activos: " << activos << std::endl;    
    //Despedir empleado.
        /*std::vector <Empleado> despidos; 
    std::cout <<"Nombre empleado a despedir: " <<trabajadores.at(2).nombre <<std::endl;
    trabajadores = despedir(trabajadores, Fede, &despidos);
    activos = contar_activos(trabajadores);
    std::cout << "Empleados activos: " << activos << std::endl;  
    std::cout <<"Nombre del lugar del EX empleado: " <<trabajadores.at(2).nombre <<std::endl;
    std::cout << "RESPALDO 1: " << despidos.at(0).nombre << std::endl; */
    
    // Eliminar 90
    /*
    int contador = 0;
    int maximo = 0; 
    for(int i=0; i < trabajadores.size(); i++){
        if(trabajadores[i].activo_hoy==true) contador++;
        if(trabajadores[i].dias_trabajados > maximo) {maximo = trabajadores[i].dias_trabajados;}
    }   //Al finalizar el for, maximo almacena el mayor numero de dias. 
    
    //Ubicamos al empleado con el mayor numero de dias si hay mas de 89 empleados HOY
    if(contador >89){
        for(int i=0; i < trabajadores.size(); i++){
            if(trabajadores[i].dias_trabajados==maximo) trabajadores[i] = {"Unsigned",0,0,0,false,false};
       }
    } 
        */
    
    trabajadores = noventa_activos(trabajadores);
    mostrar_array(trabajadores);
    return 0;
}