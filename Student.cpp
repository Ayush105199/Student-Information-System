#include "Student.h"
#include <iostream>
#include<limits>
Student::Student(std::string name, int rollNumber, int age, std::string course, std::string department,
                 std::string phoneNumber, std::string email, std::string parentPhoneNumber,
                 float cgpa, std::string cnicId)
    : name(name), rollNumber(rollNumber), age(age), course(course), department(department),
      phoneNumber(phoneNumber), email(email), parentPhoneNumber(parentPhoneNumber),
      cgpa(cgpa), cnicId(cnicId) {}

std::string Student::getName() const {
    return name;
}

int Student::getRollNumber() const {
    return rollNumber;
}

int Student::getAge() const {
    return age;
}

std::string Student::getCourse() const {
    return course;
}

std::string Student::getDepartment() const {
    return department;
}

std::string Student::getPhoneNumber() const {
    return phoneNumber;
}

std::string Student::getEmail() const {
    return email;
}

std::string Student::getParentPhoneNumber() const {
    return parentPhoneNumber;
}

float Student::getCgpa() const {
    return cgpa;
}

std::string Student::getCnicId() const {
    return cnicId;
}

void Student::display() const {
    std::cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Age: " << age
              << ", Course: " << course << ", Department: " << department
              << ", Phone Number: " << phoneNumber << ", Email: " << email
              << ", Parent Phone Number: " << parentPhoneNumber
              << ", CGPA: " << cgpa << ", CNIC ID: " << cnicId << std::endl;
}