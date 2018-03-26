#include"headerm.h"
#include<stdio.h>
int matrix_mult(int p[], int n)
{
    int m[n][n],s[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++)  
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] =99999;
            for (k=i; k<=j-1; k++)
            {
                
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
		{
                    m[i][j] = q;
		    s[i][j] = k;
		}
            }
        }
    }
	print_seq(s,1,6); 
    return m[1][n-1];
}
 

