#ifndef __AGE_H
#define __AGE_H

class Age {
  public:
    Age(std::string age);
    std::string to_string();
  private:
    std::string _age;
};
#endif
