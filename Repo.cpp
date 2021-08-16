//
//  repo.cpp
//  Book depot
//
//  Created by Jarred Harkness on 12/15/20.
//

#include "Repo.h"

void Repo::parse(string bookdata)//parses out each row one at a time
{
    BookType bt = UNDECIDED; //default value
    if (bookdata.at(0) == 'F') bt = FICTION;//Looks for first character in book type
    else if (bookdata.at(0) == 'N') bt = NONFICTION;
    
    int rhs = bookdata.find(",");//find the comma
    string bID = bookdata.substr(0, rhs); //extract the substring in front of the comma
    
    int lhs = rhs + 1; //move past the previous comma
    rhs = bookdata.find(",", lhs);
    string ttl = bookdata.substr(lhs, rhs - lhs); //book title
    
    lhs = rhs + 1; //keep going
    rhs = bookdata.find(",", lhs);
    string aut = bookdata.substr(lhs, rhs - lhs);//book author
    
    lhs = rhs + 1;//keep going again
    rhs = bookdata.find(",", lhs);
    double p1 = stod(bookdata.substr(lhs, rhs - lhs));  //first price convert to double
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p2 = stod(bookdata.substr(lhs, rhs - lhs));//second price
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p3 = stod(bookdata.substr(lhs, rhs - lhs));//third price
    
    // already found booktype above
    
    add(bID, ttl, aut, p1, p2, p3, bt);//prices go seperately creates and object.
        
}

//the add method - it only does one thing.
void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, BookType bt)
{
 //put prices into an array for constuctor
    double parr[3] = {price1, price2, price3};
    //Make new book object. Remember that last index starts at -1 and not 0
    bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt); //use full constructor
}

//display all books using tab-seperated output

void Repo::printAll()
{
    Book::printHeader();//quick way to do this part
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        cout << bookRepoArray[i]->getID(); cout << '\t';
        cout << bookRepoArray[i]->getTitle(); cout << '\t';
        cout << bookRepoArray[i]->getAuthor(); cout << '\t';
        cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
        cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
    }
}
//display only books which match given book type
 void Repo::printByBookType(BookType bt)
    {
        Book::printHeader();
        for (int i = 0; i <= Repo::lastIndex; i++){
            if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
        }
        cout << std::endl;
    }
    
//each book ID must contain _ X or x
 void Repo::printInvalidIDs()
    {
        bool any = false; //assume all correct
        for (int i = 0; i <= Repo::lastIndex; i++)
        {
            string bID = (bookRepoArray[i]->getID());
            if (bID.find('_') == string::npos || (bID.find('X') == string::npos && bID.find('x') == string::npos))
            {
        any = true;
        cout << bID << ":" << bookRepoArray[i]->getTitle() << std::endl;
            }
        }
        if (!any) cout << "NONE" << std::endl;
    }
    
//print average prices
void Repo::printAveragePrices()
{
    for (int i = 0; i <= Repo::lastIndex; i++){
        cout << bookRepoArray[i]->getID() << ": ";
        cout << (bookRepoArray[i]->getPrices()[0] + bookRepoArray[i]->getPrices()[1] + bookRepoArray[i]->getPrices()[2]) / 3.0 << std::endl;
    }
    cout <<std::endl;
}

//Remove Book ID

void Repo::removeBookByID(string bookID)//book to be removed comes in parametere
{
    bool success = false;//assume not there
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        if(bookRepoArray[i]->getID() == bookID)
        {
            success = true; //book found
            if( i < numBooks - 1)
            {
                Book* temp = bookRepoArray[i];//swap with last book
                bookRepoArray[i] = bookRepoArray[numBooks - 1];
                bookRepoArray[numBooks - 1] = temp;
            }
            Repo::lastIndex--;//Last book no longer visable but it is not deleted. It is only hidden.
            //book is effectively deleated but data is still available
        }
    }
    if (success)
    {
        cout << bookID << " removed from repository." << std::endl << std::endl;
        this->printAll();//display the books w/o the removed one
    }
    else cout << bookID << " not found." << std::endl << std::endl;
    
}

Repo::~Repo()
{
    cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
    for (int i = 0; i < numBooks; i++)
    {
        cout << "Destorying book #" << i + 1 << std::endl;
        delete bookRepoArray[i];
        bookRepoArray[i] = nullptr;
    }
}
