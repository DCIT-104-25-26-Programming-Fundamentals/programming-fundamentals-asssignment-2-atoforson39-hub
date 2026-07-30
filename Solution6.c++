#include <iostream>
#include <iomanip>
using namespace std;

void printSingleTable(int num) {
    if (num <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return;
    }

    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << (num * i) << endl;
    }
}

void printTablesUpToN(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    for (int num = 1; num <= n; num++) {
        printSingleTable(num);
        cout << "---------------------------" << endl;
    }
}

int main() {
    // ---------------- PART A: Single Table ----------------
    int num;
    cout << "Enter a number: ";
    cin >> num;
    printSingleTable(num);

    cout << endl;

    // ---------------- PART B: Tables from 1 to N ----------------
    int n;
    cout << "Enter N (to print tables from 1 to N): ";
    cin >> n;
    printTablesUpToN(n);

    return 0;
}