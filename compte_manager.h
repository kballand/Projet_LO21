#ifndef COMPTE_MANAGER_H
#define COMPTE_MANAGER_H

#include "compte_racine.h"

class CompteManager {
private:
    QVector<CompteRacine> comptesRacines;
    CompteManager(): comptesRacines() {}
public:
    CompteManager(const CompteManager& c)=delete;
    CompteManager& operator=(const CompteManager& c)=delete;
    static CompteManager& getInstance();
    const QVector<CompteRacine> getComptesRacines() const { return comptesRacines; }
    bool hasCompteRacine(const QString& nom) const;
    void creerCompteRacine(const QString& nom);
    void supprimerCompteRacine(const QString& nom);
    QVector<QString> getNomsComptesRacines() const;
};

#endif // COMPTE_MANAGER_H
