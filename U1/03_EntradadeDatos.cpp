/*
Date: 21/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Muestra la forma de ingresar tipos de datos por el usurario
*/

//Libreria para manejo de entradas y salida de pantalla
#include <iostream>
//Libreria para el uso de prinft y scanf
#include <stdio.h>

//Uso del namespace para evitar el sdt::
using namespace std;

//Funcion principal de tipo entero
int  main(){
    int entero;
    float flotante;
    double grande;
    char caracter;
    int num;


    
    cout<<"Este programa muestra el ingreso de datos por el usuario. \n";
    cout<<"Ingresa un dato de tipo enter: ";
    cin>>entero;
    /*
    if (entero==0){
        cout<<"Esto no es un dato tipo entero. \n";
    }else {
         cout<<"El dato ingrasado es: "<<entero<<endl;
    }*/

    cout<<"==================================="<<endl;

    cout << "Ingresa un dato de tipo flotante: ";
    cin >> flotante;
    cout<<"El dato ingrasado es: "<< flotante << endl;
    cout<<"==================================="<<endl;
    
    cout<<"Ingresa un dato de tipo double: ";
    cin>>grande;
    cout<<"El dato ingrasado es: "<<grande<<endl;
    cout<<"==================================="<<endl;

    cout<<"Ingresa un dato de tipo char: ";
    cin>>caracter;
    cout<<"El dato ingrasado es: "<<caracter<<endl;
    cout<<"==================================="<<endl;

    //Mas informacion en: https://cplusplus.com/reference/cstdio/printf/
    printf("Usando la funcion de prinf y scanf \n");
    printf("Ingresa un dato de tipo entero: ");
    scanf("%d",&num);
    printf("El dato ingresado es: %d \n", num);

    //Al ser una funcion debe retornar un valor, en este caso 0
    return 0;
}