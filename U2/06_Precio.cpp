/*
Date: 05/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Price 

Problem (Spanish)
Realizar un programa que lea indefinidamente cantidades de productos y su precio, y al final
indique el total de la factura. Para saber que se ha terminado con la compra, se deberá
ingresar un 0 en la cantidad.
*/
// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;
int main()
{
    // Declare the variables.
    int amount;
    float price = 0;
    float totalprice = 0;

    // Cycle to ask and save the price and amount of the products
    do
    {
        cout << "Enter the amount of products: ";
        cin >> amount;
        if (amount != 0 and amount > 0)
        {
            cout << "Enter the price of products: ";
            cin >> price;
            totalprice += (price * amount);
        }
    } while (amount != 0 and amount > 0);

    // Print the total price.
    cout << "The total price is $" << totalprice << endl;

    return 0;
}