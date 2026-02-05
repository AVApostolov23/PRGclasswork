#include "library.h"
#include <iostream>
using namespace std;

Book createBook(const string& title, const string& author, int year, double price) {
    return { title, author, year, price };
}

void printBook(const Book& book) {
    cout << "Title: " << book.title
        << " | Author: " << book.author
        << " | Year: " << book.year
        << " | Price: " << book.price << endl;
}

void printLibrary(const Library& library) {
    cout << "Library Name: " << library.name << endl;

    if (library.count == 0 || library.books == nullptr) {
        cout << "Library is empty." << endl;
        return;
    }

    // Iterate using the count
    for (int i = 0; i < library.count; ++i) {
        printBook(library.books[i]);
    }
}

double averageBookPrice(const Library& library) {
    if (library.count == 0) return 0.0;

    double total = 0;
    for (int i = 0; i < library.count; ++i) {
        total += library.books[i].price;
    }
    return total / library.count;
}

Book oldestBookInLibrary(const Library& library) {
    if (library.count == 0) return { "", "", 0, 0.0 };

    // Use a pointer to track the current oldest
    Book* oldest = &library.books[0];

    for (int i = 1; i < library.count; ++i) {
        if (library.books[i].year < oldest->year) {
            oldest = &library.books[i];
        }
    }
    return *oldest;
}