#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <ctime>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    bool is_available;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), is_available(true) {}
};

class Borrower {
public:
    string name;
    unordered_map<string, time_t> borrowed_books;  // book ISBN and borrow time

    Borrower(string n) : name(n) {}
};

vector<Book> books;
vector<Borrower> borrowers;

void add_book() {
    string title, author, isbn;
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, isbn);

    books.push_back(Book(title, author, isbn));
    cout << "Book added successfully!" << endl;
}

void view_books() {
    for (const auto& book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
        cout << ", Status: " << (book.is_available ? "Available" : "Checked out") << endl;
    }
}

void search_books() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    getline(cin, query);

    for (const auto& book : books) {
        if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.isbn.find(query) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
            cout << ", Status: " << (book.is_available ? "Available" : "Checked out") << endl;
        }
    }
}

void checkout_book() {
    string isbn, borrower_name;
    cout << "Enter ISBN of the book to check out: ";
    getline(cin, isbn);
    cout << "Enter borrower's name: ";
    getline(cin, borrower_name);

    auto book_it = find_if(books.begin(), books.end(), [&](const Book& book) { return book.isbn == isbn; });
    if (book_it == books.end() || !book_it->is_available) {
        cout << "Book not available for checkout." << endl;
        return;
    }

    auto borrower_it = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& borrower) { return borrower.name == borrower_name; });
    if (borrower_it == borrowers.end()) {
        borrowers.push_back(Borrower(borrower_name));
        borrower_it = borrowers.end() - 1;
    }

    book_it->is_available = false;
    borrower_it->borrowed_books[isbn] = time(0);
    cout << "Book checked out successfully!" << endl;
}

void return_book() {
    string isbn, borrower_name;
    cout << "Enter ISBN of the book to return: ";
    getline(cin, isbn);
    cout << "Enter borrower's name: ";
    getline(cin, borrower_name);

    auto book_it = find_if(books.begin(), books.end(), [&](const Book& book) { return book.isbn == isbn; });
    if (book_it == books.end() || book_it->is_available) {
        cout << "Invalid book return." << endl;
        return;
    }

    auto borrower_it = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& borrower) { return borrower.name == borrower_name; });
    if (borrower_it == borrowers.end() || borrower_it->borrowed_books.find(isbn) == borrower_it->borrowed_books.end()) {
        cout << "Invalid borrower." << endl;
        return;
    }

    book_it->is_available = true;
    borrower_it->borrowed_books.erase(isbn);
    cout << "Book returned successfully!" << endl;
}

void calculate_fine() {
    string borrower_name;
    cout << "Enter borrower's name: ";
    getline(cin, borrower_name);

    auto borrower_it = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& borrower) { return borrower.name == borrower_name; });
    if (borrower_it == borrowers.end()) {
        cout << "Borrower not found." << endl;
        return;
    }

    time_t now = time(0);
    double total_fine = 0.0;
    const double fine_per_day = 2.0;

    for (const auto& [isbn, borrow_time] : borrower_it->borrowed_books) {
        double overdue_days = difftime(now, borrow_time) / (60 * 60 * 24) - 14;  // Assuming 14 days loan period
        if (overdue_days > 0) {
            total_fine += overdue_days * fine_per_day;
        }
    }

    cout << "Total fine for " << borrower_name << " is: " << total_fine << endl;
}

void show_menu() {
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Search Books" << endl;
    cout << "4. Checkout Book" << endl;
    cout << "5. Return Book" << endl;
    cout << "6. Calculate Fine" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int choice;
    while (true) {
        show_menu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore();  // To clear the input buffer

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                search_books();
                break;
            case 4:
                checkout_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                calculate_fine();
                break;
            case 7:
                cout << "Exiting the Library Management System." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

