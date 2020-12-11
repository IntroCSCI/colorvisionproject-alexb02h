#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;
//class that holds all of the users date
class user {
  private : 
    fstream read;
    string name, contents;
  public :
    //constructor that sets the users name
    void setName(string n){
      name = n;
    }
    //constructor that looks for the users file
    void findName(string n){
      setName(n);
      read.open(name + ".txt");
      //checks if file is open, and if it is, the program welcomes them back
      if(read.is_open()){
        cout << "Welcome back " + name << endl;
      }
      //if the file cannot open it opens a new file and welcomes the user to their first test
      else{
        read.open(name + ".txt");
        cout << "Hello " + name + " Welcome to your first test" << endl;
      }
      read.close();
    }
    //constructor that recieves the type of color blind type the user is if the user has a file.
    void getColorBlind(){
      vector <string> content;
      read.open(name + ".txt");
      if(read.is_open()){
        while(getline(read, contents)){
          content.push_back(contents);
        }
        if(contents.size() > 0){
          for(int a = 0; a < content.size(); a++){
           cout << "based on previous results you could have " + content[a] +  "vision\n";
          }
        }
      }
      read.close();
    }
    //constructor that adds the color blind type the user is, to the users file
    void addBlindness(string blindness){
        read.open(name + ".txt", ios::out);
        read << blindness;
        read.close();
    }
};
//giveRandomRGB is the function that gives a random rgb number.
string giveRandomRGB(int randSeed){
  srand(time(0) + randSeed);
  //array which holds all of the rgb codes
  vector <string> rgb = {"(0, 128, 0)","(128, 0, 128)","(255, 0, 0)", "(0, 0, 255)",
                         "(0, 0, 0)","(255, 255, 255)","(255, 255, 0)","(128, 128, 128)"};
   int i = rand() % 8; 
   return rgb[i];
}
//isCorrectNumb checks if the user inputed number is the same that matches the number in the circle
bool isCorrectNumb(int answer, int numb){
  if(answer == numb){
    return true;
  }
  else{
    return false;
  }
}
//correctColor checks if the color in the circle matches the color that the user inputed
bool correctColor(string answer, string color){
  if(answer == color){
    return true;
  }
  else{
    return false;
  }
}
//findColor is the function which searches color.txt to find the color found in giveRandomRGB
string findColor(string rgb){
  ifstream reader;
  vector <string> colors;
  string color;
  reader.open("colors.txt");
  //If statment to check if the file is open.
  if(reader.is_open()){
    //While loop gets the lines from the file until there are no more lines to get.
    while(getline(reader, color)){
      //when it gets the color it gets put into the vector colors.
      colors.push_back(color);
    }
    for(int i = 0; i < colors.size(); i++){
      //checks to see if the current color's rgb matches that of the rgb from giveRandomRGB
      if(colors[i].find(rgb) != -1){
        color = colors[i];  
        color = color.substr(0,6);
        i += 1000;
        reader.close();
        return color;        
      }
    }  
  }
  else{
    cout << "cannot open file" << endl;
  }
  return color;
}
int main()
{
  //array that holds all the types of color-blindness.
  string colorBlind[7] = {"Normal ","Deuteranomaly ",                                                    "Protanopia ","deuteranopia ",                                                    "Tritanomaly ","Tritanopia ",                                                     "Monochromacy "};
  string responseColor,name;
  char choice;
  user u;
  cout <<  "What is your name?" << endl;
  cin >> name;
  u.findName(name);
  u.getColorBlind();
  //do while is for when the user is promtpted to take the test again, if the answer is yes the loop will go again, if otherwise it will quit the program.
do{
    //bool statments which will tell the program if the color has been used already
    bool bused = false,blused = true,rused = false,
       gused = false,wused = true,pused = false,
       grused = true,yused = false,used = false,result = false;
    int count = 0,Questions = 5,responseNumb,number;
    string finalColor;
    //do while function that runs the program until the int questions becomes 0
    do{
      //do while function that runs if the finalColor has been previously used
      do{
       //stores the color found in findColor in finalColor.
        finalColor = findColor(giveRandomRGB(rand()));
        used = false;
        //stores the color circle for Black
        if(finalColor == "Black "){
          if(blused == true){
            used = false;
          }
          else if(blused == false){
            printf( "\u001b[0;30m"  "What Color is the Text\x1b[0m \n");
            number = 0;finalColor = "Black";
            blused = true;used = true;
          }
          }
        //stores the color circle for Red
        else if(finalColor == "Red   "){
          if(rused == true){
            used = false;
          }
          else if(rused == false){
            printf(" \033[32m@@@@@@\n"
               "@@\u001b[31m@@@@\033[1;32m@@\n"
               "\033[1;32m@@\u001b[31m@\033[1;32m@@\u001b[31m@\033[1;32m@@\n"
               "@@\u001b[31m@@@@\033[1;32m@@\n"
               "@@@@@\u001b[31m@\033[1;32m@@\n" 
               "@@@@@\u001b[31m@\033[1;32m@@\n"
               " @@@@@@\n");number = 9;finalColor = "Red";
            rused = true;used = true;
          }
          }
        //stores the color cirlce for Yellow
        else if(finalColor == "Yellow"){
          if(yused == true){
            used = false;
          }
          else if(yused == false){
             printf(" \u001b[0;34m@@@@@@\n"
              "@@\u001b[3;33m@@@@\u001b[0;34m@@\n"
              "@@\u001b[3;33m@\u001b[0;34m@@@@@\n"
              "@@\u001b[3;33m@@@@\u001b[0;34m@@\n"
              "@@@@@\u001b[3;33m@\u001b[0;34m@@\n" 
              "@@\u001b[3;33m@@@@\u001b[0;34m@@\n"
              " @@@@@@\n");number = 5;finalColor = "Orange";
              yused = true;used = true;
          }
          }
        //stores the color cirlce for Purple
        else if(finalColor == "Purple"){
          if(pused == true){
            used = false;
          }
          else if(pused == false){
            printf(" \u001b[0;34m@@@@@@\n"
               "@@\u001b[35;1m@@@@\u001b[0;34m@@\n"
               "@@\u001b[35;1m@\u001b[0;34m@@@@@\n"
               "@@\u001b[35;1m@@@@\u001b[0;34m@@\n"
               "@@\u001b[35;1m@\u001b[0;34m@@\u001b[35;1m@\u001b[0;34m@@\n" 
               "@@\u001b[35;1m@@@@\u001b[0;34m@@\n"
               " @@@@@@\n"); number = 6;
              pused = true;used = true;
            }
          }
        //stores the color circle for White
        else if(finalColor == "White "){
          if(wused == true){
           used = false;
          }
          else if(wused == false){
             printf(" \u001b[37;2m@@@@@@\n"
             "@@\x1b[0m@\u001b[37;2m@@@@@\n"
             "@@\x1b[0m@\u001b[37;2m@@@@@\n"
             "@@\x1b[0m@\u001b[37;2m@@@@@\n"
             "@@\x1b[0m@\u001b[37;2m@@@@@\n"
             "@@\x1b[0m@\u001b[37;2m@@@@@\n"
             " @@@@@@\n" ); number = 1;finalColor = "White";
             wused = true;used = true;
          }        
          }
        //stores the color circle for Green
        else if(finalColor == "Green "){
          if(gused == true){
            used = false;
          }
          else if(gused == false){
            printf(" \u001b[31m@@@@@@\n"
               "@@\u001b[32m@@@@\u001b[31m@@\n"
               "\u001b[31m@@\u001b[32m@\033[1;31m@@\u001b[32m@\033[1;31m@@\n"
               "\033[1;31m@@\u001b[32m@@@@\033[1;31m@@\n"
               "\033[1;31m@@\033[1;32m@\033[1;31m@@\033[1;32m@\033[1;31m@@\n" 
               "@@\u001b[32m@@@@\033[1;31m@@\n"
               " @@@@@@\n");number = 8;
               gused = true;used = true;finalColor = "Green";
          }
          }
        //stores the color circle for Blue
        else if(finalColor == "Blue  "){
          if(bused == true){
            used = false;
          }
          else if(bused == false){
            printf(" \u001b[0;33m@@@@@@\n"
             "@@\u001b[0;34m@@@@\u001b[0;33m@@\n"
             "@@@@@\u001b[0;34m@\u001b[0;33m@@\n"
             "@@\u001b[0;34m@@@@\u001b[0;33m@@\n"
             "@@@@@\u001b[0;34m@\u001b[0;33m@@\n" 
             "@@\u001b[0;34m@@@@\u001b[0;33m@@\n"
             " @@@@@@\n" );number = 3;finalColor = "Blue";
            bused = true;used = true;
          }
          }
        //stores the color cicle for Grey
        else if(finalColor == "Grey  "){
          if(grused == true){
            used = false;
          }
          else if(grused == false){
           printf( " @@@@@@\n"
              "@@\u001b[37;1m@@@@\x1b[0m@@\n"
              "@@@@@\u001b[37;1m@\x1b[0m@@\n"
              "@@\u001b[37;1m@@@@\x1b[0m@@\n"
              "@@\u001b[37;1m@\x1b[0m@@@@@\n" 
              "@@\u001b[37;1m@@@@\x1b[0m@@\n"
              " @@@@@@\n" );number = 2;finalColor = "Grey";
              grused = true;used = true;
          }
          }
      }while(used == false);
      cout << "\nWhat Number do you see here ?" << endl; 
      cin >> responseNumb;
      //checks if the response is the same as the number in the circle
      bool correct = isCorrectNumb(responseNumb,number);
      //if answer is correct the program prompts the user with the question asking what color the number is
      if(correct == true){
       cout << "\nWhat color is the number" << endl;
       cin >> responseColor;
       correct = correctColor(responseColor, finalColor);
       //if the answer is false the program goes through an if statement and checks what color the circl was, and based on that adds the numerical value of the color to the int count, for example the numerical value of Red is one, so one gets added to count.
       if(correct == false){
        if(responseColor == "Grey" || responseColor == "White"){
          count = 100;
        }
        else if(finalColor == "Red"){
          if(responseColor == "red"){
            count += 0;
          }
          else{
            count += 1;
          }
        }
        else if(finalColor == "Blue"){
          if(responseColor == "blue"){
            count += 0;
          }
          else{
            count += 5;
          }
        }
        else if(finalColor == "Orange"){
          if(responseColor == "orange"){
            count += 0;
          }
          else{
            count += 4;
          }
        }
        else if(finalColor == "Purple"){
          if(responseColor == "purple"){
            count += 0;
          }
          else{
            count += 6;
          }
        }
        else if(finalColor == "Green"){
          if(responseColor == "green"){
            count += 0;
          }
          else{
            count += 3;
          }
        }
        }
        }
      else if(correct == false){
        if(finalColor == "Green "){
         count += 3;
        }
        else if(finalColor == "Red   "){
          count += 1;
        }
        else if(finalColor == "Blue  "){
          count += 5;
        }
        else if(finalColor == "Yellow"){
          count += 4;
        }
        else if(finalColor == "Purple"){
          count += 6;
        }
        }
      Questions -= 1;
    }while(Questions != 0);
    //switch statment that will eventually tell the user what color-blind type they are based of the int count.
    switch(count){
      case 0:cout << "You could have " + colorBlind[0] + "vision" << endl;
                      u.addBlindness(colorBlind[0]);result = true;break;
      case 5:cout << "You could have " + colorBlind[0] + "vision" << endl;
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
    //if statement checks if the program recieved a result from the survey
    if(result == false){
      cout << "Sorry we could not get a result from your answers" << endl;
      cout << "Would you like to take the test again y/n" << endl;
      }
    else{
      cout << "Would you like to take the test again y/n" << endl;
      }
    cin >> choice;
    if(choice == 'n'){
      cin.ignore();
    }
  }while(choice == 'y');
  return 0;
}