#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>

int scan_error(float a, float b, char c)
{
    if((c!='+') && (c!='-') && (c!='/') && (c!='*') & (c!='%'))
    {
        printf("Error input\n");
        return -1;
    }
    return 0;
}

void print(float ans, int i)
{
    if(i==0)
        printf("%0.0f\n", ans);
    else if(i==1)
        printf("%0.1f\n", ans);
    else if(i==2)
        printf("%0.2f\n", ans);
    else if(i==3)
        printf("%0.3f\n", ans);
    else if(i==4)
        printf("%0.4f\n", ans);
    else if(i==5)
        printf("%0.5f\n", ans);
    else if(i==6)
        printf("%0.6f\n", ans);
    else
        printf("≈%0.6f\n", ans);
}

int search_i(float a, float b)
{
    int k1=10, i=0;
    float x, y, k2 = 10;
    if(a>=0 && b>=0)
    {
        x = ((int)(a * 1 + .5) / 1.0);
        y = ((int)(b * 1 + .5) / 1.0);
        while(a!=x || b!=y)
        {
            x = ((int)(a * k1 + .5) / k2);
            y = ((int)(b * k1 + .5) / k2);
            k1=k1*10;
            k2=k2*10;
            i++;
        }
    }
    else if(a<=0 && b<=0)
    {
        x = ((int)(a * 1 - .5) / 1.0);
        y = ((int)(b * 1 - .5) / 1.0);
        while(a!=x || b!=y)
        {
            x = ((int)(a * k1 - .5) / k2);
            y = ((int)(b * k1 - .5) / k2);
            k1=k1*10;
            k2=k2*10;
            i++;
        }
    }
    else if(a<=0 && b>=0)
    {
        x = ((int)(a * 1 - .5) / 1.0);
        y = ((int)(b * 1 + .5) / 1.0);
        while(a!=x || b!=y)
        {
            x = ((int)(a * k1 - .5) / k2);
            y = ((int)(b * k1 + .5) / k2);
            k1=k1*10;
            k2=k2*10;
            i++;
        }
    }
    else
    {
        x = ((int)(a * 1 + .5) / 1.0);
        y = ((int)(b * 1 - .5) / 1.0);
        while(a!=x || b!=y)
        {
            x = ((int)(a * k1 + .5) / k2);
            y = ((int)(b * k1 - .5) / k2);
            k1=k1*10;
            k2=k2*10;
            i++;
        }
    }
    return i;
}
int search_j(int i)
{
    int j=1;
    while(i!=0)
    {
        j = j * 10;
        i--;
    }
    return j;
}
float search_x(float a, int j1, float j2)
{
    float x;
    if(a>=0){
        x = ((int)(a * j1 + .5) / j2);}
    else{
        x = ((int)(a * j1 - .5) / j2);}
    return x;
}
float search_y(float b, int j1, float j2)
{   
    float y;
    if (b>=0)
        y = ((int)(b * j1 + .5) / j2);
    else
        y = ((int)(b * j1 - .5) / j2);
    return y;
}

float sum(float x, float y)
{
    return x + y;
}

float difference(float x, float y)
{
    return x - y;
}
float mult(float a, float b)
{
    return a * b;
}