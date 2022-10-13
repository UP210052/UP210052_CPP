/*
Date: 13/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Metodo de bisección.

Problem (Spanish)
Hacer el metodo de la bisección de y=x^2 + 3x + 8 en un margen de 0.01 al -0.01
*/
// Library for input and output management.
#include <iostream>
#include <cmath>

// Use of namespace to avoid std::
using namespace std;

float resolverEcuacion (float numero){
    return pow(numero, 2) - numero -12 ; 
}

int main (){
    int interador=1;
    float a;
    float b;
    float c = (a+b) /2;
    float ya = resolverEcuacion(a);
    float yb = resolverEcuacion(b);
    float yc = resolverEcuacion(c);
    cout << "Enter the value A: ";
    cin >> a;
    cout << "Enter the value B: ";
    cin >> b;
    cout << "| Interdor \t | a \t | b \t | c \t \t | y(a) \t | y(b) \t | y(c) \t | \n";
    while (yc >= 0.01 or yc<=-0.01){
        cout << "| " << interador << " \t \t | " << a << " \t | " << b << " \t | " << c << " \t | " << ya << " \t | " << yb << " \t | " << yc << " \t | \n";
        b=c; 
        c= (a+b)/2;
        ya = resolverEcuacion(a);
        yb = resolverEcuacion(b);
        yc = resolverEcuacion(c);
        interador ++;

    }
    return 0;
}
