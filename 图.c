#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"/home/lhospital/progamma/status.h"

/*建立无向图的邻接矩阵*/
#define MaxValue INT_MAX
#define MaxVNum 100

/*void ADJMatrix(int A[MaxVNum][MaxVNum], int n, int e)
{
    int i, j, k, weight;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            A[i][j] = MaxValue;
    }

    for (k = 0; k < e; k++)
    {
        printf("Please input the imformance of graph: ");
        scanf("i = %d, j = %d, weight = %d", &i, &j, &weight);
        A[i][j] = weight;
        A[j][i] = weight;
    }
}*/


/*主函数*/
int main()
{
    int A[MaxVNum][MaxVNum], n, e;
    /*printf("Please input the number of vetrex: ");
    scanf("%d", &n);
    printf("Please intput the number of edge: ");
    scanf("%d", &e);*/

    //ADJMatrix(A, n, e);
    n = 4; e = 6;
    int i, j, k, weight;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            A[i][j] = MaxValue;
    }

    int i_new, j_new;
    for (k = 0; k < e; k++)
    {
        printf("Please input the imformance of graph: ");
        /*scanf("i = %d, j = %d, weight = %d", &i_new, &j_new, &weight);
        A[i][j] = weight;
        A[j][i] = weight;*/
    }

    getchar();
}