# Task 05 - Storage Classes

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228

## Objective
To implement and compare automatic, static, extern and register storage classes using a hostel mess token counter.

## Programs
1. Task05_Storage_Classes.c - Demonstrates automatic, static and register variables, along with separate veg and non-veg counters.
2. Task05_Extern.c - Defines global veg and non-veg counters and their functions.
3. Task05_Extern_Main.c - Accesses the global counters using extern declarations.

## Compilation Commands

Main program:

```bash
gcc -Wall -Wextra Task05/Task05_Storage_Classes.c -o Task05/Task05.exe
```

Extern program:

```bash
gcc -Wall -Wextra Task05/Task05_Extern.c Task05/Task05_Extern_Main.c -o Task05/Extern.exe
```

## Result
The static counter retained its value between function calls, while the automatic counter restarted from 1000 on each call. The extern implementation shared global counters across two source files. Separate veg and non-veg counters were successfully demonstrated. A register variable was used as a loop index.