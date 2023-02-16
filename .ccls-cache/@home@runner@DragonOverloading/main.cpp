#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class Dragon{
private:
  void Power(int power){
    if(power > 90){
      cout << "Alert! It's a Legendary Dragon!" << endl;
    }
    else if (power < 20){
      cout << "Bad luck! It's a Puny Dragon!" << endl;
    }
    else{
      cout << "It's just an Ordinary Dragon!" << endl;
    }
    cout << "Dragon's power is: " << power << endl;
  }

public:
  // Fire Dragon
 void AccessSuperPower(int power, int fireIntensity){
   Power(power);
   cout << "Fire intensity of the dragon is: " << fireIntensity << endl;
 }

  // Water Dragon
 void AccessSuperPower(int power){
   Power(power);
   cout << "Dragon is capable of altering water bodies!" << endl;
 }

  // Wind Dragon
 void AccessSuperPower(int power, bool hotAir){
   Power(power);
   if(hotAir == true){
     cout << "Dragon is capable of crazy hot wind attacks!" << endl;
   }
   else{
     cout << "Dragon is capable of freezing cold wind attacks!" << endl;
   }
 }
};

//Generate random numerical value
int RandomNumberGenerator(int x){ 
  int randomNumber;
  randomNumber = rand() % x;
  return randomNumber;
}

void ClearBadBits(){
  if(cin.fail()){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int main() {
  int n;
  int power;
  int intensity;
  int booleanGenerator;
  bool booleanValue;
  char restart;
  Dragon dragon;

  srand(time(0));

  a:
  
  cout << "\nChoose your Dragon:\n1) Fire Dragon \n2) Water Dragon \n3) Wind Dragon\n";
  cin >> n;
  ClearBadBits();
  
  power = RandomNumberGenerator(100);

  switch(n){
    case 1: intensity = RandomNumberGenerator(100);
            dragon.AccessSuperPower(power, intensity);
            break;
    case 2: dragon.AccessSuperPower(power);
            break;
    case 3: booleanGenerator = RandomNumberGenerator(2);
            booleanValue = booleanGenerator;
            dragon.AccessSuperPower(power, booleanValue);
            break;
    default:  cout << "Please enter a valid choice!" << endl;
              break;
  }

  cout << "\nDo you want to continue? y/n ";
  cin >> restart;
  ClearBadBits();
    if(restart == 'y' || restart == 'Y')
    {
      goto a;
    }
    else
    {
      cout << "Thanks for playing!\n";
    }
  
  return 0;
}