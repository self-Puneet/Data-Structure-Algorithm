// Library Book Arrangement: You are in charge of organizing a collection of books in a library. Write a program that alphabetically sorts the titles of 20 books using the bubble sort algorithm. After sorting, display the sorted list of book titles and their authors.

#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        string title;
        string author;

        Book () {
            title = "";
            author = "";
        }

        Book (string title_, string author_) {
            title = title_;
            author = author_;
        }
};

class LibraryArrangement {
    public: 
        Book books[20];  

        LibraryArrangement (string titles[], string authors[]) {

            for (int i = 0; i < 20; i++) {
                books[i] = Book(titles[i], authors[i]);
            }
        }

        void bubbleSort () {
            for (int i = 19; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (books[j].title > books[j+1].title) {
                        Book temp = books[j];
                        books[j] = books[j+1];
                        books[j+1] = temp; 
                    }
                }
            }
            cout << "Your array of books is sorted." << endl;
        }

        void display () {
            cout << books[0].title<< endl;
            for (int i = 0; i < 20; i++) {
                cout << "\n\t" << books[i].title << "\t" << books[i].author;
            }
        }
};

int main() {
    
    string titles[20] = {
        "The Great Gatsby", "1984", "To Kill a Mockingbird", "The Catcher in the Rye", 
        "Pride and Prejudice", "The Hobbit", "Moby-Dick", "War and Peace", 
        "Jane Eyre", "The Odyssey", "Crime and Punishment", "The Brothers Karamazov", 
        "Brave New World", "Wuthering Heights", "Frankenstein", "Great Expectations", 
        "The Divine Comedy", "Dracula", "The Iliad", "Les Miserables"
    };
    string authors[20] = {
        "F. Scott Fitzgerald", "George Orwell", "Harper Lee", "J.D. Salinger", 
        "Jane Austen", "J.R.R. Tolkien", "Herman Melville", "Leo Tolstoy", 
        "Charlotte Bronte", "Homer", "Fyodor Dostoevsky", "Fyodor Dostoevsky", 
        "Aldous Huxley", "Emily Bronte", "Mary Shelley", "Charles Dickens", 
        "Dante Alighieri", "Bram Stoker", "Homer", "Victor Hugo"
    };

    LibraryArrangement obj(titles, authors);
    obj.display();
    obj.bubbleSort();
    obj.display();
    return 0;
}