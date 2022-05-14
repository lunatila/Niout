#include "Circle.h"

void Circle::drawCircle()
{
    // Vari�veis para criar os c�rculos do tabuleiro
    float angle = 0;
    float x, y;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 100; i++) {
        angle = 2 * pi * i / 100;
        x = radius * cos(angle) + xCenter;
        y = radius * sin(angle) + yCenter;
        glVertex2d(x, y);
    }
    glEnd();

    //if ((x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) < radius) {

    //}
}

void Circle::showCircle() {
    cout << index << ": " << xCenter << ", " << yCenter << endl;
}