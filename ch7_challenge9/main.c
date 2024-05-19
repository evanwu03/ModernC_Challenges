
#include <stdio.h>
#include <math.h>

#define SIZE 6
void prime_factorization(size_t n);
void prime_factorization_list(const size_t list[SIZE]);

int main(void)
{

    size_t n;
    printf("Enter a number: ");
    scanf("%zu", &n);
    printf("Prime factors of %zu are: ", n);
    prime_factorization(n);

    size_t list[SIZE] = {23, 450, 1000, 235, 456, 746};
    prime_factorization_list(list);
    return 0;
}

void prime_factorization(size_t n)
{
    size_t i = 2;
    while (n > 1)
    {
        if (n % i == 0)
        {
            printf("%zu ", i);
            n /= i;
        }
        else if (i > sqrt(n))
        {
            printf("%zu ", n);
            break;
        }
        else
        {
            i++;
        }
    }
    printf("\n");
}

void prime_factorization_list(const size_t list[SIZE])
{
    for (size_t number = 0; number < SIZE; number++)
    {
        size_t n = list[number];
        size_t i = 2;
        printf("Prime factors of %zu are: ", n);
        while (n > 1)
        {
            if (n % i == 0)
            {
                printf("%zu ", i);
                n /= i;
            }
            else if (i > sqrt(n))
            {
                printf("%zu ", n);
                break;
            }
            else
            {
                i++;
            }
        }
        printf("\n");
    }
}