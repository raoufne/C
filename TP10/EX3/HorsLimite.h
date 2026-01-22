#ifndef HORSLIMITE_H
#define HORSLIMITE_H

#include <exception>

class HorsLimite : public std::exception {
    char message[100];

public:
    HorsLimite(const char* txt) throw();
    const char* what() const throw();
};

#endif
