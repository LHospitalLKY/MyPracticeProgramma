#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"/home/lhospital/progamma/status.h"

/*建立无向图的邻接矩阵*/
#define MaxValue INT_MAX
#define MaxVNum 100
/*这里直接省去了存储定点数据信息的数组，将所有的顶点数据认为是int型数据，目的是为了节省时间，因为这不是重点*/

void ADJMatrix(int A[MaxVNum][MaxVNum], int n, int e)
{
    int i, j, k, weight;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            A[i][j] = MaxValue;
    }

    for (k = 0; k < e; k++)
    {
        printf("Please input the v1: ");
        scanf("%d", &i);
        printf("Please input the v2: ");
        scanf("%d", &j);
        printf("Please input the weight: ");
        scanf("%d", &weight);
                
        A[i - 1][j - 1] = weight;
        A[j - 1][i - 1] = weight;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

}

/*邻接表存储*/
typedef struct edge
{
    /*边结点结构*/
    int adjvex;
    int weight;
    struct edge *next;
}ELink;

typedef struct ver
{
    /*顶点结点结构*/
    int vertex;
    ELink *link;
}VLink;

void AdjList(VLink G[], int n, int e)   /*这里是无向图的建立方法，有向图类似，但是有一些细节差异*/
{
    int k, vi, vj, weight;
    ELink *p, *q;

    for (k = 0; k < n; k++)
    {
        G[k].vertex = k + 1;
        G[k].link = NULL;
    }   /*初始化G数组*/

    for (k = 0; k < 2*e; k++)        /*当建立的是有向图时，k < e*/
    {
        printf("Please input the vi: ");
        scanf("%d", &vi);

        printf("Please input the vj: ");
        scanf("%d", &vj);

        printf("Please input the weight: ");
        scanf("%d", &weight);    /*分别输入两个端点，如果是有向图，那么vi为弧尾，vj是弧头*/

        p = (ELink*)malloc(sizeof(ELink));
        p -> adjvex = vj - 1;
        p -> weight = weight;
        p -> next = NULL;       /*初始化边结点*/

        if (!G[vi - 1].link)
            G[vi - 1].link = p;     /*如果顶点结点的link域为空*/
        else
        {
            q = G[vi - 1].link;
            while (q -> next)
                q = q -> next;
            q -> next = p;            /*将p插入表尾*/
        }
    }
}

void DeleVer(VLink G[], int n, int item)
{
    int i, k = -1;
    ELink *p, *q, *r;

    for (i = 0; i < n; i++)     /*找到匹配item的数据点*/
    {
        if (G[i].vertex == item)
        {
            k = i;
            break;
        }
    }

    if (k != -1)
    {
        p = G[k].link;
        for (i = k + 1; i < n; i++)
        {
            /*删除G中的第k个点，即与item匹配的点*/
            G[i - 1].vertex = G[i].vertex;
            G[i - 1].link = G[i].link;
        }
        n--;

        while (p != NULL)
        {
            /*删除第k个链表的所有边结点*/
            r = p;
            p = p -> next;
            free(r);
        }

        for (i = 0; i < n; i++)
        {
            p = G[i].link;
            while (p != NULL)
            {
                if (p -> adjvex == k)       /*如果p是依附于k的边*/
                {
                    if (G[i].link == p)     /*删除p所指的边结点*/
                        G[i].link = p -> next;
                    else                    /*删除q所指的边结点*/
                        q -> next = p -> next;

                    r = p;
                    p = p -> next;
                    free(r);
                }
                else
                {
                    if (p -> adjvex > k)    /*若p所指的边结点的adjvex域的值大于k*/
                        p -> adjvex--;      /*p所指边的adjvex域减1，因为删除了一个结点*/

                    q = p;
                    p = p -> next;          /*p移动到下一个结点*/
                }
            }
        }
    }
}

/*主函数*/
int main()
{
    
    int A[MaxVNum][MaxVNum], n, e;
    VLink G[MaxVNum];

    printf("Please input the number of vetrex: ");
    scanf("%d", &n);
    printf("Please intput the number of edge: ");
    scanf("%d", &e);
    
    //ADJMatrix(A, n, e);
    
    AdjList(G, n, e);

    int del;
    printf("Please input the item which you want to delete: ");
    scanf("%d", &del);

    DeleVer(G, n, del);

    getchar();
}