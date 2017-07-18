#include<stdio.h>
#include<stdlib.h>
#include"/home/lhospital/progamma/status.h"
#define Max 50

/*本部分对二叉树的二叉链表表示进行了演示，其中包含了六个遍历算法和一个建立算法，
遍历算法包括前、中、后序的递归与非递归算法*/

/*二叉链表结构体*/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


BiTree CreateBiTree(BiTree &T); /*二叉链表的先序建立*/
void PreOrde(BiTree T);     /*先序法遍历二叉树*/
void InOrde(BiTree T);      /*中序法遍历二叉树*/
void PostOrde(BiTree T);    /*后序法遍历二叉树*/
void InOrdeTraver(BiTree T);    /*非递归中序遍历法*/
void PreOrdeTraver(BiTree T);   /*非递归前序遍历法*/
void PostOrdeTraver(BiTree T);  /*非递归后序遍历法*/
void LayerOrder(BiTree T);  /*按层遍历方式（广度优先）*/
int Similar(BiTree T1, BiTree T2);  /*判断两个二叉树是否相似*/
int Equal(BiTree T1, BiTree T2);    /*判断两个二叉树是否等价*/
void Destroy(BiTree T);     /*删除结点*/
int ClearBiTree(BiTree &T); /*销毁二叉树*/
int DepthBiTree(BiTree T);  /*递归求深度*/
int DepthBiTree_InStack(BiTree T);    /*中序计算二叉树深度*/
int DepthBiTree_PreStack(BiTree T);     /*前序计算二叉树深度*/
int DepthBiTree_PostStack(BiTree T);    /*后序计算二叉树*/


int main()
{
    BiTree T, T_compare;
    int compare_coeff1, compare_coeff2, clear_coeff, depth;

    printf("Please input the Binary Tree:\n");
    T = CreateBiTree(T);
    printf("\n");
    //printf("Please input other binary tree:\n");    /*不知为何这里出现了bug，当创建T之后，无法创建T_compare，在进行别的内容测试时将这个注释掉*/
    //T_compare = CreateBiTree(T_compare);
    PreOrde(T);
    printf("\n");

    InOrde(T);
    printf("\n");

    PostOrde(T); 
    printf("\n");

    InOrdeTraver(T);
    printf("\n");

    PreOrdeTraver(T);
    printf("\n");

    PostOrdeTraver(T);
    printf("\n");

    LayerOrder(T);
    printf("\n");

    depth = DepthBiTree(T);
    printf("The depth of this binary tree is %d\n", depth);

    depth = DepthBiTree_InStack(T);
    printf("The depth of this binary tree is %d\n", depth);

    depth = DepthBiTree_PreStack(T);
    printf("The depth of this binary tree is %d\n", depth);

    depth = DepthBiTree_PostStack(T);
    printf("The depth of this binary tree is %d\n", depth);

    clear_coeff = ClearBiTree(T);
    if (clear_coeff == 1)
        printf("The binary tree is already clear");
    printf("\n");
    


    
    /*compare_coeff1 = Similar(T, T_compare);     //测试别的代码时将这段注释掉
    if (compare_coeff1 == 1)
        printf("These two binary tree is similar!\n");
    else
        printf("These two binary tree is not similar!\n");

    compare_coeff2 = Equal(T, T_compare);       //测试别的代码时将这段注释掉
    if (compare_coeff2 == 1)
        printf("These two binary tree is equal!\n");
    else
        printf("These two binary tree is not equal!\n");*/


    getchar();
    getchar();
    return 1;
}

/*二叉链表的递归先序建立*/
BiTree CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = 0;
    else
    {
        if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(Over);
        T -> data = ch;
        T -> lchild = CreateBiTree(T -> lchild);
        T -> rchild = CreateBiTree(T -> rchild);
    }
    return T;
}
/*二叉树递归前序遍历*/
void PreOrde(BiTree T)
{
    if (T != NULL)
    {
        printf("%c", T -> data);
        PreOrde(T -> lchild);
        PreOrde(T -> rchild);
    }
}
/*递归中序遍历*/
void InOrde(BiTree T)
{
    if (T != NULL)
    {
        InOrde(T -> lchild);
        printf("%c", T -> data);
        InOrde(T -> rchild);
    }
}
/*递归后序遍历*/
void PostOrde(BiTree T)
{
    if (T != NULL)
    {
        PostOrde(T -> lchild);
        PostOrde(T -> rchild);
        printf("%c", T -> data);
    }
}
/*中序遍历的非递归算法*/
void InOrdeTraver(BiTree T)
{
    BiTree M[Max], p;
    p = T;
    int i = -1;
    int k = 1;

    do{
        while (p != NULL)
        {
            M[++i] = p;
            p = p -> lchild;
        }
        k++;
        p = M[i--];
        printf("%c",p -> data);
        p = p -> rchild;
    } while(!(p == NULL && i == -1));
}
/*前序遍历非递归算法*/
void PreOrdeTraver(BiTree T)
{
    BiTree M[Max], p;
    p = T;
    int t = -1;

    do{
        while(p != NULL)
        {
            printf("%c", p -> data);
            M[++t] = p;
            p = p -> lchild;            
        }
        p = M[t--];
        p = p -> rchild;
    }while(!(p == NULL && t == -1));
}
/*后序遍历非递归算法*/
/*相比于前序遍历和中序遍历，后序遍历要增加一个进栈出栈的过程
因为在后序遍历中，当我们得到左子属不存在的事实时，我们需要看的是
子树根节点是否有右子树，如果没有那么才遍历子树根节点。而在存放
地址的栈堆中，左子树不存在时，就要将根节点退栈，因此需要规定一个
标志表示是否能够根节点是否能够访问，如果不能，那么访问标志记为0，如果
能，那么访问标志记为1,0时根节点再次进栈，1时不再进栈*/
void PostOrdeTraver(BiTree T)
{
    BiTree M1[Max], p;
    int M2[Max], flag, top;

    p = T;
    top = -1;
    
    if (T != NULL)
    {
        do{
            while (p != NULL)
            {
                M1[++top] = p;
                M2[top] = 0;
                p = p -> lchild;
            }

            p = M1[top];
            flag = M2[top--];
            if (flag == 0)
            {
                M1[++top] = p;
                M2[top] = 1;
                p = p -> rchild;
            }
            else
            {
                printf("%c",p -> data);
                p = NULL;
            }

        }while (!(p == NULL && top == -1));
    }
}

