#include<stdio.h>
#include<stdlib.h>
#include "/home/lhospital/progamma/status.h"

#define M 100

void Huff_Code(int w[M], int weight[], int parent[], int lchild[], int rchild[], int start[], int code[], int n, int m);

int main()
{

}

void Huff_Code(int w[M], int weight[], int parent[], int lchild[], int rchild[], int start[], int code[], int n, int m)
{
    int i, f, s1, s2, c;

    for (i = 0; i < n; i++)     /*初始化双亲结点列、左孩子结点列、右孩子结点列*/
    {
        parent[i] = 0;
        lchild[i] = 0;
        rchild[i] = 0;
    }

    for (i = 0; i < m; i++)
        weight[i] = w[i];

    for (i = m; i < n; i++)
    {
        SELECT(i - 1, s1, s2)       
        /*使用SELECT函数选择两棵跟单权值最小的子树，其根节点分别由s1和s2指出，并把s2与s2合并成以i为根的二叉树，s1,s2的parent指向i而不是0*/
        parent[s1] = i;
        parent[s2] = i;
        lchild[i] = s1;
        rchild[i] = s2;
        weight[i] = weight[s1] + weight[s2];
    }   /*至此，Huffman树已经建立*/

    for (i = 0; i < m; i++)     /*生成Huffman编码*/
    {
        start[i] = m;
        f = parent[i];
        c = i;
        while (f != 0)
        {
            if (lchild[f] == c)
                code[i][start[i]] = 0;
            else
                code[i][start[i]] = 1;
            
            start[i]--;
            c = f;
            f = parent[f];
        }
    }

}