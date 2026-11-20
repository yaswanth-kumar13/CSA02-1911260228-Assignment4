
#include <stdio.h>

struct account {
    int number;
    float balance;
};

void addInterest(struct account a, float rate) {
    printf("Address inside function: %p\n", (void *)&a);
    a.balance = a.balance + a.balance * rate / 100;
    printf("Balance inside function: %.2f\n", a.balance);
}

int main(void) {
    struct account list[3] = {
        {101, 5000},
        {102, 12000},
        {103, 800}
    };

    for (int i = 0; i < 3; i++) {
        printf("\nAddress in main: %p\n", (void *)&list[i]);
        addInterest(list[i], 4);
        printf("Original balance: %.2f\n", list[i].balance);
    }

    return 0;
}
