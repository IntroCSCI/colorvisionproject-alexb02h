
Are You ColorBlind?
## Description

Our program will be capable of detecting Color-blindness by flashing a circle on the screen. The circle will include two colors. One of the colors will be in the shape of a number, then it will prompt the user to tell us what number is on the screen, with the answers given I will be able to determine if the user is Colorblind, and if they are I will inform them what form of Colorblind they are.

V.02
In this update I included a circular object in the terminal, with two colors. I also added a random RGB generator, and utilizing that I patched it through a function called findColors(), this function examines the file called "color.txt and looks for a color matching the RGB code.

## Developer

Alexander Baron

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
 @@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
 @@@@@@

What Number do you see here ?
Green
Would you like to take the test again y/n
y
What color do you see here?
Red
Would you like to take the test again y/n
```

## C++ Guide

### Variables and Data Types
There is a string called responses, which will hold the users response to the questions. There is a char called choice, which will determine if you want to take the test again or not. The string finalColor is used to store the color inherited from findColor(). There is also an Int called I, which gets its number by finding the remainder of rand/8. It is used as the index of the array num. I have a string called color which is used in findColor to store the lines in color.txt. Int number is a variable I used as a storage to tell the computer which number is in the circle. Int final is another int that I used to 

int i,number,final;
string Responses,finalColor,color;
char choice;


### Input and Output
I will have the user input the color they see here. When the questions are done I will give them their result. 
Cout << "What color do you see here" << endl;
Cin >> Responses;

switch(final){
      case 1:cout << "You have " << colorBlind[0] << "vision" << endl;break;
      case 2:cout << "You have " << colorBlind[1] << "vision" << endl; break;
      case 3:cout << "You have " << colorBlind[2] << "vision" << endl; break;
      case 4:cout << "You have " << colorBlind[3] << "vision" << endl; break;
      case 5:cout << "You have " << colorBlind[4] << "vision" << endl;break;
      case 6:cout << "You have " << colorBlind[5] << "vision" << endl;break;
      case 7:cout << "You have " << colorBlind[6] << "vision" << endl; break;
      case 8:cout << "You have " << colorBlind[7] << "vision" << endl; break;
}
### Decisions
The decisions is that if you would like to take the test again or not. You will answer with either a y or a n.

Cout << "Would you like to take the test again y/n" << endl;
Cin >> choice;
if(choice == "n");

### Iteration
there is also a for loop in the function called findColor(), which uses the int li, and does it until li equals the size of the vector. The li is used as the index for the vector, and compares the object in that certain index to the RGB code gained from Random RGB.I will be using a switch statement rather than using an if statement because it will go much faster. I also have an if else statement which will be used to display the circl which contains the number. In these if statements there will printf() outputs the pattern :
```
 @@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
 @@@@@@
```
in two different colors, One of the colors will be in the shape of a number
A doWhile loop will go on if the user would like to take the test again. I also have an if statement in findColor() which checks if the current index contains the  RGB code. There is also a while loop which adds everyline in color.txt to the vector "text". How it works is by checking if there is anymore lines in the text file, and if there is it adds to the vector, and then checks the next line. If there is no line next the loop stops. Then I have a loop which determines if the file I opened is really open if it isnt, it displays the message
```
cannot open file
```
do{

}While(choice == "y");
switch(final){
      case 1:cout << "You have " << colorBlind[0] << "vision" << endl;break;
      case 2:cout << "You have " << colorBlind[1] << "vision" << endl; break;
      case 3:cout << "You have " << colorBlind[2] << "vision" << endl; break;
      case 4:cout << "You have " << colorBlind[3] << "vision" << endl; break;
      case 5:cout << "You have " << colorBlind[4] << "vision" << endl;break;
      case 6:cout << "You have " << colorBlind[5] << "vision" << endl;break;
      case 7:cout << "You have " << colorBlind[6] << "vision" << endl; break;
      case 8:cout << "You have " << colorBlind[7] << "vision" << endl; break;
}
### File Input and Output
  I will be using a file called color.txt that stores all the colors and their RGB codes. I will be calling this file later, 1: To add all of the lines individually to the vector called text 2: to compare the RGB code inherited from the function radnomRGB.

### Arrays/Vectors
  I have a string vector called colors which adds every line in colors.txt to the vector and then uses the vector later on to compare the RGB to rbg codes in the file.I also have array called colorBlind which stores all the types of color-blindess which will be used int a later update to tell the user what type of color-blindness. I also have a string array called rgb which stores all of the RGB codes. 

  vector <string> colors;
  string colorBlind[7] = ["Deuteranomaly","Protanomaly",                         "Protanopia","deuteranopia",                            "Tritanomaly","Tritanopia",                               "monochromacy" 

### Functions
I have a two functions called randomRGB(), and findColor() randomRGB Randomizes RGB codes and returns them, it achieves this by utilizing the rand() function to random a number between zero and eight. This is then put in the int called i, i uses the remainder of rand/8 , which is placed in index. It then calls the RGB code that is in the index of the array. The function has a int parameter called randSeed, it is employed to add time(0) in srand(time(0) + randSeed). When it is called in Int main,I randomize the number used for randSeed.Then findColor uses the RGB code found in randomRGB to acquire a color in color.txt that matches that of the RGB code. It does this by going through the vecotr colors, which contains all of the colors from the txt file.When it finds the line containing the code, it then places the line in the string color, and then I split the string color to only show the name of the color. It then returns the color. It has a string parameter called rgb which when used in main uses the function called from randomRGB. 
