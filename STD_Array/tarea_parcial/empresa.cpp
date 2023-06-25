#include <iostream>
#include <vector>
#include <time.h> //Librerias para numeros random
#include <stdlib.h>
#include <algorithm>
#include <numeric>

//Definicion de estructura empleado (la usaremos para el ejemplo)
    typedef struct{
        std::string name;
        int age;
        int CI;
        int dias_trabajados; //para gestion del contrato
        bool activo_hoy; //para determinar cantidad de trabajadores2023 activos en un dia
    } Empleado;

//Funcion que almacena la informacion del empleado a borrar.
Empleado recuperar_empleado(Empleado emp){
    Empleado copia = emp;
    return copia;
}

int main(){
    std::vector <Empleado> trabajadores2023;
    std::vector <Empleado> respaldo;
    int empleados_hoy = 0;
    srand(time(NULL));
    Empleado Emilio, Juan, Fede;
        //Definiremos los datos de los trabajadores2023
        Emilio = {"Emilio", 23, 12345678, rand() % 90, true};
        Juan = {"Juan", 37,87654321, rand() % 90,false};
        Fede = {"Federico",21, 12348765, rand() % 90,true};
        trabajadores2023.push_back(Emilio);
        trabajadores2023.push_back(Juan);
        trabajadores2023.push_back(Fede);
  
        
    //Verificacion de operaciones.
        //Expulsar empleado antes de renovar contrato:
        for(int i = 0; i< trabajadores2023.size(); i++){
        if(trabajadores2023.at(i).dias_trabajados == 89) {
            Empleado copia = trabajadores2023[i]; //Almaceno informacion.
            std::cout << "Empleado: " << trabajadores2023[i].name << " con CI: " <<trabajadores2023[i].CI << " sera expulsado." <<std::endl;
            trabajadores2023.erase(trabajadores2023.begin() + i); // Lo borro
            respaldo.push_back(copia);
        }
    }
        //Reingresar a todo empleado que fue expulsado.
        for(int i=0; i < respaldo.size(); i++){
            std::cout << "Empleado: " << respaldo[i].name << " con CI: " <<respaldo[i].CI << " sera reingresado." <<std::endl;
            trabajadores2023.push_back(respaldo[i]);
        }
  
        //Si hay mas de 90 empleados eliminar el empleado con mas dias.
            int max_index=0;
       for(int i=0; i < trabajadores2023.size(); i++){
            if(trabajadores2023[i].activo_hoy == true) empleados_hoy++;
       } 
       //Eliminacion del emplado:
       if(empleados_hoy>89){
       
        }
    
    //Mostrar trabajadores2023
        for(int i=0; i < trabajadores2023.size(); i++){
            std::cout << "Nombre: " << trabajadores2023[i].name << std::endl;
            std::cout << "CI: " << trabajadores2023[i].CI << std::endl;
            std::cout << "Edad: " << trabajadores2023[i].age << std::endl;
            std::cout << "Dias totales trabajados: " << trabajadores2023[i].dias_trabajados << std::endl;
            std::cout << "Activo hoy: " << trabajadores2023[i].activo_hoy << std::endl;
            std::cout << "---------------------" << std::endl;
        }

    return 0;
}