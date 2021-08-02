#pragma once
#include <map>

#include "Professor.h"

/*
University Class:

Purpose -

*University object stores the University's Professors
*Each node of BST is a University Object which stores all the Professors

Visual Representation -
               University :
                    List of Professors for University (Map)
                    String Name
                    Int ID
*/
class University {
public:
    int ID; //University ID
    string name; //University Name
    map<string, Professor> storage; //Stores Professor
    map<string, vector<string>> DEPT_TO_FULL; //Converts department to full name
    map<string, vector<string>> FIRST_TO_FULL; //Converts first name to full name
    map<string, vector<string>> LAST_TO_FULL; //Converts last name to full name
    map<int, string> ID_TO_FULL; //Converts ID to full name

    //Default Constructor
    University() {
        ID = 0;
        name = "";
    }

    //Specific Constructor
    University(string name, int ID) {
        this->ID = ID;
        this->name = name;
    }

    /*
     Function: storageContains
     Purpose: acts as a check function to see if University contains a professor
     */
    bool storageContains(string fullname) {
        if(storage.find(fullname) != storage.end()) //Checks if storage contains full name
            return true;
        else
            return false;
    }
};

