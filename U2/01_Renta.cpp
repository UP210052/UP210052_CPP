/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Muestra el uso del if else
*/

/*
Los tramos impositivos para la declaración de la renta en un determinado país son los siguientes:
Renta	Tipo impositivo
Menos de $10,000	5%
Entre $10,000 y $20,000	15%
Entre $20,000 y $35,000	20%
Entre $35,000 y $60,000	30%
Más de $60,000	45%
Escribir un programa que pregunte al usuario su renta anual y muestre por 
pantalla el tipo impositivo que le corresponde.
*/

#include <iostream>
using namespace std;
int main(){
    float Renta;
    float Impositivo;
    float TotalAPagar;
    cout << "Ingresa tu renta anual: ";
    cin >> Renta;
    if (Renta<10000){
        cout << "El tipo de impositivo es de 5% \n";
        Impositivo = Renta * .05;
    }
    if (Renta>=10000 and Renta<20000){
        cout << "El tipo de impositivo es de 15% \n";
        Impositivo = Renta * .15;
    }
    if (Renta>=20000 and Renta<35000){
        cout << "El tipo de impositivo es de 20%  \n";
        Impositivo = Renta * .20;
    }
    if (Renta>=35000 and Renta<60000){
        cout << "El tipo de impositivo es de 30%  \n";
        Impositivo = Renta * .30;
    }
    if (Renta>=60000){
        cout << "El tipo de impositivo es de 45% \n";
        Impositivo = Renta * .45;
    }
    cout << "El cual equivale a $" << Impositivo << endl;
    TotalAPagar= Renta + Impositivo;
    cout << "El total a pagar es de: $" << TotalAPagar << endl;
    return 0;
}