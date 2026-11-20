
## Task 03 – Weather Station Sensor Packets

- Designed a structure containing all sensor fields.
- Implemented a tagged union using enum.
- Used switch-case to display the active union member.
- Measured structure and union sizes using sizeof.
- Performed a union misuse experiment.
- Compared tagged unions, separate arrays and dynamic allocation.

### Main Program

Compile:
gcc -std=c11 -Wall -Wextra Task03_Weather_Station.c -o Task03.exe

Run:
.\Task03.exe

### Misuse Experiment

Compile:
gcc -std=c11 -Wall -Wextra Task03_Union_Misuse.c -o Misuse.exe

Run:
.\Misuse.exe

Result: Successfully executed.
