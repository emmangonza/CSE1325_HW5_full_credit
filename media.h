#ifndef __MEDIA_H
#define __MEDIA_H

class Media {
  public:
    Media(std::string media);
    std::string to_string();
  private:
    std::string _media;
};
#endif
