#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>


std::string computeHash(const std::string& password) {
    std::hash<std::string> hasher;
    size_t hashValue = hasher(password);
    return std::to_string(hashValue);
}


void writePasswordsToFile(const std::vector<std::string>& passwords) {
    std::ofstream file("passwords.txt");
    if (file.is_open()) {
        for (const std::string& password : passwords) {
            file << password << std::endl;
        }
        file.close();
        std::cout << "Passwords written to file successfully." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}


std::vector<std::string> readPasswordsFromFile() {
    std::vector<std::string> passwords;
    std::ifstream file("passwords.txt");
    if (file.is_open()) {
        std::string password;
        while (std::getline(file, password)) {
            passwords.push_back(password);
        }
        file.close();
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
    return passwords;
}

int main() {
    int numPasswords;
    std::cout << "Enter the number of passwords to create: ";
    std::cin >> numPasswords;

    std::vector<std::string> passwords;
    for (int i = 0; i < numPasswords; ++i) {
        std::string password;
        std::cout << "Enter password " << i + 1 << ": ";
        std::cin >> password;
        passwords.push_back(password);
    }

    
    writePasswordsToFile(passwords);
    std::vector<std::string> storedPasswords = readPasswordsFromFile();

    
    std::string inputPassword;
    std::cout << "Enter the password for identification: ";
    std::cin >> inputPassword;

    
    std::string hashedInputPassword = computeHash(inputPassword);

    bool passwordMatch = false;
    for (const std::string& storedPassword : storedPasswords) {
        if (hashedInputPassword == storedPassword) {
            passwordMatch = true;
            break;
        }
    }

    if (passwordMatch) {
        std::cout << "Identification successful. Password matched." << std::endl;
    } else {
        std::cout << "Identification failed. Password not found." << std::endl;
    }

    return 0;
}
