#ifndef ABSTRACT_ACCOUNT_H
#define ABSTRACT_ACCOUNT_H

#include <QString>
#include "AccountType.h"
#include "AccountException.h"
#include <QDebug>

class RootAccount;

class AbstractAccount {
private:
    QString name;
    AccountType type;
public:
    AbstractAccount()=delete;
    AbstractAccount(const AbstractAccount& account)=delete;
    AbstractAccount& operator=(const AbstractAccount& account)=delete;
    AbstractAccount(const QString& name, const AccountType& type): name(name), type(type) { qDebug() << "Creation du compte : " << name; }
    virtual ~AbstractAccount() { qDebug() << "Destruction du compte : " << name; }
    const QString& getName() const { return name; }
    const AccountType& getType() const { return type; }
    virtual double getBalance() const=0;
    virtual RootAccount& getRootAccount()=0;
};

#endif // ABSTRACT_ACCOUNT_H
