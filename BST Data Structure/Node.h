#pragma once
#include "University.h"

/*
Node Class:

Purpose -

*Each node of BST is a University Object which stores all the Professors

            Each Node Stores:
                    University
                    Left ptr
                    Right ptr
*/

class Node {
private:
    University college; //University Object
public:
    Node* left; //Left ptr
    Node* right; //Right ptr
    Node(University college): college(college), left(nullptr), right(nullptr) {} //Specific Constructor for University
    Node(University college, Node* left, Node* right): college(college), left(left), right(right) {} //More in depth Constructor

    ~Node() //Destructor
    {
        delete left;
        delete right;
    }

    /*
     Function: access
     Purpose: accessor function that returns the University
     */
    University access() {
        return college;
    }
};

