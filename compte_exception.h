#ifndef COMPTE_EXCEPTION_H
#define COMPTE_EXCEPTION_H

#include <string>
#include <exception>

using namespace std;

class CompteException : public exception {
private:
    string info;
public:
    CompteException(const string& info) noexcept : info(info) {}
    virtual ~CompteException() noexcept {}
    const char * what() const noexcept override  { return info.c_str(); }
};

#endif // COMPTE_EXCEPTION_H
