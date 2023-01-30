#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main() {
    char c = 'A';
    int d = 123;
    unsigned int u = 456;
    char *s = "string";
    void *p = &d;

    ft_printf("Test 1: char: %c\n", c);
	printf("Comparison: %c\n", c);
	printf("\n");
    ft_printf("Test 2: %%: %%%%\n");
	printf("Comparison: %%%%\n");
	printf("\n");
    ft_printf("Test 3: int: %d\n", d);
	printf("Comparison: %d\n", d);
	printf("\n");
    ft_printf("Test 4 : int: %i\n", d);
	printf("Comparison: %i\n", d);
	printf("\n");
    ft_printf("Test 5: unsigned int: %u\n", u);
	printf("Comparison: %u\n", u);
	printf("\n");
    ft_printf("Test 6: hex lowercase: %x\n", d);
	printf("Comparison: %x\n", d);
	printf("\n");
    ft_printf("Test 7: hex uppercase: %X\n", d);
	printf("Comparison: %X\n", d);
	printf("\n");
    ft_printf("Test 8: pointer: %p\n", p);
	printf("Comparison: %p\n", p);
	printf("\n");
    ft_printf("Test 9: string: %s\n", s);
	printf("Comparison: %s\n", s);
	printf("\n");
    ft_printf("Test 10: max int: %d\n", INT_MAX);
	printf("Comparison: %d\n", INT_MAX);
	printf("\n");
    ft_printf("Test 11: min int: %d\n", INT_MIN);
	printf("Comparison: %d\n", INT_MIN);

    return (0);
}

