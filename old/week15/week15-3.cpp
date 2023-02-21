#include <stdio.h>
int main()
{
    printf("A的值就是 %d\n",'A');
    printf("B的值就是 %d\n",'C');
    printf("C的值就是 %d\n",'C');

    for(int c='A';c<='Z';c++){
        printf("%c的值是%d\n",c,c);
    }
}

