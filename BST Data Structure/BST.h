#pragma once
#include "Node.h"
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

#include "University.h"
#include "Professor.h"

typedef std::pair<string, Professor> together;

/*
Binary Search Tree Class:

Purpose -

*Acts as a template that stores the root of the tree.
*Each node of BST is a University Object.

Visual Representation -
                           ROOT
                        University
                       /          \
                      /            \
                 University     University
                    /\              /\
                   /  \            /  \

Continues for all 59 Universities in Data Structure...
*/

class BST {
private:
    Node* root; //Stores the BST root node
    unordered_map<int, string> ID_TO_UNIVERSITY; //Conversion between University ID and University Name
public:
    //Default Constructor
    BST() {
        root = nullptr;
    }

    //Constructor takes queue of vectors from CSV
    BST(queue<Professor> line) {
        root = nullptr; //Sets Root to Nullptr
        unordered_map<int, University> universities; //Stores University Objects

        //Empties the queue of data and separates it into University Objects
        while(!line.empty()) {
            //Stores current vector from queue
            Professor Temp = line.front();

            //Checks if University already exists
            if(universities.count(Temp.uniID) == 0)
            {
                //Creates University Object
                University placeholder(Temp.uni,Temp.uniID);
                //Updates conversion map
                ID_TO_UNIVERSITY[Temp.uniID] = Temp.uni;
                //Stores the new University Object
                universities[Temp.uniID] = placeholder;
            }

            //Initializes firstname conversion map
            if(universities[Temp.uniID].FIRST_TO_FULL.count(Temp.firstname) == 0)
            {
                vector<string> t;
                universities[Temp.uniID].FIRST_TO_FULL[Temp.firstname] = t;
            }

            //Initializes lastname conversion map
            if(universities[Temp.uniID].LAST_TO_FULL.count(Temp.firstname) == 0)
            {
                vector<string> t;
                universities[Temp.uniID].LAST_TO_FULL[Temp.firstname] = t;
            }

            if(universities[Temp.uniID].DEPT_TO_FULL.count(Temp.dept) == 0)
            {
                vector<string> t;
                universities[Temp.uniID].LAST_TO_FULL[Temp.firstname] = t;
            }

            //Adds recent Professor information to conversion maps
            universities[Temp.uniID].FIRST_TO_FULL[Temp.firstname].push_back(Temp.fullname);
            universities[Temp.uniID].LAST_TO_FULL[Temp.lastname].push_back(Temp.fullname);
            universities[Temp.uniID].ID_TO_FULL[Temp.profID] = Temp.fullname;
            universities[Temp.uniID].DEPT_TO_FULL[Temp.dept].push_back(Temp.fullname);

            //Stores the Professor in the appropriate university
            universities[Temp.uniID].storage[Temp.fullname] = Temp;
            //Pops and moves to next item in queue (REPEATS PROCESS TILL EMPTY)
            line.pop();
        }

        //Takes all University Objects that were created and inserts them randomly into the BST Data Structure
        for (auto it = universities.begin(); it != universities.end(); it++) {
            root = insert(root, it->second);
        }
    }

    /*
     Function: accessRoot
     Purpose: acts as an accessor function for the BST root
     */
    Node* accessRoot() {
        return root;
    }

    /*
     Function: insert
     Parameters: Node* , University
     Purpose: Utilized by constructor to insert into the BST
     Note: Sorts BST by the University name
     */
    Node* insert(Node* root, University college) {
        //Inserts the new University and breaks recursion
        if(root == nullptr) {
            Node* n = new Node(college);
            return n;
        }

        if (college.name < root->access().name) {
            //Traverses left
            root->left = insert(root->left, college);
        }
        else {
            //Traverses right
            root->right = insert(root->right, college);
        }
        return root;
    }

