#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char VertexType [4];
typedef int VRType;

#define INFINITY -1
/*定点数目 number of Vertrex*/
#define MaxSize 1111

/*邻接矩阵，储存弧(Arc)的信息*/
typedef struct {
	VRType adj; //权值
}ArcNode, AdjMatrix[MaxSize][MaxSize];

/*图的定义*/
typedef struct {
	VertexType vex[MaxSize]; //顶点信息
	AdjMatrix adj; //邻接矩阵，二维数组
	int VertexNumber, ArcNum; //vertex与Arc的数量
}MatrixGraph;

/* Search vertex in Matrix Array of MatrixGraph */
int LocateVertex(MatrixGraph *N, VertexType v){
    int i = 0;
    for(i=0; i<N->VertexNumber; i++){
        if(strcmp(N->vex[i], v) == 0){
            return i;
        }
    }
    return -1;
}

void CreateGraph(MatrixGraph *Network) {
	int VertexNumver, ArcNumber;
    int i,j;
    VertexType VertexHead;
    VertexType VertexTail;
    int Weight;
	printf("Please Input the vertex and Arc number of Network(Graph with weight)\n");
	printf("Seperate with ,:");
	scanf("%d,%d", &VertexNumver, &ArcNumber);

	printf("VNumver=%d, ArcNumber=%d\n", VertexNumver, ArcNumber);
    Network->VertexNumber = VertexNumver;
    Network->ArcNum = ArcNumber;

	printf("Please Input the vertex value\n");
    for(i=0; i<VertexNumver; i++){
        scanf("%s",Network->vex[i]);
        printf("Vertex name = [%s]\n",Network->vex[i]);
    }

    /* Initialized as no connected */
    for(i=0; i<VertexNumver; i++){
        for(j=0; j<VertexNumver; j++){
            Network->adj[i][j].adj=INFINITY;
        }
    }

    /* Get the connections status */
	printf("Please Input the arc head, arc tail, arc weight value\n");
	printf("Seperate with space\n");

    for(i=0; i<ArcNumber; i++){
        scanf("%s %s %d",VertexHead,VertexTail,&Weight);
        int HeadIntex = -1, TailIndex = -1;
        HeadIntex = LocateVertex(Network,VertexHead);
        TailIndex = LocateVertex(Network,VertexTail);
        if(-1 != HeadIntex && -1 != TailIndex){
            Network->adj[HeadIntex][TailIndex].adj = Weight;
            printf("Edge index = %d: Vex[%d][%d]=[%d]\n",i,HeadIntex,TailIndex,Weight);
            //Network->vex[TailIndex][HeadIntex] = 1;
        }else{
            printf("Edge index = %d: Input Error\n",i);
        }
    }
}

void DisplayMatrixGraph(const MatrixGraph *N){
    int i,j;
    printf("\t");
    for(i=0; i<N->VertexNumber; i++){
        printf("%s\t",N->vex[i]);
    }
    printf("\n");

    for(j=0; j<N->VertexNumber; j++){
        for(i=0; i<N->VertexNumber; i++){
            if(i == 0){
                printf("%s\t",N->vex[j]);
            }
            printf("%d\t",N->adj[i][j].adj);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
	printf("Here We go\n");
	MatrixGraph Network;
	CreateGraph(&Network);

    DisplayMatrixGraph(&Network);
    /*Stop the terminal to exit */
	getchar();
    return 0;
}
