
#include <stdio.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

struct address {
    char name[30];
    char city[20];
    int pincode;
};

enum service {
    NORMAL,
    EXPRESS
};

struct parcel {
    int id;
    float weight;
    struct address from;
    struct address to;
    struct date booked;
    enum service type;
    float charge;
};

void print_parcel(const struct parcel *p) {
    printf("%d %.1f kg %s-%d %02d/%02d/%04d\n",
           p->id, p->weight, p->to.city, p->to.pincode,
           p->booked.day, p->booked.month, p->booked.year);
}

void sort_by_weight(struct parcel p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (p[j].weight < p[min].weight) {
                min = j;
            }
        }

        if (min != i) {
            struct parcel temp = p[i];
            p[i] = p[min];
            p[min] = temp;

            printf("Bytes copied in swap: %zu\n",
                   3 * sizeof(struct parcel));
        }
    }
}

void list_by_city(const struct parcel p[], int n, const char city[]) {
    printf("\nParcels for %s:\n", city);

    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].to.city, city) == 0) {
            print_parcel(&p[i]);
        }
    }
}

int main(void) {
    struct parcel list[3] = {
        {501, 4.5f, {"Ravi", "Madurai", 625001},
         {"Anu", "Madurai", 625001}, {12, 10, 2026}, NORMAL, 120.0f},

        {502, 1.2f, {"Mala", "Chennai", 600077},
         {"Bala", "Chennai", 600077}, {12, 10, 2026}, EXPRESS, 90.0f},

        {503, 2.8f, {"Kiran", "Coimbatore", 641001},
         {"Devi", "Coimbatore", 641001}, {13, 10, 2026}, NORMAL, 100.0f}
    };

    sort_by_weight(list, 3);

    printf("\nSORTED PARCELS\n");

    for (int i = 0; i < 3; i++) {
        print_parcel(&list[i]);
    }

    list_by_city(list, 3, "Chennai");

    printf("\nThird parcel PIN using dot: %d\n",
           list[2].to.pincode);

    struct parcel *ptr = list;

    printf("Third parcel PIN using arrow: %d\n",
           (ptr + 2)->to.pincode);

    printf("Size of Parcel: %zu bytes\n", sizeof(struct parcel));

    return 0;
}
