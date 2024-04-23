#include "LibCWrapper.h"

#define LOGS_ENABLED

LibCWrapper::LibCWrapper()
{
    #if defined(LOGS_ENABLED)
        std::cout << "LibCWrapper Loaded! => (" << reinterpret_cast<void*>(this) << ")\n" << std::endl;
    #endif
}

void LibCWrapper::logAvailableFunctions()
{
    #if defined(LOGS_ENABLED)
        std::cout << "my_safe_isalnum('A'): " << my_safe_isalnum('A') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isalnum('*'): " << my_safe_isalnum('*') << std::endl; // Example of a negative result

        std::cout << "my_safe_isalpha('a'): " << my_safe_isalpha('a') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isalpha('1'): " << my_safe_isalpha('1') << std::endl; // Example of a negative result

        std::cout << "my_safe_isblank(' '): " << my_safe_isblank(' ') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isblank('a'): " << my_safe_isblank('a') << std::endl; // Example of a negative result

        std::cout << "my_safe_iscntrl('\\n'): " << my_safe_iscntrl('\n') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_iscntrl('A'): " << my_safe_iscntrl('A') << std::endl; // Example of a negative result

        std::cout << "my_safe_isdigit('7'): " << my_safe_isdigit('7') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isdigit('A'): " << my_safe_isdigit('A') << std::endl; // Example of a negative result

        std::cout << "my_safe_isgraph('a'): " << my_safe_isgraph('a') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isgraph(' '): " << my_safe_isgraph(' ') << std::endl; // Example of a negative result

        std::cout << "my_safe_islower('a'): " << my_safe_islower('a') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_islower('A'): " << my_safe_islower('A') << std::endl; // Example of a negative result

        std::cout << "my_safe_isprint('a'): " << my_safe_isprint('a') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isprint('\\n'): " << my_safe_isprint('\n') << std::endl; // Example of a negative result

        std::cout << "my_safe_ispunct('.'): " << my_safe_ispunct('.') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_ispunct('A'): " << my_safe_ispunct('A') << std::endl; // Example of a negative result

        std::cout << "my_safe_isspace(' '): " << my_safe_isspace(' ') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isspace('a'): " << my_safe_isspace('a') << std::endl; // Example of a negative result

        std::cout << "my_safe_isupper('A'): " << my_safe_isupper('A') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isupper('a'): " << my_safe_isupper('a') << std::endl; // Example of a negative result

        std::cout << "my_safe_isxdigit('F'): " << my_safe_isxdigit('F') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_isxdigit('G'): " << my_safe_isxdigit('G') << std::endl; // Example of a negative result

        std::cout << "my_safe_tolower('A'): " << my_safe_tolower('A') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_tolower('3'): " << my_safe_tolower('3') << std::endl; // Example of a negative result

        std::cout << "my_safe_toupper('a'): " << my_safe_toupper('a') << std::endl; // Example of a positive outcome
        std::cout << "my_safe_toupper('9'): " << my_safe_toupper('9') << std::endl; // Example of a negative result

        std::cout << "my_safe_abs(-5): " << my_safe_abs(-5) << std::endl; // Example of a positive outcome
        std::cout << "my_safe_abs(5): " << my_safe_abs(5) << std::endl; // Example of a positive outcome

        std::cout << "my_safe_atof(\"3.14\"): " << my_safe_atof("3.14") << std::endl; // Example of a positive outcome
        std::cout << "my_safe_atof(\"hello\"): " << my_safe_atof("hello") << std::endl; // Example of a negative result

        std::cout << "my_safe_atoi(\"123\"): " << my_safe_atoi("123") << std::endl; // Example of a positive outcome
        std::cout << "my_safe_atoi(\"abc\"): " << my_safe_atoi("abc") << std::endl; // Example of a negative result
    #endif
}

int CTypeFunctions::my_safe_isalnum(int c)
{
    return (this->my_safe_isalpha(c) || this->my_safe_isdigit(c));
}

int CTypeFunctions::my_safe_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int CTypeFunctions::my_safe_isblank(int c)
{
	return (c == ' ' || c == '\t');
}

int CTypeFunctions::my_safe_iscntrl(int c)
{
	return (c == 127 || (c >= 0 && c <= 31));
}

