#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include<limits>

class Student {
private:
    std::string name;
    int rollNumber;
    int age;
    std::string course;
    std::string department;
    std::string phoneNumber;
    std::string email;
    std::string parentPhoneNumber;
    float cgpa;
    std::string cnicId;

public:
    Student(std::string name, int rollNumber, int age, std::string course, std::string department,
            std::string phoneNumber, std::string email, std::string parentPhoneNumber,
            float cgpa, std::string cnicId);

    std::string getName() const;
    int getRollNumber() const;
    int getAge() const;
    std::string getCourse() const;
    std::string getDepartment() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getParentPhoneNumber() const;
    float getCgpa() const;
    std::string getCnicId() const;

    void display() const;
};

#endif