#include <iostream>
#include <cstdlib> // For abs function
using namespace std;

int main() {
    long long a, b; // Declare variables to store soldier numbers
    
    // Read input until End Of File (EOF)
    while (cin >> a >> b) {
        // Output the absolute difference between the two numbers
        cout << abs(a - b) << endl;
    }

    return 0;
}

