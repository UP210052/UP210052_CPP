/*
Date: 26/09/2022
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: 
*/

//Libreria  para manejo de entradas y salidas.
#include <iostream>

//Uso del namespace para evitar el std::
using namespace std;

int main(){
    //Declarar las variables.
    double puntuacion;
    double dinero=0;

    //Solicitar la puntuación.
    cout << "What is your score: ";
    cin >> puntuacion;

    //Evaluar la puntuacion para asignar su tipo y dinero.
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

    //Imprimir su cantidad de dinero.
    cout << "Your amount of money is $" << dinero << endl;
    return 0;
} 