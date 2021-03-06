/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* - - -  VARIAVEIS GLOBAIS  - - - */
int k=0;

/* - - - FUNÇÕES DE MALLOC PARA LISTA ADJACENCIA,
          MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA  - - - */

// Função para criar um nó na adjacencia lista //
adjlist_node_p createNode(int v);

// Função para alocar e criar o grafo de lista de adjacencia //
adjlistgraph_p createAdjListGraph(int n, graph_type_e type);

// Função para alocar e criar o grafo de matriz de adjacencia //
adjmatgraph_p createAdjMatGraph(int n, graph_type_e type);

// Função para alocar e criar o grafo de matriz de incidencia e adiciona a aresta
incmatgraph_p createIncMatGraphAddEdge(int n, graph_type_e type, int ini, int dest);
incmatgraph_p recreateIncMatGraphAddEdge(incmatgraph_p graph, int s, int ini, int dest);

/* - - -  FUNÇÕES DE PREENCHIMENTO PARA LISTA ADJACENCIA,
          MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA - - - */

// Adiciona uma aresta a um grafo de lista de adjacencia//
void addEdgeAdjList(adjlistgraph_t *graph, int ini, int dest);

// Adiciona uma aresta a um grafo de matriz de adjacencia//
void addEdgeAdjMat(adjmatgraph_t *graph, int ini, int dest);

/* - - -  FUNÇÕES DE IMPRIMIR PARA LISTA ADJACENCIA,
          MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA  - - - */

//Função para imprimir a lista de adjacência do grafo//
void displayGraphAdjList(adjlistgraph_p graph);

//Imprimi a matriz de adjacencia do grafo
void displayMatrixGraph(adjmatgraph_p graph);

//Imprimi a matriz de incidencia do grafo
void displayIncMatGraph(incmatgraph_p graph);

/* - - - FUNÇÕES DE LIBERA MEMORIA DAS LISTA ADJACENCIA,
        MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA - - - */

//Destrói o Grafo de Lista de Adjacencia//
void destroyGraphAdjList(adjlistgraph_p graph);

//Destrói o Grafo de Matriz de Adjacencia//
void destroyGraphAdjMat(adjmatgraph_p graph);

//Destrói o Grafo de Matriz de incidencia//
void destroyGraphIncMat(incmatgraph_p graph);

