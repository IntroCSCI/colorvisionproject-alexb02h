Are You ColorBlind?
## Description
V.01
Our program will be capable of detecting Color-blindness by flashing a circle on the screen. The circle will include two colors. One of the colors will be in the shape of a number, then it will prompt the user to tell us what number is on the screen, with the answers given I will be able to determine if the user could be Color-blind, and if they are I will inform them what form of Color-blind they are.
V.02 Updates
In this update, I included a circular object in the terminal, with two colors. I also added a random RGB generator, and utilizing that I patched it through a function called findColors(), this function examines the file called "color.txt and looks for a color matching the RGB code.
V.1.0 Updates
In this update, I included the class titled User, which stores the user’s data. The program then uses the name to search for the user's file, and if the user has data in the file, it tells the user their previous result. I also added the scoring system which would tell the program which case to give out in the switch statement at the end of the program.
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
What Number do you see here?
9
What color do you see here?
Red
Would you like to take the test again y/n
```
## C++ Guide
### Variables and Data Types
 
There is a string called responses, which will hold the user’s response to the questions. There is a char called choice, which will determine if you want to take the test again or not. The string name is a private string in the class, user, the string stores the user’s name. The string contents is also a private string in the user class, the string contains the information from the users file The string finalColor is used to store the color inherited from findColor(). There is also an Int called I, which gets its number by finding the remainder of rand/8. It is used as the index of the array num. I have a string called color which is used in findColor to store the lines in color.txt. Int number is a variable I used as storage to tell the computer which number is in the circle. Int count is an int that I used to count the points given if the answer is wrong, the int would later be used in the switch statement to determine what color-blind type the user could have. I have multiple bool statements that tell the program if the color circle has been used or not, the bool title used determines if a do-while loop continues or stops. If the if statement that decides the color circle has been used, the bool used will become true. The int questions are used to set the number of questions asked in the survey, it is then used in a do-while loop.
 
int i,number,count,Questions;
string Responses,finalColor,color,name, contents;
char choice;
bool bused = false,blused = true,rused = false,
gused = false,wused = true,pused = false,
grused = true,yused = false,used = false,result = false;
 
### Input and Output
I will have the user input the color of the number they see, and the number in the color circle When the questions are done I will give them their result.
 
Cout << "What color is the number" << endl;
Cin >> responseColor
Cout << "What number do you see" << endl;
Cin >> responseNumb;
Cout << "Would you like to take the test again y/n" << endl;
Cin >> choice;
 
### Decisions
The decision is that if you would like to take the test again or not. You will answer with either a y or an n. I will be using a switch statement rather than using an if statement because it will go much faster. I also have an if-else statement which will be used to display the circle which contains the number. In these if statements there will printf() outputs the pattern :
```
 @@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@
 @@@@@@
