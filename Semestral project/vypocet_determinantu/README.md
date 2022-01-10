**Kalkulačka pro determinant matic**

Program slouží k výpočtu determinantu. Program umí načíst matici ze souboru, příklady matic ve složce /files.
Program dále umí číst matici z konzole.

**Implementace**

V programu je využita Gaussova eliminační metoda. Program při načtení kontroluje velikost matice a pokud je velikost matice větší než 10 program využije vícevláknovou implementaci.

**Benchmark**
test na 1000*1000 matici o hodnotách -15 až 15.
ST ~24000 ms
MT ~8600 ms

System Windows 11

CPU : dvoujádrový intel i7-7700U

Compiler - WSL