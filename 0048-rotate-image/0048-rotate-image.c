

void rotate(int** a, int n, int* cn){
    int x=0,i,t,y;n=n-1;
    while(x<n){
        y=n;
        for(i=x;i<n;i++){
            t=a[x][i];
            a[x][i]=a[y][x];
            a[y][x]=a[n][y];
            a[n][y--]=a[i][n];
            a[i][n]=t;
        }
        n--;
        x++;
    }
}