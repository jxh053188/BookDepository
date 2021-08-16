//
//  book.h
//  Book depot
//
//  Created by Jarred Harkness on 12/15/20.
//

#ifndef Book_h
#define Book_h
#pragma once
#include <iostream>
#include <iomanip>
#include "BookType.h"
using std::string;
using std::cout;
//using std::endl;

class Book
{
public:
    const static int priceArraySize = 3;
private:
    string bookID;
    string title;
    string author;
    double prices[priceArraySize];
    BookType bookType;
public:
    Book(); //parrameterless constructor
    Book(string bookID, string title, string author, double prices[], BookType booktype); //Full constructor
    ~Book();//destructor
    
    //getters aka accessors
    string getID();
    string getTitle();
    string getAuthor();
    double* getPrices();
    BookType getBookType();
    
    //setters aka mutators
    void setID(string ID);
    void setTitle(string title);
    void setAuthor(string author);
    void setPrices(double prices[]);
    void setBookType(BookType bt);
    
    static void printHeader();//displays a header for the data to follow
    
    void print();//displays 'this' book's data     this is for student.h in assignment
};

#endif /* Book_h */
