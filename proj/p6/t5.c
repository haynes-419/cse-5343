int f()
{
    int x;
    int _t2;
    int _t1;
    _t1 = x < 10;
    if (!_t1)
        goto _l1;
    x = 1;
    goto _l2;
_l1:
    x = 2;
_l2:
    return x;
}