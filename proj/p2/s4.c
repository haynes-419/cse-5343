int f() {
    double E;
    double alpha[16];
    int m;

    for (m = 2; m < 16; m=m+1) {
        E = (1.0 - alpha[m-1] * alpha[m-1]) * E;
    }
}