    /*
     Function: SearchFirstName
     Parameters: string
     Purpose: Performs Option 1 (Searching for a Professor by First Name)
     Note: Utilized by main
     */
    vector<string> SearchFirstName(string name) {
        int i = 0;
        //Recursive Inorder Traversal for matching First Names
        vector<string> t;
        InOrderTraversalFirstName(accessRoot(), name, i, t);

        //If the reference changes that means something was printed
        //Otherwise the function prints that nothing was found
        if(i == 0)
        {
            vector<string> x;
            x.push_back("null");
            return x;
            //cout << "ERROR NOT FOUND" << endl;
        }
        return t;
    }

    /*
     Function: SearchLastName
     Parameters: string
     Purpose: Performs Option 2 (Searching for a Professor by Last Name)
     Note: Utilized by main
     */
    vector<string> SearchLastName(string name) {
        int i = 0;
        //Recursive Inorder Traversal for matching Last Names
        vector<string> t;
        InOrderTraversalLastName(accessRoot(), name, i, t);

        //If the reference changes that means something was printed
        //Otherwise the function prints that nothing was found
        if(i == 0)
        {
            vector<string> x;
            x.push_back("null");
            return x;
            //cout << "ERROR NOT FOUND" << endl;
        }
        return t;
    }

    /*
     Function: SearchFullName
     Parameters: string
     Purpose: Performs Option 3 (Searching for a Professor by Full Name)
     Note: Utilized by main
     */
    vector<string> SearchFullName(string name) {
        int i = 0;
        //Recursive Inorder Traversal for matching Full Names
        vector<string> t;
        InOrderTraversalFullName(accessRoot(), name, i, t);

        //If the reference changes that means something was printed
        //Otherwise the function prints that nothing was found
        if(i == 0)
        {
            vector<string> x;
            x.push_back("null");
            return x;
            //cout << "ERROR NOT FOUND" << endl;
        }
        return t;
    }

    /*
     Function: SearchProfID
     Parameters: int
     Purpose: Performs Option 4 (Searching for a Professor by RMY ID)
     Note: Utilized by main
     */
    vector<string> SearchProfID(int ID) {
        int i = 0;
        //Recursive Inorder Traversal for matching ID
        vector<string> t;
        InOrderTraversalID(accessRoot(), ID, i, t);

        //If the reference changes that means something was printed
        //Otherwise the function prints that nothing was found
        if(i == 0)
        {
            vector<string> x;
            x.push_back("null");
            return x;
            //cout << "ERROR: UNIVERSITY NOT FOUND" << endl;
        }
        return t;
    }

    /*
     Function: PrintDirectoryName
     Parameters: string
     Purpose: Performs Option 5 (Prints University's Professors by University Name)
     Note: Utilized by main
     */
    vector<string> PrintDirectoryName (string name)
    {
        //Returns the node matching the name
        Node* result = searchUniversity(accessRoot(), name);

        //If result equals nullptr it means the University did not exist
        if(result == nullptr)
        {
            vector<string> t;
            t.push_back("null");
            return t;
            //cout << "ERROR: UNIVERSITY NOT FOUND" << endl;
        }
        else
        {
            //Otherwise it prints the name of all Professors
            vector<string> t = printMap(result->access());
            return t;
        }

    }

    /*
     Function: PrintDirectoryName
     Parameters: string
     Purpose: Performs Option 6 (Prints University's Professors by University ID)
     Note: Utilized by main
     */
    vector<string> PrintDirectoryID (int ID)
    {
        //Returns the node matching the ID
        Node* result = searchUniversityID(accessRoot(), ID);

        //If result equals nullptr it means the University did not exist
        if(result == nullptr)
        {
            vector<string> t;
            t.push_back("null");
            return t;
            //cout << "ERROR: UNIVERSITY NOT FOUND" << endl;
        }
        else
        {
            //Otherwise it prints the name of all Professors
            vector<string> t = printMap(result->access());
            return t;
        }
    }


