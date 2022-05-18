Drop QLineEdit in window -> Name it Display -> Preferred & Expanding
Right Click Window -> Layout -> Layout in Grid 
Create QPushButtons 5 wide and 4 deep -> Preferred & Preferred
7 8 9 / M+
4 5 6 * M-
1 2 3 + M
AC 0 +/- - =
Name them Button0 - Button9, Add, Subtract, Multiply, Divide, Equals, ChangeSign, Clear, MemAdd, MemClear, MemGet
Line Edit Stylesheet
QLineEdit {
     background-color: gray; border: 1px solid gray;
	color: #ffffff;}
10. PushButton Stylesheet
QPushButton {
     background-color: #C0C0C0; border: 1px solid gray;
	border-radius: 0px;
	padding: 5px;
}
QPushButton:pressed {
    background-color: #A9A9A9; border: 1px solid gray;
	border-radius: 0px;
	padding: 5px;
}
 
————— CALC.H —————
 
#ifndef CALC_H
#define CALC_H
 
#include <QMainWindow>
 
// Use the standard UI namespace which is tied to the .ui file
namespace Ui {
class Calc;
}
 
class Calc : public QMainWindow
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT
 
public:
    
    // Declare a constructor and by passing 0 we state this widget
    // has no parent
    explicit Calc(QWidget *parent = 0);
    ~Calc();
 
private:
    Ui::Calc *ui;
 
    // These slots are executed when a signal is
    // submitted (Ex. Number button is clicked)
private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
};
 
#endif // CALC_H
 
————— END CALC.H —————
 
 
————— CALC.CPP —————
 
#include "calc.h"
#include "ui_calc.h"
 
// Holds current value of calculation
double calcVal = 0.0;
 
// Will define if this was the last math button clicked
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
 
// Constructor
Calc::Calc(QWidget *parent) :
 
    // Call the QMainWindow constructor
    QMainWindow(parent),
 
    // Create the UI class and assign it to the ui member
    ui(new Ui::Calc)
{
 
    // Setup the UI
    ui->setupUi(this);
 
    // Put 0.0 in Display
    ui->Display->setText(QString::number(calcVal));
 
    // Will hold references to all the number buttons
    QPushButton *numButtons[10];
 
    // Cycle through locating the buttons
    for(int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);
 
        // Get the buttons by name and add to array
        numButtons[i] = Calc::findChild<QPushButton *>(butName);
 
        // When the button is released call num_pressed()
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
 
    // Connect signals and slots for math buttons
    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
 
    // Connect equals button
    connect(ui->Equals, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));
 
    // Connect change sign
    connect(ui->ChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));
 
 
}
 
Calc::~Calc()
{
    delete ui;
}
 
void Calc::NumPressed(){
 
    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();
 
    // Get number on button
    QString butVal = button->text();
 
    // Get the value in the display
    QString displayVal = ui->Display->text();
 
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
 
        // calcVal = butVal.toDouble();
        ui->Display->setText(butVal);
 
    } else {
        // Put the new number to the right of whats there
        QString newVal = displayVal + butVal;
 
        // Double version of number
        double dblNewVal = newVal.toDouble();
 
        // calcVal = newVal.toDouble();
 
        // Set value in display and allow up to 16
        // digits before using exponents
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
 
    }
}
 
void Calc::MathButtonPressed(){
 
    // Cancel out previous math button clicks
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
 
    // Store current value in Display
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
 
    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();
 
    // Get math symbol on the button
    QString butVal = button->text();
 
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }
 
    // Clear display
    ui->Display->setText("");
 
}
 
void Calc::EqualButtonPressed(){
 
    // Holds new calculation
    double solution = 0.0;
 
    // Get value in display
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
 
    // Make sure a math button was pressed
    if(addTrigger || subTrigger || multTrigger || divTrigger ){
        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        } else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        } else {
            solution = calcVal / dblDisplayVal;
        }
    }
 
    // Put solution in display
    ui->Display->setText(QString::number(solution));
 
}
 
void Calc::ChangeNumberSign(){
 
    // Get the value in the display
    QString displayVal = ui->Display->text();
 
    // Regular expression checks if it is a number
    // plus sign
    QRegExp reg("[-+]?[0-9.]*");
 
    // If it is a number change the sign
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
 
        // Put solution in display
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
 
}
 
 
————— END CALC.CPP —————
 
 
————— MAIN.CPP —————
 
#include "calc.h"
#include <QApplication>
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calc w;
    w.show();
 
    return a.exec();
}
 
————— END MAIN.CPP —————