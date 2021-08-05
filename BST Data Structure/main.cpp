#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stdio.h>
#include <ctype.h>
#include "Professor.h"
#include "BST.h"
using namespace std;
queue<Professor> csvStuff(vector<string>& data){
    queue<Professor> list;
    //NEW

    string dataLine;
    ifstream inFile("Project_3_Raw_Data.csv");

    for (int j = 0; j < 106836; j++) {
        getline(inFile, dataLine);

        string department;
        string garbage;
        istringstream stream(dataLine);
        getline(stream, department, '\'');
        getline(stream, department, '\'');
        getline(stream, department, '\'');

        bool errors = false;
        string depTemp;
        for (int i = 0; i < department.size(); i++) {
            if (department[i] == '\"' && errors == false) {
                errors = true;
                i += 2;
            }
            if (errors) {
                depTemp += department[i];
            }
        }
        if (errors == true) {
            string stuff;
            getline(stream, stuff, '\"');
            department = depTemp + '\'' + stuff;
            getline(stream, garbage, ',');
        } else {
            getline(stream, department, '\'');
            getline(stream, garbage, ',');
        }

        string ID;
        getline(stream, ID, ',');
        ID = ID.substr(10, ID.size() - 11);


        string college;
        getline(stream, college, ',');
        college = college.substr(22, college.size() - 23);

        string firstName;
        string firstTemp;
        bool quotes = false;
        getline(stream, firstName, '\'');
        getline(stream, firstName, '\'');
        getline(stream, firstName, '\'');
        for (int i = 0; i < firstName.size(); i++) {
            if (firstName[i] == '\"' && quotes == false) {
                quotes = true;
                i += 2;
            }
            if (quotes) {
                firstTemp += firstName[i];
            }
        }

        if (quotes == true) {
            string stuff;
            getline(stream, stuff, '\"');
            firstName = firstTemp + '\'' + stuff;
            getline(stream, garbage, ',');
        }
        else {
            getline(stream, firstName, '\'');
            getline(stream, garbage, ',');
        }

        string lastName;
        string temp;
        bool special = false;
        getline(stream, lastName, ',');
        getline(stream, lastName, '\'');
        getline(stream, lastName, '\'');
        getline(stream, lastName, '\'');
        for (int i = 0; i < lastName.size(); i++) {
            if (lastName[i] == '\"' && special == false) {
                special = true;
                i += 2;
            }
            if (special) {
                temp += lastName[i];
            }
        }

        if (special == true) {
            string add;
            getline(stream, add, '\"');
            lastName = temp + '\'' + add;
            getline(stream, garbage, ',');
        } else {
            getline(stream, lastName, '\'');
            getline(stream, garbage, ',');
        }

        string profID;
        getline(stream, profID, ',');
        profID = profID.substr(8, profID.size() - 8);

        string numberOfRatings;
        getline(stream, numberOfRatings, ',');
        numberOfRatings = numberOfRatings.substr(16, numberOfRatings.size() - 16);

        string classRating;
        getline(stream, classRating, ',');
        classRating = classRating.substr(18, classRating.size() - 19);

        string contentType;
        getline(stream, contentType, ',');
        contentType = contentType.substr(17, contentType.size() - 18);

        string categoryType;
        getline(stream, categoryType, ',');
        categoryType = categoryType.substr(18, categoryType.size() - 19);

        string overallRating;
        getline(stream, overallRating, '\'');
        getline(stream, overallRating, '\'');
        getline(stream, overallRating, '\'');
        getline(stream, overallRating, '\'');

        //cout << profID << endl;
        if(overallRating == "N/A")
            overallRating = "0.0";

        string returning = department + "," + ID + "," + college + "," + firstName + "," + lastName + "," + profID + "," +numberOfRatings + "," + classRating + "," + contentType + "," + categoryType + "," + overallRating;
        string full = firstName + " " + lastName;

        if(isalpha(full[0])) {
            Professor Temp(firstName,lastName,stoi(profID),stoi(numberOfRatings),classRating,stod(overallRating),department,stoi(ID),college);
            list.push(Temp);
        }

        data.push_back(returning);
    }
    return list;
}

int main() {
    vector<string> allData;

    queue<Professor> Master_List = csvStuff(allData);
    BST Tree(Master_List);

//    vector<string> list = Tree.UniversityList();
//    for(int i = 1; i<list.size()+1; i++)
//    {
//        cout << list[i] << endl;
//        //cout << "\"" << list[i] << "\" " << "<< ";
//    }

    std::ofstream myFile;
    int input;

    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "                           Rate My Professor Data Structure" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "Menu:" << endl;
    cout << "1: Search Professor by first name" << endl;
    cout << "2: Search Professor by last name" << endl;
    cout << "3: Search Professor by first and last name" << endl;
    cout << "4: Search Professor by ID" << endl;
    cout << "5: Directory of all Professors in a University by name" << endl;
    cout << "6: Directory of all Professors in a University by ID" << endl;
    cout << "7: Search for highest rated professors in a University" << endl;
    cout << "8: Search for highest rated professors in a certain University in a certain department" << endl;
    cout << "Option: ";

    cin >> input;
    if(input == 0){
        cout << "end" << endl;
    }
    else if (input == 1){
        cout << "Enter the first name" << endl;
        string firstName;
        cin.get();
        getline(cin, firstName);
        vector<string> t = Tree.SearchFirstName(firstName);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 2){
        cout << "Enter the last name" << endl;
        string lastName;
        cin.get();
        getline(cin, lastName);
        vector<string> t = Tree.SearchLastName(lastName);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }

    }
    else if (input == 3){
        cout << "Enter the first and last name" << endl;
        string name;
        cin.get();
        getline(cin, name);
        vector<string> t = Tree.SearchFullName(name);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 4){
        cout << "Enter the ID" << endl;
        string ID;
        cin.get();
        getline(cin, ID);
        vector<string> t = Tree.SearchProfID(stoi(ID));
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 5){
        cout << "Which University do you want to search?" << endl;
        string university;
        cin.get();
        getline(cin, university);
        vector<string> t = Tree.PrintDirectoryName(university);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 6){
        cout << "Which University do you want to search?" << endl;
        string ID;
        cin.get();
        getline(cin, ID);
        vector<string> t = Tree.PrintDirectoryID(stoi(ID));
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 7){
        cout << "Which University do you want to search?" << endl;
        string university;
        cin.get();
        getline(cin, university);
        vector<string> t = Tree.BestProfInUniversity(university);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }
    else if (input == 8){
        cout << "Which University do you want to search?" << endl;
        string university;
        cin.get();
        getline(cin, university);
        cout << "Which department do you want to search for?" << endl;
        string dept;
        getline(cin, dept);
        vector<string> t = Tree.BestProfInDept(university,dept);
        for(int i = 0; i<t.size(); i++)
        {
            cout << t[i] << endl;
        }
    }

    return 0;
}
