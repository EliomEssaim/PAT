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
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

int *etv, *ltv; /* �¼����緢��ʱ�����ٷ���ʱ�����飬ȫ�ֱ��� */
stack<int> ss2;
/* �ڽӾ���ṹ */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱���  */
{
	int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
}EdgeNode;

typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	int data; /* �����򣬴洢������Ϣ */
	EdgeNode *firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList,*GraphAdjList;
/* **************************** */


Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	top2=0;
	stack2 = (int *)malloc(GL->numVertexes * sizeof(int));/* ��ʼ����������ջ */
	int count=0;/* ����ͳ���������ĸ���  */
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
	TopologicalSort(GL);   /* ���������У���������etv��stack2��ֵ */
	ltv=(int *)malloc(GL->numVertexes*sizeof(int));/* �¼����緢��ʱ������ */
	for(i=0; i<GL->numVertexes; i++)
		ltv[i]=etv[GL->numVertexes-1];    /* ��ʼ�� */

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

	for(j=0; j<GL->numVertexes; j++)        /* ��ete,lte�͹ؼ�� */
	{
		for(e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k=e->adjvex;
			ete = etv[j];        /* ����緢��ʱ�� */
			lte = ltv[k] - e->weight; /* ���ٷ���ʱ�� */
			if(ete == lte)    /* ������ȼ��ڹؼ�·���� */
				printf("<v%d - v%d> length: %d \n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
		}
	}

}
