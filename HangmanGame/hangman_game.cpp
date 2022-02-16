#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

void stickyMan(int attempts);
void menu(string &inputWord, vector<char> &secretWord, vector<char> &wordInArray);
void startGame(int *attempts, string inputWord, vector<char> secretWord, vector<char> wordInArray);
void conclusion(int attempts, string inputWord, char *tryAgainOption);

int main(){
    Begin:
    int attempts = 6;
    char tryAgainOption;
    string inputWord;
    vector<char>secretWord;
    vector<char>wordInArray;
    
    menu(inputWord, secretWord, wordInArray);
    startGame(&attempts, inputWord, secretWord, wordInArray);
    conclusion(attempts, inputWord, &tryAgainOption);

    if(tryAgainOption == 'y' || tryAgainOption == 'Y')
        goto Begin;

    cout << "\nThank you for playing with me!!!\n";
    system("pause");

    return 0;
}

void menu(string &inputWord, vector<char> &secretWord, vector<char> &wordInArray){

    system("cls");
    cout << "Type the secret word: ";
    getline(cin, inputWord);

    for(int i=0; i< inputWord.length(); i++){
        if (inputWord[i] == ' '){
            secretWord.push_back(inputWord[i]);
            wordInArray.push_back(inputWord[i]);
        } else {
            secretWord.push_back('_');
            wordInArray.push_back(inputWord[i]);
        }
    }

    cout << "\nPress any button to start the game and hide your secret word!\n";
    system("pause");

};

void startGame(int *attempts, string inputWord, vector<char> secretWord, vector<char> wordInArray){
    char inputLetter;
    bool substitution = false, won = false;
    
    while(!won && *attempts > 0) {
        system("cls");
        stickyMan(*attempts);
        cout << "\n\nSecret word: ";
        for(auto i:secretWord){
            cout << i << " ";
        }

        cout << "\nTry one letter >> ";
        cin >> inputLetter;

        for(int i=0; i<inputWord.length(); i++){
            if(inputLetter == wordInArray.at(i)){
                secretWord.at(i) = inputLetter;
                substitution = true;
            }
        }

        if (substitution){
            substitution = false;
        } else {
            *attempts -= 1;
        }

        if (secretWord == wordInArray){
            won = true;
        }
    }
}

void conclusion(int attempts, string inputWord, char *tryAgainOption){
    system("cls");

    if(attempts == 0){
        stickyMan(attempts);
        cout << "\n\nUnfortunately you lost!";
    } else {
        stickyMan(attempts);
        cout << "\n\nCongratulations, you won!!!"; 
    }

    cout << "\nThe secret word was: " << inputWord;

    cout << "\n\nDo you want to try again? [y/n]: ";
    cin >> *tryAgainOption;

    //Bug prevention for using cin >> before getline();
    cin.clear();
    cin.sync();
}

void stickyMan(int attempts){
    switch (attempts){
        case 6:
            cout << "       ====:\n";
            cout << "       |   \n";
            cout << "       |  ";
            cout << "";
            cout << "";
            cout << "\n       |  ";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 5:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  ";
            cout << "";
            cout << "";
            cout << "\n       |  ";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 4:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  ";
            cout << " |";
            cout << "";
            cout << "\n       |  ";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 3:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  /";
            cout << "|";
            cout << "";
            cout << "\n       |  ";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 2:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  /";
            cout << "|";
            cout << ")";
            cout << "\n       |  ";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 1:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  /";
            cout << "|";
            cout << ")";
            cout << "\n       |  (";
            cout << " ";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        case 0:
            cout << "       ====:\n";
            cout << "       |   O\n";
            cout << "       |  /";
            cout << "|";
            cout << ")";
            cout << "\n       |  (";
            cout << " )";
            cout << "\n       |";
            cout << "\n     =====";
            break;
        default:
            cout << "\nInvalid value!\n";
            break;
    }
}