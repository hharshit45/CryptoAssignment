#include <iostream>

int extendedEuclidean(int a, int m, int& x, int& y) {
    // Base case
    if (a == 0) {
        x = 0;
        y = 1;
        return m;
    }

    // Recursive call
    int x1, y1;
    int gcd = extendedEuclidean(m % a, a, x1, y1);

    x = y1 - (m / a) * x1;
    y = x1;

    return gcd;
}

int findModularInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);

    if (gcd != 1) {
        std::cout << "Modular inverse does not exist." << std::endl;
        return -1;
    }

    x = (x % m + m) % m;
    return x;
}

int findModular(int a, int b, int m) {

    int result = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return result;
}

int main() {
    int a, m;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Enter the modulus: ";
    std::cin >> m;

    int inverse = findModularInverse(a, m);
    if (inverse != -1) {
        std::cout << "Modular inverse of " << a << " modulo " << m << " is: " << inverse << std::endl;
    }

    int b;
    std::cout << "Enter a number for modulus calculation: ";
    std::cin >> b;

    int modulus = findModular(a, b, m);
    std::cout << "(" << a << "^" << b << ") % " << m << " = " << modulus << std::endl;

    return 0;
}
