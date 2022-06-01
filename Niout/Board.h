#pragma once
#include "Player.h"
#include "Graph.h"
#include <cmath>
#include <GL/glut.h>
#include "Circle.h"
#include "GrafoTeste.h"

struct Board
{
    float boardRadius = .8;
    float bigRadius = .1;
    float smallRadius = .08;
    float pi = 3.1415;

    Circle spot[29];
    Circle horse{ 0, 0, 0.05 };

    GrafoTeste board;

    Board();

    void drawBoard();
    void drawHorse(Player player, Horse horse);
    void deleteHorse(Player player, Horse horse);

    int move(int v, int movement, int vaipraonde) {
        int now = v;
        int pos = board.getVerticeByID(v);
        for (int i = 1; i <= movement; i++) {
            if (board.vertices.at(pos).hasNext()) {
                if (vaipraonde == 0) {
                    now = board.vertices.at(pos).edgeList.front().getFinalVertex();
                    pos = board.getVerticeByID(now);
                }
                else {
                    now = board.vertices.at(pos).edgeList.back().getFinalVertex();
                    pos = board.getVerticeByID(now);
                }
            }
            else
                cout << "movimento invalido";
        }
        return now;
    }
};
