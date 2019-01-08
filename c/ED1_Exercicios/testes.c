void main(){
	char * pc;
	float *px;
	float x;
	x=6.5;
	px=&x;
	pc=(char*)px;
	
	printf("pc %p = %s\n",pc,*pc);
	printf("px %p = %f\n",&px,px);
	printf("x  %p = %f\n",&x,x);
	
	int m1[2,2];
	int m2[2][2];
	
}
