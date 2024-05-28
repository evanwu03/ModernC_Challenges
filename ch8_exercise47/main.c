#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUFF_SIZE 32

int main(int argc, char *argv[])
{

    int ret = EXIT_FAILURE;
    char buffer[BUFF_SIZE] = {0};
    switch (argc)
    {

    case 1:
    {
        while (true)
        {
            fgets(buffer, BUFF_SIZE, stdin);
            if (buffer == "quit")
            {
                break;
            }
            else
            {
                printf("Output: %s\n", buffer);
            }
        }
        ret = EXIT_SUCCESS;
        break;
    }
    default:
    {
        if (!strcmp(argv[1], "-n"))
        {
            int line_num = 1;
            for (int i = 2; i < argc; i++)
            {
                FILE *instream = fopen(argv[i], "r");
                if (instream)
                {
                    while (fgets(buffer, BUFF_SIZE, instream))
                    {
                        printf("%d: ", line_num);
                        fputs(buffer, stdout);
                        fputs("\n", stdout);
                        line_num++;
                    }
                    fclose(instream);
                    ret = EXIT_SUCCESS;
                }
                else
                {
                    fprintf(stderr, "Could not print %s: ", argv[i]);
                    perror(0);
                    errno = 0;
                }
            }
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                FILE *instream = fopen(argv[i], "r");
                if (instream)
                {

                    while (fgets(buffer, BUFF_SIZE, instream))
                    {
                        fputs(buffer, stdout);
                        fputs("\n", stdout);
                    }
                    fclose(instream);
                    ret = EXIT_SUCCESS;
                }
                else
                {
                    fprintf(stderr, "Could not print %s ", argv[i]);
                    perror(0);
                    errno = 0;
                }
            }
        }
    }
    }
    return ret;
}
