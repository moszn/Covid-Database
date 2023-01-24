#include <string>

#include "movieentry.h"

void MovieEntry::setTitle(std::string t)
{
  this->title = t;
}

void MovieEntry::setGenre(std::string g)
{
  this->genre = g;
}

void MovieEntry::setContentRating(std::string rate)
{
  this->contentRating = rate;
}

void MovieEntry::setTagline(std::string tline)
{
  this->tagline = tline;
}

void MovieEntry::setDirector(std::string dir)
{
  this->director = dir;
}

void MovieEntry::setId(long id)
{
  this->id = id;
}

void MovieEntry::setYear(int year)
{
  this->release_year = year;
}
std::string MovieEntry::getTitle() const
{
  return this->title;
}
std::string MovieEntry::getGenre() const
{
  return this->genre;
}
std::string MovieEntry::getContentRating() const
{
  return this->contentRating;
}
std::string MovieEntry::getTagline() const
{
  return this->tagline;
}

std::string MovieEntry::getDirector() const
{
  return this->director;
}
long MovieEntry::getId() const
{
  return this->id;
}

int MovieEntry::getYear() const
{
  return this->release_year;
}
