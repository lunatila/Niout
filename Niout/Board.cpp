#include "Board.h"

Board::Board()
{
    for (int i = 0; i <= 19; i++) {
        float angle = 2 * pi * i / 20;
        if (i % 5 == 0) {
            Circle circle(boardRadius * cos(angle), boardRadius * sin(angle), bigRadius);
            circle.index = (i + 14) % 20 + 1;
            spot[i] = circle;
        }
        else {
            Circle circle(boardRadius * cos(angle), boardRadius * sin(angle), smallRadius);
            circle.index = (i + 14) % 20 + 1;
            spot[i] = circle;
        }
    }

    for (int i = 1; i <= 5; i++) {
        if (i % 3 == 0) {
            Circle circle1(0, -boardRadius + 2 * boardRadius / 6 * i, .1);
            circle1.index = 25;
            spot[24] = circle1;
        }
        else {
            Circle circle1(0, boardRadius - 2 * boardRadius / 6 * i, .08);
            circle1.index = i + 22;
            spot[circle1.index - 1] = circle1;
            if (i < 3) {
                Circle circle2(-boardRadius + 2 * boardRadius / 6 * i, 0, .08);
                circle2.index = i + 20;
                spot[circle2.index - 1] = circle2;
            }
            else {
                Circle circle2(-boardRadius + 2 * boardRadius / 6 * i, 0, .08);
                circle2.index = i + 24;
                spot[circle2.index - 1] = circle2;
            }
        }
    }


}

void Board::drawBoard()
{
    for (int i = 0; i < 29; i++) {
        glColor3f(1, 1, 1);
        if (spot[i].index % 5 == 0)
            glColor3f(1, 0, 0);
        spot[i].drawCircle();
    }
}

void Board::drawHorse(Player player, Horse horse)
{
    float angle = 0;
    float x, y;
    float pi = 3.1415;

    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i <= 50; i++) {
        angle = 2 * pi * i / 50;
        x = horse.initialPosition.radius * cos(angle) + horse.initialPosition.xCenter;
        y = horse.initialPosition.radius * sin(angle) + horse.initialPosition.yCenter;
        glVertex2f(horse.initialPosition.xCenter, horse.initialPosition.yCenter);
        glVertex2f(x, y);
        i++;
        angle = 2 * pi * i / 50;
        x = horse.initialPosition.radius * cos(angle) + horse.initialPosition.xCenter;
        y = horse.initialPosition.radius * sin(angle) + horse.initialPosition.yCenter;
        glVertex2f(x, y);
        i--;
    }
    glEnd();
}

void Board::deleteHorse(Player player, Horse horse)
{

}