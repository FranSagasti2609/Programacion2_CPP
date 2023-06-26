#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

    typedef struct {
     std::vector <float> notas_personales; //Incluye cada nota para un cierto alumno
    } estudiante;

    std::vector <float> calificaciones; //Incluye el promedio de las notas de cada alumno
    std::vector <estudiante> alumnos;

//Funciones sobre vector "calificaciones"
    //Agregar nota al vector usando push_back
void agregar_calificacion(int nota){
    calificaciones.push_back(nota);
 }
    //Usando min_element, distance y erase para eliminar la calificación más baja
void eliminar_nota_baja(){
    //Retorna el indice del minimo, debo sumarle uno, ya que el punto de partida es 0 (esto en los cout, no en las funciones!)
    int min_indice = std::distance(calificaciones.begin(), std::min_element(calificaciones.begin(), calificaciones.end()));
    //std::cout << "Posicion de la nota minima: " << min_indice +1 << std::endl; //Retorna el indice de la nota mas baja
    calificaciones.erase(calificaciones.begin() + min_indice);
}
    //Usando std::accumulate y std::size calcular el promedio de las calificaciones al final del semestre.
float calcular_promedio(std::vector <float> calificaciones){
    return std::accumulate(calificaciones.begin(), calificaciones.end(),0)/ calificaciones.size();
}

//Funciones sobre vector "alumnos"

void agregar_notaAlumno(estudiante * alumno, int nota){
    alumno->notas_personales.push_back(nota);
 }

    //Cuando un estudiante se une a la clase, añades una calificación inicial de 0 al final del vector.
void nuevo_estudiante(){
    //Para agregar un cero al final usamos "resize", ampliamos "una casilla de memoria mas".
    int longitud = calificaciones.size();
    calificaciones.resize(longitud + 1);
}
    // Cuando un estudiante deja la clase, eliminas todas sus calificaciones del vector. 
void abandono_alumno(estudiante *alumno){
    alumno->notas_personales.clear();
}

    //Calcular promedio de estudiante
float promedio_alummno(estudiante alumno){
        //primero eliminamos nota mas baja
    int min_indice = std::distance(alumno.notas_personales.begin(), std::min_element(alumno.notas_personales.begin(), alumno.notas_personales.end()));
    //std::cout << "Posicion de la nota minima: " << min_indice +1 << std::endl; //Retorna el indice de la nota mas baja
    alumno.notas_personales.erase(alumno.notas_personales.begin() + min_indice);
    return calcular_promedio(alumno.notas_personales);
}

//Funcion adicional: Mostrar los elementos de un vector.
void mostrar_vector(std::vector <float> vec){
    for(int i=0; i< vec.size(); i++){
        std::cout << "Valor en la posicion " << i+1 << " es: " << vec.at(i) << std::endl;
    } 

    if(vec.size()==0) std::cout << "Vector vacio." <<std::endl;
}


//Funcion main
int main() {
    calificaciones.resize(0);
    alumnos.resize(0);

//Pruebas:
    // Añadir una calificación al vector usando push_back
    agregar_calificacion(10);
    agregar_calificacion(7);
    agregar_calificacion(3);
    agregar_calificacion(12);
    agregar_calificacion(5);
    // Encontrar y eliminar la calificación más baja usando min_element, distance y erase
    eliminar_nota_baja();
    // Calcular el promedio de las calificaciones al final del semestre
    float promedio = calcular_promedio(calificaciones);
    std::cout << "El promedio de fin del semestre es: " << promedio << std::endl;

    //Agrego un alumno y calculo el nuevo promedio
    nuevo_estudiante();
    promedio = calcular_promedio(calificaciones);
    std::cout << "El nuevo promedio de fin del semestre es: " << promedio << std::endl;
    estudiante alumno1;
    agregar_notaAlumno(&alumno1, 6);
    agregar_notaAlumno(&alumno1, 9);
    agregar_notaAlumno(&alumno1, 8);
    mostrar_vector(alumno1.notas_personales);
    float promedioA1 = promedio_alummno(alumno1);
    std::cout << "El promedio de fin del semestre del alumno 1 es : " << promedioA1 << std::endl;

    //El alumno deja el curso, probremos que pasa con las notas.
    abandono_alumno(&alumno1);
    mostrar_vector(alumno1.notas_personales);
return 0;
}
