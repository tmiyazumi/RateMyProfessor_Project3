#include "ratemyprof.h"
#include "ui_ratemyprof.h"
#include <QStringList>
#include <QComboBox>
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
#include <QTableView>


QString menuOption;
QString menuOption2;

rateMyProf::rateMyProf(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rateMyProf)
{
    ui->setupUi(this);
    QStringList list_items;

    list_items << "Search Professor by first name" << "Search Professor by last name" << "Search Professor by first and last name" << "Search Professor by ID" << "Directory of all Professors in a University by name" << "Directory of all Professors in a University by ID" << "Search for highest rated professors in a University" << "Search for highest rated professors in a certain University in a certain department";

    ui->comboBox->addItems(list_items);
    ui->tableView->activateWindow();
    ui->label_5->setText("BST: No results shown:");
    ui->label_6->setText("Will display time taken for BST structure here!");
    ui->label_7->setText("Hash: No results shown:");
    ui->label_8->setText("Will display time taken for Hash structure here!");

    QList<QString> profNames;
    QList<QString> verbalRatings;
    QList<QString> numRatings;
    QList<QString> numericalRatings;
    QList<QString> departments;
    QList<QString> universities;

    //create data that is tabular in nature
//    profNames.append("Antonio");
//    profNames.append("Taise");
//    profNames.append("Yash");
//    verbalRatings.append("Ghost");
//    verbalRatings.append("Asian");
//    verbalRatings.append("Fake Asain");
//    numRatings.append("0");
//    numRatings.append("10000");
//    numRatings.append("0");
//    numericalRatings.append("1.2");
//    numericalRatings.append("5.0");
//    numericalRatings.append("1.2");
//    departments.append("Mean");
//    departments.append("Fabulous");
//    departments.append("Hash");
//    universities.append("UF");
//    universities.append("UF");
//    universities.append("UF");



    // Create model:
    TestModel *profData = new TestModel(this);

    // Populate model with data:
    profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

    // Connect model to table view:
    ui->tableView->setModel(profData);
    ui->tableView_2->setModel(profData);

    // Make table header visible and display table:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
    ui->tableView_2->horizontalHeader()->setVisible(true);
    ui->tableView_2->show();


}

rateMyProf::~rateMyProf()
{
    delete ui;
}


TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:

void TestModel::populateData(const QList<QString> &fullName, const QList<QString> &verbalRating,const QList<QString> &numOfRatings, const QList<QString> &numericalRating, const QList<QString> &department, const QList<QString> &university){
    prof_name.clear();
    prof_name = fullName;
    verbal_rating.clear();
    verbal_rating = verbalRating;
    number_of_ratings.clear();
    number_of_ratings = numOfRatings;
    numerical_rating.clear();
    numerical_rating = numericalRating;
    department_name.clear();
    department_name = department;
    university_name.clear();
    university_name = university;

    return;
}

void TestModel::clearData(){
    prof_name.clear();
    verbal_rating.clear();
    number_of_ratings.clear();
    numerical_rating.clear();
    department_name.clear();
    university_name.clear();

    return;
}
int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return prof_name.length();
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return prof_name[index.row()];
    }
    else if (index.column() == 1) {
        return verbal_rating[index.row()];
    }
    else if (index.column() == 2) {
        return number_of_ratings[index.row()];
    }
    else if (index.column() == 3) {
        return numerical_rating[index.row()];
    }
    else if (index.column() == 4) {
        return department_name[index.row()];
    }
    else if (index.column() == 5) {
        return university_name[index.row()];
    }
    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Name");
        } else if (section == 1) {
            return QString("Verbal Rating");
        }
        else if (section == 2) {
            return QString("Number of Ratings");
        }
        else if (section == 3){
            return QString("Numerical Ratings");
        }
        else if (section == 4){
            return QString("Department");
        }
        else if (section == 5){
            return QString("University");
        }
    }
    return QVariant();
}

