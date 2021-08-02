#include<list>
#include<functional>
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
#include<algorithm>
#pragma once

class HashTable {
private:
    list<Professor> *table;
    const double load_factor = 0.5;
    int tableSize;

    unsigned int Hash(const string key, int ts) {
        hash<string> h;
        unsigned int f = h(key) % ts;
        return f;
    }

public:

    HashTable(int ts) {
        tableSize = ts;
        table = new list<Professor>[tableSize];
    }

    double getCount(string uni) {
        int count = 0;
        for (auto i : table[Hash(uni, tableSize)]) count++;
        return count;
    }

    void Copy(list<Professor> *l) {
        auto ts = tableSize * 2;
        for (int i = 0; i < tableSize; i++) {
            for (auto j : l[i]) {
                table[Hash(j.uni, ts)].push_back(j);
            }
        }
    }

    // Insert data in the hash table:
    void insertElement(string uni, Professor prof) {
        table[Hash(uni, tableSize)].push_back(prof);
        if (getCount(uni) / tableSize > load_factor) {
            auto ts = tableSize * 2;
            auto *temp = new list<Professor>[tableSize];

            temp->assign(table->begin(), table->end());
            table = new list<Professor>[ts];

            Copy(temp);

            tableSize = ts;
        }
    }

    vector<string> printAll(string uni, int input){
        // Traverse each index:
        cout << "University: " << uni << endl;
        cout << endl;
        vector<string> result;
        for (const auto& i : table[Hash(uni, tableSize)]) {
            if (i.uni == uni) {
                if (input == 5) {
                    cout << i.fullname << endl;
                    result.push_back(i.fullname);
                    //                    result.push_back(to_string(j.profID));
                    result.push_back(i.verbalRating);
                    result.push_back(to_string(i.numRatings));
                    result.push_back(to_string(i.overallRating));
                    result.push_back(i.dept);
                    result.push_back(i.uni);
                    //                    result.push_back(to_string(j.uniID));
                }
                if (input == 11) {
                    cout << i.dept << endl;
                }
            }
        }
        cout << "TESTTTT" << result.size() << endl;
        return result;
    }

    void printProfUni(string uni, string name) {
        for (const auto& i : table[Hash(uni, tableSize)]) {
            if (i.uni == uni && i.fullname == name)
                cout << i.fullname << " - " << i.profID << endl;
        }
    }

    void printUniID(string uni) {
        cout << table[Hash(uni, tableSize)].front().uniID << endl;
    }