    /*
     Function: BestProfInUniversity
     Parameters: string
     Purpose: Performs Option 7 (Prints the best Professors from a University by University name)
     Note: Utilized by main
     */
    vector<string> BestProfInUniversity(string name){
        Node* result = searchUniversity(accessRoot(), name);
        vector<string> y;
        if(result == nullptr)
        {
            y.push_back("null");
            return y;
//            cout << "ERROR: UNIVERSITY NOT FOUND" << endl;
        }
        else
        {
            map<string,Professor> t = result->access().storage;

            vector<together> temp;
            copy(t.begin(), t.end(), back_inserter<vector<together>>(temp));

            sort(temp.begin(), temp.end(), [](const together &one, const together &two) {
                return one.second.rank > two.second.rank;
            });

            for(int i = 0; i< 10; i++) {
                if(temp.size() >= i+1) {
                    y.push_back(temp[i].second.fullname);
                    //y.push_back(to_string(temp[i].second.profID));
                    y.push_back(temp[i].second.verbalRating);
                    y.push_back(to_string(temp[i].second.numRatings));
                    y.push_back(to_string(temp[i].second.overallRating));
                    y.push_back(temp[i].second.dept);
                    y.push_back(temp[i].second.uni);
                    //y.push_back(to_string(temp[i].second.uniID));

//                    cout << endl;
//                    cout << i+1 << ". " << temp[i].second.fullname << endl;
//                    cout << "Rank: " << temp[i].second.rank << endl;
//                    cout << "Department: " << temp[i].second.dept << endl;
//                    cout << "University: " << temp[i].second.uni << endl;

                }
            }
        }
        return y;
    }

    vector<string> BestProfInDept(string uni, string dept){
        Node* result = searchUniversity(accessRoot(), uni);
        vector<string> y;

        if(result == nullptr)
        {
            y.push_back("null uni");
            return y;
//            cout << "ERROR: UNIVERSITY NOT FOUND" << endl;
        }
        else
        {
            map<string,Professor> placeholder = result->access().storage;
            if(result->access().DEPT_TO_FULL.count(dept) == 0)
            {
                y.push_back("null dept");
                return y;
//            cout << "ERROR: DEPARTMENT NOT FOUND" << endl;
            }
            else
            {
                vector<string> temp = result->access().DEPT_TO_FULL[dept];
                vector<Professor> r;

                for(int i = 0; i<temp.size(); i++) {
                    r.push_back(placeholder[temp[i]]);
                }

                sort(r.begin(), r.end(), [](const Professor &one, const Professor &two) {
                    return one.rank > two.rank;
                });

                for(int i = 0; i< 10; i++) {
                    if(r.size() >= i+1) {
                        y.push_back(r[i].fullname);
                        //y.push_back(to_string(r[i].profID));
                        y.push_back(r[i].verbalRating);
                        y.push_back(to_string(r[i].numRatings));
                        y.push_back(to_string(r[i].overallRating));
                        y.push_back(r[i].dept);
                        y.push_back(r[i].uni);
                        //y.push_back(to_string(r[i].uniID));

//                        cout << endl;
//                        cout << i+1 << ". " << r[i].fullname << endl;
//                        cout << "Rank: " << r[i].rank << endl;
//                        cout << "Department: " << r[i].dept << endl;
//                        cout << "University: " << r[i].uni << endl;
                    }
                }
            }
            return y;
        }
    }

    /*
     Function: searchUniversity
     Purpose: Searches for a University by name
     Note: Utilized by PrintDirectoryName
     */
    Node* searchUniversity(Node* root, string name) {
        if(root == nullptr) {
            return nullptr; //When the University is not found
        }
        if(root->access().name == name) {
            return root; //When the University is found
        }
        if(root->access().name < name) //Traverses left or right based on the name
            return searchUniversity(root->right, name);
        return searchUniversity(root->left, name);
    }

    /*
     Function: searchUniversityID
     Purpose: Searches for a University by ID
     Note: Utilized by PrintDirectoryID
     */
    Node* searchUniversityID(Node* root, int ID) {
        string name = ID_TO_UNIVERSITY[ID]; //Converts ID to corresponding name
        return searchUniversity(root, name); //Searches for University
    }