void rateMyProf::on_comboBox_currentTextChanged(const QString &arg1)
{
    QStringList university_items;
//    vector<string> list = tree->UniversityList();
//    for (int i = 0; list.size(); i ++){
//        university_items.append(QString::fromStdString(list[i]));
//    }

    university_items << "Boston College" <<  "Boston University" <<  "Brandeis University" <<  "Brown University" <<  "California Institute of Technology" <<  "Carnegie Mellon University" <<  "Case Western Reserve University" <<  "College of William and Mary" <<"Columbia University" <<  "Cornell University" <<  "Dartmouth College" <<  "Duke University" <<  "Emory University" <<"Florida Agricultural and Mechanical University" <<  "Florida Atlantic University" <<  "Florida International University" <<  "Florida Polytechnic University" <<  "Florida State University" <<  "Georgetown University" <<  "Georgia Institute of Technology" <<  "Harvard University" <<  "Johns Hopkins University" <<  "Lehigh University" <<  "Massachusetts Institute of Technology" <<  "New College of Florida" <<  "New York University" <<  "Northwestern University" <<  "Princeton University" <<  "Rice University" <<  "Stanford University" <<  "The University of North Carolina at Chapel Hill" <<  "Tufts University" <<  "Tulane University" <<  "University Of Illinois at Urbana - Champaign" <<  "University of California Berkeley" <<  "University of California Davis" <<  "University of California Irvine" <<  "University of California Los Angeles (UCLA)" <<  "University of California San Diego" <<  "University of California Santa Barbara" <<  "University of Central Florida" <<  "University of Chicago" <<  "University of Florida" <<  "University of Georgia" <<  "Universityof Michigan" <<  "University of North Florida" <<  "University of Notre Dame" <<  "University of Pennsylvania" <<  "University of Rochester" <<  "University of South Florida" <<  "University of Southern California" <<  "University of Texas at Austin" <<  "University of Virginia" <<  "University of West Florida" <<  "University of Wisconsin - Madison" <<  "Vanderbilt University" <<  "Wake Forest University" <<  "Washington University in St. Louis" <<  "Yale University";

    menuOption = arg1;
//    ui-> label->setText(arg1);
    if (arg1 == "Search Professor by first name") {
           ui-> label_4->setText("Enter First Name of Professor");
           ui->comboBox_2->clear();
           ui->comboBox_2->addItem("N/A");
       }
       else if (arg1 == "Search Professor by last name") {
           ui-> label_4->setText("Enter Last Name of Professor");
           ui->comboBox_2->clear();
           ui->comboBox_2->addItem("N/A");
       }
       else if (arg1 == "Search Professor by first and last name") {
           ui-> label_4->setText("Enter First and Last Name of Professor");
           ui->comboBox_2->clear();
           ui->comboBox_2->addItem("N/A");
       }
        else if (arg1 == "Search Professor by ID") {
            ui-> label_4->setText("Enter Professor ID");
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("N/A");
        }
       else if (arg1 == "Directory of all Professors in a University by name") {
            ui-> label_4->setText("Use the list above to get the directory!");
            ui->comboBox_2->clear();
            ui->comboBox_2->addItems(university_items);
        }

        else if (arg1 == "Directory of all Professors in a University by ID") {
            ui-> label_4->setText("Enter University ID");
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("N/A");
        }
        else if (arg1 == "Search for highest rated professors in a University") {
            ui-> label_4->setText("Use the list above!");
            ui->comboBox_2->clear();
            ui->comboBox_2->addItems(university_items);
        }
         else if (arg1 == "Search for highest rated professors in a certain University in a certain department") {
            ui-> label_4->setText("Enter the department name");
            ui->comboBox_2->clear();
            ui->comboBox_2->addItems(university_items);
        }
}


