#include <iostream>

using namespace std;

string AreaJuegoP1[10][10]={{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
string AreaJuegoP2[10][10]={{"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
const string P1 = "Player 1";
const string P2 = "Player 2";
int player = 1;
int col, row;
char columna;
string TipoBarco[5]={"Submarine","Destroyer","Cruiser","Battleship","Carrier"};
int TiposBarcosP1[5]={3,2,1,1,1};
int TiposBarcosP2[5]={3,2,1,1,1};


/*Carrier5,Battleship4,Cruiser3,Destroyer2-2,Submarine1-3*/

void gotoxy(int x, int y);

void makeboard();

void imprimirtablerodeprueba();
void tableronaval();
void pruebalogica();
void logicbattleship();
void actualizarInventarioBarcos(int, string);
void buildships(int, int, int, int ,string);
int LettertoNumber(char);



string Jugador1A[14][23] =   {{" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
                              {"|BN"," | "," A "," | "," B "," | "," C "," | "," D "," | "," E "," | "," F "," | "," G "," | "," H "," | "," I "," | "," J "," | "},
                              {" _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "},
                              {"| 0"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 1"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},                  
                              {"| 2"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 3"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 4"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 5"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 6"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 7"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 8"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 9"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},};

string Jugador2A[14][23] =   {{" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
                              {"|BN"," | "," A "," | "," B "," | "," C "," | "," D "," | "," E "," | "," F "," | "," G "," | "," H "," | "," I "," | "," J "," | "},
                              {" _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "," _ "},
                              {"| 0"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 1"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},                  
                              {"| 2"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 3"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 4"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 5"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 6"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 7"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 8"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {"| 9"," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | ","   "," | "},
                              {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},};
                              



void putships(int, int, int);
int selectplay(int, int);
/*Playertype, shipsize, row,col*/
bool invalidplay(int, int, int, int, string);
void shootcannons(int, int, string);
bool NoWinner(string);
void dibujo();
void menuBarcos(string);

int main(){
    pruebalogica();
    return 0;
}

/*
int main()
{
    string turnplayer=P1;
    int col, row, player, entrada;
    bool placeOccupied = true;
    
    dibujo();
    gotoxy(58, 20);
    cout << "BIENVENIDO A BATALLA NAVAL";

    gotoxy(66, 24);
    cout << "Presione: " << endl;
    gotoxy(66, 25);
    cout << "1. Jugar" << endl;
    gotoxy(66, 26);
    cout << "2. Salir" << endl;
    gotoxy(66, 27);
    cin >> entrada;

    if(entrada == 1){
    system("cls");
    dibujo();
    gotoxy(58, 17);
    cout << "BIENVENIDO A BATALLA NAVAL";

    menuBarcos(turnplayer);

    //tableronaval();
    //makeboard();
    //preguntartipodebarco();
    //preguntarcordenada();Cruiser--;s por cada jugador
    pruebalogica();
    //tableronaval();

    }else if(entrada == 2){
        system("cls");
        gotoxy(58, 5);
        cout << "GRACIAS POR JUGAR";
        return 0;
    }else{
        gotoxy(64, 29);
        cout << "INCORRECTO!!!";
    }

   
    return 0;
}
*/

void dibujo(){
    system("cls");
    gotoxy(43,2);
    cout << "                         ____   _   _           \n";
    gotoxy(43,3);
    cout << "                        |____| |_| |_|          \n";
    gotoxy(43,4);
    cout << "                        |    | | | | |          \n";
    gotoxy(43,5);
    cout << "                    _   |    | | | | |          \n";
    gotoxy(43,6);
    cout << "                   |_|  |    |_|_|_|_|_         \n ";
    gotoxy(43,7);
    cout << "                   | |  |    | o o o o |        \n";
    gotoxy(43,8);
    cout << "                   | |  |    |---------|         \n";
    gotoxy(43,9);
    cout << "                ___| |__|____|_________|___      \n";
    gotoxy(43,10);
    cout << "                \\                         /     \n";
    gotoxy(43,11);
    cout << "                 \\   o o o o o o o o o o /      \n";
    gotoxy(43,12);
    cout << "                  \\---------------------/       \n";
    gotoxy(43,13);
    cout << "*******************\\                   /***************************\n";
    gotoxy(43,14);
    cout << "********************\\_________________/****************************\n";
    gotoxy(43,15);
    cout << "********************************************************************\n";
    cout << "\n";
}

void tableronaval(string player){
    int x = 0, y = 0;
 

    
    //Fila 0
    Jugador1A[3][2] = ' ' + AreaJuegoP1[0][0] + ' ';
    Jugador1A[3][4] = ' ' + AreaJuegoP1[0][1] + ' ';
    Jugador1A[3][6] = ' ' + AreaJuegoP1[0][2] + ' ';
    Jugador1A[3][8] = ' ' + AreaJuegoP1[0][3] + ' ';
    Jugador1A[3][10] = ' ' + AreaJuegoP1[0][4] + ' ';
    Jugador1A[3][12] = ' ' + AreaJuegoP1[0][5] + ' ';
    Jugador1A[3][14] = ' ' + AreaJuegoP1[0][6] + ' ';
    Jugador1A[3][16] = ' ' + AreaJuegoP1[0][7] + ' ';
    Jugador1A[3][18] = ' ' + AreaJuegoP1[0][8] + ' ';
    Jugador1A[3][20] = ' ' + AreaJuegoP1[0][9] + ' ';
    
    //Fila 1
    Jugador1A[4][2] = ' ' + AreaJuegoP1[1][0] + ' ';
    Jugador1A[4][4] = ' ' + AreaJuegoP1[1][1] + ' ';
    Jugador1A[4][6] = ' ' + AreaJuegoP1[1][2] + ' ';
    Jugador1A[4][8] = ' ' + AreaJuegoP1[1][3] + ' ';
    Jugador1A[4][10] = ' ' + AreaJuegoP1[1][4] + ' ';
    Jugador1A[4][12] = ' ' + AreaJuegoP1[1][5] + ' ';
    Jugador1A[4][14] = ' ' + AreaJuegoP1[1][6] + ' ';
    Jugador1A[4][16] = ' ' + AreaJuegoP1[1][7] + ' ';
    Jugador1A[4][18] = ' ' + AreaJuegoP1[1][8] + ' ';
    Jugador1A[4][20] = ' ' + AreaJuegoP1[1][9] + ' ';
    
    //Fila 2
    Jugador1A[5][2] = ' ' + AreaJuegoP1[2][0] + ' ';
    Jugador1A[5][4] = ' ' + AreaJuegoP1[2][1] + ' ';
    Jugador1A[5][6] = ' ' + AreaJuegoP1[2][2] + ' ';
    Jugador1A[5][8] = ' ' + AreaJuegoP1[2][3] + ' ';
    Jugador1A[5][10] = ' ' + AreaJuegoP1[2][4] + ' ';
    Jugador1A[5][12] = ' ' + AreaJuegoP1[2][5] + ' ';
    Jugador1A[5][14] = ' ' + AreaJuegoP1[2][6] + ' ';
    Jugador1A[5][16] = ' ' + AreaJuegoP1[2][7] + ' ';
    Jugador1A[5][18] = ' ' + AreaJuegoP1[2][8] + ' ';
    Jugador1A[5][20] = ' ' + AreaJuegoP1[2][9] + ' ';

    //Fila 3
    Jugador1A[6][2] = ' ' + AreaJuegoP1[3][0] + ' ';
    Jugador1A[6][4] = ' ' + AreaJuegoP1[3][1] + ' ';
    Jugador1A[6][6] = ' ' + AreaJuegoP1[3][2] + ' ';
    Jugador1A[6][8] = ' ' + AreaJuegoP1[3][3] + ' ';
    Jugador1A[6][10] = ' ' + AreaJuegoP1[3][4] + ' ';
    Jugador1A[6][12] = ' ' + AreaJuegoP1[3][5] + ' ';
    Jugador1A[6][14] = ' ' + AreaJuegoP1[3][6] + ' ';
    Jugador1A[6][16] = ' ' + AreaJuegoP1[3][7] + ' ';
    Jugador1A[6][18] = ' ' + AreaJuegoP1[3][8] + ' ';
    Jugador1A[6][20] = ' ' + AreaJuegoP1[3][9] + ' ';

    //Fila 4
    Jugador1A[7][2] = ' ' + AreaJuegoP1[4][0] + ' ';
    Jugador1A[7][4] = ' ' + AreaJuegoP1[4][1] + ' ';
    Jugador1A[7][6] = ' ' + AreaJuegoP1[4][2] + ' ';
    Jugador1A[7][8] = ' ' + AreaJuegoP1[4][3] + ' ';
    Jugador1A[7][10] = ' ' + AreaJuegoP1[4][4] + ' ';
    Jugador1A[7][12] = ' ' + AreaJuegoP1[4][5] + ' ';
    Jugador1A[7][14] = ' ' + AreaJuegoP1[4][6] + ' ';
    Jugador1A[7][16] = ' ' + AreaJuegoP1[4][7] + ' ';
    Jugador1A[7][18] = ' ' + AreaJuegoP1[4][8] + ' ';
    Jugador1A[7][20] = ' ' + AreaJuegoP1[4][9] + ' ';

    //Fila 5
    Jugador1A[8][2] = ' ' + AreaJuegoP1[5][0] + ' ';
    Jugador1A[8][4] = ' ' + AreaJuegoP1[5][1] + ' ';
    Jugador1A[8][6] = ' ' + AreaJuegoP1[5][2] + ' ';
    Jugador1A[8][8] = ' ' + AreaJuegoP1[5][3] + ' ';
    Jugador1A[8][10] = ' ' + AreaJuegoP1[5][4] + ' ';
    Jugador1A[8][12] = ' ' + AreaJuegoP1[5][5] + ' ';
    Jugador1A[8][14] = ' ' + AreaJuegoP1[5][6] + ' ';
    Jugador1A[8][16] = ' ' + AreaJuegoP1[5][7] + ' ';
    Jugador1A[8][18] = ' ' + AreaJuegoP1[5][8] + ' ';
    Jugador1A[8][20] = ' ' + AreaJuegoP1[5][9] + ' ';

    //Fila 6
    Jugador1A[9][2] = ' ' + AreaJuegoP1[6][0] + ' ';
    Jugador1A[9][4] = ' ' + AreaJuegoP1[6][1] + ' ';
    Jugador1A[9][6] = ' ' + AreaJuegoP1[6][2] + ' ';
    Jugador1A[9][8] = ' ' + AreaJuegoP1[6][3] + ' ';
    Jugador1A[9][10] = ' ' + AreaJuegoP1[6][4] + ' ';
    Jugador1A[9][12] = ' ' + AreaJuegoP1[6][5] + ' ';
    Jugador1A[9][14] = ' ' + AreaJuegoP1[6][6] + ' ';
    Jugador1A[9][16] = ' ' + AreaJuegoP1[6][7] + ' ';
    Jugador1A[9][18] = ' ' + AreaJuegoP1[6][8] + ' ';
    Jugador1A[9][20] = ' ' + AreaJuegoP1[6][9] + ' ';

    //Fila 7
    Jugador1A[10][2] = ' ' + AreaJuegoP1[7][0] + ' ';
    Jugador1A[10][4] = ' ' + AreaJuegoP1[7][1] + ' ';
    Jugador1A[10][6] = ' ' + AreaJuegoP1[7][2] + ' ';
    Jugador1A[10][8] = ' ' + AreaJuegoP1[7][3] + ' ';
    Jugador1A[10][10] = ' ' + AreaJuegoP1[7][4] + ' ';
    Jugador1A[10][12] = ' ' + AreaJuegoP1[7][5] + ' ';
    Jugador1A[10][14] = ' ' + AreaJuegoP1[7][6] + ' ';
    Jugador1A[10][16] = ' ' + AreaJuegoP1[7][7] + ' ';
    Jugador1A[10][18] = ' ' + AreaJuegoP1[7][8] + ' ';
    Jugador1A[10][20] = ' ' + AreaJuegoP1[7][9] + ' ';

    //Fila 8
    Jugador1A[11][2] = ' ' + AreaJuegoP1[8][0] + ' ';
    Jugador1A[11][4] = ' ' + AreaJuegoP1[8][1] + ' ';
    Jugador1A[11][6] = ' ' + AreaJuegoP1[8][2] + ' ';
    Jugador1A[11][8] = ' ' + AreaJuegoP1[8][3] + ' ';
    Jugador1A[11][10] = ' ' + AreaJuegoP1[8][4] + ' ';
    Jugador1A[11][12] = ' ' + AreaJuegoP1[8][5] + ' ';
    Jugador1A[11][14] = ' ' + AreaJuegoP1[8][6] + ' ';
    Jugador1A[11][16] = ' ' + AreaJuegoP1[8][7] + ' ';
    Jugador1A[11][18] = ' ' + AreaJuegoP1[8][8] + ' ';
    Jugador1A[11][20] = ' ' + AreaJuegoP1[8][9] + ' ';

    //Fila 9
    Jugador1A[12][2] = ' ' + AreaJuegoP1[9][0] + ' ';
    Jugador1A[12][4] = ' ' + AreaJuegoP1[9][1] + ' ';
    Jugador1A[12][6] = ' ' + AreaJuegoP1[9][2] + ' ';
    Jugador1A[12][8] = ' ' + AreaJuegoP1[9][3] + ' ';
    Jugador1A[12][10] = ' ' + AreaJuegoP1[9][4] + ' ';
    Jugador1A[12][12] = ' ' + AreaJuegoP1[9][5] + ' ';
    Jugador1A[12][14] = ' ' + AreaJuegoP1[9][6] + ' ';
    Jugador1A[12][16] = ' ' + AreaJuegoP1[9][7] + ' ';
    Jugador1A[12][18] = ' ' + AreaJuegoP1[9][8] + ' ';
    Jugador1A[12][20] = ' ' + AreaJuegoP1[9][9] + ' ';


    //Fila 0
    Jugador2A[3][2] = ' ' + AreaJuegoP2[0][0] + ' ';
    Jugador2A[3][4] = ' ' + AreaJuegoP2[0][1] + ' ';
    Jugador2A[3][6] = ' ' + AreaJuegoP2[0][2] + ' ';
    Jugador2A[3][8] = ' ' + AreaJuegoP2[0][3] + ' ';
    Jugador2A[3][10] = ' ' + AreaJuegoP2[0][4] + ' ';
    Jugador2A[3][12] = ' ' + AreaJuegoP2[0][5] + ' ';
    Jugador2A[3][14] = ' ' + AreaJuegoP2[0][6] + ' ';
    Jugador2A[3][16] = ' ' + Are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aJuegoP2[0][7] + ' ';
    Jugador2A[3][18] = ' ' + AreaJuegoP2[0][8] + ' ';
    Jugador2A[3][20] = ' ' + AreaJuegoP2[0][9] + ' ';
    
    //Fila 1
    Jugador2A[4][2] = ' ' + AreaJuegoP2[1][0] + ' ';
    Jugador2A[4][4] = ' ' + AreaJuegoP2[1][1] + ' ';
    Jugador2A[4][6] = ' ' + AreaJuegoP2[1][2] + ' ';
    Jugador2A[4][8] = ' ' + AreaJuegoP2[1][3] + ' ';
    Jugador2A[4][10] = ' ' + AreaJuegoP2[1][4] + ' ';
    Jugador2A[4][12] = ' ' + AreaJuegoP2[1][5] + ' ';
    Jugador2A[4][14] = ' ' + AreaJuegoP2[1][6] + ' ';
    Jugador2A[4][16] = ' ' + AreaJuegoP2[1][7] + ' ';
    Jugador2A[4][18] = ' ' + AreaJuegoP2[1][8] + ' ';
    Jugador2A[4][20] = ' ' + AreaJuegoP2[1][9] + ' ';
    
    //Fila 2
    Jugador2A[5][2] = ' ' + AreaJuegoP2[2][0] + ' ';
    Jugador2A[5][4] = ' ' + AreaJuegoP2[2][1] + ' ';
    Jugador2A[5][6] = ' ' + AreaJuegoP2[2][2] + ' ';
    Jugador2A[5][8] = ' ' + AreaJuegoP2[2][3] + ' ';
    Jugador2A[5][10] = ' ' + AreaJuegoP2[2][4] + ' ';
    Jugador2A[5][12] = ' ' + AreaJuegoP2[2][5] + ' ';
    Jugador2A[5][14] = ' ' + AreaJuegoP2[2][6] + ' ';
    Jugador2A[5][16] = ' ' + AreaJuegoP2[2][7] + ' ';
    Jugador2A[5][18] = ' ' + AreaJuegoP2[2][8] + ' ';
    Jugador2A[5][20] = ' ' + AreaJuegoP2[2][9] + ' ';

    //Fila 3
    Jugador2A[6][2] = ' ' + AreaJuegoP2[3][0] + ' ';
    Jugador2A[6][4] = ' ' + AreaJuegoP2[3][1] + ' ';
    Jugador2A[6][6] = ' ' + AreaJuegoP2[3][2] + ' ';
    Jugador2A[6][8] = ' ' + AreaJuegoP2[3][3] + ' ';
    Jugador2A[6][10] = ' ' + AreaJuegoP2[3][4] + ' ';
    Jugador2A[6][12] = ' ' + AreaJuegoP2[3][5] + ' ';
    Jugador2A[6][14] = ' ' + AreaJuegoP2[3][6] + ' ';
    Jugador2A[6][16] = ' ' + AreaJuegoP2[3][7] + ' ';
    Jugador2A[6][18] = ' ' + AreaJuegoP2[3][8] + ' ';
    Jugador2A[6][20] = ' ' + AreaJuegoP2[3][9] + ' ';

    //Fila 4
    Jugador2A[7][2] = ' ' + AreaJuegoP2[4][0] + ' ';
    Jugador2A[7][4] = ' ' + AreaJuegoP2[4][1] + ' ';
    Jugador2A[7][6] = ' ' + AreaJuegoP2[4][2] + ' ';
    Jugador2A[7][8] = ' ' + AreaJuegoP2[4][3] + ' ';
    Jugador2A[7][10] = ' ' + AreaJuegoP2[4][4] + ' ';
    Jugador2A[7][12] = ' ' + AreaJuegoP2[4][5] + ' ';
    Jugador2A[7][14] = ' ' + AreaJuegoP2[4][6] + ' ';
    Jugador2A[7][16] = ' ' + AreaJuegoP2[4][7] + ' ';
    Jugador2A[7][18] = ' ' + AreaJuegoP2[4][8] + ' ';
    Jugador2A[7][20] = ' ' + AreaJuegoP2[4][9] + ' ';

    //Fila 5
    Jugador2A[8][2] = ' ' + AreaJuegoP2[5][0] + ' ';
    Jugador2A[8][4] = ' ' + AreaJuegoP2[5][1] + ' ';
    Jugador2A[8][6] = ' ' + AreaJuegoP2[5][2] + ' ';
    Jugador2A[8][8] = ' ' + AreaJuegoP2[5][3] + ' ';
    Jugador2A[8][10] = ' ' + AreaJuegoP2[5][4] + ' ';
    Jugador2A[8][12] = ' ' + AreaJuegoP2[5][5] + ' ';
    Jugador2A[8][14] = ' ' + AreaJuegoP2[5][6] + ' ';
    Jugador2A[8][16] = ' ' + AreaJuegoP2[5][7] + ' ';
    Jugador2A[8][18] = ' ' + AreaJuegoP2[5][8] + ' ';
    Jugador2A[8][20] = ' ' + AreaJuegoP2[5][9] + ' ';

    //Fila 6
    Jugador2A[9][2] = ' ' + AreaJuegoP2[6][0] + ' ';
    Jugador2A[9][4] = ' ' + AreaJuegoP2[6][1] + ' ';
    Jugador2A[9][6] = ' ' + AreaJuegoP2[6][2] + ' ';
    Jugador2A[9][8] = ' ' + AreaJuegoP2[6][3] + ' ';
    Jugador2A[9][10] = ' ' + AreaJuegoP2[6][4] + ' ';
    Jugador2A[9][12] = ' ' + AreaJuegoP2[6][5] + ' ';
    Jugador2A[9][14] = ' ' + AreaJuegoP2[6][6] + ' ';
    Jugador2A[9][16] = ' ' + AreaJuegoP2[6][7] + ' ';
    Jugador2A[9][18] = ' ' + AreaJuegoP2[6][8] + ' ';
    Jugador2A[9][20] = ' ' + AreaJuegoP2[6][9] + ' ';

    //Fila 7
    Jugador2A[10][2] = ' ' + AreaJuegoP2[7][0] + ' ';
    Jugador2A[10][4] = ' ' + AreaJuegoP2[7][1] + ' ';
    Jugador2A[10][6] = ' ' + AreaJuegoP2[7][2] + ' ';
    Jugador2A[10][8] = ' ' + AreaJuegoP2[7][3] + ' ';
    Jugador2A[10][10] = ' ' + AreaJuegoP2[7][4] + ' ';
    Jugador2A[10][12] = ' ' + AreaJuegoP2[7][5] + ' ';
    Jugador2A[10][14] = ' ' + AreaJuegoP2[7][6] + ' ';
    Jugador2A[10][16] = ' ' + AreaJuegoP2[7][7] + ' ';
    Jugador2A[10][18] = ' ' + AreaJuegoP2[7][8] + ' ';
    Jugador2A[10][20] = ' ' + AreaJuegoP2[7][9] + ' ';

    //Fila 8
    Jugador2A[11][2] = ' ' + AreaJuegoP2[8][0] + ' ';
    Jugador2A[11][4] = ' ' + AreaJuegoP2[8][1] + ' ';
    Jugador2A[11][6] = ' ' + AreaJuegoP2[8][2] + ' ';
    Jugador2A[11][8] = ' ' + AreaJuegoP2[8][3] + ' ';
    Jugador2A[11][10] = ' ' + AreaJuegoP2[8][4] + ' ';
    Jugador2A[11][12] = ' ' + AreaJuegoP2[8][5] + ' ';
    Jugador2A[11][14] = ' ' + AreaJuegoP2[8][6] + ' ';
    Jugador2A[11][16] = ' ' + AreaJuegoP2[8][7] + ' ';
    Jugador2A[11][18] = ' ' + AreaJuegoP2[8][8] + ' ';
    Jugador2A[11][20] = ' ' + AreaJuegoP2[8][9] + ' ';

    //Fila 9
    Jugador2A[12][2] = ' ' + AreaJuegoP2[9][0] + ' ';
    Jugador2A[12][4] = ' ' + AreaJuegoP2[9][1] + ' ';
    Jugador2A[12][6] = ' ' + AreaJuegoP2[9][2] + ' ';
    Jugador2A[12][8] = ' ' + AreaJuegoP2[9][3] + ' ';
    Jugador2A[12][10] = ' ' + AreaJuegoP2[9][4] + ' ';
    Jugador2A[12][12] = ' ' + AreaJuegoP2[9][5] + ' ';
    Jugador2A[12][14] = ' ' + AreaJuegoP2[9][6] + ' ';
    Jugador2A[12][16] = ' ' + AreaJuegoP2[9][7] + ' ';
    Jugador2A[12][18] = ' ' + AreaJuegoP2[9][8] + ' ';
    Jugador2A[12][20] = ' ' + AreaJuegoP2[9][9] + ' ';
    
    
    
    for (int row = 0; row < 14; row++)
    { 
        
        cout << endl;
        if(player < 3){
        if(player == P1){
            gotoxy(43, 24 + row);
            for (int col = 0; col < 23; col++)
        {
            cout << Jugador1A[row][col];
        }
        }else{
         for(int col = 0; col < 23; col++){
            cout << Jugador2A[row][col];
        }

        }
      
        cout << "\n";
    }
}

void imprimirtablerodeprueba(){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP1[i][j];
        }
        for (int j = 0; j < 10; j++)
        {
            cout << AreaJuegoP2[i][j];
        }

        cout << "\n";
    }

}

void pruebalogica()
{
    int tipodebarco;
    bool invalidmove;
    bool Nohayganadoraun;
    int direccion;
    string currentturn;
    bool valida;

     

    do
    {
    if (player <= 8)
    {
        currentturn = P1;
    } else {
        currentturn = P2;
    }
    
    gotoxy(0, 27);
    cout << "Its " << currentturn << " turn, select your move\n";
    cout << "Shipsize:";
    cin >> tipodebarco;


    cout << "\n";
    cout << "Arriba - 1" << endl;
    cout << "Abajo - 2" << endl;
    cout << "Izquierda - 3" << endl;
    cout << "Derecha - 4" << endl;
    cout << "Direccion: ";
    cin >> direccion;

    cout << "\n";

    cout << "Row(FILA):";
    cin >> row;
    cout << "Col(COLUMNA):";
    cin >> columna;
    col = LettertoNumber(columna);
    invalidmove = invalidplay(row, col, tipodebarco, direccion, currentturn);

    invalidmove = invalidplay(row, col, tipodebarco, direccion, currentturn);

    system("cls");
    dibujo();
    gotoxy(58, 17);
    cout << "BIENVENIDO A BATALLA NAVAL";
    
    if (invalidmove == true)
    {
        gotoxy(0, 26);
        menuBarcos(turnplayer);
        cout << "Invalidmove" << endl;
        cout << "\n";
    } 
    else if (invalidmove == false)
    {
        player++;
        buildships(row, col, tipodebarco, direccion, currentturn);
        actualizarInventarioBarcos(tipodebarco, currentturn);
        imprimirtablerodeprueba();
        /*menuBarcos(turnplayer);
        cout << "\n";
        tableronaval();*/
        
    }
    }while (player<=16);



    player = 1;
    do
    {
    if (player%2==1)
    {
        currentturn = P1;
    } else {
        currentturn = P2;
    }
    cout << currentturn << endl;
    cout << "Row";
    cin >> row;
    cout << "Column";
    cin >> columna;
    col = LettertoNumber(columna);
    shootcannons(row, col, currentturn);
    imprimirtablerodeprueba();
    Nohayganadoraun = NoWinner(currentturn);
    player++;
    } while (Nohayganadoraun==true);
    cout << "El ganador es " << currentturn << "\nFELICIDADES";
}
    



bool invalidplay (int row, int col, int barco, int direccion, string player){
    if (player == P1){
        if (TiposBarcosP1[barco-1]==0){
        return true;
        }
    } else if (player == P2){
        if (TiposBarcosP2[barco-1]==0){
        return true;
        }
    }
    if (row>=10 || col >=10 || col < 0 || row < 0)
    {
        return true;
    }
    
    else if (direccion <1 || direccion >4)
    {
        return true;
    }
    

    if (direccion== 1) //Arriba
    {
        int contador=0;
        int row1=row;
        if (row<(barco-1)){
            return true;
        }
        while (contador<barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row1][col]== "O"){
                return true;
                }
            } else if  (player == P2){
                if (AreaJuegoP2[row1][col]== "O"){
                return true;
                }
            } 
            row1--;
            contador++;
        }
        
    }
    if (direccion == 2) //Abajo
    {
        int contador=0;
        int row1=row;
        if ((row+barco)>10){
            return true;
        }
        while (contador<barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row1][col]== "O"){
                return true;
                }
            } else if  (player == P2){
                if (AreaJuegoP2[row1][col]== "O"){
                return true;
                }
            }  
            row1++;
            contador++;
        }
        
    }
    if (direccion == 3)//Izquierda
    {
        int contador=0;
        int col1=col;
        if ((col-barco) < -1)
        {
            return true;
        }
        while (contador < barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row][col1]== "O"){
                return true;
                }
            } else if (player == P2){
                if (AreaJuegoP2[row][col1]== "O"){
                return true;
                }
            }
            col1--;
            contador++;   
        }
        
    }
    if (direccion == 4) //Derecha
    {
        int contador=0;
        int col1=col;
        if ((col+barco)>10)
        {
            return true;
        }
        
        while (contador < barco)
        {
            if (player == P1){
                if (AreaJuegoP1[row][col1]== "O"){
                return true;
                }
            } else if (player == P2){
                if (AreaJuegoP2[row][col1]== "O"){
                return true;
                }
            }
            col1++;
            contador++;   
        }
       
    }
    return false;
}

void buildships(int row, int col, int barco, int direccion, string player){
    if (direccion == 1) // Arriba
    {
        int contador=0;
        int row1=row;
        while (contador<barco)
        {
            if (player== P1){
                AreaJuegoP1[row1][col]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row1][col]={'O'};
            }
            row1--;
            contador++;
        }
        
    }
    if (direccion == 2) // Abajo
    {
        int contador=0;
        int row1=row;
        while (contador<barco)
        {
            if (player== P1){
                AreaJuegoP1[row1][col]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row1][col]={'O'};
            }
            row1++;
            contador++;
        }
        
    }
    if (direccion == 3) //Izquierda 
    {
        int contador=0;
        int col1=col;
        while (contador < barco)
        {
            if (player== P1){
                AreaJuegoP1[row][col1]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row][col1]={'O'};
            }
            col1--;
            contador++;   
        }
        
    }
    if (direccion == 4) //Derecha
    {
        int contador=0;
        int col1=col;
        while (contador < barco)
        {
            if (player== P1){
                AreaJuegoP1[row][col1]={'O'};
            }
            else if (player == P2){
                AreaJuegoP2[row][col1]={'O'};
            }
            col1++;
            contador++;   
        }
       
    }
}


