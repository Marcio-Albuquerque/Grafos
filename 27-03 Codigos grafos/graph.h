/*graph.h*/
/* Biblioteca de grafos no formato de uma lista de adjacencia*/
#ifndef _GRAPH_H_
#define _GRAPH_H_

/* Declara o tipo de grafo.
uma lista de coisas Inf:https://pt.wikibooks.org/wiki/Programar_em_C/Enumeração;8 */
typedef enum {NAO_DIRECIONADO=0, DIRECIONADO} graph_type_e;

/* Adjacency list node*/
typedef struct adjlist_node
{
    int vertex;                /*Index to adjacency list array*/
    struct adjlist_node *next; /*Pointer to the next node*/
}adjlist_node_t, *adjlist_node_p;

/* Adjacency list */
typedef struct adjlist
{
    int num_members;           /*number of members in the list (for future use)*/
    adjlist_node_t *head;      /*head of the adjacency linked list*/
}adjlist_t, *adjlist_p;

/* Estrutura do grafo. Um grafo está em uam verto de Lista de adjacencia.
   O tamanho do verto é o numero numero de vertices no grafos*/
typedef struct adjlistgraph
{
    graph_type_e type;        /*Tipo de grafos: Direcionado ou Não Direcionado */
    int num_vertices;         /*Número de vertices (E)*/
    adjlist_p adjListArr;     /*Lista de adjacências*/

}adjlistgraph_t, *adjlistgraph_p;

typedef struct adjmatgraph
{
    graph_type_e type;        /*Tipo de grafos: Direcionado ou Não Direcionado */
    int num_vertices;         /*Número de vertices (E)*/
    int** adj_matrix;         /*Matriz da adjacencia*/

}adjmatgraph_t, *adjmatgraph_p;

typedef struct incmatgraph
{
    int* conjEdge;            /*Conjunto de vetores (usei só para imprimir)*/
    int sizeEdge;
    graph_type_e type;        /*Tipo de grafos: Direcionado ou Não Direcionado */
    int num_vertices;         /*Número de vertices (E)*/
    int** inc_matrix;         /*Matriz da incidencia*/
    int* degree;

}incmatgraph_t, *incmatgraph_p;

#endif
