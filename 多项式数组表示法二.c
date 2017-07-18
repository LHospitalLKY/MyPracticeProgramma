#include<stdio.h>
#define MaxN 100

void PloyAdd(int A[9], int B[7], int C[]); //函数声明

int main()              //main()函数，主要用来测试求和程序
{
    int A[9], B[7];            //定义多项式A和B，A = x^100 + 2*x^10 + x^5 + 7，B = 3*x^100 + 4*x^5 + 4
    A[0] = 4; B[0] = 3;
    A[1] = 1; B[1] = 3;
    A[2] = 100; B[2] = 100;
    A[3] = 2; B[3] = 4;
    A[4] = 10; B[4] = 5;
    A[5] = 1; B[5] = 4;
    A[6] = 5; B[6] = 0;
    A[7] = 7;
    A[8] = 0;

    int C[MaxN];
    PloyAdd(A, B, C);
    return 1;
}
void PloyAdd(int A[9], int B[7], int C[]) //多项式求和主程序
{
    int i, j, k;
    i = 1; j = 1; k = 1;
    int a, b, c;                          //a, b, c和if语句中printf()函数都是为了debug程序而添加的
    while (i <= 9 - 1 && j <= 7 - 1)
    {
        if (A[i+1] == B[j+1])            //当A[i]的次数等于B[j]的次数，则将和填入C[k]的位置，i和j分别加2，k加2，进行下一步迭代
        {
            C[k] = A[i] + B[j];
            C[k+1] = A[i+1];

            a = A[i];
            b = B[j];

            i = i + 2;
            j = j + 2;
            k = k + 2;

            c = C[k];
            printf("a & b is equal!\n");
        
        }/*if*/
        else if (A[i+1] < B[j+1])       //当A[i]的次数小于B[j]的次数，则将B[j]填入C[k]的位置，j加2，k加2，进行下一步迭代
        {
            C[k] = B[j];
            C[k+1] = B[j+1];
            
            a = A[i];
            b = B[j];

            j = j + 2;
            k = k + 2;
            c = C[k];
            printf("a is small index!\n");
        
            
        }/*if*/
        else                           //当A[i]的次数等于B[j]的次数，则将A[i]填入C[k]的位置，i加2，k加2，进行下一步迭代
        {
            C[k] = A[i];
            C[k+1] = A[i+1];

            a = A[i];
            b = B[j];

            i = i + 2;
            k = k + 2;
            c = C[k];
            printf("b is small index!\n");
        
        }/*if*/
       getchar();
    }
    C[0] = k;

    int m;
    for (m = 0; m < k-1; m++)
    {
        printf("%d\n", C[m]);
    }
    getchar();
}