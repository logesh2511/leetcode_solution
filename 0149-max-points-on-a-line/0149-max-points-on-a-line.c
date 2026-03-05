#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int maxPoints(struct Point** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) return pointsSize;
    int max = 0;

    for (int i = 0; i < pointsSize; i++) {
        int samePoint = 1;
        int localMax = 0;
        int vertical = 0;

        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j]->x - points[i]->x;
            int dy = points[j]->y - points[i]->y;

            if (dx == 0 && dy == 0) {
                samePoint++;
            } else if (dx == 0) {
                vertical++;
            } else {
                int count = 0;
                for (int k = 0; k < pointsSize; k++) {
                    if ((points[k]->x - points[i]->x) * dy == (points[k]->y - points[i]->y) * dx) {
                        count++;
                    }
                }
                if (count > localMax) localMax = count;
            }
        }

        if (vertical + samePoint > localMax) localMax = vertical + samePoint;
        if (localMax > max) max = localMax;
    }

    return max;
}
