#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>
#include <string>
#include <fstream>
#include<limits>

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void displayAllStudents() const;
    void clearStudents();
    bool isDuplicateRollNumber(int rollNumber) const;

    // File I/O
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Search and Filter
    void searchByName(const std::string& name) const;
    void filterByCourse(const std::string& course) const;
    void filterByDepartment(const std::string& department) const;

    // Sort
    void sortByCgpa();
    void sortByName();

    // Delete and Update
    bool deleteStudentByRollNumber(int rollNumber);
    bool updateStudentByRollNumber(int rollNumber, const Student& updatedStudent);
};

#endif