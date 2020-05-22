#ifndef ROOT_ACCOUNT_H
#define ROOT_ACCOUNT_H

#include "ParentAccount.h"

class RootAccount : public ParentAccount {
private:
    RootAccount(const QString& name): AbstractAccount(name, RACINE), ParentAccount(name, RACINE) {}
    friend class AccountManager;
public:
    RootAccount& getRootAccount() override { return *this; }
};

#endif // ROOT_ACCOUNT_H