void gotoxy(int x, int y){
    cout << "\033[" << y << ";" << x << "f";
}

void actualizarInventarioBarcos(int barco, string player){
    if (barco==1)
    {
        if (player== P1){
            TiposBarcosP1[0]--;
        } else if (player == P2){
            TiposBarcosP2[0]--;
        }
        
    }else if (barco == 2)
    {
        if (player== P1){
            TiposBarcosP1[1]--;
        } else if (player == P2){
            TiposBarcosP2[1]--;
        }
    }else if (barco == 3)
    {
        if (player== P1){
            TiposBarcosP1[2]--;
        } else if (player == P2){
            TiposBarcosP2[2]--;
        }
    }else if (barco == 4)
    {
        if (player== P1){
            TiposBarcosP1[3]--;
        } else if (player == P2){
            TiposBarcosP2[3]--;
        }
    }else if (barco == 5){
        if (player== P1){
            TiposBarcosP1[4]--;
        } else if (player == P2){
            TiposBarcosP2[4]--;
        }
    }
}

void shootcannons(int row, int col, string player){
    if (player==P1)
    {
        if (AreaJuegoP2[row][col]== "O")
        {
            AreaJuegoP2[row][col]={"X"};
        }
        
    } else if(player==P2){
        if (AreaJuegoP1[row][col]== "O")
        {
            AreaJuegoP1[row][col]={"X"};
        }
    }
}

