int f() {
    int x;
    int y;
    int z;

    x = 3;
    y = 5;

    for(x; x < y; x += y) {
        z = z + 1;
    }

    for(x; x <= y; x -= y) {
        z = z + 1;
    }

    for(x; x > y; x *= y) {
        z = z + 1;
    }

    for(x; x >= y; x /= y) {
        z = z + 1;
    }

    while(x == y) {
        x = x + 1;
    }

    while(x != y) {
        x = x + 1;
    }


    for(x; x < y; x += y)
    z = z + 1;

    for(x; x <= y; x -= y)
    z = z + 1;

    for(x; x > y; x *= y) 
    z = z + 1;

    for(x; x >= y; x /= y)
    z = z + 1;

    while(x == y)
    x = x + 1;
    
    while(x != y)
    x = x + 1;
}