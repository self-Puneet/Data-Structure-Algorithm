// Library Book Arrangement: You are in charge of organizing a collection of books in a library. Write a program that alphabetically sorts the titles of 20 books using the bubble sort algorithm. After sorting, display the sorted list of book titles and their authors.

#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        string title;
        string author;

        Book (string title_, string author_) {
            this.title, this.author = title_, author_;
        }
};

class LibraryArrangement {
    public: 
        Book books[20] = {};  

        LibraryArrangement () {
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

            for (int i = 0; i < 20; i++) {
                this.books[i].title, this.books[i].author = titles[i], authors[i];
            }
        }

        void bubbleSort () {
            for (int i = 19; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (this.books[j].title > this.books[j+1].title) {
                        Book temp = this.books[j];
                        this.books[j] = this.books[j+1];
                        this.books[j+1] = temp; 
                    }
                }
            }
            cout << "Your array of books is sorted." << endl;
        }

        void display () {
            for (int i = 0; i < 20; i++) {
                cout << "/t" << this.books[i].title << "\t" << this.books[i].author << endl;
            }
        }
}