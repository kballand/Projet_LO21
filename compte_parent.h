#ifndef COMPTE_PARENT_H
#define COMPTE_PARENT_H

#include <QVector>
#include "compte.h"
#include "compte_enfant.h"

class CompteParent : public virtual Compte {
private:
    QVector<CompteEnfant*> comptesEnfants;
public:
    CompteParent()=delete;
    CompteParent(const QString& nom, const TypeCompte& type): Compte(nom, type), comptesEnfants() {}
    ~CompteParent();
    double getSolde() const override;
};

#endif // COMPTE_PARENT_H
