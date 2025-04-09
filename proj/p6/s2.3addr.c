int s2()
{
  int x;
  int y;
  int z;
  int _t2;
  int _t1;
  int _t4;
  int _t3;
x=1;
y=2;
z=3;
_t1=x+y;
_t2=_t1>z;
if (!_t2) goto _l2;
_t3=x+y;
z=_t3;
goto _l1;
_l2:
_t4=x-y;
z=_t4;
_l1:
return z;
}
