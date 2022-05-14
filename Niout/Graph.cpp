#include "Graph.h"

Graph::Graph(graphEdge edges[], int n, int N)
{
    // Aloca o novo Node
    head = new adjNode * [N]();
    this->NumberOfNodes = N;

    // Inicializa o head pointer para todos os v»rtices
    for (int i = 0; i < N; ++i)
        head[i] = nullptr;

    // Constroi um Grafo direcionado adicionando arestas nele
    for (unsigned i = 0; i < n; i++) {
        Circle start_ver = edges[i].startVertice;
        Circle end_ver = edges[i].endVertice;
        int weight = edges[i].weight;

        adjNode* newNode = getAdjacencyListNode(end_ver, weight, head[start_ver.index]);

        // Aponta o head pointer para o novo Node
        head[start_ver.index] = newNode;
    }
}