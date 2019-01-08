#include <stdio.h>
#include <stdlib.h>
int a,b;
int *c, *d;

int main(){
	a=10;
	b=20;
	c=&a;
	d=&b;
	b=5;
	a=b+2;
	*d=12;
	*c=*d+4;
	*d=*c+b;
	printf("%d",b);
	return b;
}
