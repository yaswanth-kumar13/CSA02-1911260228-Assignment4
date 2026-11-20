
#include <stdio.h>

int next_token(void)
{
    static int token = 1000;
    return ++token;
}

int auto_token(void)
{
    int token = 1000;
    return ++token;
}

int next_auto(int *counter)
{
    return ++(*counter);
}

int main(void)
{
    int s1 = next_token();
    int s2 = next_token();
    int s3 = next_token();

    int a1 = auto_token();
    int a2 = auto_token();
    int a3 = auto_token();

    printf("STATIC COUNTER\n");
    printf("%d %d %d\n", s1, s2, s3);

    printf("\nAUTOMATIC COUNTER\n");
    printf("%d %d %d\n", a1, a2, a3);

    printf("\nSEPARATE STATIC COUNTERS\n");

    static int veg = 1000;
    static int nonveg = 2000;

    printf("Veg: %d %d %d\n", ++veg, ++veg, ++veg);
    printf("Non-Veg: %d %d %d\n", ++nonveg, ++nonveg, ++nonveg);

    printf("\nCALLER-OWNED AUTOMATIC COUNTERS\n");

    int veg_count = 1000;
    int nonveg_count = 2000;

    printf("Veg: ");
    for (register int i = 0; i < 3; i++)
        printf("%d ", next_auto(&veg_count));

    printf("\nNon-Veg: ");
    for (register int i = 0; i < 3; i++)
        printf("%d ", next_auto(&nonveg_count));

    printf("\n\nREGISTER LOOP VARIABLE\n");

    for (register int i = 1; i <= 5; i++)
        printf("Token %d\n", i);

    return 0;
}
