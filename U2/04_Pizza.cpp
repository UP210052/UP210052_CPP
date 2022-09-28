/*
Date: 28/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description:
*/

/* Problem (Spanish)
La pizzería Bella Napoli ofrece pizzas vegetarianas y no vegetarianas a sus clientes. Los
ingredientes para cada tipo de pizza aparecen a continuación.
    -Ingredientes vegetarianos: Pimiento y tofu.
    -Ingredientes no vegetarianos: Peperoni, Jamón y Salmón.
Escribir un programa que pregunte al usuario si quiere una pizza vegetariana o no, y en
función de su respuesta le muestre un menú con los ingredientes disponibles para que elija.
Solo se puede eligir un ingrediente además de la mozzarella y el tomate que están en todas la
pizzas.
Al final se debe mostrar por pantalla si la pizza elegida es vegetariana o no y todos los
ingredientes que lleva
*/

// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;


int main()
{
    char respuesta;
    int ingrediente_vegetariano;
    int ingrediente_no_vegetariano;
    cout << "Is your vegetarian pizza ?  ";
    cin >> respuesta;
    if (respuesta == 'Yes' || respuesta == 'Y' || respuesta == 'yes' || respuesta == 'y')
    {
        cout << "Vegetatian ingredients: \n";
        cout << "1.- Bell papper \n";
        cout << "2.- Tofu \n";
        cout << "Enter the ingredient number";
        cin >> ingrediente_vegetariano;
    }
    else if (respuesta == 'No' || respuesta == 'N' || respuesta == 'no')
    {
        cout << "";
    }else {

    }
    cout << "Your pizza is vegetarian";
    
    return 0;
}