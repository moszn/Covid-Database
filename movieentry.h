#ifndef _MOVIE_ENTRY_H
#define _MOVIE_ENTRY_H

#include <string>

class MovieEntry
{
private:
    std::string title;
    std::string genre;
    std::string contentRating;
    std::string tagline;
    std::string director;
    long id;
    int release_year;

public:
    void setTitle(std::string t);
    void setGenre(std::string g);
    void setContentRating(std::string rate);
    void setTagline(std::string tline);
    void setDirector(std::string dir);
    void setId(long id);
    void setYear(int year);
    std::string getTitle() const;
    std::string getGenre() const;
    std::string getContentRating() const;
    std::string getTagline() const;
    std::string getDirector() const;
    long getId() const;
    int getYear() const;
};

#endif