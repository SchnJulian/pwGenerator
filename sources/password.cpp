#include "password.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>


void Password::resetPool(){
  std::vector<char> temp;
  pool = temp;
}

void Password::removeCharsFromString( std::string &str, char* charsToRemove ) {
  for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
    }
  std::copy(str.begin(), str.end(), std::back_inserter(pool));
}

Password::Password()
{
  std::cout << "nice";
}

void Password::generatePassword(int param){

  password = "";
  char c;


  srand (time(NULL));    // initialize the random number generator
  for (int i = 0; i < param; i++){
      c = pool.at(rand() %pool.size());
      password.append(1,c);
    }
}


std::string Password::getPassword(){
  return password;

}

void Password::setLength(){
  length = static_cast<int>(password.length());
}

int Password::getLength(){
  return length;
}

void Password::addToPool(std::vector<char> a){
  pool.insert(std::end(pool), std::begin(a), std::end(a));
}

void Password::removeFromPool(std::vector<char> r){
  std::sort(r.begin(),r.end());
  std::sort(pool.begin(), pool.end());

  std::ostringstream oss, oss2;

  if(!pool.empty()){
      std::copy(std::begin(pool),std::end(pool)-1, std::ostream_iterator<char>(oss));
      oss << pool.back();
    }
  std::string s = oss.str();

  if(!r.empty()){
      std::copy(std::begin(r),std::end(r)-1, std::ostream_iterator<char>(oss2));
      oss2 << pool.back();
    }
  std::string s2 = oss.str();


  char tab2[1024];
  strncpy(tab2, s2.c_str(), sizeof(tab2));
  tab2[sizeof(tab2) - 1] = 0;

  removeCharsFromString(s,tab2);

}

bool Password::isPoolEmpty(){
  if(pool.empty()){
      return true;
    }else {
      return false;
    }
}




