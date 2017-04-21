/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


#define MAX 20

//Criar o vetor de visitado.
int visited[MAX];

/* Function to create an adjacency list node*/
adjlist_node_p createNode(int v)
{
    adjlist_node_p newNode = (adjlist_node_p)malloc(sizeof(adjlist_node_t));
    //if(!newNode)
        //err_exit("Unable to allocate memory for new node");

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

/* Function to create a graph with n vertices; Creates both directed and undirected graphs*/
graph_p createGraph(int n, graph_type_e type)
{
    int i;
    graph_p graph = (graph_p)malloc(sizeof(graph_t));
    //if(!graph)
      //  err_exit("Unable to allocate memory for graph");
    graph->num_vertices = n;
    graph->type = type;

    graph->adj_matrix = (int **) malloc (sizeof(int **)*graph->num_vertices);

    //Alocando memoria para matriz da adjacencia.
    if(!graph->adj_matrix) {
        printf ("Fatal error in memory allocation!");
    }

    int r, c;
    for (r = 0; r < graph->num_vertices; r++) {
        graph->adj_matrix[r] = (int *) malloc(sizeof(int)*graph->num_vertices);
        if(!graph->adj_matrix[r]) {
          printf ("Fatal error in memory allocation!");
        }
     }

     for (r = 0; r < graph->num_vertices; r++) {
        for (c = 0; c < graph->num_vertices; c++) {
              graph->adj_matrix[r][c] = 0;
            }
     }

    /* Create an array of adjacency lists*/
    graph->adjListArr = (adjlist_p)malloc(n * sizeof(adjlist_t));
    //if(!graph->adjListArr)
        //err_exit("Unable to allocate memory for adjacency list array");

    for(i = 0; i < n; i++)
    {
        graph->adjListArr[i].head = NULL;
        graph->adjListArr[i].num_members = 0;
    }

    return graph;
}

/*Destroys the graph*/
void destroyGraph(graph_p graph)
{
    if(graph)
    {
        if(graph->adjListArr)
        {
            int v;
            /*Free up the nodes*/
            for (v = 0; v < graph->num_vertices; v++)
            {
                adjlist_node_p adjListPtr = graph->adjListArr[v].head;
                while (adjListPtr)
                {
                    adjlist_node_p tmp = adjListPtr;
                    adjListPtr = adjListPtr->next;
                    free(tmp);
                }
            }
            /*Free the adjacency list array*/
            free(graph->adjListArr);
        }
        /*Free the graph*/
        free(graph);
        printf("%.1d ", graph->adj_matrix[1][1]);
    }
}

/* Adds an edge to a graph*/
void addEdge(graph_t *graph, int src, int dest)
{
    graph->adj_matrix[src][dest] = 1;
    printf("%.1d ", graph->adj_matrix[src][dest]);

    /* Add an edge from src to dst in the adjacency list*/
    adjlist_node_p newNode = createNode(dest);
    newNode->next = graph->adjListArr[src].head;
    graph->adjListArr[src].head = newNode;
    graph->adjListArr[src].num_members++;

    if(graph->type == NAO_DIRECIONADO)
    {
        graph->adj_matrix[dest][src] = 1;
        newNode = createNode(src);
        newNode->next = graph->adjListArr[dest].head;
        graph->adjListArr[dest].head = newNode;
        graph->adjListArr[dest].num_members++;
    }
}

//Usando busca em profundidade para visitar os vertices;
void DFS(graph_p graph, int i){
  adjlist_node_p adjListPtr = graph->adjListArr[i].head;
  printf("\nVertice visitado : %d \n",i);
  visited[i]=1;
  while (adjListPtr!=NULL) {
    i = adjListPtr->vertex;
    if(!visited[i]){
      DFS(graph, i);
      }
      adjListPtr = adjListPtr->next;
    }
}

//Checando a conexão dos vertices;
int checkconnectionGraph(graph_p graph){
  int i, bool;
  for (i = 0; i < graph->num_vertices; i++){
    if (visited[i] == 1){
      bool = 1;
    }else {
      bool = 0;
    }
  }
  return bool;
}


  /*int i;
  int vetor[graph->num_vertices] ;
  for (i = 0; i < graph->num_vertices; i++)
  {
      vetor[i] = 0; // Munda a vida para ver como a vinda é.

      printf("\n%d Vertices Atual: ", i);
      while (adjListPtr)
      {
          printf("%d->", adjListPtr->vertex);

          if (adjListPtr->vertex == i)// Diz que tem um laço no proprio Vertice
          {
            vetor[i] = vetor[i] - 1; // adiconar decrementra essa ligação.
          }
          else
          {
            vetor[i] = vetor[i] + 1;
          }

          adjListPtr = adjListPtr->next;
      }
      printf("NULL\n");
  }
  //Ainda pensando na vida.
  for (i = 0; i < graph->num_vertices; i++)
  {
      printf("\n \n print %d", vetor[i]);
  }*/





/* Function to print the adjacency list of graph*/
void displayGraph(graph_p graph)
{
    int i;
    for (i = 0; i < graph->num_vertices; i++)
    {
        adjlist_node_p adjListPtr = graph->adjListArr[i].head;
        printf("\n%d: ", i);
        while (adjListPtr)
        {
            printf("%d->", adjListPtr->vertex);
            adjListPtr = adjListPtr->next;
        }
        printf("NULL\n");
    }
}

//Imprimi a matriz de adjacencia;
void displayMatrixGraph(graph_p graph)
{
  printf("\n\n- - - - Matriz de Adjacencia - - - -\n \n");
 	   printf("   ");
     int r, c;
 	   for (c = 0; c < graph->num_vertices; c++) {
 	     printf("%.1d ", c);
    }
 	   printf("\n");
    for (c = 0; c < graph->num_vertices; c++) {
 	     printf("---");
 	   }
 	   printf("\n");
 	   for (r = 0; r < graph->num_vertices; r++) {
 	     printf("%.1d| ", r);
 	     for (c = 0; c <  graph->num_vertices; c++) {
 	         printf("%.1d ", graph->adj_matrix[r][c]);
 	     }
 	     printf("\n");
 	   }
}

int main()
{
    graph_p undir_graph = createGraph(6, NAO_DIRECIONADO);
    graph_p dir_graph = createGraph(5, DIRECIONADO);
    //addEdge(undir_graph, 0, 1);
    addEdge(undir_graph, 0, 4);
    addEdge(undir_graph, 1, 2);
    addEdge(undir_graph, 1, 3);
    addEdge(undir_graph, 1, 4);
    addEdge(undir_graph, 2, 3);
    addEdge(undir_graph, 3, 4);
    //addEdge(undir_graph, 1, 5);
    addEdge(undir_graph, 5, 5);


//    addEdge(dir_graph, 0, 1);
//    addEdge(dir_graph, 0, 4);
//    addEdge(dir_graph, 1, 2);
//    addEdge(dir_graph, 1, 3);
//    addEdge(dir_graph, 1, 4);
//    addEdge(dir_graph, 2, 3);
//    addEdge(dir_graph, 3, 4);

    printf("\n ----- Grafo: Nao Direcionado ----- \n");
    displayGraph(undir_graph);
    displayMatrixGraph(undir_graph);
    DFS(undir_graph, 0);
    if (checkconnectionGraph( undir_graph )){
      printf(" \nGrafo e conexo");
    }else {printf(" \nGrafo nao e conexo");}
    destroyGraph(undir_graph);

//    printf("\nDIRECTED GRAPH");
//    displayGraph(dir_graph);
//    destroyGraph(dir_graph);

    return 0;
}
