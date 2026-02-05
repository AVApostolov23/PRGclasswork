#include <iostream>
#include "../lib/library.h"
using namespace std;

int main() {
    // 1. Create an array of Books
    // We allocate space for 3 books
    Book myBookCollection[3];

    // 2. Populate the array using createBook
    myBookCollection[0] = createBook("The Hobbit", "J.R.R. Tolkien", 1937, 25.0);
    myBookCollection[1] = createBook("1984", "George Orwell", 1949, 15.0);
    myBookCollection[2] = createBook("C++ Primer", "Stanley Lippman", 2012, 60.0);

    // 3. Initialize the Library struct
    Library myLib;
    myLib.name = "City Central Library";
    myLib.books = myBookCollection; // Point to our array
    myLib.count = 3;                // Set the size

    // 4. Test the functions
    printLibrary(myLib);

    cout << "\nAverage Price: " << averageBookPrice(myLib) << endl;

    Book oldest = oldestBookInLibrary(myLib);
    cout << "Oldest Book: " << oldest.title << " (" << oldest.year << ")" << endl;

    return 0;
}