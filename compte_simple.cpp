#include "compte_simple.h"

void CompteSimple::ajouter(double montant) {
    if(montant <= 0)
        throw CompteException("Le montant à ajouter doit être strictement supérieur à 0 !");
    solde += montant;
}

void CompteSimple::retirer(double montant) {
    if(montant <= 0)
        throw CompteException("Le montant à retirer doit être strictement supérieur à 0 !");
    solde -= montant;
}
