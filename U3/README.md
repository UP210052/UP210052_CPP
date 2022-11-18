# Tic tac toe

## Index
<h3>

[Instructions for execution and use](#instructions-for-execution-and-use)   
[Flowchart](#flowchart)   
[Tests](#tests)   
[Conclusion](#conclusion)  

</h3>

## Instructions for execution and use
In order to enjoy the single player and multiplayer game modes, you first need to follow the steps below depending on the operating system.
<h2> Windox </h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210052/UP210052_CPP.git"
~~~

2. Download and install the compiler in this link https://sourceforge.net/projects/mingw/files/OldFiles/ 
3. Open the terminal at the direction of the file with the command:

~~~
cd C:\Documents\...
~~~

4. To compile use command:

~~~
gcc  04_Gato.cpp -o 04_Gato.exe
~~~

5. To run type this code:

~~~
04_Gato.exe
~~~

<h2> Linux (Ubuntu)</h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210052/UP210052_CPP.git"
~~~

2. Install GNU c/c++ compiler, open the terminal and type:

~~~
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev
~~~

3. To compile this program, type:

~~~
gcc 04_Gato.c -o 04_Gato
~~~

4. To run this program, type:

~~~
./04_Gato
~~~

## Flowchart

<img src="../imagenes/gato.drawio.png" align="center">

## Tests

<h2>Things to consider</h2>

- Do not write numbers with decimal point or letters when asking for the move.  
- In single player mode the player is "O" and the PC is "X".  
- In multiplayer mode player 1 is "O" and player two is "X".  

<h2>Player vs PC</h2>

The first thing that appears on the screen is a menu to choose the game mode.  
<img src="../imagenes/gato1.png" align="center">  
Select 1 since we are going to play vs. the PC. The game board will appear with numbers from 1 to 9 to select the move.   
<img src="../imagenes/gato2.png" align="center">  
Now we will start playing against the PC, my first move is on cell 5. On the other hand, the PC's first move is always random.  
<img src="../imagenes/gato3.png" align="center">  
My second move is on cell 9. The computer now counters by placing its move on cell 1.   
<img src="../imagenes/gato4.png" align="center">  
My third move is on cell 7 to prevent the computer from winning. The PC counters by putting his move in cell 3 to prevent me from winning.
<img src="../imagenes/gato5.png" align="center">  
My fourth move is in cell 8. The CP counters by putting their move in cell 8 to prevent me from winning.  
<img src="../imagenes/gato6.png" align="center">  
As the cells ran out, the game ended in a draw.  
<img src="../imagenes/gato7.png" align="center">  




## Conclusion