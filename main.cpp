#include <iostream>

using namespace std;

int main()
{
  string colorBlind[8] = {"Deuteranomaly ","Protanomaly ",                                         "Protanopia ","deuteranopia ",                                           "Tritanomaly ","Tritanopia ",                                            "Monochromacy ","Normal "};
  string Responses;
  int final;
  char choice;
  char n[4] = "n";
  char y[4] = "y";

  do{ 
      cout << "What color do you see here ?" << endl; 
      cin >> Responses;
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
    cout << "Would you like to take the test again y/n" << endl;
    cin >> choice;
    if(choice == n[0]){
      cin.ignore();
    }
  }while(choice == y[0]);
  return 0;
}
