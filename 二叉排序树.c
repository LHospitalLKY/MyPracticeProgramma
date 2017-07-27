#include<stdio.h>
#include<stdlib.h>
#include"/home/lhospital/progamma/status.h"
#define Max 50

/*本部分对二叉排序树的二叉链表表示进行了演示，其中包含了建立、插入、删除、查找算法*/
/*Maybe, the "scanf" function is the most weird function*/

/*二叉链表结构体*/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree SortTree(char K[], int n);   /*根据一个序列生成二叉排序树*/
void Insert(BiTree &T, char item);  /*非递归插入算法*/
BiTree SortTree_Re(char K[], int n);    /*根据一个序列生成二叉排序数（递归插入）。这里是为了方便同时展示两个插入算法，否则只需要一个生成算法即可*/
void Insert_Re(BiTree &T, char item);    /*递归插入算法*/
BiTree SearchBST_noRe(BiTree &T, char item);
BiTree SearchBST_Re(BiTree &T, char item);

int main()
{
    BiTree T, T1, T2, T_noRe, T_Re;
    int n;
    char K[n], Ele_find;

    printf("Please input the number of data queue: ");
    scanf("%d", &n);
    printf("Please input the char queue: ");
    scanf("%s", K);
    T_noRe = SortTree(K, n);
    T_Re = SortTree_Re(K, n);

    printf("Choose which element you want to search: ");
    scanf("%c", &Ele_find);
    scanf("%c", &Ele_find);       /*不知何原因，这里需要输入两次scanf函数才能正确读出要查找的值*/
    getchar();
    T = T_Re;
    T1 = SearchBST_noRe(T, Ele_find);
    T2 = SearchBST_Re(T, Ele_find);

    getchar();
    getchar();
    getchar();

    return 1;
}

/*（非递归）根据序列K[]建立一个二叉排序树*/
BiTree SortTree(char K[], int n)
{
    BiTree T = NULL;
    int i;

    if (n > 0)
    {
        for (i = 0; i < n; i++)
            Insert(T, K[i]);
    }

    return T;
}
/*非递归Insert算法*/
void Insert(BiTree &T, char item)
{
    BiTree p, q;
    p = (BiTree)malloc(sizeof(BiTNode));
    p -> data = item;
    p -> lchild = NULL;
    p -> rchild = NULL;

    if (T == NULL)
        T = p;
    else
    {
        q = T;
        while (1)
        {
            if (item < q -> data)
            {
                if (q -> lchild != NULL)
                    q = q -> lchild;
                else
                {
                    q -> lchild = p;
                    break;
                }
            }
            else
            {
                if (q -> rchild != NULL)
                    q = q -> rchild;
                else
                {
                    q -> rchild = p;
                    break;
                }
            }
        }
        
    }
}

/*（递归）根据序列K[]建立一个二叉排序树*/
BiTree SortTree_Re(char K[], int n)
{
    BiTree T = NULL;
    int i;

    if (n > 0)
    {
        for (i = 0; i < n; i++)
            Insert_Re(T, K[i]);
    }

    return T;
}
/*（递归）Insert_Re算法*/
void Insert_Re(BiTree &T, char item)
{
    if (T == NULL)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T -> data = item;
        T -> lchild = NULL;
        T -> rchild = NULL;
    }
    else
    {
        if (item < T -> data)
            Insert_Re(T -> lchild, item);
        else
            Insert_Re(T -> rchild, item);
    }
}

/*删除单独结点*/
void DeleteSBT(BiTree &T, BiTree p, BiTree q)
{
    /*p 是要删除的结点，q 是p的双亲结点*/
    BiTree s, r;    /*r表示将要代替p的结点，s表示r的双亲结点，只在p的左右孩子都存在的情况下使用*/
    int flag = 0;   /*flag用来做标记*/

    if (p -> lchild == NULL)    /*p没有左孩子*/
    {
        if (p == T)             /*p是根节点*/
            T = p -> rchild;
        else                    /*p不是根节点*/
        {
            r = p -> rchild;
            flag = 1;
        }
    }
    else if (p -> rchild == NULL)   /*p没有右孩子*/
    {
        if (p == T)                 /*p是根节点*/
            T = p -> lchild;
        else                        /*p不是根节点*/
        {
            r = p -> lchild;
            flag = 1;
        }
    }
    else                        /*p左右孩子都存在*/
    {
        s = p;
        r = s -> rchild;
        while (r -> lchild != NULL)     /*寻找p的右字数最左边的结点，因为它是右子树中值最小的*/
        {
            s = r;
            r = r -> lchild;
        }
        r -> lchild = p -> rchild;      /*更新r的左孩子*/
        if (s != p)
        {
            s -> lchild = r -> rchild;  /*更新r的双亲结点的指向*/
            r -> rchild = p -> rchild;  /*更新r的右孩子*/
        }
        if (p == T)             /*p是根节点*/
            T = r;
        else                    /*p不是根节点*/
            flag = 1;
    }

    if (flag == 1)              /*更新p的双亲结点q的指向*/
    {
        if ( p == q -> lchild)
            q -> lchild = r;
        else
            q -> rchild = r;
        free(p);                /*释放p*/
    }
}

/*查找二叉排序树中的元素（非递归）*/
BiTree SearchBST_noRe(BiTree &T, char item)
{
    BiTree p = T;
    while (p != NULL)
    {
        if (p -> data == item)
            return p;
        else if (item < p -> data)
            p = p -> lchild;
        else
            p = p -> rchild;
    }

    return NULL;
}
/*查找二叉排序树中的元素（递归）*/
BiTree SearchBST_Re(BiTree &T, char item)
{
    if (T == NULL)
        return NULL;
    if (T -> data = item)
        return T;
    if (item <= T -> data)
        return SearchBST_Re(T -> lchild, item);
    else
        return SearchBST_Re(T -> rchild, item);
}