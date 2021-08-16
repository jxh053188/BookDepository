//
//  repo.hpp
//  Book depot
//
//  Created by Jarred Harkness on 12/15/20.
//

#ifndef Repo_h
#define Repo_h

#pragma once
#include "Book.h"

class Repo
{
private:
    int lastIndex = -1;
    const static int numBooks = 5;
    Book* bookRepoArray[numBooks]; //NOT declared dynamically
    
public:
    //extracts data from comma delimited strings
    void parse(string row);
    
    //Pass book data to create object
    void add(string bID, string bTitle, string bAuthor, double bprice1, double bprice2, double bprice3,BookType bt);
    
    void printAll();//calls Book class print method
    void printByBookType(BookType bt); //BookType is passed in
    void printInvalidIDs();//each book ID needs an _ or X or x
    void printAveragePrices(); //Prints the average price for each book
    void removeBookByID(string bookID);//Find the book with supplied ID and remove
    ~Repo();
};
#endif /* Repo_h */
