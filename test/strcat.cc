#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    char a[30] = "string(1)";
    char b[] = "string(2)";
    printf("before strcat() : %s\n", a);
    printf("after strcat() : %s \n a=  %s\n", strcat(a, b), a);


	return 0;
}
