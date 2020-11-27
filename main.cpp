#include <iostream>
#include <fstream>
#include <vector> 
#define RESET   "\x1b[0m"
using namespace std;
class user {
  private : 
    ifstream read;
    ofstream oRead;
    string name, contents;
  public :
    void findName(string n){
      read.open(n + ".txt");
      if(read.is_open()){
        cout << "Welcome back " + n << endl;
      }
      else{
        oRead.open(n + ".txt");
        cout << "Hello " + n + " Welcome to your first test" << endl;
      }
      read.close();
    }
    bool isOpen(string n){
      if(read.is_open()){
        return true;
      }
      else{
        return false;
      }
    }
    void getColorBlind(string n){
      read.open(n + ".txt");
      if(read.is_open()){
        while(getline(read, contents)){
          
        }
      }
    }
};
void toTheEnd( string  &a, string  &b ){
    string c = a;
    string d = b;
    if(a > b){
      a = d;
      b = c;
    }
  }
//giveRandomRGB is the function that gives a random rgb number.
string giveRandomRGB(int randSeed){
  srand(time(0) + randSeed);
  //array which holds all of the rgb codes
  vector <string> rgb;
  if(rgb.size() > 0){
   rgb = {"(0, 128, 0)","(128, 0, 128)","(255, 0, 0)", "(0, 0, 255)",
          "(0, 0, 0)","(255, 255, 255)","(255, 255, 0)","(128, 128, 128)"};
   int i = rand() % 8; 
   return rgb[7];
  }
  else{
    return "None";
  }
}
//findColor is the function which searches color.txt to find the color found in giveRandomRGB.
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
  string colorBlind[8] = {"Deuteranomaly ","Protanomaly ",                                                  "Protanopia ","deuteranopia ",                                                    "Tritanomaly ","Tritanopia ",                                                     "Monochromacy ","Normal "};
  string Responses,name;
  bool c;
  int final;
  char choice;
  user u;
  cout <<  "What is your name?" << endl;
  cin >> name ;
  u.findName(name);
  c = u.isOpen(name);
  u.getColorBlind(name);
  //do while is for when the user is promtpted to take the test again, if the answer is yes the loop will go again, if otherwise it will quit the program.
  do{
  int number;
  //stores the color found in findColor in finalColor.
  string finalColor = findColor(giveRandomRGB(rand()));
  //if else statements that contain the circles based on the color inherited from finalColor.
  cout << finalColor;
    if(finalColor == "Black "){
      printf( "\u001b[0;30m"  "What Color is the Text" RESET "\n");
    }
    else if(finalColor == "Red   "){
      printf(" \033[32m@@@@@@\n"
                        "@@\u001b[31m@@@@\033[1;32m@@\n"
                        "\033[1;32m@@\u001b[31m@\033[1;32m@@\u001b[31m@\033[1;32m@@\n"
                        "@@\u001b[31m@@@@\033[1;32m@@\n"
                        "@@@@@\u001b[31m@\033[1;32m@@\n" 
                        "@@@@@\u001b[31m@\033[1;32m@@\n"
                        " @@@@@@" RESET "\n");
                        number = 9;
    }
    else if(finalColor == "Yellow"){
     printf(" \033[45@@@@@@@\n"
                        "@@\u001b[33m@@@@\u001b[35m@@\n"
                        "@@\u001b[33m@\u001b[35m@@@@@\n"
                        "@@\u001b[33m@@@@\u001b[35m@@\n"
                        "@@@@@\u001b[33m@\u001b[35m@@\n" 
                        "@@\u001b[33m@@@@\u001b[35m@@\n"
                        " @@@@@@" RESET "\n");
                        number = 5;
    }
    else if(finalColor == "Purple"){
      printf(" \u001b[33m@@@@@@\n"
                        "@@\u001b[35;1m@@@@\u001b[33m@@\n"
                        "@@\u001b[35;1m@\u001b[33m@@@@@\n"
                        "@@\u001b[35;1m@@@@\u001b[33m@@\n"
                        "@@\u001b[35;1m@\u001b[33m@@\u001b[35;1m@\u001b[33m@@\n" 
                        "@@\u001b[35;1m@@@@\u001b[33m@@\n"
                        " @@@@@@"  RESET "\n");
                        number = 6;
    }
    else if(finalColor == "White "){
     printf(" \u001b[37;2m@@@@@@\n"
           "@@" RESET"@\u001b[37;2m@@@@@\n"
           "@@" RESET"@\u001b[37;2m@@@@@\n"
           "@@" RESET"@\u001b[37;2m@@@@@\n"
           "@@" RESET"@\u001b[37;2m@@@@@\n"
           "@@" RESET"@\u001b[37;2m@@@@@\n"
           " @@@@@@" RESET "\n" );
           number = 1;
    }
    else if(finalColor == "Green "){
      printf(" \u001b[31m@@@@@@\n"
                        "@@\u001b[32m@@@@\u001b[31m@@\n"
                        "\u001b[31m@@\u001b[32m@\033[1;31m@@\u001b[32m@\033[1;31m@@\n"
                        "\033[1;31m@@\u001b[32m@@@@\033[1;31m@@\n"
                        "\033[1;31m@@\033[1;32m@\033[1;31m@@\033[1;32m@\033[1;31m@@\n" 
                        "@@\u001b[32m@@@@\033[1;31m@@\n"
                        " @@@@@@" RESET "\n");
                        number = 8;
    }
   else if(finalColor == "Blue  "){
     printf(" \u001b[2;33m@@@@@@\n"
                        "@@\u001b[0;34m@@@@\u001b[2;33m@@\n"
                        "@@@@@\u001b[0;34m@\u001b[2;33m@@\n"
                        "@@\u001b[0;34m@@@@\u001b[2;33m@@\n"
                        "@@@@@\u001b[0;34m@\u001b[2;33m@@\n" 
                        "@@\u001b[0;34m@@@@\u001b[2;33m@@\n"
                        " @@@@@@"  RESET "\n" );
                        number = 3;
    }
    else if(finalColor == "Grey  "){
      printf( " @@@@@@\n"
            "@@\u001b[37;1m@@@@" RESET "@@\n"
            "@@@@@\u001b[37;1m@" RESET "@@\n"
            "@@\u001b[37;1m@@@@" RESET "@@\n"
            "@@\u001b[37;1m@" RESET "@@@@@\n" 
            "@@\u001b[37;1m@@@@" RESET "@@\n"
            " @@@@@@" RESET "\n" );
            number = 2;
    }
    cout << "\nWhat Number do you see here ?" << endl; 
    cin >> Responses;
    cout << "\nWhat color is the number" << endl;
    //switch statment that will eventuall tell the user what color-blind type they are based of the int final.
    switch(final){
      case 1:cout << "You have " << colorBlind[0] << "vision" << endl;break;
      case 2:cout << "You have " << colorBlind[1] << "vision" << endl; break;
      case 3:cout << "You have " << colorBlind[2] << "vision" << endl; break;
      case 4:cout << "You have " << colorBlind[3] << "vision" << endl; break;
      case 5:cout << "You have " << colorBlind[4] << "vision" << endl;break;
      case 6:cout << "You have " << colorBlind[5] << "vision" << endl;break;
      case 7:cout << "You have " << colorBlind[6] << "vision" << endl; break;
      case 0:cout << "You have " << colorBlind[7] << "vision" << endl; break;
    }
    //output that prompts the user to take the test again.
    cout << "Would you like to take the test again y/n" << endl;
    cin >> choice;
    if(choice == 'n'){
      cin.ignore();
    }
  }while(choice == 'y');
  return 0;
}