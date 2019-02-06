#ifndef PASSWORD_H
#define PASSWORD_H
#include <string>
#include <vector>


class Password
{

public:
  Password();
  std::string getPassword();
  bool setPassword(std::string pw);
  void generatePassword(int param); // PARAM definiert, welcher Pool genutzt wird
  void setLength();
  int getLength();
  void addToPool(std::vector<char> a);
void removeFromPool(std::vector<char> r);
void resetPool();
  bool isPoolEmpty();

private:
  std::string password;
  std::vector<char> pool;
  void removeCharsFromString( std::string &str, char* charsToRemove );

  int length;
};

#endif // PASSWORD_H
