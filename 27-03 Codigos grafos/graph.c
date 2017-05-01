/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


/* - - -  VARIAVEIS GLOBAIS  - - - */

//Criar o vetor de visitado.
int visitedAdjList[20], visitedAdjMat[20], visitedIncMat[20], k=0 ;

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

/* - - - FUNÇÕES DE BUSCA EM PROFUNDIDADE DAS LISTA ADJACENCIA,
          MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA - - - */

//Busca em profundidade para lista de adjacencia
void DFSAdjList(adjlistgraph_p graph, int i, int teamCC);

//Busca em profundidade para matriz de adjacencia
void DFSAdjMat(adjmatgraph_p graph, int i, int teamCC);

//Busca em profundidade para matriz de incidencia
void DFSIncMat(incmatgraph_p graph, int i, int teamCC);

/* - - - FUNÇÕES PARA VERIFICAR AS CONEXOES DO GRAFO - - - */

//Checando a conexão dos vertices: Para Lista de Adjacencia, Matriz de Adjacencia, Matriz de incidencia//
int checkConnectionGraphAdjList(adjlistgraph_p graph);

int checkConnectionGraphAdjMat(adjmatgraph_p graph);

int checkConnectionGraphIncMat(incmatgraph_p graph);


// Conta e encontra todas as componentes conexas de um grafo: Para Lista de Adjacencia, Matriz Adjacencia, Matriz incidencia.
struct cc{//Salva os numeros de conexões e qual grupo pertence
    int num_con;
    int team_vertex[20]; //Vetor com numero de vertices
}cc_t;

void connectedComponentsGraphAdjList(adjlistgraph_p graph);

void connectedComponentsGraphAdjMat(adjmatgraph_p graph);

void connectedComponentsGraphIncMat(incmatgraph_p graph);



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

      printf("\n \n- - - Busca em profundidade - - -\n \n");


      while(1){
        printf("\nQual vertices deseja inicia a busca ?\n--> ");
        scanf("%d", &vet);
        if (vet > - 1 && vet < n) {

          int i; //Zera o vetor
          for(i=0;i<n;i++){
            visitedAdjList[i]=0;
          }

          DFSAdjList(undir_graph, vet, 0);
          break;
        }else{
          printf("\n\nAletar: Numero invalido. \n\n");
        }
      }
      printf("\n \n- - - Checar as conexoes - - -\n \n");



      if (checkConnectionGraphAdjList(undir_graph)){
        printf("Grafo e conexo");
      }else {
        printf(" Grafo nao e conexo\n \n");
      }

        printf("\n \n- - - Numero de conexoes - - -\n \n");

        int i; //Zera o vetor
        for(i=0;i<n;i++){
          visitedAdjList[i]=0;
        }

        connectedComponentsGraphAdjList(undir_graph);

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

        printf("\n \n- - - Busca em profundidade - - -\n \n");
        int i;
        for(i=0;i<n;i++){
          visitedAdjMat[i]=0;}
        while(1){
          printf("\nQual vertices deseja inicia a busca ?\n--> ");
          scanf("%d", &vet);
          if (vet > - 1 && vet < n) {

            int i; //Zera o vetor
            for(i=0;i<n;i++){
              visitedAdjMat[i]=0;
            }

            DFSAdjMat(undir_graph, vet, 0);
            break;
          }else{
            printf("\n\nAletar: Numero invalido. \n\n");
          }
        }

        if (checkConnectionGraphAdjMat( undir_graph )){
          printf("\n\nGrafo e conexo \n \n");
        }else {printf("\n\nGrafo nao e conexo \n \n");}


        for(i=0;i<n;i++){
          visitedAdjMat[i]=0;
        }

        connectedComponentsGraphAdjMat(undir_graph);

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

        printf("\n \n- - - Busca em profundidade - - -\n \n");


        while(1){
          printf("\nQual vertices deseja inicia a busca ?\n--> ");
          scanf("%d", &vet);
          if (vet > - 1 && vet < n) {

            int i;
            for(i=0;i<n;i++){//Zera o vetor de visitado
              visitedIncMat[i]=0;
            }

            DFSIncMat(undir_graph, vet, 0);
            break;
          }else{
            printf("\n\nAletar: Numero invalido. \n\n");
          }
        }

        if (checkConnectionGraphIncMat( undir_graph )){
          printf("\n\nGrafo e conexo \n");
        }else {printf("\n\nGrafo nao e conexo \n");}

        int i;
        for(i=0;i<n;i++){//Zera o vetor de visitado
          visitedIncMat[i]=0;
        }

        connectedComponentsGraphIncMat(undir_graph);

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
      //GOTO: BUSCA EM PROFUNDIDADE
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
/* - - -  FUNÇÕES ADICIONAIS PARA LISTA ADJACENCIA,
          MATRIZ DE ADJACENCIA E MATRIZ DE INCIDENCIA  - - - */

//Função para imprimir a lista de adjacência do grafo//
void DFSAdjList(adjlistgraph_p graph, int i, int teamCC){
  adjlist_node_p adjListPtr = graph->adjListArr[i].head;
  printf("\nVertice visitado : %d \n",i);
  cc_t.team_vertex[i] = teamCC;
  visitedAdjList[i]=1;
  while (adjListPtr!=NULL){
    i = adjListPtr->vertex;
    if(!visitedAdjList[i]){
      DFSAdjList(graph, i, teamCC);
      }
      adjListPtr = adjListPtr->next;
    }
}

