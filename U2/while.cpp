/*
Date: 28/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Game price
*/
// Library for input and output management.
#include <iostream>

// Use of namespace to avoid std::
using namespace std;

int main()
{
    int contador;
    //Inicializacio del contador en 1 
    contador=1;
    while (contador<=15)
    {
        //Imprime el valor del contador
        cout << "El contador es "<< contador<<endl;
        //Incrementa el contador 
        contador++;
        //Contador = contador +1
        //Contador +=1
    }
    contador=1;
    do{
        //Imprime el valor del contador
        cout << "El contador es "<< contador<<endl;
        //Incrementa el contador 
        contador++;
    } while (contador<=15);
    return 0;
}