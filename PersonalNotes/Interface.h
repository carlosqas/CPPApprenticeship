/**
 * @file Interface.h
 * @author Carlos Eduardo Torres (carlos.eduardo.qas@outlook.com)
 * @brief Library with menus.
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

/**
 * @brief Home menu.
 * 
 * @param menuOpt 
 */
void menu(int *menuOpt)
{
   system("cls");
   cout << "--- Personal Notes ---";
   cout << "\n[1] - Login";
   cout << "\n[2] - Create account";
   cout << "\n[3] - Quit";
   cout << "\n----------------------";
   cout << "\n>> ";
   cin >> *menuOpt;
}

/**
 * @brief User creation menu.
 * 
 * @param users 
 * @param usersID 
 */
void createAccount(vector<User> &users, int *usersID)
{
    string username, password;
    system("cls");
    cout << "--- Create Account ---" << endl;
    cout << "Type your username: ";
    cin >> username;
    cout << "Type your password: ";
    cin >> password;

    User newUser(username, password, *usersID);
    *usersID += 1;
    users.push_back(newUser);

    cout << "\nAccount successfully created!\n";
    system("pause");
}

/**
 * @brief Login menu.
 * 
 * @param users 
 * @param userIdLogged 
 * @return true - If login was successfull.
 * @return false
 */
bool login(vector<User> users, int *userIdLogged)
{
    string username, password;
    bool loginMade = false;

    system("cls");
    cout << "--- Login ---" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (auto i : users)
    {
        if(i.getUsername() == username && i.getPassword() == password)
        {
            *userIdLogged = i.getUserId();
            loginMade = true;
        }
    }

    return loginMade;
}

/**
 * @brief Main user menu.
 * 
 * @param menuLoginOption 
 */
void menuLogin(int *menuLoginOption)
{
   system("cls");
   cout << "--- Personal Notes ---";
   cout << "\n[1] - View notes";
   cout << "\n[2] - Create note";
   cout << "\n[3] - Change username";
   cout << "\n[4] - Change password";
   cout << "\n[5] - Quit";
   cout << "\n----------------------";
   cout << "\n>> ";
   cin >> *menuLoginOption;
}

/**
 * @brief Notes menu.
 * 
 * @param users 
 * @param userIdLogged 
 */
void menuNotes(vector<User> &users, int userIdLogged)
{
    bool quit = false;
    int option, indexNote;
    string newNote;
    vector<User>::iterator selectUser;

    for(auto it = users.begin(); it != users.end(); it++)
    {
        if(it->getUserId() == userIdLogged)
            selectUser = it;            
    }

    while(!quit)
    {
        system("cls");
        cout << "--- Your Notes ---\n" ;
        
        selectUser->getAllNotes();
        cout << "\n------------------" ;
        cout << "\n[1] - Create note" ;
        cout << "\n[2] - Delete note" ;
        cout << "\n[3] - Return to menu" ;
        cout << "\n------------------" ;
        cout << "\n>> ";
        cin >> option;

        switch(option)
        {
        case 1:
            system("cls");
            cin.clear();
            cin.sync();

            cout << "--- Create Note ---";
            cout << "\n>> ";
            getline(cin, newNote);
            selectUser->newNotes(newNote);
            cout << "\nNote created successfully!\n";
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "--- Delete Note ---\n";
            selectUser->getAllNotesID();
            cout << "\n-------------------";
            cout << "\n>> ";
            cin >> indexNote;
            selectUser->deleteNote(indexNote);
            cout << "\nNote deleted successfully!\n";
            system("pause");
            break;
        case 3:
            quit = true;
            break;
        }
    }
}

/**
 * @brief Note creation menu.
 * 
 * @param users 
 * @param userIdLogged 
 */
void createNote(vector<User> &users, int userIdLogged)
{
    string newNote;
    vector<User>::iterator selectUser;

    for(auto it=users.begin(); it!=users.end(); it++)
    {
        if(it->getUserId() == userIdLogged)
            selectUser = it;
    }

    cin.clear();
    cin.sync();

    system("cls");
    cout << "--- Create Note ---";
    cout << "\n>> ";
    getline(cin, newNote);
    selectUser->newNotes(newNote);
    cout << "\nNote created successfully!\n";
    system("pause");
}

/**
 * @brief Change username menu.
 * 
 * @param users 
 * @param userIdLogged 
 */
void changeUser(vector<User> &users, int userIdLogged)
{
    string newUsername;
    vector<User>::iterator selectUser;

    for(auto it=users.begin(); it!=users.end(); it++)
    {
        if(it->getUserId() == userIdLogged)
            selectUser = it;
    }

    system("cls");
    cout << "--- Change Username ---" << endl;
    cout << ">> Type your new username: ";
    cin >> newUsername;

    selectUser->setUsername(newUsername);

    cout << "\nUsername changed successfully!\n";
    system("pause");
}

/**
 * @brief Change password menu.
 * 
 * @param users 
 * @param userIdLogged 
 */
void changePassword(vector<User> &users, int userIdLogged)
{
    string newPassword;
    vector<User>::iterator selectUser;

    for(auto it=users.begin(); it!=users.end(); it++)
    {
        if(it->getUserId() == userIdLogged)
            selectUser = it;
    }

    system("cls");
    cout << "--- Change Password ---";
    cout << "\n>> Type your new password: ";
    cin >> newPassword;

    selectUser->setPassword(newPassword);

    cout << "\nPassword changed successfully!\n";
    system("pause");
}