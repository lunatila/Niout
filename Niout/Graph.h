#pragma once
#include <iostream>
#include "Circle.h"
using namespace std;

// Guarda Adjacency Lists
struct adjNode {
    Circle spot;
    int weight;
    adjNode* next;
    //adjNode() {}
    //Hashset or UnorderedSet
};

// Estrutura para guardar as arestas
struct graphEdge {
    //Circle startSpot, endSpot;
    Circle startVertice, endVertice;
    int weight; // Peso para poder andar na aresta (será útil para as casas especiais)
};

class Graph {
public:
    // Insere novos Nodes na Adjacency List dado um Grafo
    adjNode* getAdjacencyListNode(Circle spot, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;
        newNode->spot = spot;
        newNode->weight = weight;
        newNode->next = head;   // Aponta o novo Node para a Head atual
        return newNode;
    }
    int NumberOfNodes;

    adjNode** head; // Adjacency list como uma array de ponteiros

    Graph() {}

    Graph(graphEdge edges[], int n, int N);

    ~Graph() {
        for (int i = 0; i < NumberOfNodes; i++)
            delete[] head[i];
        delete[] head;
    }

    Circle showAdjacency(int i, Circle aqui, int weight)
    {
        cout << "caminhos possiveis -> ";
        adjNode* aux = head[i];

        while (aux != nullptr) {
            if (weight < aux->weight) {
                aux = aux->next;
            }
            else {
                //cout << "casa " << aux->spot;
                if (aux->spot.index == aqui.index) {
                    return aux->spot;
                }
                aux = aux->next;
                if (aux != nullptr)
                    if (weight >= aux->weight) {
                        cout << ", ";
                    }
            }
        }
        cout << endl;
        return head[i]->spot;
    }

    bool canMove(int i, int f, int weight)
    {
        bool can = false;
        adjNode* aux;
        if (head[i] != nullptr) {
            aux = head[i];
            if (weight >= aux->weight) {
                can = true;
            }
            return can;
        }
        else
            return can;
    }

};
