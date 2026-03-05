bool isRobotBounded(const char* instructions) {
    int x = 0;
    int y = 0;
    int d = 0;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int len = strlen(instructions);
    for (int i = 0; i < len; ++i) {
        char instruction = instructions[i];
        if (instruction == 'G') {
            x += directions[d][0];
            y += directions[d][1];
        } else if (instruction == 'L') {
            d = (d + 3) % 4;
        } else {
            d = (d + 1) % 4;
        }
    }
    return (x == 0 && y == 0) || d > 0;
}
