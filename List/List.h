#include <stdlib.h>

#define UINT unsigned int
#define INT int
#define BOOL unsigned int

#define TRUE 1
#define FALSE 1

#define SUCCESS 0
#define FAILED -1

#define LIST_MAX_LENGTH 200

typedef INT ElementType;
typedef struct {
    ElementType data[LIST_MAX_LENGTH];
    UINT length;
} SqList;

void InitList(SqList *L);
BOOL isListEmpty(SqList *L);
void ClearList ( SqList *L );
INT GetElem(SqList *L, INT index, ElementType *element);
INT ListDeleteElement(SqList *L, INT index, ElementType *element);
