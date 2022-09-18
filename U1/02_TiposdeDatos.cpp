
/* Unidad 1. Tipos de datos
   Autor: Héctor Ivan Ramírez Jaime.
   Fecha: 15/09/2022
   Descripción: Muestra los diferentes tipos de datos en c++
*/
//Libreria para uso de entradas y salidas de pantalla (cout)
#include <iostream>
//Libreria para el uso de prinrf y scanf
#include <stdio.h>

//Uso del namespace para evitar el std::
using namespace std;

//Creación de función principal de tipo entero 
int main(){
    //https://geeksforgeeks.org/c-data-types/
    int entero=4;
    float flotante = 2.565465654654;
    double grande = 2.565465654654;
    char caracter = 64;
    cout <<"Este programa muestra los tipos de datos. \n";
    cout <<"EL número entero es: "<<entero<<endl;
    cout <<"EL tamaño del entero es: "<<sizeof(entero)<<endl;
    cout <<"EL número flotante es: "<<flotante<<endl;
    cout <<"EL tamaño del flotante es: "<<sizeof(flotante)<<endl;
    cout <<"EL número double es: "<<grande<<endl;
    cout <<"EL tamaño del double es: "<<sizeof(grande)<<endl;
    cout <<"EL caracter char es: "<<caracter<<endl;
    cout <<"EL tamaño del char es: "<<sizeof(caracter)<<endl;
    
    cout<<"======================="<<endl;

    //Mas informacion en https://cplusplus.com/reference/cstdio/printf/
    printf("Usando la funcion printf\n");
    printf("El número entero es: %i \n", entero);
    printf("El número flotante es: %3.1f \n", flotante);

    //Al ser una función debe retornar un valor, en este caso 0
    return 0;


}