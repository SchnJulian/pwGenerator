#ifndef PASSWORD_H
#define PASSWORD_H
#include <stdio.h>
#include <QDebug>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "infint.h"

#define minute 60
#define hour 3600
#define day 86400
#define week 604800
#define month 2592000
#define year 31536000
#define decade 315360000
#define century 3153600000
#define millenium 31536000000

class Password {
 public:
  Password();
  std::string getPassword();
  void setPassword(std::string pw);
  void generatePassword(
      int param);  // PARAM definiert, welcher Pool genutzt wird
  void setLength();
  int getLength();
  void addToPool(std::vector<char> a);
  void removeFromPool(std::vector<char> r);
  void resetPool();
  bool isPoolEmpty();
  int getCharacters();
  std::string timeUnit(InfInt seconds);
  bool databaseCheck();

 private:
  std::string password;
  std::vector<char> pool;
  void removeCharsFromString(std::string& str, char* charsToRemove);

  int length;
};

#endif  // PASSWORD_H
