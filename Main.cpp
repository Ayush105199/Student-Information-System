#include "StudentManager.h"
#include "Utils.h"
#include "Auth.h"
#include <iostream>
#include<limits>

void displayLoginMenu() {
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Signup" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

int main() {
    Auth auth;
    StudentManager manager;
    int choice;

    do {
        displayLoginMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string username, password;
        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (auth.login(username, password)) {
                    int mainChoice;
                    do {
                        displayMainMenu();
                        std::cout << "Enter your choice: ";
                        std::cin >> mainChoice;

                        switch (mainChoice) {
                            case 1:
                                addStudentPage(manager);
                                break;
                            case 2:
                                displayStudentsPage(manager);
                                break;
                            case 3:
                                clearStudentsPage(manager);
                                break;
                            case 4:
                                saveStudentsPage(manager);
                                break;
                            case 5:
                                loadStudentsPage(manager);
                                break;
                            case 6:
                                searchStudentPage(manager);
                                break;
                            case 7:
                                filterByCoursePage(manager);
                                break;
                            case 8:
                                filterByDepartmentPage(manager);
                                break;
                            case 9:
                                sortByCgpaPage(manager);
                                break;
                            case 10:
                                sortByNamePage(manager);
                                break;
                            case 11:
                                deleteStudentPage(manager);
                                break;
                            case 12:
                                updateStudentPage(manager);
                                break;
                            case 13:
                                std::cout << "Exiting the program..." << std::endl;
                                break;
                            default:
                                std::cout << "Invalid choice! Please try again." << std::endl;
                        }

                        std::cout << "Press Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();

                    } while (mainChoice != 13);
                }
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                auth.signup(username, password);
                break;
            case 3:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }

    } while (choice != 3);

    return 0;
}