    vector<string> printSpecMenu(int menu, string name) {
        vector<string> result;
        for (int i = 0; i < tableSize; i++) {
            for (const auto& j : table[i]) {
                if (menu == 1 && name == j.firstname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;

                    result.push_back(j.fullname);
                    //                    result.push_back(to_string(j.profID));
                    result.push_back(j.verbalRating);
                    result.push_back(to_string(j.numRatings));
                    result.push_back(to_string(j.overallRating));
                    result.push_back(j.dept);
                    result.push_back(j.uni);
                    //                    result.push_back(to_string(j.uniID));
                }
                if (menu == 2 && name == j.lastname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;

                    result.push_back(j.fullname);
                    //                    result.push_back(to_string(j.profID));
                    result.push_back(j.verbalRating);
                    result.push_back(to_string(j.numRatings));
                    result.push_back(to_string(j.overallRating));
                    result.push_back(j.dept);
                    result.push_back(j.uni);
                    //                    result.push_back(to_string(j.uniID));
                }
                if (menu == 3 && name == j.fullname) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;

                    result.push_back(j.fullname);
                    //                    result.push_back(to_string(j.profID));
                    result.push_back(j.verbalRating);
                    result.push_back(to_string(j.numRatings));
                    result.push_back(to_string(j.overallRating));
                    result.push_back(j.dept);
                    result.push_back(j.uni);
                    //                    result.push_back(to_string(j.uniID));
                }
                if (menu == 4 && stoi(name) == j.profID) {
                    cout << "Name: " << j.fullname << endl;
                    cout << "ID: " << j.profID << endl;
                    cout << "Verbal Rating: " << j.verbalRating << endl;
                    cout << "Number of Ratings: " << j.numRatings << endl;
                    cout << "Numerical Rating: " << j.overallRating << endl;
                    cout << "Department: " << j.dept << endl;
                    cout << "University: " << j.uni << endl;
                    cout << "University ID: " <<j.uniID << endl;
                    cout << endl;

                    result.push_back(j.fullname);
                    //                    result.push_back(to_string(j.profID));
                    result.push_back(j.verbalRating);
                    result.push_back(to_string(j.numRatings));
                    result.push_back(to_string(j.overallRating));
                    result.push_back(j.dept);
                    result.push_back(j.uni);
                    //                    result.push_back(to_string(j.uniID));
                }
                if (menu == 6) {
                    if (j.uniID == stoi(name)){
                        cout << j.fullname << endl;

                        result.push_back(j.fullname);
                        //                    result.push_back(to_string(j.profID));
                        result.push_back(j.verbalRating);
                        result.push_back(to_string(j.numRatings));
                        result.push_back(to_string(j.overallRating));
                        result.push_back(j.dept);
                        result.push_back(j.uni);
                        //                    result.push_back(to_string(j.uniID));
                    }
                }
            }
        }
        return result;
    }

    vector<Professor> storeUni(string uni){
            cout << "University: " << uni << endl;

            vector<Professor> temp;
            for (const auto& i : table[Hash(uni,tableSize)]) {
                if (i.uni == uni) {
                    temp.push_back(i);
                }
            }
            return temp;
        }

        vector<string> uniRank(string uni){
            vector<Professor>temp = storeUni(uni);
            sort( temp.begin( ), temp.end( ), [ ]( const Professor& lhs, const Professor& rhs )
            {
                return lhs.rank > rhs.rank;
            });

            vector<string> result;
            for(int i = 0; i< 10; i++) {
                if(temp.size() >= i+1) {

                    result.push_back(temp[i].fullname);
//                    result.push_back(to_string(temp[i].profID));
                    result.push_back(temp[i].verbalRating);
                    result.push_back(to_string(temp[i].numRatings));
                    result.push_back(to_string(temp[i].overallRating));
                    result.push_back(temp[i].dept);
                    result.push_back(temp[i].uni);
//                    result.push_back(to_string(temp[i].uniID));

                }
            }
            return result;
        }

        vector<Professor> storeDept (string uni, string dept){
            vector<Professor> temp;
            for (const auto& i : table[Hash(uni,tableSize)]) {
                if (i.uni == uni && i.dept == dept) {
                    temp.push_back(i);
                }
            }
            return temp;
        }

        vector<string> deptRank(string uni, string dept){
            vector<Professor>temp = storeDept(uni,dept);
            sort( temp.begin( ), temp.end( ), [ ]( const Professor& lhs, const Professor& rhs )
            {
                return lhs.rank > rhs.rank;
            });

            vector<string> result;
            for(int i = 0; i< 10; i++) {
                if(temp.size() >= i+1) {

                    result.push_back(temp[i].fullname);
    //                result.push_back(to_string(temp[i].profID));
                    result.push_back(temp[i].verbalRating);
                    result.push_back(to_string(temp[i].numRatings));
                    result.push_back(to_string(temp[i].overallRating));
                    result.push_back(temp[i].dept);
                    result.push_back(temp[i].uni);
    //                result.push_back(to_string(temp[i].uniID));

                }
            }
            return result;
        }

    void tester() {
        for(int i = 0; i < tableSize; i++){
            cout << "Index " << i << ": ";
            for(const auto& j : table[i])
                cout << j.fullname << " -> " << endl;
        }
    }


};

