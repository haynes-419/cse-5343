int s4()
{
  int _t6;
  int a[10][20];
  int _t5;
  int _t8;
  int _t7;
  int x;
  int y;
  int z;
  int _t2;
  int _t1;
  int _t4;
  int _t3;
x=1;
y=2;
z=0;
_t4=2*y;
_t5=z+_t4;
_t1=y-x;
_t2=y+x;
a[_t1][_t2]=_t5;
x=5;
_l1:
_t6=x<10;
if (! _t6) goto _l2;
_t7=z-1;
z=_t7;
_t8=x+1;
x=_t8;
goto _l1;
_l2:
return z;
}
