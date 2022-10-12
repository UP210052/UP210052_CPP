/*
Date: 12/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Tablas de multiplicasar

Problem (Spanish)
Realice un programa que realice las tablas de multiplicar del numero ingresado y tambien ingrese el limiete de las tablas.
*/
// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

// "\t" es un tabulador horizontal
int main()
{
    // Declare the variables.
    int numero;
    int limite = 0;
    // Ask the user for the number
    cout << "Enter the number: ";
    cin >> numero;

    // Ask the user for the limit
    cout << "Enter the limit: ";
    cin >> limite;
    for (int i = 0; i <= limite; i++)
    {
        // If and for to print the firts line of -
        if (i == 1)
        {
            for (int f = 0; f <= 41; f++)
            {
                cout << "-";
            }
            cout << "\n";
        }
        
        // Print the formatted table.
        cout << "|  " << i << "\t x \t" << numero << "\t = \t" << (i * numero) << "\t |\n";
        
        // For to print line of -
        for (int f = 0; f <= 41; f++)
        {
            cout << "-";
        }
        cout << "\n";
    }
    
    return 0;
}