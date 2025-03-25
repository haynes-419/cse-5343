int s4() { 
    int a[10][20]; 
    int x; 
    int y; 
    int z; 
    x = 1; 
    y = 2; 
    z = 0; 
    a[y-x][y+x] = z + 2*y;
    
    for(x = 5; x < 10; x += 1){
        z -= 1;
    }
    
    return z; }