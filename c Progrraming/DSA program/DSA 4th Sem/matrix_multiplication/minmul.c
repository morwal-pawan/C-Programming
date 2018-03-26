#include"headermin.h"
int Matrix(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min =999;
    int count;
    for (k = i; k <j; k++)
    {
        count = Matrix(p, i, k) +
                Matrix(p, k+1, j) +
                p[i-1]*p[k]*p[j];

        if (count < min)
            min = count;
    }
    return min;
}

