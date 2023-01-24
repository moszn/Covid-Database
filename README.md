# Movie-Database

This is a C++ implementation of a hash table based movie database that stores movie records. Each movie record contains the following properties:

Title
Genre
Content rating
Tagline
Director
ID
Release year
# Getting Started

To use this implementation, you will need to have a working C++ development environment and a CSV file containing movie records. The sample file movies_unique.csv is provided for testing.

# Prerequisites
C++ compiler (e.g. g++, clang++)
CSV file containing movie records (e.g. movies_unique.csv)
Make tool
# Installing
Clone the repository to your local machine
1. git clone https://github.com/username/Movie-database.git
Change directory to the cloned repository
2. cd movie-database
Build the project using the provided Makefile
3. make
# Running the tests
To test the implementation, you can run the compiled binary and provide the path to your CSV file as an argument
./client movies_unique.csv
# Built With

C++ - The programming language used
Make - Build automation tool
# Authors 
Richard Nguyen and Mohamed Mohamed

# Note

Instead of compiling the project manually, you can use the provided Makefile to automate the process by simply running the command make. The Makefile handles the compilation and linking of the source files. Additionally, you can use make clean to remove the object files and the binary.
