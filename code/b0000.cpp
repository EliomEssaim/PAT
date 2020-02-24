#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"
#include <stack>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535
using namespace std;
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

int *etv, *ltv; /* 事件最早发生时间和最迟发生时间数组，全局变量 */
stack<int> ss2;
/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode *firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges; /* 图中当前顶点数和边数 */
}graphAdjList,*GraphAdjList;
/* **************************** */


Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	top2=0;
	stack2 = (int *)malloc(GL->numVertexes * sizeof(int));/* 初始化拓扑序列栈 */
	int count=0;/* 用于统计输出顶点的个数  */
	stack<int> ss;
    for(int i=0;i<GL->numVertexes){
        if(GL->adjList[i].in==0)
            ss.push(i);
        etv[i]=0;
    }

    while(!ss.empty()){
        int top=ss.top();
        ss.pop();
        count++;
        ss2.push(top);
        stack2[++top2] = top;
        for(e=GL->adjList[top].firstedge;e;e=e.next){
            GL->adjList[e.adjvex].in--;
            if(GL->adjList[e.adjvex].in==0)
                ss.push(e.adjvex);
            if(etv[e.adjvex]<etv[top]+e.weight)
                etv[e.adjvex]=etv[top]+e.weight;
        }
    }
	printf("\n");
	if(count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	TopologicalSort(GL);   /* 求拓扑序列，计算数组etv和stack2的值 */
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* 事件最早发生时间数组 */
	for(i=0; i<GL->numVertexes; i++)
		ltv[i]=etv[GL->numVertexes-1];    /* 初始化 */

	printf("etv:\t");
	for(i=0; i<GL->numVertexes; i++)
		printf("%d -> ",etv[i]);
	printf("\n");

	while(!ss2.empty()){
        int top=ss2.top();
        ss2.pop();
        for(e=GL->adjList[top].firstedge;e;e=e.next){
            if(ltv[top]<ltv[e.adjvex]-e.weight)
                ltv[top]=ltv[e.adjvex]-e.weight;
        }
	}

	printf("ltv:\t");
	for(i=0; i<GL->numVertexes; i++)
		printf("%d -> ",ltv[i]);
	printf("\n");

	for(j=0; j<GL->numVertexes; j++)        /* 求ete,lte和关键活动 */
	{
		for(e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k=e->adjvex;
			ete = etv[j];        /* 活动最早发生时间 */
			lte = ltv[k] - e->weight; /* 活动最迟发生时间 */
			if(ete == lte)    /* 两者相等即在关键路径上 */
				printf("<v%d - v%d> length: %d \n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}
	}

}
