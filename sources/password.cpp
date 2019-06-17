#include "password.h"
#include <QDebug>

void Password::resetPool() {
  std::vector<char> temp;
  pool = temp;
}

void Password::removeCharsFromString(std::string& str, char* charsToRemove) {
  for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
    str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
  }
  std::copy(str.begin(), str.end(), std::back_inserter(pool));
}

Password::Password() {
  std::cout << "nice";
}

void Password::generatePassword(int param) {
  if (pool.empty()) {
    qWarning() << "empty";
    return;
  }
  password = "";
  char c;
  qWarning() << param << "(länge)";
  srand(time(NULL));  // initialize the random number generator
  for (int i = 0; i < param; i++) {
    c = pool.at(rand() % pool.size());
    password.append(1, c);
  }
  qWarning() << QString::fromStdString(password);
}

void Password::setPassword(std::string pw) {
  this->password = pw;
}

std::string Password::getPassword() {
  return password;
}

void Password::setLength() {
  length = static_cast<int>(password.length());
}

int Password::getLength() {
  return length;
}

void Password::addToPool(std::vector<char> a) {
  pool.insert(std::end(pool), std::begin(a), std::end(a));
}

void Password::removeFromPool(std::vector<char> r) {
  std::sort(r.begin(), r.end());
  std::sort(pool.begin(), pool.end());

  std::ostringstream oss, oss2;

  if (!pool.empty()) {
    std::copy(std::begin(pool), std::end(pool) - 1,
              std::ostream_iterator<char>(oss));
    oss << pool.back();
  }
  std::string s = oss.str();

  if (!r.empty()) {
    std::copy(std::begin(r), std::end(r) - 1,
              std::ostream_iterator<char>(oss2));
    oss2 << pool.back();
  }
  std::string s2 = oss.str();

  char tab2[1024];
  strncpy(tab2, s2.c_str(), sizeof(tab2));
  tab2[sizeof(tab2) - 1] = 0;

  removeCharsFromString(s, tab2);
}

bool Password::isPoolEmpty() {
  if (pool.empty()) {
    return true;
  } else {
    return false;
  }
}

int Password::getCharacters() {
  int characters = 0;
  unsigned long length = password.length();
  bool uppercase = false, lowercase = false, number = false, special = false;
  for (int index = 0; index < length; index++) {
    char c = password.at(index);
    if (isalpha(c) && (!lowercase || !uppercase)) {
      if (islower(c) && !lowercase) {
        characters += 26;
        lowercase = true;
      } else if (isupper(c) && !uppercase) {
        characters += 26;
        uppercase = true;
      }
    } else if (!number && isnumber(c)) {
      characters += 10;
      number = true;
    } else if (!special && (!isalpha(c) && !isnumber(c))) {
      characters += 32;
      special = true;
    }
    if (characters >= 94) {
      break;
    }
  }
  return characters;
}

bool Password::databaseCheck() {
  std::ifstream f;
  f.open("/Users/Julian/Workspace/pwGenerator/sources/firstNames.txt",
         std::ios_base::in);
  if (f.good()) {
      std::string s;
      while (std::getline(f, s)) {
        if (s == password) {
          return true;
        }
      }
  }
  f.close();
  return false;
}

std::string Password::timeUnit(InfInt seconds) {
  std::string ret;
  long x;
  if (seconds >= minute) {
    if (seconds >= hour) {
      if (seconds >= day) {
        if (seconds >= week) {
          if (seconds >= month) {
            if (seconds >= year) {
              if (seconds >= decade) {
                if (seconds >= century) {
                  if (seconds >= millenium) {
                    ret.append(" millenium(s)");
                    x = millenium;
                  } else {
                    ret.append(" century(s)");
                    x = century;
                  }
                } else {
                  ret.append(" decade(s)");
                  x = decade;
                }
              } else {
                ret.append(" year(s)");
                x = year;
              }
            } else {
              ret.append(" month(s)");
              x = month;
            }
          } else {
            ret.append(" week(s)");
            x = week;
          }
        } else {
          ret.append(" day(s)");
          x = day;
        }
      } else {
        ret.append(" hour(s)");
        x = hour;
      }
    } else {
      ret.append(" minute(s)");
      x = minute;
    }
  } else {
    ret.append(" seconds");
    x = 1;
  }
  ret.insert(0, (seconds / x).toString());
  return ret;
}
