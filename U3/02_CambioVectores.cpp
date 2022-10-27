
/*
Date: 27/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description:
Realizar un programa en el que se ingrese un monto de dinero y desgloce en cantidad de billetes o monedas
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

void obtenerCambio(int, string);
void imprimirCambio(string);

int denominaciones[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int cantidadbilletes[9] = {0};

int main()
{
    // Declare the variables.
    int dinero;
    string tipo;

    // Ask for the amount of money and type change
    cout << "Enter the money: ";
    cin >> dinero;
    cout << "Enter type change whit coin or total:";
    cin >> tipo;

    // Call the functions
    obtenerCambio(dinero, tipo);
    imprimirCambio(tipo);
    return 0;
}

// function to get the change
void obtenerCambio(int dinero, string tipo)
{
    // Do while subtracts the bills or coins until reaching 0
    do
    {

        if (tipo == "total" || tipo == "TOTAL" || tipo == "Total") // Using bills and coins
        {
            for (int denominacion = 0; denominacion < 9; denominacion++)
            {
                if ((dinero - denominaciones[denominacion]) >= 0)
                {
                    cantidadbilletes[denominacion]++;
                    dinero -= denominaciones[denominacion];
                    break;
                }
            }
        }
        else if (tipo == "coin" || tipo == "COIN" || tipo == "Coin") // Using coins
        {
            for (int denominacion = 5; denominacion < 9; denominacion++)
            {
                if ((dinero - denominaciones[denominacion]) >= 0)
                {
                    cantidadbilletes[denominacion]++;
                    dinero -= denominaciones[denominacion];
                    break;
                }
            }
        }

    } while (dinero > 0);
}

// Function to print the change
void imprimirCambio(string tipo)
{
    cout << "The exchange is : \n";
    if (tipo == "total" || tipo == "TOTAL" || tipo == "Total")
    {
        for (int denominacion = 0; denominacion < 5; denominacion++)
        {
            cout << "Bill of $" << denominaciones[denominacion] << ": " << cantidadbilletes[denominacion] << endl;
        }
        for (int denominacion = 5; denominacion < 9; denominacion++)
        {
            cout << "Coin of $" << denominaciones[denominacion] << ": " << cantidadbilletes[denominacion] << endl;
        }
    }
    else if (tipo == "coin" || tipo == "COIN" || tipo == "Coin")
    {
        for (int denominacion = 5; denominacion < 9; denominacion++)
        {
            cout << "Coin of $" << denominaciones[denominacion] << ": " << cantidadbilletes[denominacion] << endl;
        }
    }
}