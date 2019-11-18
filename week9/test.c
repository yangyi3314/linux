#include<stdlib.h>
#include<stdio.h>
static void __attribute__ ((constructor))before_main(void)
{
    printf("Running befored main!\n");
}
int main()
{
    printf("Main!\n");
    return 0;
}
