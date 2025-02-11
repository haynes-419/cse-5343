double f() {
    int x;
    int y;
    int a[5][5][5];
    int c[5][5][5];
    double b[5][5][5];
    double z;
    

    x = 1;
    y = 2;
    z = 1.2;
    a[1][1 + 1][x] = 1;
    b[1][1][1] = 1.2;


    x = a[1][1][1];
    z = b[1][1][1];

    b[1][1][1] = x + z;

    return b[1][1][1];
}