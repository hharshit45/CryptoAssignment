#include <iostream>
#include <functional>
#include <string>

// Function to compute the hash of a given message
std::size_t computeHash(const std::string& message) {
    std::hash<std::string> hashFunction;
    return hashFunction(message);
}

int main() {
    std::string message;

    
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    
    std::size_t originalHash = computeHash(message);

    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Original Hash: " << originalHash << std::endl;


    std::string receivedMessage = message;  
    std::size_t receivedHash = computeHash(receivedMessage);

    std::cout << "\nReceived Message: " << receivedMessage << std::endl;
    std::cout << "Received Hash: " << receivedHash << std::endl;

    if (receivedHash == originalHash) {
        std::cout << "Integrity check: The received message is unchanged and authentic." << std::endl;
    } else {
        std::cout << "Integrity check: The received message has been modified or is not authentic." << std::endl;
    }

    std::cout << "\nEnter a modified message: ";
    std::getline(std::cin, receivedMessage);

    receivedHash = computeHash(receivedMessage);

    std::cout << "Modified Message: " << receivedMessage << std::endl;
    std::cout << "Modified Hash: " << receivedHash << std::endl;

    if (receivedHash == originalHash) {
        std::cout << "Integrity check: The received message is unchanged and authentic." << std::endl;
    } else {
        std::cout << "Integrity check: The received message has been modified or is not authentic." << std::endl;
    }

    return 0;
}
