#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/*
Professor Struct:

*It is a struct because their is so much information it is easier to be public automatically

Purpose -

*University object stores the University's Professors
*Each node of BST is a University Object which stores all the Professors
*Every Professor Stores a variety of information including their rating

Visual Representation -
    University : List of Professors for University (Map)
    Professor Stores:
                        fullname
                        firstname
                        lastname
                        profID
                        numRatings
                        verbalRating
                        overallRating
                        dept
                        uniID
                        uni
                        rank
*/

struct Professor {
    //Stores a variety of data about the Professor
    int profID, uniID, numRatings;
    double overallRating, rank;
    string fullname, firstname, lastname, verbalRating, dept, uni;

    //Default Constructor
    Professor() {
        fullname = "";
        firstname = "";
        lastname = "";
        profID = 0;
        numRatings = 0;
        verbalRating = "";
        overallRating = 0;
        dept = "";
        uniID = 0;
        uni = "";
        rank = 0.0;
    }

    //Specific Constructor
    Professor(string firstname, string lastname, int profID, int numRatings, string verbalRating, double overallRating, string dept, int uniID, string uni) {
        this->firstname = firstname;
        this->lastname = lastname;
        fullname = firstname + " " + lastname;
        this->profID = profID;
        this->numRatings = numRatings;
        this->verbalRating = verbalRating;
        this->overallRating = overallRating;
        this->dept = dept;
        this->uniID = uniID;
        this->uni = uni;
        this->rank = Rank(numRatings, overallRating);
    }

    /*
     Function: Rank
     Parameters: int numRating, double overallRating
     Purpose: Generates an 'importance' rank based off of the rating and amount of student reviews
     */
    double Rank(int numRatings, double overallRating)
    {
        double temp = overallRating;

        if (numRatings < 10){
            temp = 0;
            return temp;
        }
        else if (numRatings < 20){
            temp = temp - 1.4f;
        }
        else if (numRatings < 30){
            temp = temp - 1.2f;
        }
        else if (numRatings < 40){
            temp = temp - 0.3f;
        }
        else if (numRatings < 50){
            temp = temp - 0.15f;
        }
        if (overallRating >= 4.0 && numRatings <= 30 && numRatings >= 20){
            temp = overallRating;
        }
        if (overallRating >= 4.0 && numRatings >= 50){
            temp = overallRating + 0.2f;
        }
        else if (overallRating >= 4.5 && numRatings >= 50){
            temp = overallRating + 0.4f;
        }
        if (numRatings >= 100 && overallRating >= 4.5){
            temp += 0.65f;
        }

        temp = temp * 55;

        return temp;
    }
};


