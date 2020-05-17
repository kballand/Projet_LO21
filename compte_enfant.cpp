#include "compte_enfant.h"
#include "compte_parent.h"

CompteEnfant::CompteEnfant(const QString& nom, const TypeCompte& type, const CompteParent& parent): Compte(nom, type), parent(parent) {
    if(type == RACINE)
        throw CompteException("Un compte enfant ne peut pas être du type RACINE !");
}

const CompteRacine& CompteEnfant::getRacine() const {
    return getParent().getRacine();
}
