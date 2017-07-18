#include<stdio.h>
#define MaxN 100
#define row 6      /*规定矩阵的规模*/
#define col 5

void Transform(int A[row][col], int TA[][3]);    /*函数声明*/
int main()
{
    int m, n;
    m=6; n=5;

    int A[6][5], TA[MaxN][3];                    /*建立矩阵*/
    A[0][0] = 0; A[0][1] = 1; A[0][2] = 0; A[0][3] = 0; A[0][4] = 5; 
    A[1][0] = 4; A[1][1] = 0; A[1][2] = 0; A[1][3] = 0; A[1][4] = 0; 
    A[2][0] = 0; A[2][1] = 0; A[2][2] = 0; A[2][3] = 7; A[2][4] = 0; 
    A[3][0] = 0; A[3][1] = 6; A[3][2] = 0; A[3][3] = 0; A[3][4] = 0; 
    A[4][0] = 8; A[4][1] = 0; A[4][2] = 9; A[4][3] = 0; A[4][4] = 0; 
    A[5][0] = 0; A[5][1] = 0; A[5][2] = 0; A[5][3] = 0; A[5][4] = 0; 
    
    Transform(A, TA);

    getchar();
    return 1;
}
void Transform(int A[row][col], int TA[][3])
{
    int m, n;
    m = 6; n = 5;
    int i, j, k;
    k = 1;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            if (A[i][j] != 0)
            {
                TA[k][0] = i+1;           /*注意点1：这里i,j是存储的标号，而不是矩阵坐标，因此要加1*/
                TA[k][1] = j+1;
                TA[k++][2] = A[i][j];
            }
        }
    }
    TA[0][0] = m;        /*不要忘了TA的表头信息*/
    TA[0][1] = n;
    TA[0][2] = k;

    int l;
    for (l = 0; l < k; l++)
    {
        printf("%d %d %d\n",TA[l][0], TA[l][1], TA[l][2]);
    }
    getchar();
}
