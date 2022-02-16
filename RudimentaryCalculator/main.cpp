#include <iostream>
using namespace std;

int menu();
void addition();
void subtraction();
void multiplication();
void division();

int main(){
    int menuOption;

    do{
        system("cls");

        menuOption = menu();

        switch(menuOption){
            case 0:
                addition();
                break;
            case 1:
                subtraction();
                break;
            case 2:
                multiplication();
                break;
            case 3:
                division();
                break;
            case 4:
                cout << "\nThank you for using the program!\n\n";
                system("pause");
                break;
            default:
                cout << "\nInvalid option! Try again.";
                break;
        }
    } while (menuOption!=4);
    return 0;
}

int menu(){
    int menuOption;

    cout << "\n---- Menu ----\n";
    cout << "[0] Addition\n"; 
    cout << "[1] Subtraction\n"; 
    cout << "[2] Multiplication\n"; 
    cout << "[3] Division\n";
    cout << "[4] Quit\n"; 
    cout << "-----------------\n";
    cout << "Select your option: ";
    cin >> menuOption;

    return menuOption;
}

void addition(){
    float number1, number2, result;

    cout << "\nType the first number: ";
    cin >> number1;
    cout << "\nType the second number: ";
    cin >> number2;
    result = number1 + number2;
    cout << "\n>> " << number1 << " + " << number2 << " = " << result << "\n\n";
    system("pause");
}

void subtraction(){
    float number1, number2, result;

    cout << "\nType the first number: ";
    cin >> number1;
    cout << "\nType the second number: ";
    cin >> number2;
    result = number1 - number2;
    cout << "\n>> " << number1 << " - " << number2 << " = " << result << "\n\n";
    system("pause");
}

void multiplication(){
    float number1, number2, result;

    cout << "\nType the first number: ";
    cin >> number1;
    cout << "\nType the second number: ";
    cin >> number2;
    result = number1 * number2;
    cout << "\n>> " << number1 << " * " << number2 << " = " << result << "\n\n";
    system("pause");
}

void division(){
    float number1, number2, result;

    cout << "\nType the first number: ";
    cin >> number1;
    cout << "\nType the second number: ";
    cin >> number2;
    result = number1/number2;
    cout << "\n>> " << number1 << "/" << number2 << " = " << result << "\n\n";
    system("pause");
}