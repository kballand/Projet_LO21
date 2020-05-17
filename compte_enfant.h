#ifndef COMPTE_ENFANT_H
#define COMPTE_ENFANT_H

#include "compte.h"

class CompteParent;

class CompteEnfant : public virtual Compte {
private:
    const CompteParent& parent;
public:
    CompteEnfant()=delete;
    CompteEnfant(const QString& nom, const TypeCompte& type, const CompteParent& parent);
    const CompteRacine& getRacine() const override;
    const CompteParent& getParent() const { return parent; }
};

#endif // COMPTE_ENFANT_H
