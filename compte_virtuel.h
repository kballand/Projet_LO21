#ifndef COMPTE_VIRTUEL_H
#define COMPTE_VIRTUEL_H

#include "compte_parent.h"
#include "compte_enfant.h"
#include "compte_racine.h"

class CompteVirtuel : public CompteEnfant, public CompteParent {
private:
    CompteVirtuel(const QString& nom, const CompteVirtuel& parent): Compte(nom, parent.getType()), CompteEnfant(nom, parent.getType(), parent), CompteParent(nom, parent.getType()) {}
    CompteVirtuel(const QString& nom, const TypeCompte& type, const CompteRacine& racine): Compte(nom, type), CompteEnfant(nom, type, racine), CompteParent(nom, type) {}
    friend class CompteParent;
public:
    CompteVirtuel()=delete;
};

#endif // COMPTE_VIRTUEL_H
