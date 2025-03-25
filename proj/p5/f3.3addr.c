int f3()
{
  int res;
  int _t5;
  int i;
  int _t2;
  int _t1;
  int n;
  int _t4;
  int _t3;
n=10;
i=1;
res=1;
_l1:
_t1=i<=n;
if (! _t1) goto _l2;
_t2=i%2;
_t3=_t2==0;
if (!_t3) goto _l3;
_t4=res*i;
res=_t4;
_l3:
_t5=i+1;
i=_t5;
goto _l1;
_l2:
return res;
;
}
