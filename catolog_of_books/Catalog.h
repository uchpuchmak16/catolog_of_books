#pragma once
#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <vector>

struct Book {
    std::string id;
    std::string author;
    std::string title;
    int pages;

    Book(const std::string& id, const std::string& author, const std::string& title, int pages)
        : id(id), author(author), title(title), pages(pages) {
    }
};

std::vector<Book> readBooksFromFile(const std::string& filename);
void addBook(const std::string& filename, const Book& book);
void showAllBooks(const std::string& filename);
void deleteBook(const std::string& filename, const std::string& bookId);
void searchBook(const std::string& filename, const std::string& searchTerm);
void editBook(const std::string& filename, const std::string& bookId, const std::string& newTitle, int newPages);

#endif

