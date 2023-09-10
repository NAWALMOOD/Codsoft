//2nd task of Codsoft internship
//Calculator

//Develop a calculator program that performs basic arithmetic
//operations such as addition, subtraction, multiplication, and
//division. Allow the user to input two numbers and choose an
//operation to perform.s

#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double num1, num2, result;
        char operation;

        cout << "Calculator" << endl;
        cout << "Enter number 1: ";
        cin >> num1;

        cout << "Enter number 2: ";
        cin >> num2;

        cout << "Enter operation of your choice : ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return 1;
                }
                break;
            default:
                cout << "Error: Invalid operation." << endl;
                return 1;
        }
        cout << endl;
        cout << "Result: " << result << endl;

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the calculator program." << endl;

    return 0;
}
