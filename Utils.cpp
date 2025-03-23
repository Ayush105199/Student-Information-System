#include "Utils.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <algorithm>

void displayMainMenu() {
    std::cout << "Student Management System" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Display All Students" << std::endl;
    std::cout << "3. Clear All Students" << std::endl;
    std::cout << "4. Save Students to File" << std::endl;
    std::cout << "5. Load Students from File" << std::endl;
    std::cout << "6. Search Student by Name" << std::endl;
    std::cout << "7. Filter Students by Course" << std::endl;
    std::cout << "8. Filter Students by Department" << std::endl;
    std::cout << "9. Sort Students by CGPA" << std::endl;
    std::cout << "10. Sort Students by Name" << std::endl;
    std::cout << "11. Delete Student by Roll Number" << std::endl;
    std::cout << "12. Update Student by Roll Number" << std::endl;
    std::cout << "13. Exit" << std::endl;
}

void addStudentPage(StudentManager& manager) {
    std::string name, course, department, phoneNumber, email, parentPhoneNumber, cnicId;
    int rollNumber, age;
    float cgpa;

    std::cout << "Enter student name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;

    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << "Enter course: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, course);

    std::cout << "Enter department: ";
    std::getline(std::cin, department);

    while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        if (isValidPhoneNumber(phoneNumber)) {
            break;
        }
        std::cout << "Invalid phone number! Please enter only digits." << std::endl;
    }

    while (true) {
        std::cout << "Enter email: ";
        std::getline(std::cin, email);
        if (isValidEmail(email)) {
            break;
        }
        std::cout << "Invalid email! Please include '@' in the email." << std::endl;
    }

    std::cout << "Enter parent phone number: ";
    std::getline(std::cin, parentPhoneNumber);

    std::cout << "Enter CGPA: ";
    std::cin >> cgpa;

    std::cout << "Enter CNIC ID: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cnicId);

    if (manager.isDuplicateRollNumber(rollNumber)) {
        std::cout << "Error: A student with this roll number already exists!" << std::endl;
        return;
    }

    manager.addStudent(Student(name, rollNumber, age, course, department, phoneNumber, email, parentPhoneNumber, cgpa, cnicId));
    std::cout << "Student added successfully!" << std::endl;
}

void displayStudentsPage(const StudentManager& manager) {
    std::cout << "List of Students:" << std::endl;
    manager.displayAllStudents();
}

void clearStudentsPage(StudentManager& manager) {
    manager.clearStudents();
}

void saveStudentsPage(StudentManager& manager) {
    std::string filename;
    std::cout << "Enter filename to save: ";
    std::cin >> filename;

    try {
        manager.saveToFile(filename);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void loadStudentsPage(StudentManager& manager) {
    std::string filename;
    std::cout << "Enter filename to load: ";
    std::cin >> filename;

    try {
        manager.loadFromFile(filename);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void searchStudentPage(const StudentManager& manager) {
    std::string name;
    std::cout << "Enter student name to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    manager.searchByName(name);
}

void filterByCoursePage(const StudentManager& manager) {
    std::string course;
    std::cout << "Enter course to filter: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, course);

    manager.filterByCourse(course);
}

void filterByDepartmentPage(const StudentManager& manager) {
    std::string department;
    std::cout << "Enter department to filter: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, department);

    manager.filterByDepartment(department);
}

void sortByCgpaPage(StudentManager& manager) {
    manager.sortByCgpa();
}

void sortByNamePage(StudentManager& manager) {
    manager.sortByName();
}

void deleteStudentPage(StudentManager& manager) {
    int rollNumber;
    std::cout << "Enter roll number of the student to delete: ";
    std::cin >> rollNumber;

    if (manager.deleteStudentByRollNumber(rollNumber)) {
        std::cout << "Student with roll number " << rollNumber << " deleted successfully." << std::endl;
    } else {
        std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
    }
}

void updateStudentPage(StudentManager& manager) {
    int rollNumber;
    std::cout << "Enter roll number of the student to update: ";
    std::cin >> rollNumber;

    std::string name, course, department, phoneNumber, email, parentPhoneNumber, cnicId;
    int age;
    float cgpa;

    std::cout << "Enter updated student name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::cout << "Enter updated age: ";
    std::cin >> age;

    std::cout << "Enter updated course: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, course);

    std::cout << "Enter updated department: ";
    std::getline(std::cin, department);

    while (true) {
        std::cout << "Enter updated phone number: ";
        std::getline(std::cin, phoneNumber);
        if (isValidPhoneNumber(phoneNumber)) {
            break;
        }
        std::cout << "Invalid phone number! Please enter only digits." << std::endl;
    }

    while (true) {
        std::cout << "Enter updated email: ";
        std::getline(std::cin, email);
        if (isValidEmail(email)) {
            break;
        }
        std::cout << "Invalid email! Please include '@' in the email." << std::endl;
    }

    std::cout << "Enter updated parent phone number: ";
    std::getline(std::cin, parentPhoneNumber);

    std::cout << "Enter updated CGPA: ";
    std::cin >> cgpa;

    std::cout << "Enter updated CNIC ID: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cnicId);

    Student updatedStudent(name, rollNumber, age, course, department, phoneNumber, email, parentPhoneNumber, cgpa, cnicId);

    if (manager.updateStudentByRollNumber(rollNumber, updatedStudent)) {
        std::cout << "Student with roll number " << rollNumber << " updated successfully." << std::endl;
    } else {
        std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
    }
}

bool isValidEmail(const std::string& email) {
    return email.find('@') != std::string::npos;
}

bool isValidPhoneNumber(const std::string& phoneNumber) {
    return std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit);
}