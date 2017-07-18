/********************************************
*文件夹：G:\VS2017_datatype\Book\N1\SqList  *
*内容：单链表顺序结构相关函数测试           *
*********************************************/
#include<stdio.h>
#include "/home/lhospital/progamma/CPROGRAMMA/数据结构文件集/SequenceList.c"
/*Function*/
Status CmpGreater(LElemType_Sq e, LElemType_Sq data);
void PrintElem(LElemType_Sq e);
int main(int argc, char **argv)
{
    SqList L;
    int i;
    LElemType_Sq e;
    printf("Function Init_Sq test \n");
    {
        printf("Initiate SqList L");
        InitList_Sq(&L);
        printf("\n\n");
    }
    PressEnter;
    printf("Function ListEmpty_Sq test \n");
    {
        ListEmpty_Sq(L) ? printf("L is empty!! \n") : printf("L is not empty!! \n");
        printf("\n\n");
    }
    PressEnter;
    printf("Function ListInset_Sq test \n");
    {
        for (i = 1; i <= 6; i++)
        {
            printf("As an instance, insert %d in location \"%d\" \n  " , i, 2 * i);
            ListInsert_Sq(&L, i, 2 * i);
        }
        printf("\n\n");
    }
    PressEnter;
    printf("Function ListTraverse_Sq \n");
    {
        printf("The element in list L is: L=");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("Function ListLength_Sq test \n");
    {
        i = ListLength_Sq(L);
        printf("The length of list L is: i = %d", i);
        printf("\n\n");
    }
    PressEnter;
    printf("Function ListDelete_Sq test \n");
    {
        ListDelete_Sq(&L, 3, &e);
        printf("Delete the 3th element of \"%d\"...\n", e);
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("Function GetElem_Sq test \n");
    {
        GetElem_Sq(L, 4, &e);
        printf("The 4th element in the list is: \"%d\" \n", e);
        printf("\n\n");
    }
    PressEnter;
    printf("Function LocateElem_Sq test \n");
    {
        i = LocateElem_Sq(L, 7, CmpGreater);
        printf("The first L=7 is locate in: %d \n", i);
        printf("\n\n");
    }
    PressEnter;
    printf("Function PriorElem_Sq test \n");
    {
        PriorElem_Sq(L, 8, &e);
        printf("The prior element of 6 is: \"%d\" \n", e);
        printf("\n\n");
    }
    PressEnter;
    printf("Function NextElem_Sq test \n");
    {
        NextElem_Sq(L, 8, &e);
        printf("The next element of 6 is: \"%d\" \n", e);
        printf("\n\n");1
    }
    PressEnter;
    *printf("Function ClearList_Sq test \n");
    {
        printf("Before clear the List \n");
        ListEmpty_Sq(L) ? printf("L is empty! \n") : printf("L is not empty! \n");
        ClearList_Sq(&L);
        printf("After clear the list \n");
        ListEmpty_Sq(L) ? printf("L is empty! \n") : printf("L is not empty! \n");
        printf("\n\n");
    }
    PressEnter;
    printf("Function DestroyList_Sq test \n");
    {
        printf("Before destroy the List \n");
        ListEmpty_Sq(L) == 0 ? printf("L is existed! \n") : printf("L is not existed! \n");
        DestroyList_Sq(&L);
        printf("After destroy the list \n");
        ListEmpty_Sq(L) == 0 ? printf("L is existed! \n") : printf("L is not existed! \n");
        printf("\n\n");
    }
    PressEnter;
    return 0;
}
Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
    return data > e ? TRUE : FALSE;
}
void PrintElem(LElemType_Sq e)
{
    printf("%d ", e);
}