#ifndef CHILD_ACCOUNT_H
#define CHILD_ACCOUNT_H

#include "AbstractAccount.h"

class ParentAccount;

class ChildAccount : public virtual AbstractAccount {
private:
    ParentAccount& parent;
public:
    ChildAccount(const QString& name, const AccountType& type, ParentAccount& parent);
    ~ChildAccount();
    RootAccount& getRootAccount() override;
    ParentAccount& getParent() { return parent; }
};

#endif // CHILD_ACCOUNT_H
