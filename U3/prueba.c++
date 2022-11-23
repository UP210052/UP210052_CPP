 /*
Date: 
Author: Héctor Iván Ramírez Jaime.
Email: up210052@alumnos.upa.edu.mx
Description: 
*/

//Library for input and output management.
#include <iostream>
#include<unistd.h>

//Use of namespace to avoid std::
using namespace std;
void gotoxy(int, int);
int main()
{
    for (int x=1; x<10; x++){
        gotoxy(x,2);
        
        cout << "Hola";
        usleep(10000);
        //system("clear");
    }
    return 0;
}

void gotoxy (int x, int y){
    cout << "\033["<<y<<";"<<x<<"f";
}