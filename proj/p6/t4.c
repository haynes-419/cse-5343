int f()
{
    int x;
    int _t2;
    int _t1;
_l1:
_l21:
_l31:
    _t1 = x < 10;
    if (!_t1)
        goto _l2;
    _t2 = x + 1;
    x = _t2;
    goto _l1;
_l2:
_l22:
_l32:
_l42:
    return x;
}