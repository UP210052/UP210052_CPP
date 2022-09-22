/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Muestra el uso del if simple
*/
#include <iostream>
using namespace std;

int main(){
    int numero;
    int dato=1;
    int num1, dato1=8;
    cout << "Ingresa un número entero: ";
    cin >> numero;
    if(numero == dato){
        cout << "El número es igual al dato \n";
    }
    //Ejercicio: utilice las diferentes comparaciones ==, !=, <, >, <=, >=
    if(numero != dato){
        cout << "El número es diferente al dato \n";
    }
    if(numero < dato){
        cout << "El número es menor al dato \n";
    }
    if(numero > dato){
        cout << "El número es mayor al dato \n";
    }
    if(numero <= dato){
        cout << "El número es menor o igual al dato \n";
    }
    if(numero >= dato){
        cout << "El número es mayor o igual al dato \n";
    }
    //Extra 
    cout << "=========================================== \n";
    cout << "Adivina el numero \n";
    cout << "Ingresa un número entero: ";
        cin >> num1;
    while (num1!=dato1)
    {
        if(num1<dato1){
            cout << "Ingresa otro numero mas grande: ";
            cin >> num1;
        }
        if(num1>dato1){
            cout << "Ingresa otro numero mas pequeño: ";
            cin >> num1;
        }
    }
    cout << "Ganaste \n";
    
    return 0;
}