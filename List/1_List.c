/*******************************************************
 * Description:
 *  List implement by array
 *
 * ADT
 * ADT 线性表(List)
 * Data
 *     线性表的数据对象集合为{a1, a2, ......, an}，每个元素的类型均为DataType。
 *     其中，除第一个元素a1外，每一个元素有且只有一个直接前驱元素，
 *     除了最后一个元素an外，每一个元素有且只有一个直接后继元素。
 *     数据元素之间的关系是一对一的关系。
 * Operation
 *     InitList(*L):          初始化操作，建立一个空的线性表L。
 *     ListEmpty(L):          若线性表为空，返回true，否则返回false。
 *     ClearList(*L):         将线性表清空。
 *     GetElem(L, i, *e):     将线性表L中的第i个位置元素值返回给e。
 *     LocateElem(L, e):      在线性表L中查找与给定值e相等的元素，
 *                            如果查找成功，返回该元素在表中序号表示成功；
*******************************************************/

#include "List.h"

void InitList(SqList *L) {
    L->length = 0;
    return;
}

BOOL isListEmpty (SqList *L){
    return L->length==0 ? TRUE : FALSE;
}

void ClearList (SqList *L){
    L->length = 0;
}

INT GetElem(SqList *L, INT index, ElementType *element){
    if (NULL==L || index<1 || L->length<1 || index>L->length){
        return FAILED;
    } else {
        *element = L->data[index-1];
        return SUCCESS;
    }
}

INT LocateElem(SqList *L, ElementType element){
    INT index = 0;
    if(NULL == L){
        return FAILED;
    }
    for(index=0; index<L->length; index++){
        if(element == L->data[index]){
            break;
        }
    }
    if(index >= L->length){
        return FAILED;
    }
    return index + 1;
}

INT ListDeleteElement(SqList *L, INT index, ElementType *element){
    INT i = index;
    if (NULL==L || index<1 || L->length<1 || index>L->length){
        return FAILED;
    }

    *element = L->data[index-1];

    for(i=index; i<L->length; i++){
        L->data[i-1] = L->data[i];
    }
    L->length--;

    return SUCCESS;
}

INT ListInsertElement(SqList *L, INT index, ElementType element){
    INT i = index;
    // Is List Full?
    if(L->length == LIST_MAX_LENGTH){
        return FAILED;
    }
    // Insert after the tail?
    if(L->length + 1 < index){
        return FAILED;
    }

    if (NULL==L || index<1){
        return FAILED;
    }

    // Insert the element not at tail, give out a place to insert
    if(index < L->length){
        for(i=index; i<L->length; i++){
            L->data[i-1] = L->data[1+i];
        }
    }

    L->data[index-1] = element;

    L->length++;

    return SUCCESS;
}
