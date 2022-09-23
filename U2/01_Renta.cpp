/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Rent y Tax
*/

/*
Los tramos Taxs para la declaración de la Rent en un determinado país son los siguientes:
Rent	Tipo Tax
Menos de $10,000	5%
Entre $10,000 y $20,000	15%
Entre $20,000 y $35,000	20%
Entre $35,000 y $60,000	30%
Más de $60,000	45%
Escribir un programa que pregunte al usuario su Rent anual y muestre por 
pantalla el tipo Tax que le corresponde.
*/

//Libreria  para manejo de entradas y salidas.
#include <iostream>

//Uso del namespace para evitar el std::
using namespace std;

//Función principal de tipo entero
int main(){
    //Declaración de variables.
    float Rent;
    float Tax;
    
    //Solicitar la renta.
    cout << "Enter your annual rent: ";
    cin >> Rent;
    
    //Evaluar la renta (rent) para obtener el porcentaje (tax)
    if (Rent>=0){
        if (Rent<10000){
            Tax = .05;
        }
        if (Rent>=10000 and Rent<20000){
            Tax = .15;
        } 
        if (Rent>=20000 and Rent<35000){
            Tax = .20;
        }
        if (Rent>=35000 and Rent<60000){
            Tax = .30;
        }
        if (Rent>=60000){
            Tax = .45;
        }
        
        //Visualización de datos.
        cout << "The tax rate is" << (Tax*100) << "% \n";
        Tax= Rent * Tax;
        cout << "Which is the equivalent $" << Tax << endl;
    }
    else {
        cout << "The rent you entered is ncorrect. \n";  
    }
   return 0;
}