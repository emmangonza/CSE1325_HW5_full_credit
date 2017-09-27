#ifndef __LIBRARY_H
#define __LIBRARY_H

class Library {
  public:
    void add_publication(Publication pub);
    void check_out(int publication_index, std::string patron_name,
                    std::string patron_phone);
    void check_in(int publication_index);
    std::string publication_to_string(int publication_index);
    int number_of_publications();

  private:
    std::vector<Publication> publications;
};
#endif
