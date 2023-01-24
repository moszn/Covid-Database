#include "moviedb.h"

MovieDB::MovieDB()
{
    this->table = new Node *[table_size];
    for (int i = 0; i < this->table_size; i++)
    {
        this->table[i] = nullptr;
    }
}

MovieDB::~MovieDB()
{
    for (int i = 0; i < this->table_size; i++)
    {
        while (table[i])
        {
            Node *n = this->table[i];
            this->table[i] = this->table[i]->next;
            delete n;
        }
    }

    delete[] table;
}

bool MovieDB::put(const MovieEntry &m)
{
    // Get the index in the hash table to insert a new movie record
    int index = hash(m.getTitle());

    // Delete these lines if we allow two duplicate titles
    for (Node *curr = this->table[index]; curr != nullptr; curr = curr->next)
    {
        if (curr->movie_record->getTitle() == m.getTitle())
            return false;
    }
    // End delete

    // Create a movie record and update its information
    Node *new_node = new Node;
    new_node->movie_record = new MovieEntry;
    new_node->movie_record->setContentRating(m.getContentRating());
    new_node->movie_record->setDirector(m.getDirector());
    new_node->movie_record->setGenre(m.getGenre());
    new_node->movie_record->setId(m.getId());
    new_node->movie_record->setTagline(m.getTagline());
    new_node->movie_record->setTitle(m.getTitle());
    new_node->movie_record->setYear(m.getYear());

    new_node->next = this->table[index];
    this->table[index] = new_node;

    // Update the total number of elements
    this->element_size++;

    double curr_load_factor = (1.0 * this->element_size) / this->table_size;

    // Rehash the hash table if the load factor exceeds the initial upper load factor.
    if (curr_load_factor > this->upper_load_factor)
        rehash();

    return true;
}

MovieEntry *MovieDB::get(const std::string &title)
{
    {
        // Get tbe index from the title in the hash table
        int index = hash(title);

        // Access the element in the index
        Node *curr = this->table[index];

        // while the
        while (curr != nullptr)
        {
            // Exist the traversing if the record is found
            if (curr->movie_record->getTitle() == title)
                return curr->movie_record;
            curr = curr->next;
        }
        return nullptr;
    }
}

void MovieDB::remove(const std::string &title)
{
    // Get tbe index in the hash table to delete a movie record
    int index = hash(title);

    if (this->table[index]->movie_record->getTitle() == title)
    {
        Node *curr = this->table[index];
        this->table[index] = curr->next;
        delete curr;
        curr = nullptr;
    }
    else
    {
        // Access the element in the index
        Node *curr = this->table[index]->next;
        Node *prev = this->table[index];

        // Traverse the linked list of records if the exists collided records
        while (curr != nullptr)
        {
            // Exist the traversing if the record is found
            if (curr->movie_record->getTitle() == title)
                break;

            // Go to the next element and store the current element
            prev = curr;
            curr = curr->next;
        }

        // The record is successfully found
        if (curr != nullptr)
        {
            prev->next = curr->next;
            delete curr;
            curr = nullptr;
        }
    }

    // Update the total number of elements
    this->element_size--;

    double curr_load_factor = (1.0 * this->element_size) / this->table_size;

    // Shrink the hash table if the load factor overly reduces to the inital lower load factor
    if (curr_load_factor < this->lower_load_factor)
        shrink();
}

int MovieDB::hash(std::string s)
{
    unsigned int sum = 0;

    for (char c : s) // range-based for loop
    {
        sum = (sum * 31 + c) % this->table_size; // m is the hash table size
    }
    return sum;
}

void MovieDB::rehash()
{
    int old_table_size = this->table_size;
    this->table_size = old_table_size << 1;

    std::cout << "Hash table increases from " << old_table_size << " to " << this->table_size << ". " << std::endl;
    Node **new_table = new Node *[this->table_size];
    for (int i = 0; i < this->table_size; ++i)
    {
        new_table[i] = nullptr;
    }

    for (int i = 0; i < old_table_size; ++i)
    {
        Node *node = this->table[i];

        while (node != nullptr)
        {
            Node *tmp = node;
            node = node->next;

            Node *&bucket = new_table[hash(tmp->movie_record->getTitle())];
            tmp->next = bucket;
            bucket = tmp;
        }
    }

    delete[] this->table;
    this->table = new_table;
}

void MovieDB::shrink()
{
    int old_table_size = this->table_size;
    this->table_size = old_table_size >> 1;
    if (table_size < 7)
        table_size = 7;
    std::cout << "Hash table decreases from " << old_table_size << " to " << this->table_size << ". " << std::endl;

    Node **new_table = new Node *[this->table_size];
    for (int i = 0; i < this->table_size; ++i)
    {
        new_table[i] = nullptr;
    }

    for (int i = 0; i < old_table_size; ++i)
    {
        Node *node = this->table[i];

        while (node != nullptr)
        {
            Node *tmp = node;
            node = node->next;

            Node *&bucket = new_table[hash(node->movie_record->getTitle())];
            tmp->next = bucket;
            bucket = tmp;
        }
    }

    delete[] this->table;
    this->table = new_table;
}
