#include "calc.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent), m_log(), m_singleStr(""), m_strList(), m_leftBkt_cnt(0), m_rightBkt_cnt(0)
{
    QPushButton* btn1 = new QPushButton("1", this);
    QPushButton* btn2 = new QPushButton("2", this);
    QPushButton* btn3 = new QPushButton("3", this);
    QPushButton* btn4 = new QPushButton("4", this);
    QPushButton* btn5 = new QPushButton("5", this);
    QPushButton* btn6 = new QPushButton("6", this);
    QPushButton* btn7 = new QPushButton("7", this);
    QPushButton* btn8 = new QPushButton("8", this);
    QPushButton* btn9 = new QPushButton("9", this);
    QPushButton* btn0 = new QPushButton("0", this);
    QPushButton* btnPt = new QPushButton(".", this);
    QPushButton* btnClear = new QPushButton("C", this);
    QPushButton* btnPlus = new QPushButton("+", this);
    QPushButton* btnMins = new QPushButton("-", this);
    QPushButton* btnMult = new QPushButton("x", this);
    QPushButton* btnDiv = new QPushButton("/", this);
    QPushButton* btnEqual = new QPushButton("=", this);

    QPushButton* btnLeftbarcket = new QPushButton("(", this);
    QPushButton* btnRightbarcket = new QPushButton(")", this);
    m_lbl = new QLabel("0", this);

    m_showLog = new QTextEdit("print operator warning here!", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(m_lbl, 0, 0, 1, 5);

    grid->addWidget(btn7, 1, 0);
    grid->addWidget(btn8, 1, 1);
    grid->addWidget(btn9, 1, 2);
    grid->addWidget(btnLeftbarcket, 1, 3);
    grid->addWidget(btnRightbarcket, 1, 4);

    grid->addWidget(btn4, 2, 0);
    grid->addWidget(btn5, 2, 1);
    grid->addWidget(btn6, 2, 2);
    grid->addWidget(btnPlus, 2, 3);
    grid->addWidget(btnMins, 2, 4);

    grid->addWidget(btn1, 3, 0);
    grid->addWidget(btn2, 3, 1);
    grid->addWidget(btn3, 3, 2);
    grid->addWidget(btnMult, 3, 3);
    grid->addWidget(btnDiv, 3, 4);

    grid->addWidget(btn0, 4, 0);
    grid->addWidget(btnPt, 4, 1);
    grid->addWidget(btnClear, 4, 2);
    grid->addWidget(btnEqual, 4, 3);

    grid->addWidget(m_showLog, 5, 0, 1, 5);

    m_lbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_lbl->setFrameStyle(QFrame::Box | QFrame::Panel);
    m_showLog->setAlignment(Qt::AlignLeft);
    m_showLog->setFrameStyle(QFrame::Panel | QFrame::Box);
    m_showLog->setReadOnly(true);

    QFont ft= m_lbl->font();
    ft.setPointSize(16);
    m_lbl->setFont(ft);

    setLayout(grid);

    connect(btn1, &QPushButton::clicked, this, &PlusMinus::on_btn1);
    connect(btn2, &QPushButton::clicked, this, &PlusMinus::on_btn2);
    connect(btn3, &QPushButton::clicked, this, &PlusMinus::on_btn3);
    connect(btn4, &QPushButton::clicked, this, &PlusMinus::on_btn4);
    connect(btn5, &QPushButton::clicked, this, &PlusMinus::on_btn5);
    connect(btn6, &QPushButton::clicked, this, &PlusMinus::on_btn6);
    connect(btn7, &QPushButton::clicked, this, &PlusMinus::on_btn7);
    connect(btn8, &QPushButton::clicked, this, &PlusMinus::on_btn8);
    connect(btn9, &QPushButton::clicked, this, &PlusMinus::on_btn9);
    connect(btn0, &QPushButton::clicked, this, &PlusMinus::on_btn0);
    connect(btnPt, &QPushButton::clicked, this, &PlusMinus::on_btnPt);
    connect(btnClear, &QPushButton::clicked, this, &PlusMinus::on_btnClear);
    connect(btnPlus, &QPushButton::clicked, this, &PlusMinus::on_btnPlus);
    connect(btnMins, &QPushButton::clicked, this, &PlusMinus::on_btnMins);
    connect(btnMult, &QPushButton::clicked, this, &PlusMinus::on_btnMult);
    connect(btnDiv, &QPushButton::clicked, this, &PlusMinus::on_btnDiv);
    connect(btnEqual, &QPushButton::clicked, this, &PlusMinus::on_btnEqual);
    connect(btnLeftbarcket, &QPushButton::clicked, this, &PlusMinus::on_btnLeftBracket);
    connect(btnRightbarcket, &QPushButton::clicked, this, &PlusMinus::on_btnRightBracket);
}

void PlusMinus::on_btnEqual(){//input = , calc result
    if(!m_singleStr.isEmpty())
        m_strList<<m_singleStr;
    m_singleStr.clear();

    QStringList popOut;
}

void PlusMinus::on_btnLeftBracket(){
    if(lastIsLeftBracket() || lastIsNone() || lastIsOperator()){
        m_strList<<"(";
        m_leftBkt_cnt++;
        m_lbl->setText(m_strList.join(""));
    }
    else if(lastIsNum() || lastIsRightBracket()){
        flushLog("(");
    }
}

void PlusMinus::on_btnRightBracket(){
    if(lastIsNone() || lastIsLeftBracket() || lastIsPoint())
        flushLog(")");
    else if(lastIsNum()){
        if(m_leftBkt_cnt>m_rightBkt_cnt){
            m_strList<<m_singleStr<<")";
            m_rightBkt_cnt++;
            m_singleStr.clear();
            m_lbl->setText(m_strList.join(""));
        }
        else
            flushLog(")");
    }
}
void PlusMinus::on_btn1() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("1");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("1");
    }
}

