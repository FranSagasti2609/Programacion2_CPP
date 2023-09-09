#include <iostream>
#include <map>

/*
Crea una agenda telefónica usando std::map donde 
puedas agregar, eliminar y buscar números de teléfono.
*/

//Funcion para agregar numero
void agregar_num(std::map <std::string, int> * map){
    //Variables.
    std::string name;
    int number;

    std::cout << "Ingrese el nombre del usuario:" <<std::endl;
    std::cin >> name;
    std::cout << "Ingrese el numero del usuario:" <<std::endl;
    std::cin >> number;
        map->insert_or_assign(name,number);
}

//Funcion para eliminar numero
void borrar_num(std::map <std::string, int> * map){
    
}
//Funcion para buscar numero


int main(){

    std::map <std::string, int> agenda;
    int opcion;
    
    //Empezamos...
    do{
        std::cout << "Ingrese una opcion: " <<std::endl;
        std::cout << "1. Agregar numero." << std::endl << "2. Eliminar numero." << std::endl << 
        "3. Buscar numero." << std::endl << "4. Salir." << std::endl;
            std::cin >> opcion;
        //En base a mi operacion deseada realizamos un switch.
        switch(opcion){
            case 1:
            agregar_num(&agenda);
            break;
            case 2:
            borrar_num(&agenda);
            break;
            case 3:

            break;
            default:
            std::cout << "Ninguna operacion seleccionada." <<std::endl;
            break;
        }

    }while(opcion!=4);
    
    //Muestro mi agenda, para probar..
    std::cout << "BIENVENIDO A SU AGENDA." << std::endl;

    auto it_cont = agenda.begin();
    while(it_cont!= agenda.end()){
        std::cout << "Nombre: " << it_cont->first << " Celular: " << it_cont->second << std::endl;
        it_cont++;
    }

    return 0;
}