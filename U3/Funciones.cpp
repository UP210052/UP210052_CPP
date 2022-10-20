 /*
Date: 20/10/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Creacion y manejo de funciones.
*/
/* Funcion:
    tipo nombre(tipo var1, tipo var2,...tipo varn){
        instrucciones;
    }
*/

//Library for input and output management.
#include <iostream>

//Use of namespace to avoid std::
using namespace std;

//Prototipado de funcion
int Obtenervalmax (int num1, int num2);


int main()
{
   int primernum, segundonum;
   cout << "Dame un numero: ";
   cin >> primernum;
   cout << "Dame otro numero: ";
   cin >> segundonum;
   cout << "===================================== \n";
   cout << "El numero mayor es: " << Obtenervalmax(primernum,segundonum) << endl;

   return 0;
}
int Obtenervalmax (int num1, int num2){
    return (num1 > num2)?num1:num2;
}