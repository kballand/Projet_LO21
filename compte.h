#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include "compte_exception.h"

enum TypeCompte {
    RACINE = 0,
    ACITF,
    PASSIF,
    CHARGE,
    PRODUIT
};

class CompteParent;
class CompteRacine;

class Compte {
    QString nom;
    TypeCompte type;
public:
    Compte()=delete;
    Compte(const QString& nom, const TypeCompte& type): nom(nom), type(type) {}
    virtual ~Compte()=default;
    const QString& getNom() const { return nom; }
    const TypeCompte& getType() const { return type; }
    virtual double getSolde() const=0;
    virtual const CompteRacine& getRacine() const=0;
};

#endif // COMPTE_H
