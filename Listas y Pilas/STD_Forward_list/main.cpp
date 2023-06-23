#include <iostream>
#include <forward_list>

//Definicion de estructura empleado (la usaremos para el ejemplo)
    typedef struct{
        std::string name;
        int age;
        int CI;
    } Empleado;


int main(){
    std::forward_list <Empleado> trabajadores2023;
    Empleado Emilio, Juan, Fede;
        //Definiremos los datos de los empleados
        Emilio = {"Emilio", 23, 12345678};
        Juan = {"Juan", 37,87654321};
        Fede = {"Federico",21, 12348765};

    trabajadores2023.push_front(Emilio);
    trabajadores2023.insert_after(trabajadores2023.begin(), Juan);
    trabajadores2023.push_front(Fede);
 
        trabajadores2023.resize(8);
        bool vacia = trabajadores2023.empty();
        std::cout << "Lista vacia " << vacia << std::endl;
    return 0;
}

