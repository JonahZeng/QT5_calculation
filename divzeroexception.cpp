#include "divzeroexception.h"

DivZeroException::DivZeroException(QString message):QException(),msg(message)
{

}

DivZeroException::~DivZeroException()
{

}

const QString& DivZeroException::getMsg(){
    return this->msg;
}
