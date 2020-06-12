#pragma once

#include <QtWidgets/QDialog>
#include<QPalette>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
//#include "ui_Palette.h"
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif //WIN32
class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = Q_NULLPTR);
    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox* comboBox);
    void display();
    void showConnect();
private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();
private:
    //Ui::PaletteClass ui;
    QLabel* windowLabel, * windowTextLabel, * buttonLabel, * buttonTextLabel, * baseLabel, * inputStringLabel, * inputLabel;
    QComboBox* windowComboBox, * windowTextComboBox, * buttonComboBox, * buttonTextComboBox, * baseComboBox, * textComboBox, * inputComboBox;
    QLineEdit* inputStringLineEdit;
    QTextEdit* textEdit;
    QPushButton* okBtn, * cancelBtn;
    QHBoxLayout* mainLayout;
    QFrame* ctrlFrame, * contentFrame;
};