int CTypeFunctions::my_safe_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int CTypeFunctions::my_safe_isgraph(int c)
{
	return (this->my_safe_isprint(c) && c != ' ');
}

int CTypeFunctions::my_safe_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int CTypeFunctions::my_safe_isprint(int c)
{
	return (c >= 0x20 && c <= 0x7E);
}

int CTypeFunctions::my_safe_ispunct(int c)
{
	return (this->my_safe_isprint(c) && !this->my_safe_isspace(c) && !this->my_safe_isalnum(c));
}

int CTypeFunctions::my_safe_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

int CTypeFunctions::my_safe_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int CTypeFunctions::my_safe_isxdigit(int c)
{
	return (this->my_safe_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int CTypeFunctions::my_safe_tolower(int c)
{
	if (this->my_safe_isupper(c))
		return 'a' - 'A' + c;
    
	return c;
}

int CTypeFunctions::my_safe_toupper(int c)
{
    if (this->my_safe_isalpha(c))
    {
        if (c >= 'a' && c <= 'z')
        {
            return c - 'a' + 'A';
        }
    }

    return c;
}

int StdlibFunctions::my_safe_abs(int j)
{
    return(j < 0 ? -j : j);
}

double StdlibFunctions::my_safe_atof(const char *ascii)
{
    double result = 0.0;
    double power = 1.0;
    int sign = 1;

    // Ignore leading white spaces
    while (my_safe_isspace(*ascii))
    {
        ascii++;
    }

    // Handle sign
    if (*ascii == '-' || *ascii == '+')
    {
        sign = (*ascii++ == '-') ? -1 : 1;
    }

    // Process integer part
    while (my_safe_isdigit(*ascii))
    {
        result = result * 10.0 + (*ascii - '0');
        ascii++;
    }

    // Process decimal part
    if (*ascii == '.')
    {
        ascii++;
        while (my_safe_isdigit(*ascii))
        {
            result = result * 10.0 + (*ascii - '0');
            power *= 10.0;
            ascii++;
        }
    }

    // Return the final value considering the sign and decimal power
    return sign * result / power;
}

int StdlibFunctions::my_safe_atoi(const char *str)
{
    return((int)strtol(str, (char **)NULL, 10));
}

long StdlibFunctions::strtol(const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
	unsigned long acc;
	int c;
	unsigned long cutoff;
	int neg = 0, any, cutlim;

	/*
	 * Skip white space and pick up leading +/- sign if any.
	 * If base is 0, allow 0x for hex and 0 for octal, else
	 * assume decimal; if base is already 16, allow 0x.
	 */
	do {
		c = *s++;
	} while (my_safe_isspace(c));

	if (c == '-') {
		neg = 1;
		c = *s++;
	} else if (c == '+')
		c = *s++;
	if ((base == 0 || base == 16) &&
	    c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	}

	if (base == 0)
		base = c == '0' ? 8 : 10;

	/*
	 * Compute the cutoff value between legal numbers and illegal
	 * numbers.  That is the largest legal value, divided by the
	 * base.  An input number that is greater than this value, if
	 * followed by a legal input character, is too big.  One that
	 * is equal to this value may be valid or not; the limit
	 * between valid and invalid numbers is then based on the last
	 * digit.  For instance, if the range for longs is
	 * [-2147483648..2147483647] and the input base is 10,
	 * cutoff will be set to 214748364 and cutlim to either
	 * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
	 * a value > 214748364, or equal but the next digit is > 7 (or 8),
	 * the number is too big, and we will return a range error.
	 *
	 * Set any if any `digits' consumed; make it negative to indicate
	 * overflow.
	 */
	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;

	for (acc = 0, any = 0;; c = *s++) {
		if (my_safe_isdigit(c))
			c -= '0';
		else if (my_safe_isalpha(c))
			c -= my_safe_isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
			any = -1;
		else {
			any = 1;
			acc *= base;
			acc += c;
		}
	}

	if (any < 0) {
		acc = neg ? LONG_MIN : LONG_MAX;
		errno = ERANGE;
	} else if (neg)
		acc = -acc;
    
	if (endptr != 0)
		*endptr = (char *)(any ? s - 1 : nptr);
    
	return (acc);
}