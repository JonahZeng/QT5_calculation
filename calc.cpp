#include "calc.h"
#include <QGridLayout>
#include <QVBoxLayout>

PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent), m_log(), m_singleStr(""), m_strList(), m_leftBkt_cnt(0), m_rightBkt_cnt(0)
{
    QPushButton* btn1 = new QPushButton("1", this);
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn2 = new QPushButton("2", this);
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn3 = new QPushButton("3", this);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn4 = new QPushButton("4", this);
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn5 = new QPushButton("5", this);
    btn5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn6 = new QPushButton("6", this);
    btn6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn7 = new QPushButton("7", this);
    btn7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn8 = new QPushButton("8", this);
    btn8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn9 = new QPushButton("9", this);
    btn9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn0 = new QPushButton("0", this);
    btn0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnPt = new QPushButton(".", this);
    btnPt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnClear = new QPushButton("C", this);
    btnClear->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnPlus = new QPushButton("+", this);
    btnPlus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnMins = new QPushButton("-", this);
    btnMins->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnMult = new QPushButton("x", this);
    btnMult->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnDiv = new QPushButton("/", this);
    btnDiv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnEqual = new QPushButton("=", this);
    btnEqual->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* btnLeftbarcket = new QPushButton("(", this);
    btnLeftbarcket->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btnRightbarcket = new QPushButton(")", this);
    btnRightbarcket->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_lbl = new QLabel("0", this);

    m_showLog = new QTextEdit("print operator warning here!", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->setHorizontalSpacing(8);
    grid->setVerticalSpacing(8);

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

    grid->setRowStretch(0,1);
    grid->setRowMinimumHeight(0,20);
    grid->setRowStretch(1,1);
    grid->setRowMinimumHeight(1,20);
    grid->setRowStretch(2,1);
    grid->setRowMinimumHeight(1,20);
    grid->setRowStretch(3,1);
    grid->setRowMinimumHeight(1,20);
    grid->setRowStretch(4,1);
    grid->setRowMinimumHeight(1,20);
    grid->setRowStretch(5,1);

    grid->setColumnStretch(0,1);
    grid->setColumnStretch(1,1);
    grid->setColumnStretch(2,1);
    grid->setColumnStretch(3,1);
    grid->setColumnStretch(4,1);

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

/*
 * press '=' , calc result
*/
void PlusMinus::on_btnEqual(){
    if(lastIsNone())
        return;
    else if(lastIsLeftBracket() || lastIsOperator() || lastIsPoint()){
        flushLog("can't calc result now!");
        return;
    }
    else if(lastIsNum()){
        if(m_leftBkt_cnt != m_rightBkt_cnt){
            flushLog("left bracket count != right bracket count, can't calc result");
            return;
        }
        m_strList<<m_singleStr;
    }
    else if(lastIsRightBracket()){
        if(m_leftBkt_cnt != m_rightBkt_cnt){
            flushLog("left bracket count != right bracket count, can't calc result");
            return;
        }
    }

    if(m_strList.size()<=2){
        flushLog("no enough input, do nothing!");
        return;
    }
    QStack<QString> userInput;
    QStringList popOut;
#ifdef DEBUG_MODE
    qDebug()<<m_strList;
#endif
    QStringList::iterator it = m_strList.begin();
    while(it != m_strList.end()){
        if(*it != ")"){
            userInput.push(*it);
            it++;
#ifdef DEBUG_MODE
            qDebug()<<userInput<<1;
#endif
        }
        else{
            while(userInput.top()!="("){
                popOut.append(userInput.pop());
            }
            userInput.pop();//pop "("
            QString res;
            try{
                res = calcPopOut(popOut);// note: reverse order
                popOut.clear();
            }
            catch(DivZeroException& de){
                flushLog(de.getMsg());
                return;
            }
            catch(QException& ex){
                flushLog("no supported operator!");
                return;
            }
            userInput.push(res);
            it++;
#ifdef DEBUG_MODE
            qDebug()<<userInput<<2;
#endif
        }
    }
#ifdef DEBUG_MODE
    qDebug()<<userInput<<3;
#endif
    m_strList.clear();
    m_singleStr.clear();
    m_leftBkt_cnt = m_rightBkt_cnt = 0;
    try{
        m_lbl->setText(calcFinalOut(userInput.toList()));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    catch(DivZeroException& de){
        flushLog(de.getMsg());
        m_lbl->setText("0");
#ifdef MACOS
        m_lbl->repaint();
#endif
        return;
    }
    catch(QException& ex){
        flushLog("no supported operator!");
        m_lbl->setText("0");
#ifdef MACOS
        m_lbl->repaint();
#endif
        return;
    }
}

/*
example: popout: 1-3*2  the result is 2*3-1 = 5
*/
QString PlusMinus::calcPopOut(QStringList& popOut){
    double res = 0.0;
    if(popOut.count("*")>0 || popOut.count("/")>0){
        if(popOut.last()=="-"){
            popOut.pop_back();
            popOut.last().prepend('-');
        }
        QStringList::size_type size = popOut.size();
        for(QStringList::size_type idx = size-2; idx>=1; idx--){
            if(popOut[idx]=="*"){
                QString tmpStr;
                if(popOut[idx-1].contains('.') || popOut[idx+1].contains('.')){
                    double tmp = popOut[idx+1].toDouble() * popOut[idx-1].toDouble();
                    tmpStr = QString("%1").arg(tmp);
                }
                else{
                    int tmp = popOut[idx+1].toInt() * popOut[idx-1].toInt();
                    tmpStr = QString("%1").arg(tmp);
                }
                popOut.removeAt(idx+1);
                popOut.removeAt(idx);
                popOut[idx-1] = tmpStr;
            }
            else if(popOut[idx]=="/"){
                if(popOut[idx-1].toDouble()==0.0)
                    throw DivZeroException("can't divied by 0!");
                double tmp = popOut[idx+1].toDouble() / popOut[idx-1].toDouble();
                QString tmpStr = QString("%1").arg(tmp);
                popOut.removeAt(idx+1);
                popOut.removeAt(idx);
                popOut[idx-1] = tmpStr;
            }
        }
    }
    //else{//have no '*' and '/'
        if(popOut.last()=="-"){
            popOut.pop_back();
            popOut.last().prepend('-');
        }
        QStringList::size_type size = popOut.size();
        res = popOut[size-1].toDouble();
        for(QStringList::size_type idx=size-2; idx>=1; idx-=2){
            if(popOut[idx]=="+"){
                if(popOut[idx-1].contains('.'))
                    res += popOut[idx-1].toDouble();
                else
                    res += popOut[idx-1].toInt();
            }
            else if(popOut[idx]=="-"){
                if(popOut[idx-1].contains('.'))
                    res -= popOut[idx-1].toDouble();
                else
                    res -= popOut[idx-1].toInt();
            }
            else if(popOut[idx]=="*"){
                if(popOut[idx-1].contains('.'))
                    res *= popOut[idx-1].toDouble();
                else
                    res *= popOut[idx-1].toInt();
            }
            else if(popOut[idx]=="/"){
                if(popOut[idx-1].contains('.')){
                    double tmp = popOut[idx-1].toDouble();
                    if(tmp==0.0)
                        throw DivZeroException("can't divied by 0!");
                    res /= tmp;
                }
                else{
                    int tmp = popOut[idx-1].toInt();
                    if(tmp==0)
                        throw DivZeroException("can't divied by 0!");
                    res /= tmp;
                }
            }
            else{
                throw QException();
            }
    }
    QString ret("%1");
    return ret.arg(res);
}

QString PlusMinus::calcFinalOut(QStringList finalOut){
    QStringList reverseList;
    for(QStringList::reverse_iterator it=finalOut.rbegin(); it!=finalOut.rend(); it++){
        reverseList.append(*it);
    }
    return calcPopOut(reverseList);
}

void PlusMinus::on_btnLeftBracket(){
    if(lastIsLeftBracket() || lastIsNone() || lastIsOperator()){
        m_strList<<"(";
        m_leftBkt_cnt++;
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsNum() || lastIsRightBracket()){
        flushLog("can not input \"(\" now !");
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
#ifdef MACOS
        m_lbl->repaint();
#endif
        }
        else
            flushLog("can not input \")\" now !");
    }
    else if(lastIsRightBracket()){
        if(m_leftBkt_cnt>m_rightBkt_cnt){
            m_strList<<")";
            m_rightBkt_cnt++;
            m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
        }
        else
            flushLog("can not input \")\" now !");
    }
}
void PlusMinus::on_btn1() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("1");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"1\" now !");
    }
}

