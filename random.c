#include <stdio.h>

int main()
{
    int a = 20;
    const char *b = (a < 18) ? "You are not eligible" : "You are eligible";
    printf("%s\n", b);
    return 0;
}
