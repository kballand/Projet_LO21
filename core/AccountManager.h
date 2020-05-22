#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include "RootAccount.h"

class AccountManager {
private:
    QVector<RootAccount*> rootAccounts;
    AccountManager(): rootAccounts() {}
public:
    AccountManager(const AccountManager& accountManager)=delete;
    AccountManager& operator=(const AccountManager& accountManager)=delete;
    ~AccountManager();
    static AccountManager& getInstance();
    bool hasRootAccount(const QString& name) const;
    RootAccount& getRootAccount(const QString& name);
    RootAccount& createRootAccount(const QString& name);
    void deleteRootAccount(const QString& name);
    QList<RootAccount*> getRootAccounts() const;
    QList<QString> getRootAccountsNames() const;
};

#endif // ACCOUNT_MANAGER_H
