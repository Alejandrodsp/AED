#include <stdio.h>
#include <stdlib.h>

int main()
{
int a, *b, **c, ***d;
a = 10;
b = &a;
c = &b;
d = &c;
scanf("%d" ,**d);
printf("%d" ,***d);
printf("%d", a);
    return 0;
}