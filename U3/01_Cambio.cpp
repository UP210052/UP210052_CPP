/*
Date:
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description:
Realizar un programa que de el cambio en monedas y billetes.
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

void obtenerCambio(int, string);
void imprimirCambio(string);

//Declare the global variables.
int quinientos = 0, docientos = 0, cien = 0, cincuenta = 0, veinte = 0, diez = 0, cinco = 0, dos = 0, uno = 0;

int main()
{
    //Declare the variables.
    int dinero;
    string tipo;

    //Ask for the amount of money and type change
    cout << "Enter the money: ";
    cin >> dinero;
    cout << "Enter type change whit coin or total:";
    cin >> tipo;

    //Call the functions 
    obtenerCambio(dinero, tipo);
    imprimirCambio(tipo);
    return 0;
}

//function to get the change
void obtenerCambio(int dinero, string tipo)
{
    // Do while subtracts the bills or coins until reaching 0
    do
    {
        
        if (tipo=="total" || tipo == "TOTAL" || tipo == "Total") //Using bills and coins
        {
            // If ternary to subtract the coins and bills from money
            ((dinero - 500) >= 0) ? quinientos++, dinero -= 500 
                : ((dinero - 200) >= 0) ? docientos++, dinero -= 200 
                    : ((dinero - 100) >= 0) ? cien++, dinero -= 100 
                        : ((dinero - 50) >= 0) ? cincuenta++, dinero -= 50 
                            : ((dinero - 20) >= 0) ? veinte++, dinero -= 20 
                                : ((dinero - 10) >= 0) ? diez++, dinero -= 10 
                                    : ((dinero - 5) >= 0) ? cinco++, dinero -= 5 
                                        : ((dinero - 2) >= 0) ? dos++, dinero -= 2 
                                            : ((dinero - 1) >= 0) ? uno++, dinero -= 1 
                                                : uno;
        }else if (tipo == "coin" || tipo == "COIN" || tipo == "Coin") //Using coins
        {
            //If ternary to subtract the coins from money
            ((dinero - 10) >= 0) ? diez++, dinero -= 10 
                : ((dinero - 5) >= 0) ? cinco++, dinero -= 5 
                    : ((dinero - 2) >= 0) ? dos++, dinero -= 2 
                        : ((dinero - 1) >= 0) ? uno++, dinero -= 1 
                            : uno;
        }
        
    } while (dinero > 0);
}

//Function to print the change
void imprimirCambio(string tipo)
{
    cout << "The exchange is : \n";
    if (tipo == "total" || tipo == "TOTAL" || tipo == "Total")
    {
        cout << "Bill of $500: " << quinientos << endl;
        cout << "Bill of $200: " << docientos << endl;
        cout << "Bill of $100: " << cien << endl;
        cout << "Bill of $50: " << cincuenta << endl;
        cout << "Bill of $20: " << veinte << endl;
        cout << "Coin of $10: " << diez << endl;
        cout << "Coin of $5: " << cinco << endl;
        cout << "Coin of $2: " << dos << endl;
        cout << "Coin of $1: " << uno << endl;
    }else if (tipo == "coin" || tipo == "COIN" || tipo == "Coin") 
    {
        cout << "Coin of $10: " << diez << endl;
        cout << "Coin of $5: " << cinco << endl;
        cout << "Coin of $2: " << dos << endl;
        cout << "Coin of $1: " << uno << endl;
    }
    
}
