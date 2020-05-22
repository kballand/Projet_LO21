#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "ChildAccount.h"
#include "VirtualAccount.h"
#include "RootAccount.h"

class Account : public ChildAccount {
private:
    double balance;
    double balanceReconciliation;
public:
    Account(const QString& name, VirtualAccount& parent): AbstractAccount(name, parent.getType()), ChildAccount(name, parent.getType(), parent) {}
    Account(const QString& name, const AccountType& type, RootAccount& root): AbstractAccount(name, type), ChildAccount(name, type, root) {}
    double getBalance() const override { return balance; }
    double getBalanceReconciliation() const { return balanceReconciliation; }
    void add(double amount);
    void withdraw(double amount);
};

#endif // ACCOUNT_H
