/*
Date: 26/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: Benefit
*/

//Library for input and output management.
#include <iostream>

//Use of namespace to avoid std::
using namespace std;

//Main function of integer type
int main(){
    //Declare the variables.
    double puntuacion;
    double dinero=0;

    //Solicitar la puntuación.
    cout << "What is your score: ";
    cin >> puntuacion;

    //Evaluate the score to assign your type and money.
    if( (puntuacion <= 1 ) && ((puntuacion >= 0.6) || (puntuacion == 0.4 ))){
        dinero = puntuacion* 2400;
        if (puntuacion >= 0.6) {
            cout << "Your score is Meritorious \n";
        }else{
            cout << "Your score is Acceptable \n";
        }

    } else{
        cout << "Your score is unacceptable \n";
    }

    //Print your amount of money.
    cout << "Your amount of money is $" << dinero << endl;
    return 0;
} 