#pragma once
#include "Player.h"
#include "Graph.h"
#include <cmath>
#include <GL/glut.h>
#include "Circle.h"

struct Board
{
    float boardRadius = .8;
    float bigRadius = .1;
    float smallRadius = .08;
    float pi = 3.1415;

    Circle spot[29];
    Circle horse{ 0, 0, 0.05 };
    graphEdge edges[31] = {
        // (x, y, p) -> Vértice x para  o vértice y com peso p
        // As quatro primeiras linhas denotam a circunferência externa
        {spot[0],spot[1],1},{spot[1],spot[2],1},{spot[2],spot[3],1},
        {spot[3],spot[4],1},{spot[4],spot[5],1},{spot[5],spot[6],1},
        {spot[6],spot[7],1},{spot[7],spot[8],1},{spot[8],spot[9],1,},
        {spot[9],spot[10],1},{spot[10],spot[11],1},{spot[11],spot[12],1},
        {spot[12],spot[13],1},{spot[13],spot[14],1},{spot[14],spot[15],1},
        {spot[15],spot[16],1},{spot[16],spot[17],1},{spot[17],spot[18],1},
        {spot[18],spot[19],1},
        // Adicionamos os pesos das casas esternas especiais
        {spot[4],spot[20],2},{spot[9],spot[26],2},{spot[14],spot[28],2},
        // E a cruz interna com o peso da casa central
        {spot[20],spot[21],1},{spot[21],spot[24],1},
        {spot[23],spot[22],1},{spot[22],spot[19],1},
        {spot[26],spot[25],1},{spot[25],spot[24],1},
        {spot[28],spot[27],1},{spot[27],spot[24],1},
        {spot[24],spot[23],1}
    };
    int numberOfSpaces = 31;
    int numberOfEdges = sizeof(edges) / sizeof(edges[0]);

    Graph board{ edges, numberOfEdges, numberOfSpaces };

    Board();

    void drawBoard();
    void drawHorse(Player player, Horse horse);
    void deleteHorse(Player player, Horse horse);
};
