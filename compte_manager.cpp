#include "compte_manager.h"

CompteManager& CompteManager::getInstance() {
    static CompteManager instance;
    return instance;
}
