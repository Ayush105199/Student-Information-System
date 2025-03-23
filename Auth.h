#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <map>
#include<limits>

class Auth {
private:
    std::map<std::string, std::string> users; // username -> password

public:
    bool signup(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
};

#endif