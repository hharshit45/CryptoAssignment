#include <iostream>
#include <cmath>

long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main()
{
    long long int P, G, a, b, ka, kb;

    std::cout << "Enter the value of P (prime number): ";
    std::cin >> P;

    std::cout << "Enter the value of G (primitive root for P): ";
    std::cin >> G;

    std::cout << "Enter the private key a for Alice: ";
    std::cin >> a;

    std::cout << "Enter the private key b for Bob: ";
    std::cin >> b;

    long long int x = power(G, a, P); // Alice's generated key
    long long int y = power(G, b, P); // Bob's generated key

    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    std::cout << "Secret key for Alice is: " << ka << std::endl;
    std::cout << "Secret key for Bob is: " << kb << std::endl;

    return 0;
}
