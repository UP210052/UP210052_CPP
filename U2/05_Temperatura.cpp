/*
Date: 03/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Temperature
*/

/* Problem (Spanish)
Hacer un programa en el que se ingresen 6 temperaturas y determine el promedio, la mas
baja y la mas alta.
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

int main()
{

    // Declare the variables.
    int contador = 0;
    float temperatura;
    float tempAcum = 0;
    float tempmayor = -10000;
    float tempmenor = 10000;

    // Cycle to ask and save the 6 temperatures.
    while (contador <= 5)
    {
        cout << "Give me the temperature: ";
        cin >> temperatura;
        //Save the sum of temperatures
        tempAcum += temperatura;

        //Find and save the highest temperature.
        if (temperatura > tempmayor)
        {
            tempmayor = temperatura;
        }

        //Find and save the lowest temperature.
        if (temperatura < tempmenor)
        {
            tempmenor = temperatura;
        }
        contador++;
    }

    // Print the mean, highest and lower temperature.
    cout << "The mean is: " << (tempAcum / 6) << endl;
    cout << "The highest temperature is " << tempmayor << endl;
    cout << "The lowest temperature is " << tempmenor << endl;
    return 0;
}