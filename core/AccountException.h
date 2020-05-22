#ifndef ACCOUNT_EXCEPTION_H
#define ACCOUNT_EXCEPTION_H

#include <string>
#include <exception>

using namespace std;

class AccountException : public exception {
private:
    string message;
public:
    AccountException(const string& message) noexcept : message(message) {}
    virtual ~AccountException() noexcept {}
    const char* what() const noexcept override  { return message.c_str(); }
};

#endif // ACCOUNT_EXCEPTION_H
