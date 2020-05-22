#include "core/AccountManager.h"
#include "core/Account.h"

int main() {
    AccountManager& instance = AccountManager::getInstance();
    instance.createRootAccount("test");
    instance.getRootAccount("test");
    instance.deleteRootAccount("test");
    RootAccount& c = instance.createRootAccount("test");
    Account("autre", CHARGE, c);
    return 0;
}
