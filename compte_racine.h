#ifndef COMPTE_RACINE_H
#define COMPTE_RACINE_H

#include "compte_parent.h"

class CompteRacine : public CompteParent {
private:
    CompteRacine(const QString& nom): Compte(nom, RACINE), CompteParent(nom, RACINE) {}
    friend class CompteManager;
public:
    CompteRacine()=delete;
    const CompteRacine& getRacine() const override { return *this; }
};

#endif // COMPTE_RACINE_H
