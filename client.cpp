#include <iostream>
#include <fstream>
#include <sstream>

#include "moviedb.h"
#include "movieentry.h"

int main()
{
	MovieDB moviedb;

	// Initialize ifstream instances to read csv files
	std::string small_set = "movies_unique.csv";

	std::ifstream small_set_fin{small_set, std::ios::in};
	//std::ifstream large_get_fin{large_set, std::ios::in};

	// Store values from CSV
	std::string row;
	std::string id;
	std::string title;
	std::string genre;
	std::string release_year;
	std::string content_rating;
	std::string tagline;
	std::string director;

	// Ignore header
	std::getline(small_set_fin, row);

	// Read the csv files
	while (std::getline(small_set_fin, row))
	{
		// Convert row to stringstream since getline doens't accept
		// std::string as input.
		std::istringstream iss(row);

		std::getline(iss, id, ',');
		std::getline(iss, title, ',');
		std::getline(iss, genre, ',');
		std::getline(iss, release_year, ',');
		std::getline(iss, content_rating, ',');
		std::getline(iss, tagline, ',');
		// Remove the end of last record symbol
		std::getline(iss, director, '\r');

		MovieEntry movie;

		movie.setContentRating(content_rating);
		movie.setDirector(director);
		movie.setGenre(genre);
		movie.setId(std::stol(id));
		movie.setTagline(tagline);
		movie.setTitle(title);
		movie.setYear(std::stoi(release_year));

		moviedb.put(movie);
	}

	// (3) Check get() function with user input
	std::cout << "Enter movie's title to find: (Enter q to exit)" << std::endl;
	while (std::getline(std::cin, title))
	{
		if (title == "q")
			break;

		MovieEntry *movie = moviedb.get(title);

		if (movie == nullptr)
			std::cout << "NOT FOUND!" << std::endl;
		else
		{
			std::cout << "ID :" << movie->getId() << std::endl;
			std::cout << "Title :" << movie->getTitle() << std::endl;
			std::cout << "Genre :" << movie->getGenre() << std::endl;
			std::cout << "Content Rating :" << movie->getContentRating() << std::endl;
			std::cout << "Tagline :" << movie->getTagline() << std::endl;
			std::cout << "Director :" << movie->getDirector() << std::endl;
			std::cout << "Release Year :" << movie->getYear() << std::endl;
		}

		std::cout << std::endl;
	}

	// (4) Check remove() function with user input
	std::cout << "Enter movie's title to delete: (Enter q to exit)" << std::endl;
	while (std::getline(std::cin, title))
	{
		if (title == "q")
			break;

		MovieEntry *movie = moviedb.get(title);

		if (movie == nullptr)
		{
			std::cout << "NOT FOUND!" << std::endl;
		}
		else
		{
			moviedb.remove(movie->getTitle());
			std::cout << "SUCCESS!" << std::endl;
		}

		std::cout << std::endl;
	}

	// (5) Check get() function with user input after deletion
	std::cout << "Enter movie's title to find: (Enter q to exit)" << std::endl;
	while (std::getline(std::cin, title))
	{
		if (title == "q")
			break;

		MovieEntry *movie = moviedb.get(title);

		if (movie == nullptr)
			std::cout << "NOT FOUND!" << std::endl;
		else
		{
			std::cout << "ID :" << movie->getId() << std::endl;
			std::cout << "Title :" << movie->getTitle() << std::endl;
			std::cout << "Genre :" << movie->getGenre() << std::endl;
			std::cout << "Content Rating :" << movie->getContentRating() << std::endl;
			std::cout << "Tagline :" << movie->getTagline() << std::endl;
			std::cout << "Director :" << movie->getDirector() << std::endl;
			std::cout << "Release Year :" << movie->getYear() << std::endl;

			// Deacllocate movie entry object
			delete movie;
		}

		std::cout << std::endl;
	}

	return 0;
}