int main()
{   printf("     /\\---/\\     **************************************    _.._..,_,_\n");
    printf("    /^   ^  \\    *    Programa para criar um grafo    *   (          )\n");
    printf("   ( O   O   )   *       Ant. Marcio A. A. 2017       *    ]~,'-.-~~[\n");
    printf("    `.=o=__,'    *     o.marcio.albu@gmail.com        *  .=])' (;  ([\n");
    printf("                 **************************************  | ]:: '    [\n");
    printf("                                                         '=]): .)  ([\n");
    printf("                                                           |:: '    |\n");
    printf("                                                            ~~----~~\n");
  int n, t, r, c = 0, in, de, ch=0, vet;

  while (1) { //Leitura e verificação do numero de vertices.
    printf("Entre com o numero de vertices:\n--> ");
    scanf("%d", &n);
    if (n > 1) {
      break;
    }
    else
    {
      printf("\n\nAletar: Zero, Um ou numero negativos nao seram aceitos. \n\n");
    }
  }

  while (1) { //Leitura e verificação do numero de vertices.
    printf("\nEscolha qual o tipo de grafo:\n ");
    printf("1 - Nao Direcionado;\n ");
    printf("2 - Direcionado.\n--> ");
    scanf("%d", &t);
    if (t > 0 && t < 3) {
      break;
    }
    else
    {
      printf("\n\nAletar: Numero invalido. \n\n");
    }
  }

  while (1) { //Leitura e verificação do numero de vertices.
    printf("\nEscolha qual o tipo de grafo:\n ");
    printf("1 - Lista de Adjacencia;\n ");
    printf("2 - Matriz de Adjacencia;\n ");
    printf("3 - Matriz de Incidencia.\n--> ");
    scanf("%d", &r);
    if (r > 0 && r < 4) {
      break;
    }
    else
    {
      printf("\n\nAletar: Numero invalido. \n\n");
    }
  }

  //Vai executar o que foi escolhido.
  if (t ==1){// Nao Direcionado
    if (r==1){ // Não Direcionado e Lista de adjacencia
      
	    adjlistgraph_p undir_graph = createAdjListGraph(n, NAO_DIRECIONADO);

      while(1){
        printf("\nFormato de par de nos: <V1> <V2> \n");
        printf("Inserir par de nos:\n-->");
        //Para limpar o buffer em Windows e Linux
        fflush(stdin);//Windows
        //__fpurge(stdin); //Linux
        scanf ("%d %d", &in, &de);

        if (in > -1 && in < n && de > - 1 && de < n){
	             addEdgeAdjList(undir_graph, in, de);
 	       printf ("\nConexao (NAO DIRECIONADA) entre %d para %d\n", in, de);

 	     }else{
         printf ("\nAVISO: Conexao INVALIDA entre %d para %d\n", in, de);
       }

        printf("\nAviso para funcao Inserir:\n ");
        printf("1 - Para CONTINUAR na funcao;\n ");
        printf("2 - Para SAIR da funcao. \n--> ");
        scanf("%d", &ch);

        if(ch == 2){
          break;
        }
      }

      displayGraphAdjList(undir_graph);
      destroyGraphAdjList(undir_graph);
	    
    }
    else
    {// Parte do código para grafos nao direcionados
      if(r==2){ // Não Direcionado e matriz de adjacencia
        adjmatgraph_p undir_graph = createAdjMatGraph(n, NAO_DIRECIONADO);

        while(1){
          printf("\nFormato de par de nos: <V1> <V2> \n");
          printf("Inserir par de nos:\n-->");
          //Para limpar o buffer em Windows e Linux
          fflush(stdin);//Windows
          //__fpurge(stdin); //Linux
          scanf ("%d %d", &in, &de);

          if (in > -1 && in < n && de > - 1 && de < n){
                 addEdgeAdjMat(undir_graph, in, de);
           printf ("\nConexao (NAO DIRECIONADA) entre %d para %d\n", in, de);

         }else{
           printf ("\nAVISO: Conexao INVALIDA entre %d para %d\n", in, de);
         }

          printf("\nAviso para funcao Inserir:\n ");
          printf("1 - Para CONTINUAR na funcao;\n ");
          printf("2 - Para SAIR da funcao. \n--> ");
          scanf("%d", &ch);

          if(ch == 2){
            break;
          }
        }

        displayMatrixGraph(undir_graph);
        destroyGraphAdjMat(undir_graph);


      }else{//Não Direcionado e Matriz de Incidencia
        int sizeEdge = 0; //Um contador
        incmatgraph_p undir_graph;
        while(1){
          printf("\nFormato de par de nos: <V1> <V2> \n");
          printf("Inserir par de nos:\n-->");
          //Para limpar o buffer em Windows e Linux
          fflush(stdin);//Windows
          //__fpurge(stdin); //Linux
          scanf ("%d %d", &in, &de);

          if (in > -1 && in < n && de > - 1 && de < n){
            sizeEdge++;
            if(sizeEdge == 1){
              undir_graph = createIncMatGraphAddEdge(n, NAO_DIRECIONADO, in, de);
            }else{
              // Atualiza a matriz
              undir_graph = recreateIncMatGraphAddEdge(undir_graph, sizeEdge, in, de);
            }
            printf ("\nConexao (NAO DIRECIONADA) entre %d para %d, para a Aresta: %d\n", in, de, sizeEdge);
          }else{
            printf ("\nAVISO: Conexao INVALIDA entre %d para %d, para a Aresta: %d \n", in, de, NULL);
          }

          printf("\nAviso para funcao Inserir:\n ");
          printf("1 - Para CONTINUAR na funcao;\n ");
          printf("2 - Para SAIR da funcao. \n--> ");
          scanf("%d", &ch);

          if(ch == 2){
            undir_graph->sizeEdge= sizeEdge;
            break;
          }
        }

        displayIncMatGraph(undir_graph);
        destroyGraphIncMat(undir_graph);

      }
  }

}else{ // Parte do código para grafos direcionados
  if (r==1){ // Direcionado e lista de adjacencia

    adjlistgraph_p dir_graph = createAdjListGraph(n, DIRECIONADO);

    while(1){
      printf("\nFormato de par de nos: <V1> <V2> \n");
      printf("Inserir par de nos:\n-->");
      //Para limpar o buffer em Windows e Linux
      fflush(stdin);//Windows
      //__fpurge(stdin); //Linux
      scanf ("%d %d", &in, &de);

      if (in > -1 && in < n && de > - 1 && de < n){
             addEdgeAdjList(dir_graph, in, de);
       printf ("\nConexao (DIRECIONADA) entre %d para %d\n", in, de);

     }else{
       printf ("\nAVISO: Conexao INVALIDA entre %d para %d\n", in, de);
     }

      printf("\nAviso para funcao Inserir:\n ");
      printf("1 - Para CONTINUAR na funcao;\n ");
      printf("2 - Para SAIR da funcao. \n--> ");
      scanf("%d", &ch);

      if(ch == 2){
        break;
      }
    }

    displayGraphAdjList(dir_graph);
    destroyGraphAdjList(dir_graph);

  }else{// Parte do código para grafos direcionados
    if(r==2){//Direcionado e matriz de adjacencia

      adjmatgraph_p dir_graph = createAdjMatGraph(n, DIRECIONADO);

      while(1){
        printf("\nFormato de par de nos: <V1> <V2> \n");
        printf("Inserir par de nos:\n-->");
        //Para limpar o buffer em Windows e Linux
        fflush(stdin);//Windows
        //__fpurge(stdin); //Linux
        scanf ("%d %d", &in, &de);

        if (in > -1 && in < n && de > - 1 && de < n){
               addEdgeAdjMat(dir_graph, in, de);
         printf ("\nConexao (DIRECIONADA) entre %d para %d\n", in, de);

       }else{
         printf ("\nAVISO: Conexao INVALIDA entre %d para %d\n", in, de);
       }

        printf("\nAviso para funcao Inserir:\n ");
        printf("1 - Para CONTINUAR na funcao;\n ");
        printf("2 - Para SAIR da funcao. \n--> ");
        scanf("%d", &ch);

        if(ch == 2){
          break;
        }
      }

      displayMatrixGraph(dir_graph);
      destroyGraphAdjMat(dir_graph);
    }else{  //Não Direcionado e Matriz de Incidencia
        int sizeEdge = 0; //Um contador
        incmatgraph_p dir_graph;
        while(1){
          printf("\nFormato de par de nos: <V1> <V2> \n");
          printf("Inserir par de nos:\n-->");
          //Para limpar o buffer em Windows e Linux
          fflush(stdin);//Windows
          //__fpurge(stdin); //Linux
          scanf ("%d %d", &in, &de);

          if (in > -1 && in < n && de > - 1 && de < n){
            sizeEdge++;
            if(sizeEdge == 1){
              dir_graph = createIncMatGraphAddEdge(n, DIRECIONADO, in, de);
            }else{
              // Atualiza a matriz
              dir_graph = recreateIncMatGraphAddEdge(dir_graph, sizeEdge, in, de);
            }
            printf ("\nConexao (DIRECIONADA) entre %d para %d, para a Aresta: %d\n", in, de, sizeEdge);
          }else{
            printf ("\nAVISO: Conexao INVALIDA entre %d para %d, para a Aresta: %d \n", in, de, NULL);
          }

          printf("\nAviso para funcao Inserir:\n ");
          printf("1 - Para CONTINUAR na funcao;\n ");
          printf("2 - Para SAIR da funcao. \n--> ");
          scanf("%d", &ch);

          if(ch == 2){
            dir_graph->sizeEdge= sizeEdge;
            break;
          }
        }
        displayIncMatGraph(dir_graph);
        destroyGraphIncMat(dir_graph);

    }
  }
  }

    return 0;
}


