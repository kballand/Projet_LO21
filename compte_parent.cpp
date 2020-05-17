#include "compte_parent.h"

CompteParent::~CompteParent() {
    for(auto it = comptesEnfants.cbegin(); it != comptesEnfants.cend(); ++it) {
        delete *it;
    }
}

double CompteParent::getSolde() const {
    double solde = 0;
    for(auto it = comptesEnfants.cbegin(); it != comptesEnfants.cend(); ++it) {
        solde += (*it)->getSolde();
    }
    return solde;
}
