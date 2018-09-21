#include "calc.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent), m_singleStr(""), m_strList(), m_leftBkt_cnt(0), m_rightBkt_cnt(0)
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

    QGridLayout *grid = new QGridLayout(this);
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

    grid->addWidget(m_lbl, 0, 0, 1, 5);
    m_lbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    m_lbl->setFrameStyle(QFrame::Box | QFrame::Plain);
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
    if(!m_singleStr.isEmpty())// '(' must be after +-*/(, for these 5 case, the single str must be empty
        return;
    else if(m_strList.size() == 0){
        m_strList<<QString("(");
        m_singleStr.clear();
        m_lbl->setText("(");
        m_leftBkt_cnt++;
    }
    else{
        const QString str = m_strList.constLast();//get last string in stringlist, str list must not be empty
        if(str=="+" || str=="-" || str=="*" || str=="/" || str=="("){
            m_strList<<"(";
            m_singleStr.clear();
            m_lbl->setText(m_strList.join(""));
            m_leftBkt_cnt++;
        }
    }
}

void PlusMinus::on_btnRightBracket(){
    if(m_singleStr.isEmpty()){
        if(m_strList.size() == 0)
            return;
        else{
            const QString str = m_strList.constLast();
            if(str=="(" || str=="+" || str=="-" || str=="*" || str=="/")
                return;
            else{
                if(m_leftBkt_cnt <= m_rightBkt_cnt)
                    return;
                m_strList<<")";
                m_lbl->setText(m_strList.join(""));
                m_rightBkt_cnt++;
            }
        }
    }
    else{
        if(m_singleStr.endsWith("."))
            return;
        else{
            if(m_leftBkt_cnt <= m_rightBkt_cnt)
                return;
            m_strList<<m_singleStr<<")";
            m_singleStr.clear();
            m_lbl->setText(m_strList.join(""));
            m_rightBkt_cnt++;
        }
    }
}
void PlusMinus::on_btn1() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("1");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn2() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("2");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn3() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("3");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn4() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("4");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn5() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("5");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn6() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("6");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn7() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("7");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn8() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("8");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn9() {
    if(m_singleStr.isEmpty() && m_strList.size()>0 && m_strList.constLast()==")")
        return;
    m_singleStr.append("9");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btn0() {
    if(m_singleStr.isEmpty()){
        if(m_strList.size()==0){
            m_singleStr = "0";
        }
        else{
            if(m_strList.constLast()==")")
                return;
        }
    }
    else if(m_singleStr == "0")
        return;
    else
        m_singleStr.append("0");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

void PlusMinus::on_btnPt(){
    if(m_singleStr.contains('.'))
        return;
    else if(m_singleStr.isEmpty())
        m_singleStr = "0.";
    else
        m_singleStr.append(".");
    m_lbl->setText(m_strList.join("")+m_singleStr);
}

//press 'C', clear all, reset screen to '0'
void PlusMinus::on_btnClear(){
    m_singleStr.clear();
    m_strList.clear();
    m_lbl->setText("0");
}

//press '+', append last string to list, append "+" to list; clear single string;
void PlusMinus::on_btnPlus(){
    if(!m_singleStr.isEmpty())
        m_strList<<m_singleStr<<"+";
    else
        m_strList<<"+";
    m_singleStr.clear();
    m_lbl->setText(m_strList.join(""));
}

void PlusMinus::on_btnMins(){
    if(!m_singleStr.isEmpty())
        m_strList<<m_singleStr<<"-";
    else
        m_strList<<"-";
    m_singleStr.clear();
    m_lbl->setText(m_strList.join(""));
}

void PlusMinus::on_btnMult(){
    if(!m_singleStr.isEmpty())
        m_strList<<m_singleStr<<"*";
    else
        m_strList<<"*";
    m_singleStr.clear();
    m_lbl->setText(m_strList.join(""));
}

void PlusMinus::on_btnDiv(){
    if(!m_singleStr.isEmpty())
        m_strList<<m_singleStr<<"/";
    else
        m_strList<<"/";
    m_singleStr.clear();
    m_lbl->setText(m_strList.join(""));
}


