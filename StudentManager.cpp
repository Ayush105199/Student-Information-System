#include "StudentManager.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include<limits>

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students found!" << std::endl;
    } else {
        for (const auto& student : students) {
            student.display();
        }
    }
}

void StudentManager::clearStudents() {
    students.clear();
    std::cout << "All students have been removed." << std::endl;
}

bool StudentManager::isDuplicateRollNumber(int rollNumber) const {
    for (const auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            return true;
        }
    }
    return false;
}

void StudentManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for saving.");
    }

    for (const auto& student : students) {
        file << student.getName() << "," << student.getRollNumber() << "," << student.getAge() << ","
             << student.getCourse() << "," << student.getDepartment() << "," << student.getPhoneNumber() << ","
             << student.getEmail() << "," << student.getParentPhoneNumber() << ","
             << student.getCgpa() << "," << student.getCnicId() << "\n";
    }
    file.close();
    std::cout << "Student data saved to " << filename << std::endl;
}

void StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for loading.");
    }

    students.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        std::vector<std::string> tokens;
        while ((pos = line.find(',')) != std::string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);

        if (tokens.size() == 10) {
            students.push_back(Student(
                tokens[0], std::stoi(tokens[1]), std::stoi(tokens[2]), tokens[3], tokens[4],
                tokens[5], tokens[6], tokens[7], std::stof(tokens[8]), tokens[9]
            ));
        }
    }
    file.close();
    std::cout << "Student data loaded from " << filename << std::endl;
}

void StudentManager::searchByName(const std::string& name) const {
    bool found = false;
    for (const auto& student : students) {
        if (student.getName() == name) {
            student.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No student found with name: " << name << std::endl;
    }
}

void StudentManager::filterByCourse(const std::string& course) const {
    bool found = false;
    for (const auto& student : students) {
        if (student.getCourse() == course) {
            student.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No students found in course: " << course << std::endl;
    }
}

void StudentManager::filterByDepartment(const std::string& department) const {
    bool found = false;
    for (const auto& student : students) {
        if (student.getDepartment() == department) {
            student.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No students found in department: " << department << std::endl;
    }
}

void StudentManager::sortByCgpa() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getCgpa() > b.getCgpa(); // Sort in descending order
    });
    std::cout << "Students sorted by CGPA." << std::endl;
}

void StudentManager::sortByName() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getName() < b.getName(); // Sort in ascending order
    });
    std::cout << "Students sorted by name." << std::endl;
}

bool StudentManager::deleteStudentByRollNumber(int rollNumber) {
    auto it = std::remove_if(students.begin(), students.end(), [rollNumber](const Student& student) {
        return student.getRollNumber() == rollNumber;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        return true; // Student deleted
    }
    return false; // Student not found
}

bool StudentManager::updateStudentByRollNumber(int rollNumber, const Student& updatedStudent) {
    for (auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student = updatedStudent;
            return true; // Student updated
        }
    }
    return false; // Student not found
}