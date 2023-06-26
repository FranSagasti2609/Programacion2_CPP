#include <iostream>
#include <stack>
//Ejemplo pilas empleado.
//Definicion de estructura empleado (la usaremos para el ejemplo)
    typedef struct{
        std::string name;
        int age;
        int CI;
    } Empleado;

int main(){
    std::stack <Empleado> stackEmpleados; //Definimos una pila de empleados
    
    Empleado Emilio, Juan, Fede; //Ingresamos algunos ejemplos
    Emilio.name = "Emilio";
    Juan.name = "Juan";
    Fede.name = "Federico";

    stackEmpleados.push(Emilio);
    stackEmpleados.push(Juan);
    stackEmpleados.push(Fede);

    std::cout << "Cant. De empleados: " << stackEmpleados.size() << std::endl;
    std::cout << "Empresa vacia? " << stackEmpleados.empty() << std::endl;


    return 0;  
}