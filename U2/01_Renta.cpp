/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Muestra el uso del if else
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