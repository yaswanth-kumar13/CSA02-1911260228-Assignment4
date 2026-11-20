# Task 06 - College Canteen Inventory and Billing

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228

## Objective
To design and implement a canteen inventory and billing system using structures, nested structures, arrays, pointers and tagged unions.

## Features
1. Packaged items with expiry dates.
2. Cooked items with preparation times.
3. Combo meals containing up to three components.
4. Stock validation and automatic stock deduction.
5. Expiry warnings for packaged items.
6. Daily sales summary sorted by revenue.

## Compilation

```bash
gcc -Wall -Wextra Task06/Task06_Canteen_Inventory.c -o Task06/Task06.exe
```

## Execution

```bash
./Task06/Task06.exe
```

On Windows PowerShell:

```powershell
.\Task06\Task06.exe
```

## Data Structures
The program uses date, clock_time, combo_data, item and sale structures. The item structure contains a tagged union selected using an enumeration.

## Result
The program successfully demonstrated normal sales, combo component stock deduction, rejection of insufficient-stock sales, expiry warnings and a daily revenue-sorted summary.