#include <iostream>
#include "Player.h"
#include "Graph.h"
#include "Board.h"
#include "Horse.h"
#include "Mouse.h"
#include "GrafoTeste.h"
#include <gl/freeglut.h>

using namespace std;

Board board1;
Player player1, player2, AI;
//Horse horsesPlayer1[4], horsesPlayer2[4], horsesAI[4];

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
    player2.horse.setColor(1);
    board1.drawHorse(player1, player1.horse);
    board1.drawHorse(player2, player2.horse);

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

            int vaipraonde = 0;

            if (player1.playAgain == false) {
                cout << "Esta na vez do Player 2!" << endl;
            }
            else {
                player1.playAgain = false;

                player1.tossCoins();

                player2.playAgain = !player1.playAgain;

                if (player1.horse.atualSpot % 5 == 0 && player1.horse.atualSpot != 25) {
                    cout << "Quer continuar no circulo [0] ou ir para a cruz interna [1]?";
                    cin >> vaipraonde;
                }

                for (int i = 0; i < 29; i++) {
                    if (board1.spot[i].index == board1.move(player1.horse.atualSpot, player1.movement, vaipraonde)) {
                        player1.horse.initialPosition = board1.spot[i];
                        break;
                    }
                }

                cout << "Player 1 andou " << player1.movement << " casas" << endl;

                board1.drawHorse(player1, player1.horse);

                player1.horse.atualSpot = player1.horse.initialPosition.index;
            }

            if (player2.horse.atualSpot == player1.horse.atualSpot) {
                player2.horse.initialPosition = board1.spot[6];
                board1.drawHorse(player2, player2.horse);
                player2.horse.atualSpot = player2.horse.initialPosition.index;
                cout << "Player 1 capturou a peça do Player 2!" << endl;
            }

            if (player1.horse.atualSpot == 20)
                cout << "Player 1 é o vencedor!";


            /*if (board1.board.vertices.at(player1.horse.initialPosition.index - 1).hasNext()) {
                player1.horse.initialPosition = board1.spot[player1.horse.finalSpot];
                board1.drawHorse(player1, player1.horse);
                player1.horse.atualSpot = player1.horse.finalSpot;
            }*/

            /*mouse.xStartDrag = xStartDrag;
            mouse.yStartDrag = yStartDrag;
            mouse.xEndDrag = xEndDrag;
            mouse.yEndDrag = yEndDrag;

            for (Circle x : board1.spot) {
                if (mouse.spot(mouse.xStartDrag, mouse.yStartDrag) == x) {
                    player1.horse.atualSpot = x.index;
                }
            }*/
        }
        if (state == GLUT_UP) {

            /*if (mouse.xStartDrag != mouse.xEndDrag || mouse.yStartDrag != mouse.yEndDrag) {

                for (int i = 0; i <= 28; i++) {
                    float x2 = (xEndDrag - board1.spot[i].xCenter) * (xEndDrag - board1.spot[i].xCenter);
                    float y2 = (yEndDrag - board1.spot[i].yCenter) * (yEndDrag - board1.spot[i].yCenter);
                    if (x2 + y2 < board1.spot[i].radius * board1.spot[i].radius) {
                        player1.horse.finalSpot = i;
                        casa = player1.horse.finalSpot;
                        break;
                    }
                }
            }
            if (board1.board.vertices.at(player1.horse.atualSpot - 1).hasNext()) {
                cout << player1.horse.atualSpot << endl;
                player1.horse.initialPosition = board1.spot[player1.horse.finalSpot];
                board1.drawHorse(player1, player1.horse);
            }
            else
                cout << "movimento invalido!" << endl;*/
            
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            int vaipraonde = 0;

            if (player2.playAgain == false) {
                cout << "Esta na vez do Player 1!" << endl;
            }
            else {
                player2.playAgain = false;

                player2.tossCoins();

                player1.playAgain = !player2.playAgain;

                if (player2.horse.atualSpot % 5 == 0 && player1.horse.atualSpot != 25) {
                    cout << "Quer continuar no circulo [0] ou ir para a cruz interna [1]?";
                    cin >> vaipraonde;
                }

                for (int i = 0; i < 29; i++) {
                    if (board1.spot[i].index == board1.move(player2.horse.atualSpot, player2.movement, vaipraonde)) {
                        player2.horse.initialPosition = board1.spot[i];
                        break ;
                    }
                }

                cout << "Player 2 andou " << player2.movement << " casas" << endl;

                board1.drawHorse(player2, player2.horse);

                player2.horse.atualSpot = player2.horse.initialPosition.index;
            }

            if (player2.horse.atualSpot == player1.horse.atualSpot) {
                player1.horse.initialPosition = board1.spot[6];
                board1.drawHorse(player1, player1.horse);
                player1.horse.atualSpot = player1.horse.initialPosition.index;
                cout << "Player 2 capturou a peça do Player 1!" << endl;
            }
                

            if (player2.horse.atualSpot == 20)
                cout << "Player 2 é o vencedor!" << endl;
        }
    }
    glutPostRedisplay();
}

void MouseDrag(int x, int y)
{
    /*mouse.xEndDrag = (float)x / 300 - 1;
    mouse.yEndDrag = -(float)y / 300 + 1;

    for (Circle x : board1.spot) {
        if (mouse.spot(mouse.yEndDrag, mouse.yEndDrag) == x) {
            player1.horse.finalPosition = x;
        }
    }*/
}

int menu() {
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
    Board g;

    srand(time(NULL));

    //g.alo.move(5, 5);
    //g.board.printGraph();

    /*cout << "\n          Bem vindo ao Jogo Niout!" << endl << endl;
    int escolha = menu();*/

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

