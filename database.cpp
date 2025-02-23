#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    double gpa;
};

std::vector<Student> studentDatabase;

void addStudent() {
    Student newStudent;
    std::cout << "Enter student name: ";
    std::cin >> newStudent.name;
    std::cout << "Enter student age: ";
    std::cin >> newStudent.age;
    std::cout << "Enter student GPA: ";
    std::cin >> newStudent.gpa;

    studentDatabase.push_back(newStudent);
    std::cout << "Student added to the database." << std::endl;
}

void listStudents() {
    if (studentDatabase.empty()) {
        std::cout << "No students in the database." << std::endl;
        return;
    }

    std::cout << "Student List:" << std::endl;
    for (const Student& student : studentDatabase) {
        std::cout << "Name: " << student.name << ", Age: " << student.age << ", GPA: " << student.gpa << std::endl;
    }
}

int main() {
    char choice;

    do {
        std::cout << "\nStudent Database Menu:" << std::endl;
        std::cout << "1. Add Student\n";
        std::cout << "2. List Students\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                listStudents();
                break;
            case '3':
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select again." << std::endl;
        }
    } while (choice != '3');

    return 0;
}
