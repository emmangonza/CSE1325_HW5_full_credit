#ifndef __PUBLICATION_H
#define __PUBLICATION_H

class Publication {
  public:
    Publication(std::string title, std::string author, std::string copyright,
                Genre genre, Media media, Age target_age, std::string isbn);
    void check_out(std::string patron_name, std::string patron_phone);
    void check_in();
    bool is_checked_out();
    std::string to_string();

  private:
    std::string _title;
    std::string _author;
    std::string _copyright;
    Genre _genre;
    Media _media;
    Age _target_age;
    std::string _isbn;
    bool checked_out;
    std::string _patron_name;
    std::string _patron_phone;
};
#endif
