
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** data = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        data[i] = (int*)malloc(n * sizeof(int));
    }
    int rowStart = 0;
    int colStart = 0;
    int rowEnd = n - 1;
    int colEnd = n - 1;
    int counter = 1;
    while(rowStart <= rowEnd && colStart <= colEnd){
        for(int i = colStart; i <= colEnd; i++){
            data[rowStart][i] = counter;
            counter = counter + 1;
        }

        rowStart = rowStart + 1;

        for(int i = rowStart; i <= rowEnd; i++){
            data[i][colEnd] = counter;
            counter = counter + 1;
        }
        
        colEnd = colEnd - 1;

        if(rowStart <= rowEnd){
            for(int i = colEnd; i >= colStart; i--){
                data[rowEnd][i] = counter;
                counter = counter + 1;
            }

            rowEnd = rowEnd - 1;
        }

        if(colStart <= colEnd){
            for(int i = rowEnd; i >= rowStart; i--){
                data[i][colStart] = counter;
                counter = counter + 1;
            }

            colStart = colStart + 1;
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return data;
}