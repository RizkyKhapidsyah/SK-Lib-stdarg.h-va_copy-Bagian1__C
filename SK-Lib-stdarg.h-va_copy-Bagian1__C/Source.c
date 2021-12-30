#pragma warning(disable:4996)

#include <stdio.h>      /* printf, vprintf*/
#include <stdlib.h>     /* malloc */
#include <string.h>     /* strlen, strcat */
#include <stdarg.h>     /* va_list, va_start, va_copy, va_arg, va_end */
#include <conio.h>

/*
    Source by CPlusPlus
    Modified For Learn by RK
    I.D.E : VS2019
*/

/* print ints until a zero is found: */
void PrintInts(int first, ...) {
    char* buffer;
    const char* format = "[%d] ";
    int count = 0;
    int val = first;
    va_list vl, vl_count;
    va_start(vl, first);

    va_copy(vl_count, vl);

    while (val != 0) {
        val = va_arg(vl_count, int);
        ++count;
    }
    
    va_end(vl_count);

    buffer = (char*)malloc(strlen(format) * count + 1);
    buffer[0] = '\0';

    for (; count > 0; --count) {
        strcat(buffer, format);
    }

    printf(format, first);
    vprintf(buffer, vl);

    va_end(vl);
}

int main() {
    PrintInts(10, 20, 30, 40, 50, 0);
    _getch();
    return 0;
}