    /*
     Function: InOrderTraversalFirstName
     Purpose: Searches for a Professor by first name
     Note: Utilized by SearchFirstName
     */
    void InOrderTraversalFirstName(Node* root, string name, int& i, vector<string>& result) {
        if(root == nullptr) { //In case the name does not exist
            return;
        }

        //Inorder Traversal (Left)
        InOrderTraversalFirstName(root->left, name, i, result);

        //Checks every node if it has a professor sharing the first name
        if(root->access().FIRST_TO_FULL.count(name) != 0) {
            i = i + 1;
            vector<string> t = root->access().FIRST_TO_FULL[name];
            for(int i = 0; i<t.size(); i++)
            {
                Professor p = root->access().storage[t[i]];
                result.push_back(p.fullname);
                result.push_back(to_string(p.profID));
                result.push_back(p.verbalRating);
                result.push_back(to_string(p.numRatings));
                result.push_back(to_string(p.overallRating));
                result.push_back(p.dept);
                result.push_back(p.uni);
                result.push_back(to_string(p.uniID));
//                cout << "Name: " << p.fullname << endl;
//                cout << "ID: " << p.profID << endl;
//                cout << "Verbal Rating: " << p.verbalRating << endl;
//                cout << "Number of Ratings: " << p.numRatings << endl;
//                cout << "Numerical Rating: " << p.overallRating << endl;
//                cout << "Department: " << p.dept << endl;
//                cout << "University: " << p.uni << endl;
//                cout << "University ID: " <<p.uniID << endl;
            }
        }

        //Inorder Traversal (Right)
        InOrderTraversalFirstName(root->right, name, i, result);
    }

    /*
     Function: InOrderTraversalLastName
     Purpose: Searches for a Professor by last name
     Note: Utilized by SearchLastName
     */
    void InOrderTraversalLastName(Node* root, string name, int& i, vector<string>& result) {
        if(root == nullptr) { //In case the name does not exist
            return;
        }


        //Inorder Traversal (Left)
        InOrderTraversalLastName(root->left, name, i, result);

        //Checks every node if it has a professor sharing the last name
        if(root->access().LAST_TO_FULL.count(name) != 0) {
            i = i + 1;
            vector<string> t = root->access().LAST_TO_FULL[name];
            for(int i = 0; i<t.size(); i++)
            {
                Professor p = root->access().storage[t[i]];
                result.push_back(p.fullname);
                result.push_back(to_string(p.profID));
                result.push_back(p.verbalRating);
                result.push_back(to_string(p.numRatings));
                result.push_back(to_string(p.overallRating));
                result.push_back(p.dept);
                result.push_back(p.uni);
                result.push_back(to_string(p.uniID));

//                cout << endl;
//                Professor p = root->access().storage[t[i]];
//                cout << "Name: " << p.fullname << endl;
//                cout << "ID: " << p.profID << endl;
//                cout << "Verbal Rating: " << p.verbalRating << endl;
//                cout << "Number of Ratings: " << p.numRatings << endl;
//                cout << "Numerical Rating: " << p.overallRating << endl;
//                cout << "Department: " << p.dept << endl;
//                cout << "University: " << p.uni << endl;
//                cout << "University ID: " <<p.uniID << endl;
            }
        }

        //Inorder Traversal (Right)
        InOrderTraversalLastName(root->right, name, i, result);
    }

