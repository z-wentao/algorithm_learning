#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Bstnode
{
	int key;
	struct Bstnode *lchild, *rchild;
}Bstnode, *Bstree;

Bstree Create();
Bstree Insert(Bstree tree, int key);
Bstree Search(Bstree tree, int key);
void Traverse(Bstree tree);
Bstree Delete(Bstree tree, int key);

Bstree Create() {
	int key;
	Bstree tree = NULL;
	scanf("%d", &key);
	while (key != 0) {
		tree = Insert(tree, key);
		scanf("%d", &key);
	}
	return tree;
} 

Bstree Insert(Bstree tree, int key) {
	Bstree p = tree;
	Bstree s, f;
	while (p != NULL) {
		f = p;
		if (key == p->key) return tree;
		if (key < p->key) p = p->lchild;
		else p = p->rchild;
	}
	s = (Bstree)malloc(sizeof(Bstnode));
	s->key = key;
	s->lchild = NULL;
	s->rchild = NULL;
	if (tree == NULL) return s;
	if (key < f->key) f->lchild = s;
	else f->rchild = s;
	return tree;
}

Bstree Search(Bstree tree, int key) {
	Bstree p = tree;
	int flag = 0;
	while (p != NULL) {
		if (p->key == key) {
			printf("查询到该节点！");
			flag = 1;
			return(p);
			break;
		}
		if (key<p->key) p = p->lchild;
		else p = p->rchild;
	}
	if (flag == 0) {
		printf("查询不到关键字%d的节点!", key);
		return NULL;
	}
}

void Traverse(Bstree tree) {
    if (tree) {
        Traverse(tree->lchild);
        printf("%4d", tree->key);
        Traverse(tree->rchild);
    }
}

Bstree Delete(Bstree tree, int key) {
    Bstree p = tree;
    Bstree f, s, q;
    f = NULL;
    while (p) {
        if (p->key == key) break;
        f = p;
        if (p->key > key) p = p->lchild;
        else p = p->rchild;
    }
    if (p == NULL) return tree;
    if ((p->lchild == NULL) || (p->rchild == NULL)) {
        if (f == NULL) {
            if (p->lchild == NULL) tree = p->rchild;
            else tree = p->lchild;
        }
        else if (p->lchild==NULL) 
            if (f->lchild==p) f->lchild = p->rchild;
            else f->rchild=p->rchild;
        else if (f->lchild==p) f->lchild=p->lchild;
            else f->lchild = p->lchild;
            free(p);
        
    }
    else {
        q = p; s=p->lchild;
        while (s->rchild) {
            q = s; s=s->rchild;
        }
        if (q == p) q->rchild=s->lchild;
        p->key=s->key;
        free(s);
    }
    return tree;
}
int main() {
    system("color 1E");
    Bstree tree, p;
    int key1, key2, key3;
    int select, flag;
    printf("##########################################\n");
    printf("|*             欢迎使用本系统            *|\n");
    printf("|*****************************************|\n");
    printf("|*          1.创建二叉排序树             *|\n");
    printf("|*          2.插入                       *|\n");
    printf("|*          3.查找                       *|\n");
    printf("|*          4.遍历                       *|\n");
    printf("|*          5.删除                       *|\n");
    printf("|*          6.退出                       *|\n");
    printf("|* ************************************* *|\n");

    while (select != 6) {
        printf("选择的功能：");
        scanf("%d", &select);
        switch(select) {
            case 1: printf("请输入节点信息（0表示结束）\n");
                    tree = Create();
                    printf("\n");
                    break;
            case 2: printf("插入一个新的节点：");
                    scanf("%d", &key1); Insert(tree, key1);
                    printf("插入后的序列为：\n");
                    Traverse(tree);
                    printf("\n");
                    break;
            case 3: printf("输入查找的数据:");
                    scanf("%d", &key2);
                    p = Search(tree, key2);
                    printf("\n");
                    break;
            case 4: printf("遍历所得序列为：\n");
                    Traverse(tree);
                    printf("\n");
                    break;
            case 5: printf("输入删除的数据：");
                    scanf("%d", &key3);
                    tree = Delete(tree, key3);
                    printf("删除后遍历所得序列：\n");
                    Traverse(tree);
                    printf("\n");
                    break;
            case 6: printf("谢谢您的使用， 再见\n");
                    flag = 0; break;
            default: printf("输入错误， 请重试！\n");
                     break;
        }
    }
}
