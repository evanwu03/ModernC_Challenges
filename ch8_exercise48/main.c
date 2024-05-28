#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <stdlib.h>
#include <stdbool.h>
_Static_assert('z'-'a' == 25, "alphabetic characters are not contiguous");

#include <ctype.h>
/* convert an alphanumeric digit to an unsigned */
/* '0' ... '9'   =>   0 .. 9u  */
/* 'A' ... 'Z'   =>  10 .. 35u */
/* 'a' ... 'z'   =>  10 .. 35u */
unsigned hexatridecimal(int a) {
    if(isdigit(a)) { 
        /* This is guaranteed to work, decimal digits are
            consecutive and isdigit is not locale 
            dependent */
        return a - '0'; 
    }
    else { 
        /* leaves a unchanged if it is not lower case */
        a = toupper(a);
        /* Returns value >= 36 if not latin upper case */
        return (isupper(a)) ? 10 + (a - 'A') : -1; 
        // This relation assumes that a has an ASCII value of 65 or greater otherwise we get a negative value  
    }
}

unsigned long Strtoul_inner(char const s[static 1], size_t i , unsigned base) { 

    unsigned long ret = 0; 
    while(s[i]) { 
        unsigned c = hexatridecimal(s[i]); 
        if(c >= base) break; 
        /* maximal representable value for 64 bit is 
            3w5e11264sgsf in base 36*/
        if (ULONG_MAX/base < ret) {
            ret = ULONG_MAX;
            errno = ERANGE; 
            break;
        }
        ret *= base; 
        ret += c; 
        ++i;
    }
    return ret; 

}


// Exercise 51 says implement a find_prefix function for Strtoul 
unsigned long Strtoul(char const s[static 1], unsigned base) { 

    if (base > 36u) {       /* test if base 
        */
       errno = EINVAL;      /* extends specification
        */
       return ULONG_MAX; 
    }
    size_t i = strspn(s, " \f\n\r\t\v"); /* skip spaces 
        */
    bool switchsign = false; /* look for a sign 
        */
    switch(s[i])  { 
        case '-' : switchsign = true;
        case '+' : ++i;
    }
    if (!base || base == 16) {/*adjust the base */
        size_t adj = find_prefix(s, i, "0x");
        if (!base) base  = (unsigned[]){ 10, 8, 16 }[adj];
        i += adj; 
    }
    /* now, star tthe real conversion */
    unsigned long ret  = Strtoul_inner(s, i, base);
    return (switchsign) ? -ret : ret;


}


int main(void) { 

    const char str[]  = "clouds";
    printf("%s in decimal is %u", Strtoul(str, 10));
}

