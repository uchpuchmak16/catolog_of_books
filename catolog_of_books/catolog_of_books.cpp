#include <iostream>
#include <fstream>
#include "Catalog.h"




void addBook(const std::string& filename, const Book& book) {
    if (book.id.empty()) {
        std::cout << "Failed to add book: empty ID provided." << std::endl;
        return;
    }

    std::ofstream file(filename, std::ios_base::app);

    if (file.is_open()) {
        file << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
        file.close();
        std::cout << "Book added successfully!" << std::endl;
    }
    else {
        std::cout << "Failed to add book." << std::endl;
    }
}

void deleteBook(const std::string& filename, const std::string& bookId) {
    std::vector<Book> books = readBooksFromFile(filename);
    std::ofstream file(filename);

    if (file.is_open()) {
        bool bookDeleted = false;
        for (const auto& book : books) {
            if (book.id != bookId) {
                file << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
            }
            else {
                bookDeleted = true;
            }
        }
        file.close();

        if (bookDeleted) {
            std::cout << "Book deleted successfully!" << std::endl;
        }
        else {
            std::cout << "Book with ID '" << bookId << "' not found for deletion." << std::endl;
        }
    }
    else {
        std::cout << "Failed to delete book." << std::endl;
    }
}

void editBook(const std::string& filename, const std::string& bookId, const std::string& newTitle, int newPages) {
    std::vector<Book> books = readBooksFromFile(filename);
    std::ofstream file(filename);

    if (file.is_open()) {
        bool bookEdited = false;
        for (auto& book : books) {
            if (book.id == bookId) {
                book.title = newTitle;
                book.pages = newPages;
                bookEdited = true;
            }
            file << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
        }
        file.close();

        if (bookEdited) {
            std::cout << "Book edited successfully!" << std::endl;
        }
        else {
            std::cout << "Book with ID '" << bookId << "' not found for editing." << std::endl;
        }
    }
    else {
        std::cout << "Failed to edit book." << std::endl;
    }
}