    /*
     Function: InOrderTraversalFullName
     Purpose: Searches for a Professor by full name
     Note: Utilized by SearchFullName
     */
    void InOrderTraversalFullName(Node* root, string name, int& i,vector<string>& result) {
        if(root == nullptr) { //In case the name does not exist
            return;
        }

        //Inorder Traversal (Left)
        InOrderTraversalFullName(root->left, name, i, result);

        //Checks every node if it has a professor sharing the ID
        if(root->access().storageContains(name))
        {
            Professor p = root->access().storage[name];
            result.push_back(p.fullname);
            result.push_back(to_string(p.profID));
            result.push_back(p.verbalRating);
            result.push_back(to_string(p.numRatings));
            result.push_back(to_string(p.overallRating));
            result.push_back(p.dept);
            result.push_back(p.uni);
            result.push_back(to_string(p.uniID));
            i = i + 1;
            return;

//            cout << endl;
//            Professor p = root->access().storage[name];
//            cout << "Name: " << p.fullname << endl;
//            cout << "ID: " << p.profID << endl;
//            cout << "Verbal Rating: " << p.verbalRating << endl;
//            cout << "Number of Ratings: " << p.numRatings << endl;
//            cout << "Numerical Rating: " << p.overallRating << endl;
//            cout << "Department: " << p.dept << endl;
//            cout << "University: " << p.uni << endl;
//            cout << "University ID: " <<p.uniID << endl;

        }

        //Inorder Traversal (Right)
        InOrderTraversalFullName(root->right, name, i, result);
    }

    /*
     Function: InOrderTraversalID
     Purpose: Searches for a Professor by ID
     Note: Utilized by SearchProfID
     */
    void InOrderTraversalID(Node* root, int ID, int& i, vector<string>& result) {
        if(root == nullptr) { //In case the name does not exist
            return;
        }

        //Inorder Traversal (Left)
        InOrderTraversalID(root->left, ID, i, result);

        //Checks every node if it has a professor sharing the ID
        if(root->access().ID_TO_FULL.count(ID) != 0) {
            i = i + 1;
            Professor p = root->access().storage[root->access().ID_TO_FULL[ID]];
            result.push_back(p.fullname);
            result.push_back(to_string(p.profID));
            result.push_back(p.verbalRating);
            result.push_back(to_string(p.numRatings));
            result.push_back(to_string(p.overallRating));
            result.push_back(p.dept);
            result.push_back(p.uni);
            result.push_back(to_string(p.uniID));

//            cout << endl;
//            Professor p = root->access().storage[root->access().ID_TO_FULL[ID]];
//            cout << "Name: " << p.fullname << endl;
//            cout << "ID: " << p.profID << endl;
//            cout << "Verbal Rating: " << p.verbalRating << endl;
//            cout << "Number of Ratings: " << p.numRatings << endl;
//            cout << "Numerical Rating: " << p.overallRating << endl;
//            cout << "Department: " << p.dept << endl;
//            cout << "University: " << p.uni << endl;
//            cout << "University ID: " <<p.uniID << endl;
        }

        //Inorder Traversal (Right)
        InOrderTraversalID(root->right, ID, i, result);
    }

    /*
     Function: printInorder
     Purpose: Traverses entire tree and prints
     */
    void printInorder(Node* root) {
        if (root == nullptr) //Break case
            return;

        printInorder(root->left); //Inorder Traversal (Left)

        printMap(root->access()); //Prints

        printInorder(root->right); //Inorder Traversal (Right)
    }

    /*
     Function: printMap
     Purpose: prints all Professors in University
     Note: Utilized by printInorder
     */
    vector<string> printMap(University college) {
        vector<string> uni;
        uni.push_back(college.name);
//        cout << endl;
//        cout << "University: " << college.name << endl; //Prints University Name
//        cout << endl;


        for (auto it = college.storage.begin(); it != college.storage.end(); it++) {
            uni.push_back(it->second.fullname);
            uni.push_back(it->second.verbalRating);
            uni.push_back(to_string(it->second.numRatings));
            uni.push_back(to_string(it->second.overallRating));
            uni.push_back(it->second.dept);
            uni.push_back(it->second.uni);
//            cout << it->second.fullname << endl; //Iterates through maps of Professors
        }
        return uni;
    }

    vector<string> UniversityList() {
        vector<string> list;
        for (auto it = ID_TO_UNIVERSITY.begin(); it != ID_TO_UNIVERSITY.end(); it++) {
            list.push_back(it->second);
        }

        sort(list.begin(), list.end());
        return list;
    }


};