//// FUNÇÕES DE MALLOC PARA LISTA ADJACENCIA, MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA ////

// Função para criar um nó na adjacencia lista //
adjlist_node_p createNode(int v){
    adjlist_node_p newNode = (adjlist_node_p)malloc(sizeof(adjlist_node_t));

    if(!newNode){
        printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");}

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

//Função da lista de adjacencia.
adjlistgraph_p createAdjListGraph(int n, graph_type_e type){
    int i;
    adjlistgraph_p graph = (adjlistgraph_p)malloc(sizeof(adjlistgraph_t));
    if(!graph){
        printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
    }

    graph->num_vertices = n;
    graph->type = type;

    /* Create an array of adjacency lists*/
    graph->adjListArr = (adjlist_p)malloc(n * sizeof(adjlist_t));
    if(!graph->adjListArr){
          printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
      }
    for(i = 0; i < n; i++)
    {
        graph->adjListArr[i].head = NULL;
        graph->adjListArr[i].num_members = 0;
    }

    return graph;
}

//Função da matriz de adjacencia.
adjmatgraph_p createAdjMatGraph(int n, graph_type_e type){

  adjmatgraph_p graph = (adjmatgraph_p)malloc(sizeof(adjmatgraph_t));
  if(!graph){
      printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
  }

  graph->num_vertices = n;
  graph->type = type;

  graph->adj_matrix = (int **) malloc (sizeof(int **)*graph->num_vertices);

  //Alocando memoria para matriz da adjacencia.
  if(!graph->adj_matrix) {
      printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
  }
  int r, c;
  for (r = 0; r < graph->num_vertices; r++) {
    graph->adj_matrix[r] = (int *) malloc(sizeof(int)*graph->num_vertices);
    if(!graph->adj_matrix[r]) {
      printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
    }
  }

  for (r = 0; r < graph->num_vertices; r++) {
    for (c = 0; c < graph->num_vertices; c++) {
      graph->adj_matrix[r][c] = 0;
    }
  }

  return graph;
}

// Função para alocar e criar o grafo de matriz de incidencia e adiciona a aresta
incmatgraph_p createIncMatGraphAddEdge(int n, graph_type_e type, int ini, int dest){

  incmatgraph_p graph = (incmatgraph_p)malloc(sizeof(incmatgraph_t));

  if(!graph){
      printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
  }

  graph->num_vertices = n;
  graph->type = type;

  graph->degree = (int*)malloc(sizeof(int*)*graph->num_vertices);
  graph->conjEdge = (int*)malloc(sizeof(int*)*2);

  if(!graph->conjEdge) {
    printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
  }

  graph->inc_matrix = (int **)malloc(sizeof(int **)*(graph->num_vertices));

  int r,c;
  for (r = 0; r < graph->num_vertices; r++) {
      graph->inc_matrix[r] = (int *) malloc(sizeof(int)*graph->num_vertices);
      if(!graph->inc_matrix[r]) {
        printf("\n \n Aviso: Falhar na alocacao de memoria \n  \n");
      }
   }


   for (r = 0; r < graph->num_vertices; r++) {
      graph->degree[r] = 0;
      for (c = 0; c < 1; c++) {
              graph->inc_matrix[r][c] = 0;

          }
   }

   graph->degree[ini]++;
   graph->degree[dest]++;

    graph->conjEdge[0] = ini;
    graph->conjEdge[1] = dest;

    graph->inc_matrix[ini][0] = 1;

    if(graph->type == NAO_DIRECIONADO){
      graph->inc_matrix[dest][0] = 1;
    }
  return graph;
}

//Função para realocar a estrutura de incidencia;
incmatgraph_p recreateIncMatGraphAddEdge(incmatgraph_p graph, int s, int ini, int dest){

  graph->conjEdge = realloc(graph->conjEdge, sizeof(int*)*(s*2));

  graph->inc_matrix = realloc( graph->inc_matrix , sizeof(int **)*graph->num_vertices*s );

  int r;
  for (r = 0; r < graph->num_vertices; r++) {//colocar o valor zero nas funções
         graph->inc_matrix[r][s-1] = 0;
  }

    graph->degree[ini]++;
    graph->degree[dest]++;

    graph->conjEdge[s + k] = ini;
    graph->conjEdge[s + (k+1)] = dest;
    k++;

    graph->inc_matrix[ini][s-1] = 1;

  if(graph->type == NAO_DIRECIONADO){
    graph->inc_matrix[dest][s-1] = 1;
  }
  return graph;
}


//// FUNÇÕES DE PREENCHIMENTO PARA LISTA ADJACENCIA, MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA ////
// Adiciona uma aresta a um grafo de lista de adjacencia//
void addEdgeAdjList(adjlistgraph_t *graph, int ini, int dest){

    // Adicionar uma aresta de ini para dest na lista de adjacência//
    adjlist_node_p newNode = createNode(dest);
    newNode->next = graph->adjListArr[ini].head;
    graph->adjListArr[ini].head = newNode;
    graph->adjListArr[ini].num_members++;

    if(graph->type == NAO_DIRECIONADO)
    {
        newNode = createNode(ini);
        newNode->next = graph->adjListArr[dest].head;
        graph->adjListArr[dest].head = newNode;
        graph->adjListArr[dest].num_members++;
    }
}

// Adiciona uma aresta a um grafo de matriz de adjacencia//
void addEdgeAdjMat(adjmatgraph_t *graph, int ini, int dest){
  // Adicionar uma aresta de ini para dest na matriz de adjacência//
  graph->adj_matrix[ini][dest] = 1;
  if (graph->type == NAO_DIRECIONADO) {
    graph->adj_matrix[dest][ini] = 1;
  }
}

//// FUNÇÕES DE IMPRIMIR PARA LISTA ADJACENCIA, MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA ////

//Função para imprimir a lista de adjacência do grafo//
void displayGraphAdjList(adjlistgraph_p graph){
    int i, e=0;
    for (i = 0; i < graph->num_vertices; i++)
    {
        adjlist_node_p adjListPtr = graph->adjListArr[i].head;
        printf("\n%d: ", i);
        while (adjListPtr)
        {
            e++;
            printf("%d->", adjListPtr->vertex);
            adjListPtr = adjListPtr->next;
        }
        printf("NULL\n");
    }
    graph->num_edges = e/2;
}

//Imprimi a matriz de adjacencia do grafo
void displayMatrixGraph(adjmatgraph_p graph){
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

//Imprimi a matriz de incidencia do grafo
void displayIncMatGraph(incmatgraph_p graph){
  printf("\n\n- - - - Matriz de Incidencia - - - -\n \n");
 	   printf("   ");
     int r, c,x =0 , y=0;
 	   for (c = 0; c < graph->sizeEdge ; c++) {

 	     printf("%.1d/%.1d ", graph->conjEdge[(c*2)], graph->conjEdge[((2*c)+1)]);
    }

    printf("\n");
    for (c = 0; c < graph->sizeEdge; c++) {
        printf("-----");
      }

    printf("\n");
    for (r = 0; r < graph->num_vertices; r++) {
      printf("%.1d| ", r);
      for (c = 0; c <  graph->sizeEdge; c++) {
          printf("%.1d   ", graph->inc_matrix[r][c]);
      }
      printf("\n");
    }

}

//// FUNÇÕES DE LIBERA MEMORIA DAS LISTA ADJACENCIA, MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA ////

//Destrói o Grafo//
void destroyGraphAdjList(adjlistgraph_p graph){
    if(graph){
        if(graph->adjListArr){
            int v;
            //Limpa da memoria o nó
            for (v = 0; v < graph->num_vertices; v++){
                adjlist_node_p adjListPtr = graph->adjListArr[v].head;
                while (adjListPtr){
                    adjlist_node_p tmp = adjListPtr;
                    adjListPtr = adjListPtr->next;
                    free(tmp);
                }
            }
            //Limpa da memoria a de lista de adjacência
            free(graph->adjListArr);
        }
        //Limpa da memoria o grafo
        free(graph);
    }
}
//Destrói o Grafo de matriz de adjacencia//
void destroyGraphAdjMat(adjmatgraph_p graph){
  int i;
  for (i = 0; i < graph->num_vertices; i++) {
      int* currentIntPtr = graph->adj_matrix[i];
      free(currentIntPtr);
  }
  free(graph);
}

//Destrói o Grafo de Matriz de incidencia//
void destroyGraphIncMat(incmatgraph_p graph){
  int i;
  for (i = 0; i < graph->num_vertices; i++) {
      int* currentIntPtr = graph->inc_matrix[i];
      free(currentIntPtr);
  }
  free(graph);

}