bool NoWinner(string player){
    if (player == P1)
    {
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (AreaJuegoP2[row][col]=="O")
            {
                return true;
            }
        }
    }
    }
    else if (player==P2){
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (AreaJuegoP1[row][col]=="O")
            {
                return true;
            }
        }
    }
    }
    return false;
}

int LettertoNumber(char Letter){//Transform letter
    if(Letter== 'A' || Letter == 'a'){
        return 0;
    }
    if(Letter== 'B' || Letter == 'b'){
        return 1;
    }
    if(Letter== 'C' || Letter == 'c'){
        return 2;
    }
    if(Letter== 'D' || Letter == 'd'){
        return 3;
    }
    if(Letter== 'E' || Letter == 'e'){
        return 4;
    }
    if(Letter== 'F' || Letter == 'f'){
        return 5;
    }
    if(Letter== 'G' || Letter == 'g'){
        return 6;
    }
    if(Letter== 'H' || Letter == 'h'){
        return 7;
    }
    if(Letter== 'I' || Letter == 'i'){
        return 8;
    }
    if(Letter== 'J' || Letter == 'j'){
        return 9;
}
else{
    return -1;
}
}
/*int menuBarcos(){
    1 Submarine [1] (3)
    2 Destroyer [2] (2)
    3 Cruiser  [3]
    4 Battleship 
    5 Carrier
void menuBarcos(string turnplayer){

    gotoxy(10, 19);
    cout << "Submarine [1 Posicion] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[0];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[0];
    }
    cout << " Submariene)" << endl;
    gotoxy(10, 20);


    cout << "Destroyer [2 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[1];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[1];
    }
    cout << " Destroyers)" << endl;
    gotoxy(10, 21);


    cout << "Cruiser  [3 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[2];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[2];
    }
    cout << " Crusier)" << endl;
    gotoxy(10, 22);


    cout << "Battleship [4 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[3];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[3];
    }
    cout << " Battleship)" << endl;
    gotoxy(10, 23); 


    cout << "Carrier [5 Posiciones] (";
    if(turnplayer == P1){
        cout << TiposBarcosP1[4];
    }else if(turnplayer == P2){
        cout << TiposBarcosP2[4];
    }
    cout << " Carrier)" << endl;

     cout << "\n";
}


