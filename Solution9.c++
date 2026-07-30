#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0;
    }
    success = true;
    return a / b;
}

double modulus(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0;
    }
    success = true;
    return fmod(a, b);
}

double exponent(double base, double exp) {
    double result = 1;
    int e = static_cast<int>(exp);
    for (int i = 0; i < e; i++) {
        result *= base;
    }
    return result;
}

void showMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    bool running = true;

    cout << fixed << setprecision(2);

    while (running) {
        showMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please select a number between 1 and 7." << endl;
            cout << endl;
            continue;
        }

        double num1, num2;
        cout << "Enter first number : ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        bool success = true;

        switch (choice) {
            case 1:
                cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case 4: {
                double result = divide(num1, num2, success);
                if (!success) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            }
            case 5: {
                double result = modulus(num1, num2, success);
                if (!success) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
                }
                break;
            }
            case 6:
                cout << "Result: " << num1 << " ^ " << num2 << " = " << exponent(num1, num2) << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}