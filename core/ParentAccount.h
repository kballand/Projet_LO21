#ifndef PARENT_ACCOUNT_H
#define PARENT_ACCOUNT_H

#include <QVector>
#include <QList>
#include "AbstractAccount.h"
#include "ChildAccount.h"

class BasicAccount;
class VirtualAccount;

class ParentAccount : public virtual AbstractAccount {
private:
    QVector<ChildAccount*> childAccounts;
    friend class ChildAccount;
public:
    ParentAccount(const QString& name, const AccountType& type): AbstractAccount(name, type), childAccounts() {}
    ~ParentAccount();
    double getBalance() const override;
    bool hasChildAccount(const QString& name) const;
    ChildAccount& getChildAccount(const QString& name);
    void deleteChildAccount(const QString& name);
    QList<ChildAccount*> getChildAccounts() const;
    QList<QString> getChildAccountsNames() const;
};

#endif // PARENT_ACCOUNT_H
