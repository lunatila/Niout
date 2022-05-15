#pragma once
#include "Circle.h"
#include "Horse.h"
#include "Board.h"

struct Mouse {
    float xClick, yClick;
    float xStartDrag, yStartDrag, xEndDrag, yEndDrag;
    Board niout;

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
        Circle hand(-1, 1, 0);

        for (int i = 0; i <= 28; i++) {
            float x2 = (x - niout.spot[i].xCenter) * (x - niout.spot[i].xCenter);
            float y2 = (y - niout.spot[i].yCenter) * (y - niout.spot[i].yCenter);
            if (x2 + y2 < niout.spot[i].radius * niout.spot[i].radius) {
                return niout.spot[i];
                break;
            }
        }
            return hand;
    }
    Circle horse(float x, float y) 
    {
        Circle hand(-1, 1, 0);

        for (int i = 0; i <= 28; i++) {
            float x2 = (x - niout.spot[i].xCenter) * (x - niout.spot[i].xCenter);
            float y2 = (y - niout.spot[i].yCenter) * (y - niout.spot[i].yCenter);
            if (x2 + y2 < 0.05 * 0.05) {
                return niout.spot[i];
                break;
            }
        }
        return hand;
    }
};

