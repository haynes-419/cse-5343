int f()
{
    int x;
    int _t2;
    int _t1;
_l1:
    _t1 = 1 < 2;
    if (!_t1)
        goto _l2;
_l3:
    _t2 = 2 < 3;
    if (!_t2)
        goto _l4;
    x = 8;
    goto _l3;
_l4:
    goto _l1;
_l2:
    return x;
}