#include "Catalog.h"
#include <iostream>
#include <fstream>

void editBook(const std::string& filename, const std::string& bookId, const std::string& newTitle, int newPages) {
    std::vector<Book> books = readBooksFromFile(filename);
    std::ofstream file(filename);

    if (file.is_open()) {
        for (auto& book : books) {
            if (book.id == bookId) {
                book.title = newTitle;
                book.pages = newPages;
            }
            file << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
        }
        file.close();
        std::cout << "Book edited successfully!" << std::endl;
    }
    else {
        std::cout << "Failed to edit book." << std::endl;
    }
}
int main() {
    std::string filename = "books.txt";
    
    // Примеры использования функций
    //addBook(filename, { "0004", "J.K. Rowling", "Harry Potter", 432 });
    showAllBooks(filename);
    deleteBook(filename, "0002");
    searchBook(filename, "Rowling");
    editBook(filename, "0001", "Eugene Onegin", 162);

    return 0;
}
