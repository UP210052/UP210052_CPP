/*
Date: 05/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Price

Problem (Spanish)
Realice un programa que realice la conversión de decimal a binario, solo para números
enteros mayores a 0. El resultado puede ser mostrado mediante una variable entera o en un
conjunto de caracteres.
*/
// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

int main()
{
    // Declare the variables.
    int contador = 1;
    int numero = 0;
    string resultado;
    //Ask the number
    cout << "Enter the number: ";
    cin >> numero;
  
    if (numero > 0)
    {
        //Cycle to divide the number by 3 and print the ramainder.
        while (numero != 0)
        {
            if (numero % 2 == 0)
            {
                resultado = '0' + resultado;
            }
            else
            {
                resultado = '1' + resultado;
            }
            numero /= 2;
        }
        //Print the binary number
        cout << "The number in binary is " << resultado << endl;
    }
    else if (numero == 0)
    {   
        //Print the binary number.
        cout << "The number in binary is 0. \n";
    }
    else
    {
        //Print the error message.
        cout << "Only accept numbers greater then or equal to 0. \n";
    }
    return 0;
}