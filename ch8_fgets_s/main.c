

#include <stdio.h>
#include <stdlib.h>
char *fgets_manually(char s[restrict], int n, FILE *restrict stream)
{
    if (!stream)
        return 0;
    if (!n)
        return s;
    /* Read at most n-1 characters */
    for (size_t pos = 0; pos < n - 1; ++pos)
    {
        int val = fgetc(stream);
        switch (val)
        {
        /* EOF signals end-of-file or error */
        case EOF:
            if (feof(stream))
            {
                s[pos] = 0;
                /* has been a valid call */
                return s;
            }
            else
            {
                /* we are on error */
                return 0;
            }
        case '\n':
            s[pos] = val;
            s[pos + 1] = 0;
            return s;
        /* otherwise just assign an continue */
        default:
            s[pos] = val;
        }
    }
    s[n - 1] = 0;
    return s;
}

int main(void)
{

    return 0;
}