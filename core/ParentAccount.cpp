#include "ParentAccount.h"
#include "Account.h"

ParentAccount::~ParentAccount() {
    for(auto childAccount : childAccounts) {
        delete childAccount;
    }
}

double ParentAccount::getBalance() const {
    double balance = 0;
    for(auto it = childAccounts.cbegin(); it != childAccounts.cend(); ++it) {
        balance += (*it)->getBalance();
    }
    return balance;
}

bool ParentAccount::hasChildAccount(const QString& name) const {
    for(auto it = childAccounts.cbegin(); it != childAccounts.cend(); ++it) {
        ChildAccount* childAccount = *it;
        if(childAccount && childAccount->getName() == name) {
            return true;
        }
    }
    return false;
}

ChildAccount& ParentAccount::getChildAccount(const QString& name) {
    for(auto it = childAccounts.cbegin(); it != childAccounts.cend(); ++it) {
        ChildAccount* childAccount = *it;
        if(childAccount && childAccount->getName() == name) {
            return *childAccount;
        }
    }
    throw AccountException("Il n'existe pas de compte enfant avec ce nom !");
}

void ParentAccount::deleteChildAccount(const QString& name) {
    ChildAccount& c = getChildAccount(name);
    childAccounts.removeOne(&c);
    delete &c;
}

QList<ChildAccount*> ParentAccount::getChildAccounts() const {
    return childAccounts.toList();
}

QList<QString> ParentAccount::getChildAccountsNames() const {
    QList<QString> childAccountsNames;
    for(auto it = childAccounts.cbegin(); it != childAccounts.cend(); ++it) {
        ChildAccount* childAccount = *it;
        if(childAccount) {
            childAccountsNames.push_back(childAccount->getName());
        }
    }
    return childAccountsNames;
}
