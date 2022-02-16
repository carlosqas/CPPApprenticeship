#include <iostream>
using namespace std;

int main(void){
    int number, i;
    char repeat;
    
    begin:
    system("cls");

    cout << "\nType the number that you want to see the multiplication table: ";
    cin >> number;

    for(i=0; i<10; i++){
        int result = number * i;
        cout << "\n" << number << " X " << i << " = " << result;
    }

    cout << "\n\nDo you want to do other multiplication table? [y/n]: ";
    cin >> repeat;

    if(repeat == 'y' or repeat == 'Y'){
        goto begin;
    }

    cout << "\n\nThank you for using the program!\n";
    system("pause");

    return 0;
}