/*按层遍历的算法*/
void LayerOrder(BiTree T)
{
    BiTree Queue[Max], p;
    int front, rear;
    if (T != NULL)
    {
        Queue[0] = T;
        front = -1;
        rear = 0;

        while (front < rear)
        {
            p = Queue[++front];
            printf("%c", p -> data);
            if (p -> lchild != NULL)
                Queue[++rear] = p -> lchild;
            if (p -> rchild != NULL)
                Queue[++rear] = p -> rchild;
        }
    }
}

/*二叉树的相似性（递归）*/
int Similar(BiTree T1, BiTree T2)
{
    if (!T1 && !T2)         /*如果两棵二叉树为空*/
        return 1;
    if (T1 && T2 && Similar(T1 -> lchild, T2 -> lchild) && Similar(T1 -> rchild, T2 -> rchild))  /*如果左子树相似且右子树相似*/
        return 1;
    return 0;
}
/*二叉树的等价性（递归）*/
int Equal(BiTree T1, BiTree T2)
{
    if (!T1 && !T2)         /*如果两棵二叉树为空*/
        return 1;
    if (T1 && T2 
            && (T1 -> data == T2 -> data) 
            && Equal(T1 -> lchild, T2 -> lchild) 
            && Equal(T1 -> rchild, T2 -> rchild))  /*如果左子树相似且右子树相似*/
        return 1;
    return 0;
}

/*二叉树的删除与销毁*/
/*二叉树的销毁是删除并释放各节点所占用的存储空间，然后将根节点的指针置为NULL，适合使用后序遍历。*/
void Destroy(BiTree T)
{
    if (T != NULL)
    {
        Destroy(T -> lchild);
        Destroy(T -> rchild);
        free(T);
    }
}
int ClearBiTree(BiTree &T)
{
    Destroy(T);
    T = NULL;
    return 1;
}

/*二叉树深度递归算法*/
int DepthBiTree(BiTree T)
{
    int ldepth, rdepth;
    if (T == NULL)
        return 0;
    else
    {
        ldepth = DepthBiTree(T -> lchild);  /*此处不将DepthBiTree()函数放入if条件中可能是为了提升效率*/
        rdepth = DepthBiTree(T -> rchild);
        if (ldepth >= rdepth)
            return ldepth + 1;
        else
            return rdepth + 1;
    }
}
/*中序二叉树深度非递归算法*/
int DepthBiTree_InStack(BiTree T)
{
    BiTree p, M1[Max];
    int curdepth, maxdepth, top, M2[Max];
    if (T == NULL)
        return 0;
    else
    {
        p = T;
        top = -1;
        curdepth = 1;
        maxdepth = 0;
        do{
            while (p != NULL)
            {
                M1[++top] = p;
                M2[top] = curdepth;
                p = p -> lchild;
                curdepth++;
            }
            p = M1[top];
            curdepth = M2[top--];
            if (p -> lchild == NULL && p -> rchild == NULL)
                if (maxdepth <= curdepth)
                    maxdepth = curdepth;
            p = p -> rchild;
            curdepth++;
        }while (!(p == NULL && top == -1));
        
        return maxdepth;
    }
    
}
/*前序非递归求深度*/
int DepthBiTree_PreStack(BiTree T)
{
    BiTree p, M1[Max];
    int curdepth, maxdepth, top, M2[Max];

    if (T == NULL)
        return 0;
    else
    {
        p = T;
        top = -1;
        curdepth = 1;
        maxdepth = 0;
        do{
            while (p != NULL)
            {
                M1[++top] = p;
                M2[top] = curdepth;
                if (p -> lchild == NULL && p -> rchild == NULL)
                    if (maxdepth <= curdepth)
                        maxdepth = curdepth;
                p = p -> lchild;
                curdepth++;
            }
            p = M1[top];
            curdepth = M2[top--];
            
            p = p -> rchild;
            curdepth++;
        }while (!(p == NULL && top == -1));

        return maxdepth;
    }
}
/*后序非递归求深度*/
int DepthBiTree_PostStack(BiTree T)
{
    BiTree p, M1[Max];
    int curdepth, maxdepth, top, flag, M2[Max], M3[Max];
    if (T == NULL)
        return 0;
    else
    {
        p = T;
        top = -1;
        curdepth = 1;
        maxdepth = 0;
        do{
            while (p != NULL)
            {
                M1[++top] = p;
                M2[top] = 0;
                M3[top] = curdepth;
                p = p -> lchild;
                curdepth++;
            }
            p = M1[top];
            flag = M2[top];
            curdepth = M3[top--];
            if (flag == 0)
            {
                M1[++top] = p;
                M2[top] = 1;
                M3[top] = curdepth;
                p = p -> rchild;
                curdepth++;
            }
            else
            {
                if (p -> lchild == NULL && p -> rchild == NULL)
                    if (maxdepth <=  curdepth)
                        maxdepth = curdepth;
                p = NULL;
            }
        }while (!(p == NULL && top == -1));
    }
    return maxdepth;
}