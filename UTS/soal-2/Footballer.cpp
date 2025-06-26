#include "Footballer.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
Footballer::Footballer() {
    name = "noname";
    playPosition = "none";
    nationality = "Indonesia";
    height= 180;
    weight = 70;
    birthYear = 2000;
  }

Footballer::Footballer(string _name, int _birth, string _playpos, string _nat, int _h, int _w) {
    name = _name;
    playPosition = _playpos;
    nationality = _nat;
    height= _h;
    weight = _w;
    birthYear = _birth;
}

Footballer::Footballer(const Footballer& o){
    name = o.name;
    playPosition = o.playPosition;
    nationality = o.nationality;
    height= o.height;
    weight = o.weight;
    birthYear = o.birthYear;
}

Footballer::~Footballer(){}

Footballer& Footballer::operator=(const Footballer& o) {
    name = o.name;
    playPosition = o.playPosition;
    nationality = o.nationality;
    height= o.height;
    weight = o.weight;
    birthYear = o.birthYear;
    return *this;
}

void Footballer::setName(string n){
    name = n;
  }
string Footballer::getName() const {
    return name;
  }

void Footballer::setPlayPosition(string pp){
    playPosition = pp;
}
string Footballer::getPlayPosition() const {
    return playPosition;
}

void Footballer::setNationality(string n){
    nationality = n;
  }
string Footballer::getNationality() const {
    return nationality;
  }

void Footballer::setHeight(int h){
    height = h;
}
int Footballer::getHeight() const {
    return height;
}
void Footballer::setWeight(int w){
    weight = w;
}
int Footballer::getWeight() const {
    return weight;
}

  // gunakan CURRENT_YEAR untuk menghitung umur
  int Footballer::getAge(){
    return (CURRENT_YEAR - birthYear);
  }

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  double Footballer::getBMI() const {
    double h = static_cast<double>(height) / 100;
    return weight / (h * h);
  }

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  string Footballer::getCategory() const {
    double bmi = getBMI();
    if (bmi < 18.5) {return "Underweight";}
    else if (bmi < 25.0) {return "Normal";}
    else if (bmi < 30.0) {return "Overweight";}
    else {return "Obese";}
  }

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  void Footballer::displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "BMI: " << fixed << setprecision(2) << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
  }

  // int main(){
  //   Footballer x("n", 2000, "y", "x", 179, 60);
  //   // Footballer x;
  //   x.displayInfo();

  //   return 0;
  // }