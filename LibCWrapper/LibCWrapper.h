#ifndef LIBCWRAPPER_H
#define LIBCWRAPPER_H

#include <iostream> // For console output
#include <cstdlib> // For definition of some standard functions like strtol
#include <climits> // For getting limits of integer types
#include <cerrno> // For error definitions

class CTypeFunctions
{
public:
    int my_safe_isalnum(int c);
    int my_safe_isalpha(int c);
    int my_safe_isblank(int c);
    int my_safe_iscntrl(int c);
    int my_safe_isdigit(int c);
    int my_safe_isgraph(int c);
    int my_safe_islower(int c);
    int my_safe_isprint(int c);
    int my_safe_ispunct(int c);
    int my_safe_isspace(int c);
    int my_safe_isupper(int c);
    int my_safe_isxdigit(int c);
    int my_safe_tolower(int c);
    int my_safe_toupper(int c);
};

class StdlibFunctions
    : public CTypeFunctions
{
public:
    int my_safe_abs(int j);
    double my_safe_atof(const char *ascii);
    int my_safe_atoi(const char *str);
    long strtol(const char *nptr, char **endptr, int base);
};

class LibCWrapper
    : public StdlibFunctions
{
public:
    LibCWrapper();
    void logAvailableFunctions();
};

#endif //LIBCWRAPPER_H