void PlusMinus::on_btn2() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("2");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"2\" now !");
    }
}

void PlusMinus::on_btn3() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("3");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"3\" now !");
    }
}

void PlusMinus::on_btn4() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("4");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"4\" now !");
    }
}

void PlusMinus::on_btn5() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("5");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"5\" now !");
    }
}

void PlusMinus::on_btn6() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("6");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"6\" now !");
    }
}

void PlusMinus::on_btn7() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("7");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"7\" now !");
    }
}

void PlusMinus::on_btn8() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("8");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"8\" now !");
    }
}

void PlusMinus::on_btn9() {
    if(lastIsNone() || lastIsLeftBracket() || lastIsOperator() || lastIsNum() || lastIsPoint()){
        m_singleStr.append("9");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"9\" now !");
    }
}

void PlusMinus::on_btn0() {
    if(lastIsRightBracket()){
        flushLog("can not input \"0\" now !");
    }
    else if(lastIsNone()){
        return;
    }
    else if(lastIsNum() || lastIsPoint()){
        m_singleStr.append("0");
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsOperator() || lastIsLeftBracket()){
        m_singleStr = "0";
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
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
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsNone()){
        m_singleStr = "0.";
        m_lbl->setText(m_strList.join("")+m_singleStr);
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \".\" now !");
    }
}

