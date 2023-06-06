#include <iostream>
#include <string>

std::string encryptAffine(std::string plaintext, int a, int b) {
    std::string ciphertext = "";
    int m = 26;

    for (char c : plaintext) {
        if (isalpha(c)) {
            char encryptedChar = ((a * (c - 'a') + b) % m) + 'a';
            ciphertext += encryptedChar;
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

std::string decryptAffine(std::string ciphertext, int a, int b) {
    std::string plaintext = "";
    int m = 26;

    int aInverse = -1;
    for (int x = 1; x < m; ++x) {
        if (((a % m) * (x % m)) % m == 1) {
            aInverse = x;
            break;
        }
    }

    if (aInverse == -1) {
        std::cout << "Error: Multiplicative inverse of 'a' doesn't exist." << std::endl;
        return "";
    }

    for (char c : ciphertext) {
        if (isalpha(c)) {
            char decryptedChar = ((aInverse * (c - 'a' - b + m)) % m) + 'a';
            plaintext += decryptedChar;
        } else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    std::string plaintext;
    int a, b;

    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);

    std::cout << "Enter the value of 'a' (must be coprime with 26): ";
    std::cin >> a;

    std::cout << "Enter the value of 'b': ";
    std::cin >> b;

    std::string ciphertext = encryptAffine(plaintext, a, b);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    std::string decryptedText = decryptAffine(ciphertext, a, b);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
