#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct BTNode {
  ElementType data;
  struct BTNode *lchild, *rchild;
} BTNode, *BTree;

/* 前序遍历输入， #代表NULL */
void CreateBTNode(BTree *BT){
    char c = '\0';
    int ret = -1;
    scanf("%c", &c);

    // End of leaves
    if('#' == c){
        return ;
    }
    
    *BT = malloc(sizeof(BTNode));
    if (NULL == BT){
        printf("Malloc Error\n");
    }
    (*BT)->data = c;

    CreateBTNode(&((*BT)->lchild));
    CreateBTNode(&((*BT)->rchild));
}

void visit(BTree *BT, int level){
    printf("Data:[%c], level:[%d]\n",(*BT)->data, level);
}

//前序遍历
void PreRev(BTree *BT, int level){
    if(NULL == *BT){
        return ;
    }
    visit(BT, level);
    PreRev(&((*BT)->lchild), level+1);
    PreRev(&((*BT)->rchild), level+1);
}

//后序遍历
void BackRev(BTree *BT, int level){
    if(NULL == *BT){
        return ;
    }
    PreRev(&((*BT)->lchild), level+1);
    PreRev(&((*BT)->rchild), level+1);
    visit(BT, level);
}

//中序遍历
void MidRev(BTree *BT, int level){
    if(NULL == *BT){
        return ;
    }
    PreRev(&((*BT)->lchild), level+1);
    visit(BT, level);
    PreRev(&((*BT)->rchild), level+1);
}

int main(int argc, char * argv[]){
    // Header Node
    BTree BT;
    CreateBTNode(&BT);

    printf("Pre------------------\n");
    PreRev(&BT, 1);
    printf("Bac------------------\n");
    BackRev(&BT, 1);
    printf("Mid------------------\n");
    MidRev(&BT, 1);

    return 0;
}
