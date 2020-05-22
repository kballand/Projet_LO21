#include "AccountManager.h"

AccountManager::~AccountManager() {
    for(auto it = rootAccounts.begin(); it != rootAccounts.end(); ++it) {
        delete *it;
    }
}

AccountManager& AccountManager::getInstance() {
    static AccountManager instance;
    return instance;
}

bool AccountManager::hasRootAccount(const QString& name) const {
    for(auto it = rootAccounts.cbegin(); it != rootAccounts.cend(); ++it) {
        RootAccount* rootAccount = *it;
        if(rootAccount && rootAccount->getName() == name) {
            return true;
        }
    }
    return false;
}

RootAccount& AccountManager::getRootAccount(const QString& name) {
    for(auto it = rootAccounts.cbegin(); it != rootAccounts.cend(); ++it) {
        RootAccount* rootAccount = *it;
        if(rootAccount && rootAccount->getName() == name) {
            return *rootAccount;
        }
    }
    throw AccountException("Il n'existe pas de compte racine avec ce nom !");
}

RootAccount& AccountManager::createRootAccount(const QString& name) {
    if(hasRootAccount(name))
        throw AccountException("Il existe deja un compte racine avec ce nom !");
    RootAccount* rootAccount = new RootAccount(name);
    rootAccounts.push_back(rootAccount);
    return *rootAccount;
}

void AccountManager::deleteRootAccount(const QString& name) {
    RootAccount& c = getRootAccount(name);
    rootAccounts.removeOne(&c);
    delete &c;
}

QList<RootAccount*> AccountManager::getRootAccounts() const {
    return rootAccounts.toList();
}

QList<QString> AccountManager::getRootAccountsNames() const {
    QList<QString> rootAccountsNames;
    for(auto it = rootAccounts.cbegin(); it != rootAccounts.cend(); ++it) {
        RootAccount* root = *it;
        if(root) {
            rootAccountsNames.push_back(root->getName());
        }
    }
    return rootAccountsNames;
}
