//
//  main.cpp
//  Book depot
//
//  Created by Jarred Harkness on 12/15/20.
//

#include <iostream>
#include "Repo.h"
//using std::endl;

int main()
{
    //The long strings to parse//
    const string bookData[] =
    {
        "NX_1,Book Title 1,Author 1,23.4,33.3,99.43,NONFICITON",
        "Fx0_F2,Useless title,Useless Author,32.45,23.13,45.24,FICTION",
        "UXU1x,Another dumb book,Another dumb Author,43.2,200,34.23,UNDECIDED",
        "F3-F,I'm over this book,And this author,86.56,24.45,12.32,FICTION",
        "N_W1,An agnoizing death,David Bishopp,99.99,87.90,56.79,NONFICTION"
    };
    
    const int numBooks = 5;//Too Bad arrays don't record their own size. There are 5 books.
    Repo repo;//This createes th repo using the derfault parameterless consturctor
    
    for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
    cout << "Displaying all books: " << std::endl;
    repo.printAll();
    cout << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by book type: " << bookTypeStrings[i] << std::endl;
        repo.printByBookType((BookType)i); //cast the integer to a BookType
    }
    
    cout << "Displaying books with invalid IDs" << std::endl;
    repo.printInvalidIDs();
    cout << std::endl;
    
    cout << "Displaying average prices: " << std::endl;
    repo.printAveragePrices();
    
    cout << "Removing book with ID N_W1:" << std::endl;
    repo.removeBookByID("N_W1"); //This method does it's own output
    cout << std::endl;
    
    cout << "Removing book with ID N_W1:" << std::endl;
    repo.removeBookByID("N_W1"); //second time to show it has been removed
    cout << std::endl;

    system("pause");
    return 0;
}