void rateMyProf::on_pushButton_clicked()
{
    QString input = ui->lineEdit->text();
    std::string str = input.toStdString();
    tree->SearchFirstName(str);
//    std::cout << arg1.toStdString() << std::endl;
    if (menuOption == "Search Professor by first name" && input != ""){
        ui->lineEdit->setText("worked");
        ui->label_5->setText("Showing BST result for: " + input);
        ui->label_7->setText("Showing Hash Table result for: " + input);

        QList<QString> profNames;
        QList<QString> verbalRatings;
        QList<QString> numRatings;
        QList<QString> numericalRatings;
        QList<QString> departments;
        QList<QString> universities;

        auto start = std::chrono::steady_clock::now();

        vector<string> result = tree->SearchFirstName(input.toStdString());

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
        double functionTime = bstTime + elapsedTime;
        functionTime /= 1e9;

        QString stringTime = QString::number(functionTime);

        ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");
        int number = 6;

        for (int i = 0; i < result.size(); i++){
            if (i%number == 0){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                profNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                verbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                departments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                universities.append(qstr);
            }
        }

        // Create model:
        TestModel *profData = new TestModel(this);

        // Populate model with data:
        profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

        // Connect model to table view:
        ui->tableView->setModel(profData);
        ui->tableView->show();

        QList<QString> htProfNames;
        QList<QString> htVerbalRatings;
        QList<QString> htNumRatings;
        QList<QString> htNumericalRatings;
        QList<QString> htDepartments;
        QList<QString> htUniversities;

        auto htStart = std::chrono::steady_clock::now();

        vector<string> htResult = ht->printSpecMenu(1, input.toStdString());

        auto htEnd = std::chrono::steady_clock::now();
        double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
        double htFunctionTime = hashTime + htElapsedTime;
        htFunctionTime /= 1e9;

        QString htStringTime = QString::number(htFunctionTime);

        ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

        for (int i = 0; i < htResult.size(); i++){
            if (i%number == 0){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htProfNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htVerbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htDepartments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htUniversities.append(qstr);
            }
        }

        // Create model:
        TestModel *htProfData = new TestModel(this);

        // Populate model with data:
        htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

        // Connect model to table view:
        ui->tableView_2->setModel(htProfData);
        ui->tableView_2->show();

    }

    if (menuOption == "Search Professor by last name" && input != ""){
           ui->lineEdit->setText("worked");
           ui->label_5->setText("Showing BST result for: " + input);
           ui->label_7->setText("Showing Hash Table result for: " + input);

           QList<QString> profNames;
           QList<QString> verbalRatings;
           QList<QString> numRatings;
           QList<QString> numericalRatings;
           QList<QString> departments;
           QList<QString> universities;

           auto start = std::chrono::steady_clock::now();

           vector<string> result = tree->SearchLastName(input.toStdString());

           auto end = std::chrono::steady_clock::now();
           double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
           double functionTime = bstTime + elapsedTime;
           functionTime /= 1e9;

           QString stringTime = QString::number(functionTime);
           ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

           int number = 6;

           for (int i = 0; i < result.size(); i++){
               if (i%number == 0){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   profNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   verbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   departments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   universities.append(qstr);
               }
           }


           // Create model:
           TestModel *profData = new TestModel(this);

           // Populate model with data:
           profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

           // Connect model to table view:
           ui->tableView->setModel(profData);
           ui->tableView->show();

           QList<QString> htProfNames;
           QList<QString> htVerbalRatings;
           QList<QString> htNumRatings;
           QList<QString> htNumericalRatings;
           QList<QString> htDepartments;
           QList<QString> htUniversities;

           auto htStart = std::chrono::steady_clock::now();

           vector<string> htResult = ht->printSpecMenu(2, input.toStdString());

           auto htEnd = std::chrono::steady_clock::now();
           double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
           double htFunctionTime = hashTime + htElapsedTime;
           htFunctionTime /= 1e9;

           QString htStringTime = QString::number(htFunctionTime);

           ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

           for (int i = 0; i < htResult.size(); i++){
               if (i%number == 0){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htProfNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htVerbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htDepartments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htUniversities.append(qstr);
               }
           }

           // Create model:
           TestModel *htProfData = new TestModel(this);

           // Populate model with data:
           htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

           // Connect model to table view:
           ui->tableView_2->setModel(htProfData);
           ui->tableView_2->show();
    }
    if (menuOption == "Search Professor by first and last name" && input != ""){
           ui->lineEdit->setText("worked");
           ui->label_5->setText("Showing BST result for: " + input);
           ui->label_7->setText("Showing Hash Table result for: " + input);

           QList<QString> profNames;
           QList<QString> verbalRatings;
           QList<QString> numRatings;
           QList<QString> numericalRatings;
           QList<QString> departments;
           QList<QString> universities;

           auto start = std::chrono::steady_clock::now();

           vector<string> result = tree->SearchFullName(input.toStdString());

           auto end = std::chrono::steady_clock::now();
           double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
           double functionTime = bstTime + elapsedTime;
           functionTime /= 1e9;

           QString stringTime = QString::number(functionTime);
           ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

           int number = 6;

           for (int i = 0; i < result.size(); i++){
               if (i%number == 0){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   profNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   verbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   departments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   universities.append(qstr);
               }
           }

           // Create model:
           TestModel *profData = new TestModel(this);

           // Populate model with data:
           profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

           // Connect model to table view:
           ui->tableView->setModel(profData);
           ui->tableView->show();

           QList<QString> htProfNames;
           QList<QString> htVerbalRatings;
           QList<QString> htNumRatings;
           QList<QString> htNumericalRatings;
           QList<QString> htDepartments;
           QList<QString> htUniversities;

           auto htStart = std::chrono::steady_clock::now();

           vector<string> htResult = ht->printSpecMenu(3, input.toStdString());

           auto htEnd = std::chrono::steady_clock::now();
           double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
           double htFunctionTime = hashTime + htElapsedTime;
           htFunctionTime /= 1e9;

           QString htStringTime = QString::number(htFunctionTime);

           ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

           for (int i = 0; i < htResult.size(); i++){
               if (i%number == 0){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htProfNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htVerbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htDepartments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htUniversities.append(qstr);
               }
           }

           // Create model:
           TestModel *htProfData = new TestModel(this);

           // Populate model with data:
           htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

           // Connect model to table view:
           ui->tableView_2->setModel(htProfData);
           ui->tableView_2->show();
    }
    if (menuOption == "Search Professor by ID" && input != ""){
           ui->lineEdit->setText("searched");
           ui->label_5->setText("Showing BST result for: " + input);
           ui->label_7->setText("Showing Hash Table result for: " + input);

           int id = input.toInt();

           QList<QString> profNames;
           QList<QString> verbalRatings;
           QList<QString> numRatings;
           QList<QString> numericalRatings;
           QList<QString> departments;
           QList<QString> universities;

           auto start = std::chrono::steady_clock::now();

           vector<string> result = tree->SearchProfID(id);

           auto end = std::chrono::steady_clock::now();
           double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
           double functionTime = bstTime + elapsedTime;
           functionTime /= 1e9;

           QString stringTime = QString::number(functionTime);
           ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

           int number = 6;

           for (int i = 0; i < result.size(); i++){
               if (i%number == 0){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   profNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   verbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   numericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   departments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = result[i];
                   QString qstr = QString::fromStdString(str);
                   universities.append(qstr);
               }
           }

           // Create model:
           TestModel *profData = new TestModel(this);

           // Populate model with data:
           profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

           // Connect model to table view:
           ui->tableView->setModel(profData);
           ui->tableView->show();

           QList<QString> htProfNames;
           QList<QString> htVerbalRatings;
           QList<QString> htNumRatings;
           QList<QString> htNumericalRatings;
           QList<QString> htDepartments;
           QList<QString> htUniversities;

           auto htStart = std::chrono::steady_clock::now();

           vector<string> htResult = ht->printSpecMenu(4, input.toStdString());

           auto htEnd = std::chrono::steady_clock::now();
           double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
           double htFunctionTime = hashTime + htElapsedTime;
           htFunctionTime /= 1e9;

           QString htStringTime = QString::number(htFunctionTime);

           ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

           for (int i = 0; i < htResult.size(); i++){
               if (i%number == 0){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htProfNames.append(qstr);
               }
               else if (i%number == 1){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htVerbalRatings.append(qstr);
               }
               else if (i%number == 2){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumRatings.append(qstr);
               }
               else if (i%number == 3){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htNumericalRatings.append(qstr);
              }
               else if (i%number == 4){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htDepartments.append(qstr);
               }
               else if (i%number == 5){
                   std::string str = htResult[i];
                   QString qstr = QString::fromStdString(str);
                   htUniversities.append(qstr);
               }
           }

           // Create model:
           TestModel *htProfData = new TestModel(this);

           // Populate model with data:
           htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

           // Connect model to table view:
           ui->tableView_2->setModel(htProfData);
           ui->tableView_2->show();
    }
    if (menuOption == "Directory of all Professors in a University by name" && input == ""){
//        ui->lineEdit->setText("searched");
        ui->label_5->setText("Showing BST result for: " + input);
        ui->label_7->setText("Showing Hash Table result for: " + input);

        QList<QString> profNames;
        QList<QString> verbalRatings;
        QList<QString> numRatings;
        QList<QString> numericalRatings;
        QList<QString> departments;
        QList<QString> universities;

        auto start = std::chrono::steady_clock::now();

        vector<string> result = tree->PrintDirectoryName(menuOption2.toStdString());

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
        double functionTime = bstTime + elapsedTime;
        functionTime /= 1e9;

        QString stringTime = QString::number(functionTime);
        ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

        int number = 6;

        for (int i = 0; i < result.size(); i++){
            if (i%number == 0){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                profNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                verbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                departments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                universities.append(qstr);
            }
        }

        // Create model:
        TestModel *profData = new TestModel(this);

        // Populate model with data:
        profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

        // Connect model to table view:
        ui->tableView->setModel(profData);
        ui->tableView->show();

        QList<QString> htProfNames;
        QList<QString> htVerbalRatings;
        QList<QString> htNumRatings;
        QList<QString> htNumericalRatings;
        QList<QString> htDepartments;
        QList<QString> htUniversities;

        auto htStart = std::chrono::steady_clock::now();

        vector<string> htResult = ht->printAll(menuOption2.toStdString(), 5);

        auto htEnd = std::chrono::steady_clock::now();
        double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
        double htFunctionTime = hashTime + htElapsedTime;
        htFunctionTime /= 1e9;

        QString htStringTime = QString::number(htFunctionTime);

        ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");


        for (int i = 0; i < htResult.size(); i++){
            if (i%number == 0){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htProfNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htVerbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htDepartments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htUniversities.append(qstr);
            }
        }

        // Create model:
        TestModel *htProfData = new TestModel(this);

        // Populate model with data:
        htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

        // Connect model to table view:
        ui->tableView_2->setModel(htProfData);
        ui->tableView_2->show();

    }
    if (menuOption == "Directory of all Professors in a University by ID" && input != ""){
        ui->lineEdit->setText("searched");
        ui->label_5->setText("Showing BST result for: " + input);
        ui->label_7->setText("Showing Hash Table result for: " + input);

        int id = input.toInt();

        QList<QString> profNames;
        QList<QString> verbalRatings;
        QList<QString> numRatings;
        QList<QString> numericalRatings;
        QList<QString> departments;
        QList<QString> universities;

        auto start = std::chrono::steady_clock::now();

        vector<string> result = tree->PrintDirectoryID(id);

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
        double functionTime = bstTime + elapsedTime;
        functionTime /= 1e9;

        QString stringTime = QString::number(functionTime);
        ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

        int number = 6;

        for (int i = 0; i < result.size(); i++){
            if (i%number == 0){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                profNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                verbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                departments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                universities.append(qstr);
            }
        }

        // Create model:
        TestModel *profData = new TestModel(this);

        // Populate model with data:
        profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

        // Connect model to table view:
        ui->tableView->setModel(profData);
        ui->tableView->show();

        QList<QString> htProfNames;
        QList<QString> htVerbalRatings;
        QList<QString> htNumRatings;
        QList<QString> htNumericalRatings;
        QList<QString> htDepartments;
        QList<QString> htUniversities;

        auto htStart = std::chrono::steady_clock::now();

        vector<string> htResult = ht->printSpecMenu(6, input.toStdString());

        auto htEnd = std::chrono::steady_clock::now();
        double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
        double htFunctionTime = hashTime + htElapsedTime;
        htFunctionTime /= 1e9;

        QString htStringTime = QString::number(htFunctionTime);

        ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");


        for (int i = 0; i < htResult.size(); i++){
            if (i%number == 0){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htProfNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htVerbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htDepartments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htUniversities.append(qstr);
            }
        }

        // Create model:
        TestModel *htProfData = new TestModel(this);

        // Populate model with data:
        htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

        // Connect model to table view:
        ui->tableView_2->setModel(htProfData);
        ui->tableView_2->show();

    }
    if (menuOption == "Search for highest rated professors in a University" && input == ""){

        ui->label_5->setText("BST: Showing top 10 recommended from highest to lowest rank in " + menuOption2);
        ui->label_7->setText("Hash: Showing top 10 recommended from highest to lowest rank in " + menuOption2);

        int id = input.toInt();

        QList<QString> profNames;
        QList<QString> verbalRatings;
        QList<QString> numRatings;
        QList<QString> numericalRatings;
        QList<QString> departments;
        QList<QString> universities;

        auto start = std::chrono::steady_clock::now();

        vector<string> result = tree->BestProfInUniversity(menuOption2.toStdString());

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
        double functionTime = bstTime + elapsedTime;
        functionTime /= 1e9;

        QString stringTime = QString::number(functionTime);
        ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

        int number = 6;

        for (int i = 0; i < result.size(); i++){
            if (i%number == 0){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                profNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                verbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                departments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                universities.append(qstr);
            }
        }

        // Create model:
        TestModel *profData = new TestModel(this);

        // Populate model with data:
        profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

        // Connect model to table view:
        ui->tableView->setModel(profData);
        ui->tableView->show();

        QList<QString> htProfNames;
        QList<QString> htVerbalRatings;
        QList<QString> htNumRatings;
        QList<QString> htNumericalRatings;
        QList<QString> htDepartments;
        QList<QString> htUniversities;

        auto htStart = std::chrono::steady_clock::now();

        vector<string> htResult = ht->uniRank(menuOption2.toStdString());

        auto htEnd = std::chrono::steady_clock::now();
        double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
        double htFunctionTime = hashTime + htElapsedTime;
        htFunctionTime /= 1e9;

        QString htStringTime = QString::number(htFunctionTime);

        ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

        for (int i = 0; i < htResult.size(); i++){
            if (i%number == 0){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htProfNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htVerbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htDepartments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htUniversities.append(qstr);
            }
        }

        // Create model:
        TestModel *htProfData = new TestModel(this);

        // Populate model with data:
        htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

        // Connect model to table view:
        ui->tableView_2->setModel(htProfData);
        ui->tableView_2->show();

    }
    if (menuOption == "Search for highest rated professors in a certain University in a certain department" && input != ""){

        ui->label_5->setText("BST: Showing top 10 recommended from highest to lowest rank in " + menuOption2 + " Department: " + input);
        ui->label_7->setText("Hash: Showing top 10 recommended from highest to lowest rank in " + menuOption2 + " Department: " + input);

        QList<QString> profNames;
        QList<QString> verbalRatings;
        QList<QString> numRatings;
        QList<QString> numericalRatings;
        QList<QString> departments;
        QList<QString> universities;

        auto start = std::chrono::steady_clock::now();

        vector<string> result = tree->BestProfInDept(menuOption2.toStdString(),input.toStdString());

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(end-start).count());
        double functionTime = bstTime + elapsedTime;
        functionTime /= 1e9;

        QString stringTime = QString::number(functionTime);
        ui-> label_6->setText("Time taken for BST approach of the menu option: " + stringTime + "s");

        int number = 6;

        for (int i = 0; i < result.size(); i++){
            if (i%number == 0){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                profNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                verbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                numericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                departments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = result[i];
                QString qstr = QString::fromStdString(str);
                universities.append(qstr);
            }
        }

        // Create model:
        TestModel *profData = new TestModel(this);

        // Populate model with data:
        profData->populateData(profNames,verbalRatings, numRatings, numericalRatings, departments, universities);

        // Connect model to table view:
        ui->tableView->setModel(profData);
        ui->tableView->show();

        QList<QString> htProfNames;
        QList<QString> htVerbalRatings;
        QList<QString> htNumRatings;
        QList<QString> htNumericalRatings;
        QList<QString> htDepartments;
        QList<QString> htUniversities;

        auto htStart = std::chrono::steady_clock::now();

        vector<string> htResult = ht->deptRank(menuOption2.toStdString(), input.toStdString());

        auto htEnd = std::chrono::steady_clock::now();
        double htElapsedTime = double (std::chrono::duration_cast <std::chrono::nanoseconds>(htEnd-htStart).count());
        double htFunctionTime = hashTime + htElapsedTime;
        htFunctionTime /= 1e9;

        QString htStringTime = QString::number(htFunctionTime);

        ui-> label_8->setText("Time taken for hash approach of the menu option: " + htStringTime + "s");

        for (int i = 0; i < htResult.size(); i++){
            if (i%number == 0){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htProfNames.append(qstr);
            }
            else if (i%number == 1){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htVerbalRatings.append(qstr);
            }
            else if (i%number == 2){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumRatings.append(qstr);
            }
            else if (i%number == 3){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htNumericalRatings.append(qstr);
           }
            else if (i%number == 4){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htDepartments.append(qstr);
            }
            else if (i%number == 5){
                std::string str = htResult[i];
                QString qstr = QString::fromStdString(str);
                htUniversities.append(qstr);
            }
        }

        // Create model:
        TestModel *htProfData = new TestModel(this);

        // Populate model with data:
        htProfData->populateData(htProfNames,htVerbalRatings, htNumRatings, htNumericalRatings, htDepartments, htUniversities);

        // Connect model to table view:
        ui->tableView_2->setModel(htProfData);
        ui->tableView_2->show();
    }
}


void rateMyProf::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    menuOption2 = arg1;
}

