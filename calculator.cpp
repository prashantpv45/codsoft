#include <iostream>
using namespace std;

void add(double x, double y) {
    cout << x << " + " << y << " = " << x + y << endl;
}

void subtract(double x, double y) {
    cout << x << " - " << y << " = " << x - y << endl;
}

void multiply(double x, double y) {
    cout << x << " * " << y << " = " << x * y << endl;
}

void divide(double x, double y) {
    if (y != 0) {
        cout << x << " / " << y << " = " << x / y << endl;
    } else {
        cout << "Error! Division by zero." << endl;
    }
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        cout << "Select operation:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice (1/2/3/4/5): ";
        cin >> choice;

        if (choice == 5) {
            break;
        }

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch (choice) {
                case 1:
                    add(num1, num2);
                    break;
                case 2:
                    subtract(num1, num2);
                    break;
                case 3:
                    multiply(num1, num2);
                    break;
                case 4:
                    divide(num1, num2);
                    break;
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}

