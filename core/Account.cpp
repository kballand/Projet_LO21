#include "Account.h"

void Account::add(double amount) {
    if(amount <= 0)
        throw AccountException("Le montant a ajouter doit etre strictement superieur a 0 !");
    balance += amount;
}

void Account::withdraw(double amount) {
    if(amount <= 0)
        throw AccountException("Le montant a retirer doit etre strictement superieur a 0 !");
    balance -= amount;
}
