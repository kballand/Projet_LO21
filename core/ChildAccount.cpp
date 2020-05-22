#include "ChildAccount.h"
#include "ParentAccount.h"

ChildAccount::~ChildAccount() {
    parent.childAccounts.removeAll(this);
}

ChildAccount::ChildAccount(const QString& name, const AccountType& type, ParentAccount& parent): AbstractAccount(name, type), parent(parent) {
    if(type == RACINE)
        throw AccountException("Un compte enfant ne peut pas etre du type RACINE !");
    parent.childAccounts.push_back(this);
}

RootAccount& ChildAccount::getRootAccount() {
    return getParent().getRootAccount();
}