```
in two different colors, One of the colors will be in the shape of a number. There is also a statement that checks if the variable correct is true or not true, if the variable is true it then presents the user with the next question, and the next if statement, if the variable isn’t true, it goes through a list of if-else statements and determines the numerical value of the color circle in the question, and adds the value to the int count. if the first part of the question is true, but the second part of the question is false, it does the same as if the first part was false. I also have if-else statements in the functions correctColor, and correctNumb, both of these if-else statements work the same way, if the response is similar to the color, or the number, return true, else return false. And at the end of the program, the program checks to see if the switch statement received a result, if it did it prompts the user to take the test again, but if it didn’t get a result, the user is still prompted with the same prompt but this time with the program saying that it could not come up with a result.
 
if(correct == false){
if(responseColor == "Grey" || responseColor == "White"){
  count = 100;
}
else if(finalColor == "Red"){
  count += 1;
}
else if(finalColor == "Blue"){
  count += 5;
}
else if(finalColor == "Orange"){
  count += 4;
}
else if(finalColor == "Purple"){
  count += 6;
}
else if(finalColor == "Green"){
  count += 3;
}
}
switch(count){
   case 0:cout << "You could have " + colorBlind[0] + "vision" << endl;
                   u.addBlindness(colorBlind[0]);result = true;break;
   case 1:cout << "You could have " + colorBlind[1] << endl;
                   u.addBlindness(colorBlind[1]);result = true;break;
   case 4:cout << "You could have " + colorBlind[3] << endl;
                   u.addBlindness(colorBlind[3]);result = true;break;
   case 3:cout << "You could have " + colorBlind[2] << endl;
                   u.addBlindness(colorBlind[2]);result = true;break;
   case 8:cout << "You could have " + colorBlind[4] << endl;
                   u.addBlindness(colorBlind[4]);result = true;break;
   case 19:cout << "You could have " + colorBlind[5] << endl;
                   u.addBlindness(colorBlind[5]);result = true;break;
   case 100:cout << "You could have " + colorBlind[6] << endl;
                   u.addBlindness(colorBlind[6]);result = true;break;
}
if(result == false){
cout << "Sorry we could not get a result from your answers" << endl;
cout << "Would you like to take the test again y/n" << endl;
}
else{
cout << "Would you like to take the test again y/n" << endl;
}
 
### Iteration
There is a for loop in the function called findColor(), which uses the int li, and does it until li equals the size of the vector. The li is used as the index for the vector and compares the object in that certain index to the RGB code gained from Random RGB. A do-while loop will go on if the user would like to take the test again. I also have an if statement in findColor() which checks if the current index contains the  RGB code. There is also a while loop which adds every line in color.txt to the vector "text". How it works is by checking if there are any more lines in the text file, and if there are it adds to the vector, and then checks the next line. If there is no line next the loop stops. Then I have a loop that determines if the file I opened is open if it isn’t, it displays the message
```
cannot open file
```
I also added two more do-while loops, the first loop goes to the previous color circle if statements, and checks if they have previously been used, and if they have been the program restarts until it comes across a color circle that hasn’t been used yet. The second do-while loop is used to restrict the number of questions asked, so at the end of the do part of the loop the in question gets decreased by one.
 
do{
}While(choice == "y");
do{
}while(questions != 0);
do{
}while(used == false);
 
### File Input and Output
I will be using a file called color.txt that stores all the colors and their RGB codes. I will be calling this file later, 1: To add all of the lines individually to the vector called text 2: to compare the RGB code inherited from the function radnomRGB. I created a system, in the user class, which checks if the user has a previous file, and if they do not it creates a new one. In the user’s file, it contains the user’s color-blind results from the previous test. I have a fstream reader called read in the user class, and an ifstream reader titled reader in the function findColor.
 
### Arrays/Vectors
I have a string vector called colors which adds every line in colors.txt to the vector and then uses the vector, later on, to compare the RGB to RGB codes in the file. I also have an array called colorBlind which stores all the types of color-blindness which will be used in a later update to tell the user what type of color-blindness. I also have a string array called RGB which stores all of the RGB codes.
vector <string> colors;
string colorBlind[7] = ["Normal","Deuteranomaly","Protanomaly",                         ,"deuteranopia",                            "Tritanomaly","Tritanopia",                               "monochromacy"
 
### Functions
I have two functions called randomRGB(), and findColor() randomRGB Randomizes RGB codes and returns them, it achieves this by utilizing the rand() function to random a number between zero and eight. This is then put in the int called i, i uses the remainder of rand/8, which is placed in the index. It then calls the RGB code that is in the index of the array. The function has a int parameter called randSeed, it is employed to add time(0) in srand(time(0) + randSeed). When it is called in Int main, I randomize the number used for randSeed.Then findColor uses the RGB code found in randomRGB to acquire a color in color.txt that matches that of the RGB code. It does this by going through the vector colors, which contains all of the colors from the txt file. When it finds the line containing the code, it then places the line in the string color, and then I split the string color to only show the name of the color. It then returns the color. It has a string parameter called RGB which when used in main uses the function called from randomRGB. In version 1.0 I added six new functions, four of those being in the user class. The first two functions titled, correctNumb, and correctColor, both checked the user's response to make sure it matched the number and color contained in the color circle if it did the functions returned true, if not the function returns false. The functions had two parameters,
correctNumb had the parameters of number, and response, while correctColor had the parameters of color, and response. both functions were bool functions, meaning they could only return the true or false values.
Class Functions :
The four functions in the user class were all void functions and were titled setName, findName, getColorBlind, and addBlindness. The first function setName had a string parameter titled n, the function used the string n, and set the private string name to the variable held in n. The next function, findName did not have a parameter, the function looks for the user's file, and if the function cannot find the file it creates a new one. getColorBlind searches through the user's file to return the type of color-blind the user may be. The final function addBlindness has a string parameter titled blindness, this function adds the results from the survey to the user's file.
 
### Classes
I created a class titled user, which holds three private variables, and four public constructors. The purpose of the class is to store the user’s info, in said class the user's: name and colorblind type are stored. The name is created into a new file if it did not previously exist, and after the survey is finished the color-blind type is stored in the user's file. I previously talked about the four constructors in my functions section. The private variables held in the class are a fstream titled read, a string called name, and another string called contents.
.