# Exercise 1: A program that asks the user for his annual rent and displays the corresponding tax rate.
## Tax rate selection section (code).
    c++
    //Request for rent.
    cout << "Enter your annual rent: ";
    cin >> Rent;
    
    //Evaluate rent to obtain the tax.
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
        
        //Visualize the data.
        cout << "The tax rate is" << (Tax*100) << "% \n";
        Tax= Rent * Tax;
        cout << "Which is the equivalent $" << Tax << endl;
    }
    else {
        cout << "The rent you entered is ncorrect. \n";  
    }

## Explanation.
1. Ask the user for his annual rent.
2. Check that the user entered a valid rent.   
2.1 If the user does not enter a valid rent, print a message that the user entered an incorrect number.  
2.2 If the user entered a valid rent, continue with the program.
3.  Check by several if's which tax rate.  
3.1 If the rent is less than $10, 000 it is 5% (.05).  
3.2 If the rent is greater than or equal to $10,000 and less than $20,000 it is 15% (.15).  
3.3 If the rent is greater or equal to $20,000 and less than $35,000, it is 20% (.20).   
3.4 If the rent is greater or equal to $35,000 and less than $60,000 it is 30% (.30).  
3.5 If the rent is greater than $60,000 it is 45% (.45). 

4. Multiply the rent by the tax rate.
5. Print the tax rate and its equivalent in dollars. 

## Texts
### A) Rent < $10,000
<img src="UP210052_CPP/../../imagenes/Img_01.png" align="center" height="150" width="700"/>

### B) Rent >= $10,000 and Rent < $20,000 
<img src="UP210052_CPP/../../imagenes/Img_02.png" align="center" height="150" width="700"/>

### C) Rent >= $20,000 and Rent < $35,000 
<img src="UP210052_CPP/../../imagenes/Img_03.png" align="center" height="150" width="700"/>

### D) Rent >= $60,000
<img src="UP210052_CPP/../../imagenes/Img_03.png" align="center" height="150" width="700"/>
