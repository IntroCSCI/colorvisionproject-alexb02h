# !!!Replace with your unique project name!!!
Are You ColorBlind?
## Description

Our program will be able to detect ColorBlindnes by flashing the word color on the screen, the word "color" will be a specific color, and then it will prompt the user to tell us what color is on the screen, with the answers given we will be able to determine if the user is ColorBlind, and if they are we will tell them what form of ColorBlind they are.

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
What color do you see here ?
Green
Would you like to take the test again y/n
y
What color do you see here?
Red
Would you like to take the test again y/n
```

## C++ Guide

### Variables and Data Types
I am using a array to hold all of the certain colorBlind types, also using an red, blue, and green int to increase the colors. Then there is a string called responses, which will hold the users response to the questions. There is a char called choice, which will determine if you want to take the test again or not. There is also the string variable filename, this variable will come in handy when talking about file input/output.

string colorBlind[7] = ["Deuteranomaly","Protanomaly",                            "Protanopia","deuteranopia",                              "Tritanomaly","Tritanopia",                               "monochromacy" ]
int Red,Blue,Green;
string Responses,filename;
char choice;


### Input and Output
We will have the user input the color they see here. When the questions are done we will give them their result. I will be using a switch statement rather than using an if statement because it will go much faster.

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
A doWhile loop will go on if the user would like to take the test again.
do{

}While(choice == "y");

### File Input and Output
  We will be analyzing a color, and then checkinf if that color is compatable with a color in the file. We will be prompting the user to open a file.

  cout << "Enter the file name to check colors" << endl;
  cin >> filename;

  The user will then input a filename, and the program will determine if a certain color is in the file.

