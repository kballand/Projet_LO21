#ifndef COMPTE_SIMPLE_H
#define COMPTE_SIMPLE_H

#include "compte_enfant.h"
#include "compte_virtuel.h"
#include "compte_racine.h"

class CompteSimple : public CompteEnfant {
private:
    double solde;
    double soldeRapprochement;
    CompteSimple(const QString& nom, const CompteVirtuel& parent): Compte(nom, parent.getType()), CompteEnfant(nom, parent.getType(), parent) {}
    CompteSimple(const QString& nom, const TypeCompte& type, const CompteRacine& racine): Compte(nom, type), CompteEnfant(nom, type, racine) {}
    friend class CompteParent;
public:
    CompteSimple()=delete;
    double getSolde() const override { return solde; }
    double getSoldeRapprochement() const { return soldeRapprochement; }
    void ajouter(double montant);
    void retirer(double montant);
};

#endif // COMPTE_SIMPLE_H
