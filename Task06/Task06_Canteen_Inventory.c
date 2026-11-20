
#include <stdio.h>
#include <string.h>

#define ITEM_COUNT 6
#define MAX_SALES 20

enum item_type {
    PACKAGED,
    COOKED,
    COMBO
};

struct date {
    int day;
    int month;
    int year;
};

struct clock_time {
    int hour;
    int minute;
};

struct combo_data {
    int item_ids[3];
    int quantities[3];
    int count;
};

struct item {
    int id;
    char name[30];
    float price;
    int stock;
    enum item_type type;
    union {
        struct date expiry;
        struct clock_time prepared;
        struct combo_data combo;
    } details;
};

struct sale {
    int item_id;
    char name[30];
    int quantity;
    float revenue;
};

struct item items[ITEM_COUNT] = {
    {101, "Milk Packet", 30.0f, 10, PACKAGED, {.expiry = {22, 11, 2026}}},
    {102, "Biscuit", 20.0f, 15, PACKAGED, {.expiry = {25, 11, 2026}}},
    {201, "Veg Sandwich", 50.0f, 8, COOKED, {.prepared = {8, 30}}},
    {202, "Veg Rice", 70.0f, 6, COOKED, {.prepared = {9, 0}}},
    {301, "Combo Meal", 100.0f, 0, COMBO, {.combo = {{201, 202}, {1, 1}, 2}}},
    {302, "Milk Combo", 45.0f, 0, COMBO, {.combo = {{101, 102}, {1, 1}, 2}}}
};

struct sale sales[MAX_SALES];
int sale_count = 0;
float total_revenue = 0.0f;

int find_item(int id)
{
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (items[i].id == id)
            return i;
    }
    return -1;
}

int date_to_days(struct date d)
{
    return d.year * 365 + d.month * 30 + d.day;
}

void show_expiry_warnings(struct date today)
{
    int current = date_to_days(today);

    printf("\nEXPIRY WARNINGS\n");

    for (int i = 0; i < ITEM_COUNT; i++) {
        if (items[i].type == PACKAGED) {
            int remaining = date_to_days(items[i].details.expiry) - current;

            if (remaining >= 0 && remaining <= 2) {
                printf("%s expires on %02d/%02d/%04d\n",
                       items[i].name,
                       items[i].details.expiry.day,
                       items[i].details.expiry.month,
                       items[i].details.expiry.year);
            }
        }
    }
}

int can_sell(struct item *p, int quantity)
{
    if (quantity <= 0)
        return 0;

    if (p->type != COMBO)
        return p->stock >= quantity;

    for (int i = 0; i < p->details.combo.count; i++) {
        int index = find_item(p->details.combo.item_ids[i]);

        if (index == -1 ||
            items[index].stock < p->details.combo.quantities[i] * quantity)
            return 0;
    }

    return 1;
}

void record_sale(int id, int quantity)
{
    int index = find_item(id);

    if (index == -1) {
        printf("Invalid item ID\n");
        return;
    }

    struct item *p = &items[index];

    if (!can_sell(p, quantity)) {
        printf("Sale rejected: insufficient stock or invalid quantity for %s\n",
               p->name);
        return;
    }

    if (p->type == COMBO) {
        for (int i = 0; i < p->details.combo.count; i++) {
            int component = find_item(p->details.combo.item_ids[i]);
            items[component].stock -=
                p->details.combo.quantities[i] * quantity;
        }
    } else {
        p->stock -= quantity;
    }

    if (sale_count >= MAX_SALES) {
        printf("Sales record is full\n");
        return;
    }

    sales[sale_count].item_id = p->id;
    strcpy(sales[sale_count].name, p->name);
    sales[sale_count].quantity = quantity;
    sales[sale_count].revenue = p->price * quantity;

    total_revenue += sales[sale_count].revenue;
    sale_count++;

    printf("Sale successful: %s x %d = Rs. %.2f\n",
           p->name, quantity, p->price * quantity);
}

void print_stock(void)
{
    printf("\nCURRENT STOCK\n");

    for (int i = 0; i < ITEM_COUNT; i++) {
        printf("%d %-15s ", items[i].id, items[i].name);

        if (items[i].type == COMBO) {
            printf("Combo meal\n");
        } else {
            printf("Stock: %d\n", items[i].stock);
        }
    }
}

void print_sorted_summary(void)
{
    struct sale temp;

    for (int i = 0; i < sale_count - 1; i++) {
        for (int j = 0; j < sale_count - i - 1; j++) {
            if (sales[j].revenue < sales[j + 1].revenue) {
                temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }

    printf("\nDAILY BILL SUMMARY - SORTED BY REVENUE\n");

    for (int i = 0; i < sale_count; i++) {
        printf("%-15s Quantity: %d Revenue: Rs. %.2f\n",
               sales[i].name,
               sales[i].quantity,
               sales[i].revenue);
    }

    printf("TOTAL REVENUE: Rs. %.2f\n", total_revenue);
}

int main(void)
{
    struct date today = {21, 11, 2026};

    printf("COLLEGE CANTEEN INVENTORY AND BILLING\n");

    print_stock();

    show_expiry_warnings(today);

    printf("\nRECORDING SALES\n");

    record_sale(201, 2);
    record_sale(301, 2);
    record_sale(102, 20);
    record_sale(101, 1);

    print_stock();
    print_sorted_summary();

    return 0;
}

