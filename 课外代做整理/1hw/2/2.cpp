#include <stdio.h>

#define MaxVex        100            //最大顶点数
#define INFINITY    65535        //表示∞
#define TRUE        1
#define    FALSE        0
typedef char        VertexType;    //顶点类型
typedef    int            EdgeType;    //权值类型
typedef int            Bool;
Bool    visited[MaxVex];

typedef struct {
    VertexType    vexs[MaxVex];            //顶点数组
    EdgeType    arc[MaxVex][MaxVex];    //邻接矩阵
    int    numVertexes, numEdges;            //当前图中的结点数以及边数
}MGraph;


//广度优先遍历需要的循环队列
typedef struct {
    int    data[MaxVex];
    int    front, rear;
}Queue;


/****************************************/
//队列的相关操作

//初始化
void InitQueue(Queue *Q)
{
    Q->front = Q->rear = 0;
}

//入队
void EnQueue(Queue *Q, int e)
{
    if ((Q->rear+1)%MaxVex == Q->front)
        return ;

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MaxVex;
}

//判空
Bool QueueEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
        return TRUE;
    else
        return FALSE;
}

//出队
void DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear)
        return ;
    
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxVex;
}
/****************************************/


//建立图的邻接矩阵
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;

    printf("输入顶点数和边数: ");
    scanf("%d%d", &G->numVertexes,&G->numEdges);
    fflush(stdin);

    printf("==============================\n");
    printf("输入各个顶点:\n");
    for (i=0; i<G->numVertexes; ++i)
    {
        printf("顶点%d: ",i+1);
        scanf("%c", &G->vexs[i]);
        fflush(stdin);
    }

    for (i=0; i<G->numVertexes; ++i)
    {
        for (j=0; j<G->numVertexes; ++j)
            G->arc[i][j] = INFINITY;
    }

    printf("==============================\n");
    for (k=0; k<G->numEdges; ++k)
    {
        printf("输入边(vi, vj)中的下标i和j和权W: ");
        scanf("%d%d%d", &i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}


//输出
void DisMGraph(MGraph *G)
{
    int i, j, k;
    k = G->numVertexes;
    for (i=0; i<k; ++i)
    {
        for (j=0; j<k; ++j)
        {
            printf("%5d ", G->arc[i][j]);
        }
        putchar('\n');
    }
}


/****************************************/
//图的深度优先遍历
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ",    G.vexs[i]);

    for (j=0; j<G.numVertexes; ++j)
    {
        if (G.arc[i][j]!=INFINITY  &&  !visited[j])
            DFS(G, j);
    }
}

void DFSTraverse(MGraph G)
{
    int i;
    for (i=0; i<G.numVertexes; ++i)
        visited[i] = FALSE;

    for (i=0; i<G.numVertexes; ++i)
    {
        if (!visited[i])
            DFS(G, i);
    }

}


//图的广度优先遍历
void BFSTraverse(MGraph *G)
{
    int i, j;
    Queue Q;

    for (i=0; i<G->numVertexes; ++i)
        visited[i] = FALSE;

    InitQueue(&Q);

    for (i=0; i<G->numVertexes; ++i)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", G->vexs[i]);
            EnQueue(&Q, i);

            while (!QueueEmpty(&Q))
            {
                DeQueue(&Q, &i);
                for (j=0; j<G->numVertexes; ++j)
                {
                    if (!visited[j] && G->arc[i][j]!=INFINITY)
                    {
                        visited[j] = TRUE;
                        printf("%c ", G->vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}
/****************************************/

//程序入口
int main(){
    MGraph G;

    CreateMGraph(&G);

    printf("\n图的深度优先遍历为: ");
    DFSTraverse(G);    

    printf("\n图的广度优先遍历为: ");
    BFSTraverse(&G);

    printf("\n");

    return 0;
}

/*
8 9
a
b
c
d
e
f
g
h
0 1 3
0 2 6
1 3 9
1 4 7
3 7 5
4 7 8
2 5 1
2 6 4
5 6 2 
*/ 
