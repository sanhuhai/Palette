#include "Palette.h"

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    //ui.setupUi(this);
    display();
}

void Palette::display() {
    createCtrlFrame();
    createContentFrame();
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
    showConnect();
}

void Palette::createCtrlFrame() {       //颜色选择区
    ctrlFrame = new QFrame;
    windowLabel = new QLabel("QPalette::Window");
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    //connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(showWindow()));
    windowTextLabel = new QLabel("QPalette::WindowText");
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    //connect(windowTextComboBox, SIGNAL(activated(int)), this, SLOT(showWindowText()));
    buttonLabel = new QLabel("QPalette::Button");
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    //connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(showButton()));
    buttonTextLabel = new QLabel("QPalette::ButtonText");
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    //connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(showButtonText()));
    baseLabel = new QLabel("QPalette::Base");
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    //connect(baseComboBox, SIGNAL(activated(int)), this, SLOT(showBase()));
    QGridLayout* leftLayout = new QGridLayout(ctrlFrame);
    leftLayout->setSpacing(20);
    leftLayout->addWidget(windowLabel, 0, 0);
    leftLayout->addWidget(windowComboBox, 0, 1);
    leftLayout->addWidget(windowTextLabel, 1, 0);
    leftLayout->addWidget(windowTextComboBox, 1, 1);
    leftLayout->addWidget(buttonLabel, 2, 0);
    leftLayout->addWidget(buttonComboBox, 2, 1);
    leftLayout->addWidget(buttonTextLabel, 3, 0);
    leftLayout->addWidget(buttonTextComboBox, 3, 1);
    leftLayout->addWidget(baseLabel, 4, 0);
    leftLayout->addWidget(baseComboBox, 4, 1);
}

void Palette::createContentFrame() {        //具体显示面板
    contentFrame = new QFrame;
    inputLabel = new QLabel("请选择一个值:");
    inputComboBox = new QComboBox;
    inputStringLabel = new QLabel("请输入字符串:");
    inputStringLineEdit = new QLineEdit;
    textEdit = new QTextEdit;
    okBtn = new QPushButton("确定");
    cancelBtn = new QPushButton("取消");
    QGridLayout* topLayout = new QGridLayout;
    topLayout->addWidget(inputLabel, 0, 0);
    topLayout->addWidget(inputComboBox, 0, 1);
    topLayout->addWidget(inputStringLabel, 1, 0);
    topLayout->addWidget(inputStringLineEdit, 1, 1);
    topLayout->addWidget(textEdit, 2, 0, 1, 2);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okBtn);
    buttonLayout->addWidget(cancelBtn);
    QVBoxLayout* rightLayout = new QVBoxLayout(contentFrame);
    rightLayout->addLayout(topLayout);
    rightLayout->addLayout(buttonLayout);
}

void Palette::fillColorList(QComboBox* comboBox) {      //插入颜色
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach(color,colorList) {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void Palette::showWindow() {
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palette::showWindowText() {
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[windowTextComboBox->currentIndex()]);
	QPalette p = contentFrame->palette();
	p.setColor(QPalette::WindowText, color);
	contentFrame->setPalette(p);
	//contentFrame->update();
}

void Palette::showButton() {
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
	QPalette p = contentFrame->palette();
	p.setColor(QPalette::Button, color);
	contentFrame->setPalette(p);
	contentFrame->update();
}

void Palette::showButtonText() {
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
	QPalette p = contentFrame->palette();
	p.setColor(QPalette::ButtonText, color);
	contentFrame->setPalette(p);
	contentFrame->update();
}

void Palette::showBase() {
	QStringList colorList = QColor::colorNames();
	QColor color = QColor(colorList[baseComboBox->currentIndex()]);
	QPalette p = contentFrame->palette();
	p.setColor(QPalette::Base, color);
	contentFrame->setPalette(p);
	contentFrame->update();
}

void Palette::showConnect() {
    connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(showWindow()));
    connect(windowTextComboBox, SIGNAL(activated(int)), this, SLOT(showWindowText()));
    connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(showButton()));
    connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(showButtonText()));
    connect(baseComboBox, SIGNAL(activated(int)), this, SLOT(showBase()));
}