#include "HorsLimite.h"
#include <cstring>

HorsLimite::HorsLimite(const char* txt) throw() {
    strcpy(message, txt);
}

const char* HorsLimite::what() const throw() {
    return message;
}
