#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
int compar(const void *,const void*);
void urand(int *,int);
void ushow(int *,int);
void mysort(void *base,size_t len,size_t width,int (*Comp)(const void *,const void *));
