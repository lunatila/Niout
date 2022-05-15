#include <iostream>
#include "Player.h"
#include "Graph.h"
#include "Board.h"
#include "Horse.h"
#include "Mouse.h"
#include <gl/freeglut.h>

using namespace std;

Board board1;
Player player1, player2, AI;
Horse horsesPlayer1[4], horsesPlayer2[4], horsesAI[4];

float xClick, yClick;
float xStartDrag, yStartDrag, xEndDrag, yEndDrag;
int weight;

Mouse mouse(xClick, yClick, xStartDrag, yStartDrag, xEndDrag, yEndDrag);

void scalexy(int x, int y) {
    xClick = (float)x / 300 - 1;
    yClick = -(float)y / 300 + 1;
    xStartDrag = (float)x / 300 - 1;
    yStartDrag = -(float)y / 300 + 1;
    xEndDrag = (float)x / 300 - 1;
    yEndDrag = -(float)y / 300 + 1;
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
    mouse.xClick = xClick;
    mouse.yClick = yClick;

    int casa = 0;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {

            mouse.xStartDrag = xStartDrag;
            mouse.yStartDrag = yStartDrag;
            mouse.xEndDrag = xEndDrag;
            mouse.yEndDrag = yEndDrag;

            /*for (Circle x : board1.spot) {
                if (mouse.spot(xClick, yClick) == x)
                    x.showCircle();
            }*/
        }
        if (state == GLUT_UP) {

            if (mouse.xStartDrag != mouse.xEndDrag || mouse.yStartDrag != mouse.yEndDrag) {

                for (int i = 0; i <= 28; i++) {
                    float x2 = (xEndDrag - board1.spot[i].xCenter) * (xEndDrag - board1.spot[i].xCenter);
                    float y2 = (yEndDrag - board1.spot[i].yCenter) * (yEndDrag - board1.spot[i].yCenter);
                    if (x2 + y2 < board1.spot[i].radius * board1.spot[i].radius) {
                        horsesPlayer1[1].finalSpot = i;
                        casa = horsesPlayer1[1].finalSpot;
                        break;
                    }
                }
            }
                if (board1.board.canMove(horsesPlayer1[1].atualSpot, horsesPlayer1[1].finalSpot, 1) == true) {

                    horsesPlayer1[1].initialPosition = board1.spot[horsesPlayer1[1].finalSpot];

                    board1.drawHorse(player1, horsesPlayer1[1]);

                    glutPostRedisplay();
                }
                else
                    cout << "movimento invalido!" << endl;
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {

        }
    }
}

void MouseDrag(int x, int y)
{
    mouse.xEndDrag = (float)x / 300 - 1;
    mouse.yEndDrag = -(float)y / 300 + 1;

    for (Circle x : board1.spot) {
        if (mouse.spot(mouse.yEndDrag, mouse.yEndDrag) == x) {
            horsesPlayer1[1].finalPosition = x;
        }
    }
}

int menu(void) {
    cout << "Escolha uma opcao de programa: \n<1> para jogar contra o computador. \n<2> para jogo com 2 jogadores." << endl;
    cout << "opcao: ";
    int in;
    cin >> in;
    return in;
}

int main(int argc, char** argv)
{
    player1.playerColor = 1;
    player2.playerColor = 0;
    AI.playerColor = 0;

    srand(time(NULL));

    cout << "\n          Bem vindo ao Jogo Niout!" << endl << endl;
    int escolha = menu();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutInitWindowSize(600, 600);

    glutCreateWindow("Niout");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1);
    glutMouseFunc(MouseClick);
    glutMotionFunc(MouseDrag);

    glutMainLoop();

}

