/*
Date: 22/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Rent y Tax
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

//Library for input and output management.
#include <iostream>

//Use of namespace to avoid std::
using namespace std;

//Main function of integer type
int main(){
    //Declare the variables.
    float Rent;
    float Tax;
    
    //Request for rent.
    cout << "Enter your annual rent: ";
    cin >> Rent;
    
    //Evaluate rent to obtain the tax.
    if (Rent>=0){
        if (Rent<10000){
            Tax = .05;
        }
        else if (Rent>=10000 and Rent<20000){
            Tax = .15;
        } 
        else if (Rent>=20000 and Rent<35000){
            Tax = .20;
        }
        else if (Rent>=35000 and Rent<60000){
            Tax = .30;
        }
        else if (Rent>=60000){
            Tax = .45;
        }
        
        //Visualization of the improvisation and its equivalence in money.
        cout << "The tax rate is " << (Tax*100) << "% \n";
        Tax= Rent * Tax;
        cout << "Which is the equivalent $" << Tax << endl;
    }
    else {
        cout << "The rent you entered is ncorrect. \n";  
    }
   return 0;
}