void PlusMinus::on_btn2() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("2");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("2");
    }
}

void PlusMinus::on_btn3() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("3");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("3");
    }
}

void PlusMinus::on_btn4() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("4");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("4");
    }
}

void PlusMinus::on_btn5() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("5");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("5");
    }
}

void PlusMinus::on_btn6() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("6");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("6");
    }
}

void PlusMinus::on_btn7() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("7");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("7");
    }
}

void PlusMinus::on_btn8() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("8");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("8");
    }
}

void PlusMinus::on_btn9() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("9");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog("9");
    }
}

void PlusMinus::on_btn0() {
    if(lastIsRightBracket()){
        flushLog("0");
    }
    else if(lastIsNone()){
        return;
    }
    else if(lastIsNum() || lastIsPoint()){
        m_singleStr.append("0");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else if(lastIsOperator() || lastIsLeftBracket()){
        m_singleStr = "0";
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
}

void PlusMinus::on_btnPt(){
    if(lastIsNum()){
        if(m_singleStr.contains('.')){
            flushLog(".");
            return;
        }
        m_singleStr.append(".");
        m_lbl->setText(m_strList.join("")+m_singleStr);
    }
    else{
        flushLog(".");
    }
}

//press 'C', clear all, reset screen to '0'
void PlusMinus::on_btnClear(){
    m_singleStr.clear();
    m_strList.clear();
    m_lbl->setText("0");
}

//press '+', append last string to list, append "+" to list; clear single string;
void PlusMinus::on_btnPlus(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"+";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
    }
    else if(lastIsRightBracket()){
        m_strList<<"+";
        m_lbl->setText(m_strList.join(""));
    }
    else{
        flushLog("+");
    }
}

void PlusMinus::on_btnMins(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"-";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
    }
    else if(lastIsRightBracket() || lastIsNone()){
        m_strList<<"-";
        m_lbl->setText(m_strList.join(""));
    }
    else{
        flushLog("-");
    }
}

void PlusMinus::on_btnMult(){
    if(lastIsNum() || lastIsRightBracket()){
        m_strList<<m_singleStr<<"*";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
    }
    else{
        flushLog("*");
    }
}

void PlusMinus::on_btnDiv(){
    if(lastIsNum() || lastIsRightBracket()){
        m_strList<<m_singleStr<<"/";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
    }
    else{
        flushLog("/");
    }
}

void PlusMinus::flushLog(QString ch){
    if(m_log.size()>=LOG_LINE)
        m_log.dequeue();
    QString tmp("can not input \"%1\"here!");
    m_log.enqueue(tmp.arg(ch));
    m_showLog->setText(m_log.join("\n"));
}

/*
below functions used for get input status
*/
bool PlusMinus::lastIsLeftBracket(){
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()=="(")
        return true;
    else
        return false;
}

bool PlusMinus::lastIsRightBracket(){
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return true;
    else
        return false;
}

bool PlusMinus::lastIsNum(){
    if(m_singleStr.size()>0 && *(m_singleStr.rbegin())!='.')
        return true;
    else
        return false;
}

bool PlusMinus::lastIsOperator(){
    if(m_singleStr.isEmpty() && m_strList.size()>0){
        const QString last = m_strList.constLast();
        if(last=="+" || last=="-" || last=="*" || last=="/")
            return true;
        else
            return false;
    }
    else
        return false;
}

bool PlusMinus::lastIsNone(){
    if(m_strList.size()==0 && m_singleStr.isEmpty())
        return true;
    else
        return false;
}

bool PlusMinus::lastIsPoint(){
    if(m_singleStr.size()>0 && m_singleStr.endsWith('.'))
        return true;
    else
        return false;
}
