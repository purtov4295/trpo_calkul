#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>
int main()
{
    float a, b, ans;
    char c;
    
    scanf("%f %c %f", &a, &c, &b);
    if(scan_error(a, b, c) == -1)
        return -1;
    
    int i = search_i(a,b);
    int j1 = search_j(i);
    float j2=(float)j1;
    float x = search_x(a,j1,j2);
    float y = search_y(b,j1,j2);
    if (c=='+')
    {
        ans = sum(x, y);
        print(ans, i);
    }
    
    return 0;
}