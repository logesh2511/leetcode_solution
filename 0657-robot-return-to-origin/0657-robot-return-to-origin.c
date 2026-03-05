#include <stdbool.h>
#include <stdio.h>


bool judgeCircle(char *moves) {
    int horizontal = 0;
    int vertical = 0;  
   
   
    for (int i = 0; moves[i] != '\0'; i++) {
        switch (moves[i]) {
            case 'U':
                vertical++;
                break;
            case 'D':
                vertical--;  
                break;
            case 'L':
                horizontal--;
                break;
            case 'R':
                horizontal++;
                break;
            default:
                break;
        }
    }
   
    return horizontal == 0 && vertical == 0;
}
