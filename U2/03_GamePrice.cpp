/*
Date: 28/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Game price
*/
/*-------Problem (Spanish)----------
Escribir un programa para una empresa que tiene salas de juegos para todas las edades y
quiere calcular de forma automática el precio que debe cobrar a sus clientes por entrar. El
programa debe preguntar al usuario la edad del cliente y mostrar el precio de la entrada. Si
el cliente es menor de 4 años puede entrar gratis, si tiene entre 4 y 18 años debe pagar $5 y
si es mayor de 18 años, $10
*/
// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

int main()
{
    // Declare the variables.
    int edad;
    int precio;

    // Ask for the age.
    cout << "How old are you?  ";
    cin >> edad;

    // Evaluate your age and asignate the cost of your ticked .
    if (edad > 18)
    {
        precio = 10;
    }
    else if (edad >= 4 && edad <=18)
    {
        precio = 5;
    }
    else if (edad >= 0)
    {
        precio = 0;
    }
    else
    {
        cout << "Your age is invalid \n";
        precio = 0;
    }

    // Print your cost.
    cout << "The cost of your ticked is $" << precio << endl;

    return 0;
}