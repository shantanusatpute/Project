#include <bits/stdc++.h> 

using namespace std;

class Node {
public:
    virtual ~Node() {} //When a class has a virtual destructor, it allows objects of derived classes to be correctly destroyed through a pointer to the base class.
};

class Student : public Node {
public:
    std::string name;
    int id_no;
    std::string Stream;
    std::string book1, book2;
    int book_no, issuedbook;

public:
    Student(std::string name, int id_no, std::string Stream)
    {
        this->name = name;
        this->id_no = id_no;
        this->Stream = Stream;
    }
};

class library_management {
public:
    Node* root;

    library_management() : root(nullptr) {} //constructor for the library_management class. It initializes the root member variable of the library_management class to nullptr.
    vector<string> books;
    int bookCount;

    void insert(Node* newNode) {
        if (root == nullptr) {
            root = newNode;
        }
        else {
            cout << "Cannot insert more than one student in this version." << endl;
        }
    }

    bool containsNode(const string& name) {
        return searchStudent(root, name) != nullptr;
    }

    Student* searchStudent(Node* current, const string& name) {
        if (current == nullptr) {
            return nullptr;
        }
        if (Student* student = dynamic_cast<Student*>(current)) {
            if (student->name == name) {
                return student;
            }
        }
        return nullptr;
    }

    void remove(const string& name) {
        if (containsNode(name)) {
            delete root;
            root = nullptr;
        }
        else {
            cout << "Student not found in the library." << endl;
        }
    }

    void display(Student** students, int& count) { //pointer to a pointer of type Student
        if (root != nullptr) {
            Student* student = dynamic_cast<Student*>(root);
            students[count++] = student;
        }
    }

    void issueBook() {
        string name;
        cout << "Enter the name of the student: ";
        cin.ignore(); //called to clear the input buffer before reading a new line of input
        getline(cin, name); //used to read a line of text from the user's input and store it in the variable name

        Student* current = searchStudent(root, name);
        if (current != nullptr) {
            cout << "Book issued to student: " << current->name << endl;
        }
        else {
            cout << "Student not found in the library." << endl;
        }
    }
    
    void addBook(const std::string& book) 
    {
        books.push_back(book);
        bookCount++;
        std::cout << "Book added: " << book << std::endl;
    }
    
    void removeBook(const std::string& book) 
    {
        auto it = std::find(books.begin(), books.end(), book);
        if (it != books.end()) 
        {
            books.erase(it);
            bookCount--;
            std::cout << "Book removed: " << book << std::endl;
        } 
        else 
        {
            std::cout << "Book not found in the library." << std::endl;
        }
    }
    
    void displayBooks() 
    {
        if (bookCount > 0) {
            std::cout << "\n------- Books in the Library -------" << std::endl;
            for (const auto& book : books) {
                std::cout << "Book: " << book << std::endl;
            }
        } else {
            std::cout << "No books in the library." << std::endl;
        }
    }
    

    void returnBook() {
        string name;
        cout << "Enter the name of the student: ";
        cin.ignore();
        getline(cin, name);

        Student* current = searchStudent(root, name);
        if (current != nullptr) {
            cout << "Book returned by student: " << current->name << endl;
        }
        else {
            cout << "Student not found in the library." << endl;
        }
    }
};

int main() {
    library_management lib;

    while (true) {
        cout << "\n------- Library Management System -------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Issue Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Add Books" << endl;
        cout << "8. Remove Books" << endl;
        cout << "9. Display Books" << endl;
        cout << "10. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, stream;
            int id;
            cout << "Enter the name of the student: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the ID of the student: ";
            cin >> id;
            cout << "Enter the stream of the student: ";
            cin.ignore();
            getline(cin, stream);
            Student* newStudent = new Student(name, id, stream);
            lib.insert(newStudent);
            break;
        }
        case 2: {
            string name;
            cout << "Enter the name of the student to be removed: ";
            cin.ignore();
            getline(cin, name);
            if (lib.containsNode(name)) {
                lib.remove(name);
                cout << "Student removed successfully." << endl;
            }
            else {
                cout << "Student not found in the library." << endl;
            }
            break;
        }
        case 3: {
            string name;
            cout << "Enter the name of the student to be searched: ";
            cin.ignore();
            getline(cin, name);
            if (lib.containsNode(name)) {
                cout << "Student found in the library." << endl;
            }
            else {
                cout << "Student not found in the library." << endl;
            }
            break;
        }
        case 4: {
            Student* students[100];
            int count = 0;
            lib.display(students, count);
            if (count > 0) {
                cout << "\n------- Students in the Library -------" << endl;
                for (int i = 0; i < count; i++) {
                    cout << "Name: " << students[i]->name << endl;
                    cout << "ID: " << students[i]->id_no << endl;
                    cout << "Stream: " << students[i]->Stream << endl;
                    cout << "-------------------------------" << endl;
                }
            }
            else {
                cout << "No students in the library." << endl;
            }
            break;
        }
        case 5:
            lib.issueBook();
            break;
        case 6:
            lib.returnBook();
            break;
        case 7: 
        {
            std::string book;
            std::cout << "Enter the name of the book: ";
            std::cin.ignore();
            getline(std::cin, book);
            lib.addBook(book);
            break;
        }
        case 8: 
        {
            std::string book;
            std::cout << "Enter the name of the book to be removed: ";
            std::cin.ignore();
            getline(std::cin, book);
            lib.removeBook(book);
            break;
        }
        case 9:
            lib.displayBooks();
            break;
        case 10:
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 10." << endl;
        }
    }

    return 0;
}
