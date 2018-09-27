#ifndef DIVZEROEXCEPTION_H
#define DIVZEROEXCEPTION_H

#include <QString>
#include <QException>
class DivZeroException : public QException
{
public:
    DivZeroException(QString message);
    ~DivZeroException();
    void raise() const { throw *this; }
    DivZeroException *clone() const { return new DivZeroException(*this); }
    const QString& getMsg();
private:
    QString msg;
};

#endif // DIVZEROEXCEPTION_H
