#ifndef VIRTUAL_ACCOUNT_H
#define VIRTUAL_ACCOUNT_H

#include "ParentAccount.h"
#include "ChildAccount.h"
#include "RootAccount.h"

class VirtualAccount : public ChildAccount, public ParentAccount {
private:
    VirtualAccount(const QString& name, VirtualAccount& parent): AbstractAccount(name, parent.getType()), ChildAccount(name, parent.getType(), parent), ParentAccount(name, parent.getType()) {}
    VirtualAccount(const QString& name, const AccountType& type, RootAccount& root): AbstractAccount(name, type), ChildAccount(name, type, root), ParentAccount(name, type) {}
    friend class ParentAccount;
};

#endif // VIRTUAL_ACCOUNT_H
