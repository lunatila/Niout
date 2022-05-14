#include <iostream>
#include "Player.h"
#include "Graph.h"
#include "Board.h"
#include "Horse.h"
#include <gl/freeglut.h>

using namespace std;

Board board1;
Player player1, player2, AI;
Horse horsesPlayer1[4], horsesPlayer2[4], horsesAI[4];

float xClick, yClick;
float xStartDrag, yStartDrag, xEndDrag, yEndDrag;
int weight;

struct Mouse {
    float xClick, yClick;
    float xStartDrag, yStartDrag, xEndDrag, yEndDrag;

    Mouse(float x, float y, float x1, float y1, float x2, float y2) {
        xClick = x;
        yClick = y;
        xStartDrag = x1;
        yStartDrag = y1;
        xEndDrag = x2;
        yEndDrag = y2;
    }

    Circle spot(float x, float y)
    {
        for (int i = 0; i <= 28; i++) {
            float x2 = (x - board1.spot[i].xCenter) * (x - board1.spot[i].xCenter);
            float y2 = (y - board1.spot[i].yCenter) * (y - board1.spot[i].yCenter);
            if (x2 + y2 < board1.spot[i].radius * board1.spot[i].radius)
                return board1.spot[i];
        }
    }
    Horse horse() {

    }
};

void scalexy(int x, int y) {
    xClick = (float)x / 300 - 1;
    yClick = -(float)y / 300 + 1;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    board1.drawBoard();
    board1.drawHorse(player1, horsesPlayer1[1]);

    glutSwapBuffers();
}

void MouseClick(int button, int state, int x, int y)
{
    scalexy(x, y);
    //Mouse mouse(newx, newy, newx, newy, newx, newy);
    Mouse mouse(xClick, yClick, xClick, yClick, xClick, yClick);

    int casa = 0;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {

            for (Circle x : board1.spot) {
                if(mouse.spot(xClick,yClick) == x)
                    x.showCircle();
            }
            
            //mouse.spot(newx, newy).showCircle();
            ////xStartDrag = xClick;
            ////yStartDrag = yClick;
            //xEndDrag = xStartDrag;
            //yEndDrag = yStartDrag;

            //cout << "casa " << casa << ": ";
            ////nioutBoard.showAdjacency(atualSpot, 1);

            //float x = horsesPlayer1[1].initialPosition.xCenter;
            //float y = horsesPlayer1[1].initialPosition.yCenter;
            //float r = horsesPlayer1[1].initialPosition.radius;

            ////float x2 = (xClick - x) * (xClick - x);
            ////float y2 = (yClick - y) * (yClick - y);
            //float x2 = (xStartDrag - x) * (xStartDrag - x);
            //float y2 = (yStartDrag - y) * (yStartDrag - y);

            //if (x2 + y2 < r * r) {
            //    cout << "pocoto" << endl;
            //}
            //cout << horsesPlayer1[1].atualSpot << endl;
            ////casa = nioutBoard.showAdjacency(casa, 2, 1);
            ////cout << casa << endl;
        }
        if (state == GLUT_UP) {
            ////adjNode* newNode = nioutBoard.getAdjacencyListNode(horsesPlayer1[1].initialPosition.index, 1, nioutBoard.head[atualSpot]);

            //cout << "inicio" << casa << endl;

            //if (xEndDrag != xStartDrag && yEndDrag != yStartDrag) {

            //    for (int i = 0; i <= 28; i++) {
            //        float x2 = (xEndDrag - board1.spot[i].xCenter) * (xEndDrag - board1.spot[i].xCenter);
            //        float y2 = (yEndDrag - board1.spot[i].yCenter) * (yEndDrag - board1.spot[i].yCenter);
            //        if (x2 + y2 < board1.spot[i].radius * board1.spot[i].radius) {
            //            horsesPlayer1[1].finalSpot = i;
            //            casa = horsesPlayer1[1].finalSpot;
            //            break;
            //        }
            //    }

            //    /*float xh = horsesPlayer1[1].initialPosition.xCenter;
            //    float yh = horsesPlayer1[1].initialPosition.yCenter;
            //    float rh = horsesPlayer1[1].initialPosition.radius;

            //    float x2 = (xEndDrag - x) * (xEndDrag - x);
            //    float y2 = (yEndDrag - y) * (yEndDrag - y);*/

            //    if (board1.nioutBoard.canMove(horsesPlayer1[1].atualSpot, horsesPlayer1[1].finalSpot, 1) == true) {

            //        //Circle newHorse(xEndDrag, yEndDrag, 0.05);

            //        horsesPlayer1[1].initialPosition = board1.spot[horsesPlayer1[1].finalSpot];

            //        board1.drawHorse(player1, horsesPlayer1[1]);

            //        glutPostRedisplay();

            //        cout << "fim" << casa << endl;
            //    }
            //    else
            //        cout << "movimento invalido!" << endl;


            //}
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {

        }
    }
}

void MouseDrag(int x, int y)
{
    /*
    xEndDrag = (float)x / 300 - 1;
    yEndDrag = -(float)y / 300 + 1;

    float xh = horsesPlayer1[1].initialPosition.xCenter;
    float yh = horsesPlayer1[1].initialPosition.yCenter;
    float rh = horsesPlayer1[1].initialPosition.radius;

    float x2 = (xEndDrag - xh) * (xEndDrag - xh);
    float y2 = (yEndDrag - yh) * (yEndDrag - yh);*/

    /*if (x2 + y2 < rh * rh) {
        for (int i = 0; i <= 28; i++) {
            float xx = (xEndDrag - board1.spot[i].xCenter) * (xEndDrag - board1.spot[i].xCenter);
            float yy = (yEndDrag - board1.spot[i].yCenter) * (yEndDrag - board1.spot[i].yCenter);
            if (xx + yy < board1.spot[i].radius * board1.spot[i].radius) {
                horsesPlayer1[1].finalSpot = board1.spot[i].index;
            }
        }
        cout << horsesPlayer1[1].finalSpot;
    }*/


}

int main(int argc, char** argv)
{
    player1.playerColor = 1;
    player2.playerColor = 0;
    AI.playerColor = 0;

    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutInitWindowSize(600, 600);

    glutCreateWindow("Niout");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1);
    //glutKeyboardFunc(input.Keyboard);
    glutMouseFunc(MouseClick);
    glutMotionFunc(MouseDrag);

    glutMainLoop();

}

