
#include <stdio.h>

union sensor {
    float celsius;
    int percent;
};

int main(void) {
    union sensor data;

    data.celsius = 31.5f;

    printf("Temperature: %.1f\n", data.celsius);
    printf("Humidity member read: %d\n", data.percent);

    return 0;
}
