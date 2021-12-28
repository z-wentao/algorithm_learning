/*
测试数据:
5
3
2
4
7
6
8
0 
*/
#include <stdio.h>
#include <stdlib.h>
 
#define ENDKEY 0
 
typedef int KeyType;
 
typedef struct  node
{
    KeyType  key ; /*关键字的值*/
    struct node  *lchild,*rchild;/*左右指针*/
}BSTNode, *BSTree;
 
void InsertBST(BSTree *bst, KeyType key)
/*若在二叉排序树中不存在关键字等于key的元素，插入该元素*/
{ 
    BSTree s;
    if (*bst == NULL)/*递归结束条件*/
    {
        s=(BSTree)malloc(sizeof(BSTNode));/*申请新的结点s*/
        s-> key=key;
        s->lchild=NULL; 
        s->rchild=NULL;
        *bst=s;
    }
    else 
        if (key < (*bst)->key)
            InsertBST(&((*bst)->lchild), key);/*将s插入左子树*/
        else 
            if (key > (*bst)->key)
                InsertBST(&((*bst)->rchild), key); /*将s插入右子树*/
}
 
void  CreateBST(BSTree  *bst)
/*从键盘输入元素的值，创建相应的二叉排序树*/
{ 
    KeyType key;
    *bst=NULL;
    scanf("%d", &key);
    while (key!=ENDKEY)   /*ENDKEY为自定义常量*/
    {
        InsertBST(bst, key);
        scanf("%d", &key);
    }
}
 
void  PreOrder(BSTree root) 
/*先序遍历二叉树, root为指向二叉树根结点的指针*/
{
    if (root!=NULL)
    {
        printf("%d  ",root->key);  /*输出结点*/
        PreOrder(root->lchild);  /*先序遍历左子树*/
        PreOrder(root->rchild);  /*先序遍历右子树*/
    }
}
 
/*
BSTree  SearchBST(BSTree bst, KeyType key)
/ *在根指针bst所指二叉排序树中，递归查找某关键字等于key的元素，若查找成功，返回指向该元素结点指针，否则返回空指针* /
{ 
    if (!bst) 
        return NULL;
    else 
        if (bst->key == key)
            return bst;/ *查找成功* /
        else
            if (bst->key > key)
                return SearchBST(bst->lchild, key);/ *在左子树继续查找* /
            else 
                return SearchBST(bst->rchild, key);/ *在右子树继续查找* /
}*/
 
 
BSTree  SearchBST(BSTree bst, KeyType key)
/*在根指针bst所指二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{ 
    BSTree q;
    q=bst;
    while(q)
    {
        if (q->key == key) 
            return q;  /*查找成功*/
        if (q->key > key)  
            q=q->lchild;  /*在左子树中查找*/
        else  
            q=q->rchild;  /*在右子树中查找*/
    }
    return NULL; /*查找失败*/
}/*SearchBST*/
 
BSTNode  * DelBST(BSTree t, KeyType  k) /*在二叉排序树t中删去关键字为k的结点*/
{
    BSTNode  *p, *f,*s ,*q;
    p=t; 
    f=NULL;
    while(p)  /*查找关键字为k的待删结点p*/
    { 
        if(p->key==k )  break;  /*找到则跳出循环*/
        f=p;   /*f指向p结点的双亲结点*/
        if(p->key>k)  
            p=p->lchild;
        else 
            p=p->rchild;
    } 
    if(p==NULL)  return t;  /*若找不到，返回原来的二叉排序树*/
    if(p->lchild==NULL)  /*p无左子树*/
    { 
        if(f==NULL) 
            t=p->rchild;  /*p是原二叉排序树的根*/
        else 
            if(f->lchild==p)  /*p是f的左孩子*/
                f->lchild=p->rchild ;  /*将p的右子树链到f的左链上*/
            else  /*p是f的右孩子*/
                f->rchild=p->rchild ;  /*将p的右子树链到f的右链上*/
            free(p);  /*释放被删除的结点p*/
    }
    else  /*p有左子树*/
    { 
        q=p; 
        s=p->lchild;
        while(s->rchild)  /*在p的左子树中查找最右下结点*/
        {
            q=s; 
            s=s->rchild;
        }
        if(q==p) 
            q->lchild=s->lchild ;  /*将s的左子树链到q上*/
        else 
            q->rchild=s->lchild;
        p->key=s->key;  /*将s的值赋给p*/
        free(s);
    }
    return t;
}
 
 
int main()
{
    BSTree T;
    int k;
    BSTree result;
    printf("建立二叉排序树，请输入序列:\n");
    CreateBST(&T);
    printf("先序遍历输出序列为:");
    PreOrder(T);
    printf("\n请输入要查找的元素:");
    fflush(stdin);
    scanf("%d",&k);
    result = SearchBST(T,k);
    if (result != NULL)
        printf("要查找的元素为%d\n",result->key);
    else
        printf("未找到!\n");
    result = DelBST(T,k);
    PreOrder(result);
}
