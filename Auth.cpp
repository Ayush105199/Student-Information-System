#include "Auth.h"
#include <iostream>
#include <string>
#include<limits>

bool Auth::signup(const std::string& username, const std::string& password) {
    if (users.find(username) != users.end()) {
        std::cout << "Username already exists! Please choose a different username." << std::endl;
        return false;
    }
    users[username] = password;
    std::cout << "Signup successful!" << std::endl;
    return true;
}

bool Auth::login(const std::string& username, const std::string& password) {
    if (users.find(username) == users.end() || users[username] != password) {
        std::cout << "Invalid username or password!" << std::endl;
        return false;
    }
    std::cout << "Login successful!" << std::endl;
    return true;
}