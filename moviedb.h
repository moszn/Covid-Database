#ifndef _MOVIE_DB_H
#define _MOVIE_DB_H

#include <iostream>
#include "movieentry.h"

class MovieDB
{
public:
    /**
     * @brief Default constructor
     */
    MovieDB();

    /**
     * @brief Destructor
     */
    ~MovieDB();

    /**
     * @brief Inserts a movie into a hash table if it does not exist. It returns true if insertion is successful and false otherwise.
     * 
     * @param m Movie object to insert
     */
    bool put(const MovieEntry &m);

    /**
     * @brief Retrieves a movie (MovieEntry) with the specified title. It returns NULL if no such a movie exists.
     * 
     * @param title String-typed title representing a movie object.
     */
    MovieEntry *get(const std::string &title);

    /**
     * @brief Removes the movie with the specified title and deallocate dynamic memory used by the MovieEntry object.
     * 
     * @param title String-typed title representing a movie object.
     */
    void remove(const std::string &title);

private:
    // Private methods and data members should go here
    struct Node
    {
        MovieEntry *movie_record;
        Node *next;
    };

    /**
     * @brief Stores the hasing table as an array of linked-lists
     * 
     * @example 
     * 
     * MovieDB: {
     *  0: "ABC",
     *  1: "AAB" -> "AAC",
     *  2: "",
     *  3: "CAB" -> "BAC" -> "ACB"
     * }
     */
    Node **table;

    int table_size = 17;
    int min_size = 7;
    float upper_load_factor = 0.7; // rehash
    float lower_load_factor = 0.2; // shrink
    int element_size = 0;

    /**
     * @brief Hashes a movie’s title into an entry in the hash table
     * 
     * @param s String-typed title representing a movie object.
     */
    int hash(std::string s);

    /**
     * @brief Rehashes the movie database into a new larger table when the size exceeds the upper_load_factor.
     */
    void rehash();

    /**
     * @brief Shrinks the movie database into a new smaller table when the size exceeds the lower_load_factor.
     */
    void shrink();
};

#endif