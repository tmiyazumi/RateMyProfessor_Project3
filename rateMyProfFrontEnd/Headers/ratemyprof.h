#ifndef RATEMYPROF_H
#define RATEMYPROF_H

#include <QMainWindow>
#include "BST.h"
#include "HashTable.h"
#include <QAbstractTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class rateMyProf; }
QT_END_NAMESPACE


class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TestModel(QObject *parent = 0);

    void populateData(const QList<QString> &fullName, const QList<QString> &verbalRating, const QList<QString> &numOfRatings, const QList<QString> &numericalRating, const QList<QString> &department, const QList<QString> &university);
    void clearData();

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> prof_name;
    QList<QString> verbal_rating;
    QList<QString> number_of_ratings;
    QList<QString> numerical_rating;
    QList<QString> department_name;
    QList<QString> university_name;


};

class rateMyProf : public QMainWindow
{
    Q_OBJECT
    BST* tree;
    HashTable* ht;
    double bstTime;
    double hashTime;

public:
    rateMyProf(QWidget *parent = nullptr);
    ~rateMyProf();
    void setTree(BST* Tree){
        this->tree = Tree;
    };
    void setTime(double defaultTime, double htTime){
        bstTime = defaultTime;
        hashTime = htTime;
    };
    void setHash(HashTable* hash){
        ht = hash;
    }

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::rateMyProf *ui;
};
#endif // RATEMYPROF_H
