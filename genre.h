#ifndef __GENRE_H
#define __GENRE_H

class Genre {
  public:
    Genre(std::string genre);
    std::string to_string();
  private:
    std::string _genre;
};
#endif
