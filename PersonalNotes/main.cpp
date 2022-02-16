/**
 * @file main.cpp
 * @author Carlos Eduardo Torres (carlos.eduardo.qas@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>

#include "Interface.h"
#include "DataIO.h"

using namespace std;

int main(int argc, char *argv[])
{
    int menuOption, menuLoginOption;
    vector<User> users;
    int usersID = 0;
    int userIdLogged = 0;
    bool validAnswer = false;

    readData(users, usersID);

    while(!validAnswer)
    {
        bool loginMade = false;
        bool quitLogin = false;
        menu(&menuOption);
        switch (menuOption)
        {
        case 1:
            loginMade = login(users, &userIdLogged);
            if(loginMade)
            {
                while(!quitLogin)
                {
                    menuLogin(&menuLoginOption);
                    switch (menuLoginOption)
                    {
                    case 1:
                        menuNotes(users, userIdLogged);
                        break;
                    case 2:
                        createNote(users, userIdLogged);
                        break;
                    case 3:
                        changeUser(users, userIdLogged);
                        break;
                    case 4:
                        changePassword(users, userIdLogged);
                        break;
                    case 5:
                        quitLogin = true;
                        break;
                    default:
                        cout << "\nInvalid option, try again!\n";
                        system("pause");
                        break;
                    }
                }
            } 
            else 
            {
                cout << "\nInvalid login, try again!\n";
                system("pause");
            }
            break;
        case 2:
            createAccount(users, &usersID);
            break;
        case 3:
            saveData(users);
            validAnswer = true;
            break;
        default:
            cout << "\nInvalid option, try again!\n";
            system("pause");
            break;
        }
    }

    return 0;
}
