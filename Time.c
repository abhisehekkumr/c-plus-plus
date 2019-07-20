#include<stdio.h>
#include<stdlib.h>

int min(int x, int y) { return (x < y)? x: y; }


void get(double h,double m)
{
    if(h==12)h=0;
    if(m==60)m=0;
    float a=abs((60*h)-(11*m))/2.0;
    printf("%d\n", min(360-a,a));
}


int main()
{
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        double h,m;
        scanf("%lf %lf\n",&h,&m);
        get(h,m);
        printf("\n");
    }
    return 0;
}