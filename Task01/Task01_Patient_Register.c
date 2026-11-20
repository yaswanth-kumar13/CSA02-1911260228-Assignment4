
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_PATIENTS 100

struct BloodPressure {
    int systolic;
    int diastolic;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Patient {
    char name[50];
    int age;
    char phone[11];
    struct BloodPressure bp;
    struct Date visitDate;
};

struct PatientRegister {
    struct Patient patients[MAX_PATIENTS];
    int count;
};

int addPatient(struct PatientRegister *reg, const struct Patient *p) {
    if (reg->count >= MAX_PATIENTS) {
        return 0;
    }

    reg->patients[reg->count] = *p;
    reg->count++;
    return 1;
}

void sortByAge(struct PatientRegister *reg) {
    for (int i = 0; i < reg->count - 1; i++) {
        for (int j = 0; j < reg->count - i - 1; j++) {
            if (reg->patients[j].age > reg->patients[j + 1].age) {
                struct Patient temp = reg->patients[j];
                reg->patients[j] = reg->patients[j + 1];
                reg->patients[j + 1] = temp;
            }
        }
    }
}

void displayPatients(const struct PatientRegister *reg) {
    printf("\nPATIENT REGISTER\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < reg->count; i++) {
        const struct Patient *p = &reg->patients[i];

        printf("Name: %s\n", p->name);
        printf("Age: %d\n", p->age);
        printf("Phone: %s\n", p->phone);
        printf("Blood Pressure: %d/%d\n",
               p->bp.systolic, p->bp.diastolic);
        printf("Visit Date: %02d/%02d/%04d\n",
               p->visitDate.day,
               p->visitDate.month,
               p->visitDate.year);
        printf("--------------------------------------------------\n");
    }
}

int main(void) {
    struct PatientRegister reg = {0};

    struct Patient p1 = {
        "Arun", 25, "9876543210", {120, 80}, {12, 10, 2026}
    };

    struct Patient p2 = {
        "Kumar", 19, "9876501234", {118, 78}, {13, 10, 2026}
    };

    struct Patient p3 = {
        "Priya", 32, "9876512345", {125, 85}, {14, 10, 2026}
    };

    addPatient(&reg, &p1);
    addPatient(&reg, &p2);
    addPatient(&reg, &p3);

    printf("Number of patients: %d\n", reg.count);

    displayPatients(&reg);

    sortByAge(&reg);

    printf("\nPATIENTS SORTED BY AGE\n");
    displayPatients(&reg);

    printf("\nMEMORY DETAILS\n");
    printf("Size of BloodPressure: %zu bytes\n",
           sizeof(struct BloodPressure));
    printf("Size of Date: %zu bytes\n", sizeof(struct Date));
    printf("Size of Patient: %zu bytes\n", sizeof(struct Patient));
    printf("Offset of age: %zu bytes\n",
           offsetof(struct Patient, age));
    printf("Offset of blood pressure: %zu bytes\n",
           offsetof(struct Patient, bp));
    printf("Offset of visit date: %zu bytes\n",
           offsetof(struct Patient, visitDate));

    return 0;
}
