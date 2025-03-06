#include "BigNumber.hpp"
#include <iostream>
using namespace std;

const int BigNumber::max_digit = 20;

BigNumber::BigNumber() {
  this->digit = new int[BigNumber::max_digit];
}

BigNumber::BigNumber(int number) {
  this->digit = new int[BigNumber::max_digit];
  for (int i = 0; i < BigNumber::max_digit; i++) {
    this->digit[i] = number % 10;
    number /= 10;
  }
}

BigNumber::BigNumber(string aVeryBigNumber) {
  this->digit = new int[BigNumber::max_digit];
  int strSize = aVeryBigNumber.size();
  for (int i = 0; i < strSize; i++) {
    this->digit[i] = aVeryBigNumber[strSize - 1 - i] - '0';
  }
}

BigNumber::BigNumber(const BigNumber& bn) {
  this->digit = new int[BigNumber::max_digit];
  for (int i = 0; i < BigNumber::max_digit; i++) {
    this->digit[i] = bn[i];
  }
}

int BigNumber::getMaxDigit() {
  return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit) {
  this->digit[i] = digit;
}

int& BigNumber::operator[](int i) {
  return this->digit[i];
}

int BigNumber::operator[](int i) const {
  return this->digit[i];
}

BigNumber::~BigNumber() {
  delete[] this->digit;
}

// hint   : gunakan operator overload [] untuk mengakses digit
// contoh : other[i]
// hint   : untuk this, dapat langsung menggunakan this->digit[i]
bool BigNumber::operator==(const BigNumber& other) {
  for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
    if (this->digit[i] != other[i]){
      return false;
    }
  }
  return true;
}

bool BigNumber::operator<(const BigNumber& other) {
  for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
    if (this->digit[i] < other[i]){
      return true;
    }
  }
  return false;
}

bool BigNumber::operator>(const BigNumber& other) {
  for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
    if (this->digit[i] > other[i]){
      return true;
    }
  }
  return false;
}

BigNumber BigNumber::operator+(const BigNumber& other) {
  BigNumber c;
  // hint: gunakan operator overload [] untuk mengakses dan mengubah digit
  // contoh:
  // - c[i] = this->digit[i]
  // - c[i] = other[i] 
  for (int i = 0; i < BigNumber::getMaxDigit(); i++){
    this->digit[i] = 0;
  }
  int carry = 0;
  for (int i = 0; i < BigNumber::getMaxDigit(); i++) {
    int add = this->digit[i] + other[i];
    if (carry){
      add++;
      carry = 0;
    }
    if (add >= 10){
      c.setDigit(i , add % 10);
      carry = 1;
    }
  }
  return c;
}

// ostream& operator<<(ostream& os, const BigNumber& bn) {
//   bool foundNonZero = false;
//   for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
//     if (bn[i] > 0) {
//       foundNonZero = true;
//     }
//     if (foundNonZero) {
//       os << bn[i];
//     }
//   }
//   if (!foundNonZero) {
//     os << "0";
//   }
//   return os;
// }

// int main() {
//   BigNumber a(123), b("2210");
//   cout << a << endl; // 123
//   cout << b << endl; // 2210
//   cout << (a < b) << endl; // 1
//   cout << (a > b) << endl; // 0
//   cout << (a + b) << endl; // 2333
//   return 0;
// }