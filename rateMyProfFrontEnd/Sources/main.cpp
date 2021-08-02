#include "ratemyprof.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
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
#include "HashTable.h"

using namespace std;

queue<Professor> csvStuff(vector<string>& data){
    queue<Professor> list;
    //NEW

    string dataLine;
    ifstream inFile("/Users/taisemiyazumi/Qt/Projects/rateMyProfessorFrontEnd/Project_3_Raw_Data.csv");

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

queue<Professor> csvStuff(HashTable &ht){
    queue<Professor> list;

    //NEW

    string dataLine;
    ifstream inFile("/Users/taisemiyazumi/Qt/Projects/rateMyProfessorFrontEnd/Project_3_Raw_Data.csv");


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
            ht.insertElement(college, Temp);
            list.push(Temp);
        }
    }
    return list;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<string> allData;

    auto start = std::chrono::steady_clock::now();

    queue<Professor> Master_List = csvStuff(allData);
    BST Tree(Master_List);
    auto end = std::chrono::steady_clock::now();

    double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
    cout << "Elapsed time: " << elapsedTime / 1e9 << endl;

    auto htStart = std::chrono::steady_clock::now();
    HashTable ht(59);
    queue<Professor> Hash_List = csvStuff(ht);
    auto htEnd = std::chrono::steady_clock::now();

    double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
    cout << "Hash Elapsed time: " << htElapsedTime / 1e9 << endl;



    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "rateMyProfessorFrontEnd_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    rateMyProf w;
    w.setHash(&ht);
    w.setTime(elapsedTime,htElapsedTime);
    w.setTree(&Tree);
    w.show();
    return a.exec();

}
