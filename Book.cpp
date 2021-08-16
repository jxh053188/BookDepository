//
//  book.cpp
//  Book depot
//
//  Created by Jarred Harkness on 12/15/20.
//

#include "Book.h"

Book::Book()//parameterless constructor sets to default values
{
    this->bookID = "";  //Emptystring is something, nullptr is nothing
    this->title = "";
    this->author = "";
    for(int i = 0; i < priceArraySize; i++) this->prices[i] = 0;
    this->bookType = BookType::UNDECIDED;
}

Book::Book(string bookID, string title, string author, double prices[], BookType bookType)
{
    this->bookID =  bookID;
    this->title = title;
    this->author = author;
    for(int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
    this->bookType = bookType;
}

Book::~Book() {} //destructor does nothing - book class creates nothing dynamically

string Book::getID() { return this->bookID; }
string Book::getTitle() { return this->title; }
string Book::getAuthor() { return this->author; }
double* Book::getPrices() { return this->prices; }
BookType Book::getBookType() { return this->bookType; }

void Book::setID(string ID) { this->bookID = ID; }
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) {this->author = author;}
void Book::setPrices(double prices[])//set each price individually
{
    for (int i=0; i < priceArraySize; i++) this->prices[i] = prices[i];
}
void Book::setBookType(BookType bt) { this-> bookType = bt;}

void Book::printHeader()//use to print header
{
    cout << "Output format: ID|Title|Author|Prices|Type\n";
}

void Book::print()
{
    cout << this->getID() << '\t';
    cout << this->getTitle() << '\t';
    cout << this->getAuthor() << '\t';
    cout << this->getPrices()[0] << ',';
    cout << this->getPrices()[1] << ',';
    cout << this->getPrices()[2] << '\t';
    cout << bookTypeStrings[this->getBookType()] << '\n'; //booktype string
}
