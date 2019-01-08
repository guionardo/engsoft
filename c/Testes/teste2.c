void main(){
char *pc;
float *px;
float x;

x = 6.5;
px = &x;
pc = (char*) px;

printf("x = %f (%p)\n",x,&x)	;
printf("px = %f (%p)\n",*px,px);
printf("pc = %s (%p)\n",pc,&pc);
printf("sizeof(char)=%d\n",sizeof(char));
printf("sizeof(float)=%d\n",sizeof(float));
}
