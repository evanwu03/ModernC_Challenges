#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

enum
{
    buf_max = 32
};

int main(int argc, char *argv[])
{
    int ret = EXIT_FAILURE;
    char buffer[buf_max] = {0};

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            FILE *instream = fopen(argv[i], "r");
            if (instream)
            {
                while (fgets(buffer, buf_max, instream))
                {
                    fputs(buffer, stdout);
                }
                fclose(instream);
                ret = EXIT_SUCCESS;
            }
            else
            {
                /* Provide some error diagnostic. */
                fprintf(stderr, "Could not open %s: ", argv[i]);
                perror(0);
                errno = 0;
            }
        }
        return ret;
    }
    else { 
        printf("no command line args detected.\n");
        while(fgets(buffer, buf_max, stdin)) { 
            printf("Output is: ");
            fputs(buffer, stdout);
            printf("\n");
        } 
        ret = EXIT_SUCCESS;
        return ret;
    }
}