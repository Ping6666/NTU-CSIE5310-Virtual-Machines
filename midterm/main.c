#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main()
{
    unsigned long entry = 0x7F84212000;

    unsigned long pdg_offset = (entry >> 39) & 0x1FF;
    unsigned long pud_offset = (entry >> 30) & 0x1FF;
    unsigned long pmd_offset = (entry >> 21) & 0x1FF;
    unsigned long pte_offset = (entry >> 12) & 0x1FF;

    printf("Hi\n");
    printf("%lx\n", pdg_offset);
    printf("%lx\n", pud_offset);
    printf("%lx\n", pmd_offset);
    printf("%lx\n", pte_offset);

    return 0;
}