//press 'C', clear all, reset screen to '0'
void PlusMinus::on_btnClear(){
    m_singleStr.clear();
    m_strList.clear();
    m_leftBkt_cnt = 0;
    m_rightBkt_cnt = 0;
    m_lbl->setText("0");
#ifdef MACOS
    m_lbl->repaint();
#endif
}

//press '+', append last string to list, append "+" to list; clear single string;
void PlusMinus::on_btnPlus(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"+";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsRightBracket()){
        m_strList<<"+";
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"+\" now !");
    }
}

void PlusMinus::on_btnMins(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"-";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsRightBracket() || lastIsNone() || lastIsLeftBracket()){
        m_strList<<"-";
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"-\" now !");
    }
}

/*
 * press 'x'
*/
void PlusMinus::on_btnMult(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"*";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsRightBracket()){
        m_strList<<"*";
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"*\" now !");
    }
}

/*
* press '/'
*/
void PlusMinus::on_btnDiv(){
    if(lastIsNum()){
        m_strList<<m_singleStr<<"/";
        m_singleStr.clear();
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else if(lastIsRightBracket()){
        m_strList<<"*";
        m_lbl->setText(m_strList.join(""));
#ifdef MACOS
        m_lbl->repaint();
#endif
    }
    else{
        flushLog("can not input \"/\" now !");
    }
}

/*
used for output operation warnning
*/
void PlusMinus::flushLog(QString ch){
    if(m_log.size()>=LOG_LINE)
        m_log.dequeue();
    QString curTime = QTime::currentTime().toString("hh:mm:ss");
    QString tmp("[%1]: %2");
    m_log.enqueue(tmp.arg(curTime).arg(ch));
    m_showLog->setText(m_log.join("\n"));
#ifdef MACOS
    m_showLog->repaint();
#endif
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
