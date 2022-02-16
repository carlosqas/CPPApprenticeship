/**
 * @file DataIO.h
 * @author Carlos Eduardo Torres (carlos.eduardo.qas@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <fstream>
#include <vector>

#include "User.h"

using namespace std;

/**
 * @brief Read stored users data.
 * 
 * @param users 
 */
void readData(vector<User> &users, int &usersID)
{
    ifstream inData;
    string inputData, username, password;
    int index = 0;
    int infoState = 0;

    inData.open("usersData.txt");

    if(!inData.is_open())
    {
        cout << "\nNao foi possivel abrir arquivo\n";
        return;
    }
    while (getline(inData, inputData))
    {
        infoState = 0;
        username.clear();
        password.clear();

        for (int i = 0; i < inputData.size(); i++)
        {
            cout << "\nchar do momento: " << inputData[i];
            if (infoState == 0)
            {
                if (inputData[i] == '~')
                    infoState++;
                else
                    username.push_back(inputData[i]);
            }
            else if (infoState == 1)
            {
                cout << "User: " << username << endl;
                index = 0;
                if (inputData[i] == '~')
                    infoState++;
                else
                    password.push_back(inputData[i]);
            }
        }
        if (infoState == 2)
        {
            cout << "Pass: " << password << endl;
            User newUser(username, password, usersID);
            usersID += 1;
            users.push_back(newUser);
        }
    }

    system("pause");

    inData.close();
}

/**
 * @brief Save stored users data.
 * 
 * @param users 
 */
void saveData(vector<User> &users)
{
    ofstream outData;
    
    if(users.empty())
        return;

    outData.open("usersData.txt", ios::out);

    for(auto user : users)
        outData << user.getUsername() << '~' << user.getPassword() << '~' << endl;

    outData.close();
}