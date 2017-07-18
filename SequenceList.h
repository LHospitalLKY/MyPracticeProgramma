/******************************************
*文件名：SequenceList.h                   *
*内容：顺序表相关操作                     *
*******************************************/
#pragma once
#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H
#include <stdio.h>
#include <stdlib.h>
#include"/home/lhospital/progamma/CPROGRAMMA/数据结构文件集/status.h"
/**/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
/**/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif
typedef struct
{
    LElemType_Sq *elem;
    int length;
    int listsize;
}SqList;
/**/
Status InitList_Sq(SqList *L);
/****************************
*(01) 算法2.3 初始化空顺序表*
*****************************/
void ClearList_Sq(SqList *L);
/****************************
*(02) 清空顺序表            *
*****************************/
void DestroyList_Sq(SqList *L);
/****************************
*(03) 销毁顺序表            *
*****************************/
Status ListEmpty_Sq(SqList L);
/****************************
*(04) 判断顺序表是否非空    *
*****************************/
int ListLength_Sq(SqList L);
/****************************
*(05) 返回顺序表L中元素个数 *
*****************************/
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);
/****************************
*(06) 返回顺序表中第i个元素 *
*****************************/
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));
/*************************************************************
*(07) 算法2.6：返回顺序表L中与首个e满足Compare关系的元素位序 *
**************************************************************/
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);
/*****************************
*(08) 用pre_e返回cur_e的前驱 *
******************************/
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);
/******************************
*(09) 用next_e返回cur_e的后驱 *
*******************************/
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);
/*************************************************
*(10) 算法2.4：在顺序表i位置上插入元素e          *
**************************************************/
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);
/*************************************************
*(11) 算法2.5：删除顺序表L上第i个元素，并用e返回 *
**************************************************/
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));
/*************************************************
*(12) 用Visit函数访问顺序表L                     *
**************************************************/
#endif