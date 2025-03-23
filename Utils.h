#ifndef UTILS_H
#define UTILS_H

#include "StudentManager.h"
#include <string>

void displayMainMenu();
void addStudentPage(StudentManager& manager);
void displayStudentsPage(const StudentManager& manager);
void clearStudentsPage(StudentManager& manager);
void saveStudentsPage(StudentManager& manager);
void loadStudentsPage(StudentManager& manager);
void searchStudentPage(const StudentManager& manager);
void filterByCoursePage(const StudentManager& manager);
void filterByDepartmentPage(const StudentManager& manager);
void sortByCgpaPage(StudentManager& manager);
void sortByNamePage(StudentManager& manager);
void deleteStudentPage(StudentManager& manager);
void updateStudentPage(StudentManager& manager);

// Validation functions
bool isValidEmail(const std::string& email);
bool isValidPhoneNumber(const std::string& phoneNumber);

#endif