//Busca em profundidade para matriz de adjacencia
void DFSAdjMat(adjmatgraph_p graph, int i, int teamCC){
  int j;
  printf("\nVertice visitado : %d \n",i);
  cc_t.team_vertex[i] = teamCC;
  visitedAdjMat[i]=1;

  for(j=0;j<graph->num_vertices;j++){
     if(!visitedAdjMat[j] && graph->adj_matrix[i][j]==1){
          DFSAdjMat(graph,j, teamCC);
        }
  }
}

void DFSIncMat(incmatgraph_p graph, int i, int teamCC){
  int j,y,y1;
  printf("\nVertice visitado : %d \n",i);
  visitedIncMat[i]=1;
  cc_t.team_vertex[i] = teamCC;
  for (j = 0; j <  graph->sizeEdge; j++) {

    y = graph->conjEdge[((2*j)+1)]; // N° Impar
    y1 = graph->conjEdge[((2*j))]; // N° par

    if (!visitedIncMat[y]  && graph->inc_matrix[i][j] == 1) {
      DFSIncMat(graph, y, teamCC);
    }

    if (!visitedIncMat[y1]  && graph->inc_matrix[i][j] == 1) {
        DFSIncMat(graph, y1, teamCC);
    }
  }

}

/* - - - FUNÇÕES PARA VERIFICAR AS CONEXOES DO GRAFO - - - */

//Checando a conexão dos vertices//
int checkConnectionGraphAdjList(adjlistgraph_p graph){
  int i, bool;
  for (i = 0; i < graph->num_vertices; i++){
    if (visitedAdjList[i] == 1){
      bool = 1;
    }else {
      bool = 0;
    }
  }
  return bool;
}

//Checando a conexão dos vertices//
int checkConnectionGraphAdjMat(adjmatgraph_p graph){
  int i, bool;
  for (i = 0; i < graph->num_vertices; i++){
    if (visitedAdjMat[i] == 1){
      bool = 1;
    }else {
      bool = 0;
    }
  }
  return bool;
}

//Checando a conexão dos vertices para matriz de incidencia//
int checkConnectionGraphIncMat(incmatgraph_p graph){
  int i, bool;
  for (i = 0; i < graph->num_vertices; i++){
    if (visitedIncMat[i] == 1){
      bool = 1;
    }else {
      bool = 0;
    }
  }
  return bool;
}

//TODO: IMPLEMENTAND SEGUNDA da LISTA
// Conta e encontra todas as componentes conexas de um grafo
void connectedComponentsGraphAdjList(adjlistgraph_p graph){
  int totalComponents=0;
  for( int i = 0 ; i < graph->num_vertices ; ++i ){ //interação com todos os vertices
    if(!visitedAdjList[i]){ // Se qualquer nó não foi visitado DFS chamar
      printf("\n  Grupo ( %d ) de conexao do grafo: \n \n" , totalComponents);
      DFSAdjList(graph, i, totalComponents);
      totalComponents++; //incremento de número de componentes
    }

    }

    cc_t.num_con = totalComponents; //Salva o valor em um struct

    printf("\nO numero de componentes conexas do grafo: %d\n \n" , cc_t.num_con);

    for( int i = 0 ; i < graph->num_vertices ; i++ ){
        printf("Vertice: %d - Grupo: %d\n", i, cc_t.team_vertex[i]);
      }
}

void connectedComponentsGraphAdjMat(adjmatgraph_p graph){
  int totalComponents=0;

  for( int i = 0 ; i < graph->num_vertices ; ++i ){ //interação com todos os vertices
    if(!visitedAdjMat[i]){ // Se qualquer nó não foi visitado DFS chamar
      printf("\n  Grupo ( %d ) de conexao do grafo: \n \n" , totalComponents);
      DFSAdjMat(graph, i, totalComponents);
      totalComponents++; //incremento de número de componentes
    }

    }

    cc_t.num_con = totalComponents; //Salva o valor em um struct

    printf("\nO numero de componentes conexas do grafo: %d\n \n" , cc_t.num_con);

    //for( int i = 0 ; i < graph->num_vertices ; i++ ){
    //    printf("Vertice: %d - Grupo: %d\n", i, cc_t.team_vertex[i]);
    //  }
}

void connectedComponentsGraphIncMat(incmatgraph_p graph){
  int totalComponents=0;

  for( int i = 0 ; i < graph->num_vertices ; ++i ){ //interação com todos os vertices
    if(!visitedIncMat[i]){ // Se qualquer nó não foi visitado DFS chamar
      printf("\n  Grupo ( %d ) de conexao do grafo: \n \n" , totalComponents);
      DFSIncMat(graph, i, totalComponents);
      totalComponents++; //incremento de número de componentes
    }
  }

    cc_t.num_con = totalComponents; //Salva o valor em um struct

    printf("\nO numero de componentes conexas do grafo: %d\n \n" , cc_t.num_con);

    //for( int i = 0 ; i < graph->num_vertices ; i++ ){
    //    printf("Vertice: %d - Grupo: %d\n", i, cc_t.team_vertex[i]);
    //  }
}
