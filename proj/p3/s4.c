int f() { 
    int a;
    double b;
    int c[5];
    double d[5];

    a = 5 % 10;
    b = a;
    c[1] = 4;
    d[2] = c[1];
    d[3] = b;

    a = 1 + 1;
    a = 2 * 3;
    b = 4 / 2;
    a = 2 - 1;
    a += 1; 
    a -= 1; 
    a /= 1; 
    a *= 1;
    a %= 1;  
    
    return a; 
}