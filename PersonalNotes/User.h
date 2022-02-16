/**
 * @file User.h
 * @author Carlos Eduardo Torres (carlos.eduardo.qas@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <map>

using namespace std;

/**
 * @brief User class.
 * 
 */
class User
{
public:
    /**
     * @brief Construct a new User object.
     * 
     * @param usern User username.
     * @param passw User password.
     * @param userid User ID.
     */
    User(string usern, string passw, int userid);

    /**
     * @brief Changes the username.
     * 
     * @param newUser New username.
     */
    void setUsername(string newUser);

    /**
     * @brief Get the current username.
     * 
     * @return string - User's username.
     */
    string getUsername();

    /**
     * @brief Changes the password.
     * 
     * @param newPass New password.
     */
    void setPassword(string newPass);

    /**
     * @brief Get the current password.
     * 
     * @return string - User's password.
     */
    string getPassword();

    /**
     * @brief Changes the user's ID.
     * 
     * @param newId New ID.
     */
    void setUserId(int newId);

    /**
     * @brief Get the current user's ID.
     * 
     * @return int - User's ID.
     */
    int getUserId();

    /**
     * @brief Print all user's notes.
     * 
     */
    void getAllNotes();

    /**
     * @brief Print all user's notes and its ID.
     * 
     */
    void getAllNotesID();

    /**
     * @brief Create a new note.
     * 
     * @param newNote New note.
     */
    void newNotes(string newNote);

    /**
     * @brief Delete a defined note.
     * 
     * @param indexNote Note's ID.
     */
    void deleteNote(int indexNote);

    /**
     * @brief Delete all user's note.
     * 
     */
    void deleteAllNotes();

private:
    string username;        // User's username.
    string password;        // User's password.
    int userId;             // User's ID.
    int noteIndex = 0;      // Note's ID.
    map<int, string> notes; // Map with notes and its ID.
};

User::User(string usern, string passw, int userid) : username(usern), password(passw), userId(userid)
{
    notes.insert(pair<int, string>(noteIndex, "Welcome to Personal Notes, this is a welcome note, you can delete this if you want to. I hope you enjoy the application"));
    noteIndex++;
}

void User::setUsername(string newUser)
{
    username = newUser;
}

string User::getUsername()
{
    return username;
}

void User::setPassword(string newPass)
{
    password = newPass;
}

string User::getPassword()
{
    return password;
}

void User::setUserId(int newId)
{
    userId = newId;
}

int User::getUserId()
{
    return userId;
}

void User::getAllNotes()
{
    if(notes.empty())
        cout << ">> You don't have any notes <<";
    else 
    {
        for(auto i : notes)
            cout << "> " << i.second << endl;
    }
}

void User::getAllNotesID()
{
    if(notes.empty())
        cout << ">> You don't have any notes <<";
    else 
    {
        for(auto i:notes)
            cout << "[" << i.first << "] " << i.second << endl;
    }
}

void User::newNotes(string newNote)
{
    notes.insert(pair<int, string>(noteIndex, newNote));
    noteIndex++;
}

void User::deleteNote(int indexNote)
{
    notes.erase(indexNote);
}

void User::deleteAllNotes()
{
    notes.clear();
}