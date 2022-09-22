/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Muestra el uso del if else
*/
#include <iostream>
using namespace std;

int main(){
    int numero;
    int dato = 1;
    cout << "Ingresa un número entero: ";
    cin >> numero;
    cout << "If else con == \n";
    if (numero == dato){
        cout << "El número es igual al dato.\n";

    }
    else {
        cout << "El número es diferente del dato.\n";
    }
    cout << "======================================== \n";
    cout << "If else con != \n";
    if (numero != dato){
        cout << "El número es diferente al dato.\n";

    }
    else {
        cout << "El número es igual al dato.\n";
    }
    cout << "======================================== \n";
    cout << "If else con < \n";
    if (numero < dato){
        cout << "El número es menor al dato.\n";

    }
    else {
        cout << "El número es mayor o igual del dato.\n";
    }
    cout << "======================================== \n";
    cout << "If else con > \n";
    if (numero > dato){
        cout << "El número es mayor al dato.\n";

    }
    else {
        cout << "El número es menor o igual del dato.\n";
    }
    cout << "======================================== \n";
    cout << "If else con <= \n";
    if (numero <= dato){
        cout << "El número menor o igual all dato.\n";

    }
    else {
        cout << "El número mayor o igual al dato.\n";
    }
    cout << "======================================== \n";
    cout << "If else con >= \n";
    if (numero >= dato){
        cout << "El número es mayor o igual al dato.\n";

    }
    else {
        cout << "El número es menor o igual al dato.\n";
    }
}