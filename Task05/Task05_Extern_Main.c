
#include <stdio.h>

extern int veg_token;
extern int nonveg_token;

int next_veg_token(void);
int next_nonveg_token(void);

int main(void)
{
    printf("EXTERN STORAGE CLASS\n");

    printf("Veg: %d %d %d\n",
           next_veg_token(),
           next_veg_token(),
           next_veg_token());

    printf("Non-Veg: %d %d %d\n",
           next_nonveg_token(),
           next_nonveg_token(),
           next_nonveg_token());

    printf("Global Veg Counter: %d\n", veg_token);
    printf("Global Non-Veg Counter: %d\n", nonveg_token);

    return 0;
}
