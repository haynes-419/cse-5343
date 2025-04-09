int s3()
{
  int res;
  int i;
  int _t2;
  int _t1;
  int n;
  int _t3;
n=10;
i=1;
res=1;
_l1:
_t1=i<=n;
if (! _t1) goto _l2;
_t2=res*i;
res=_t2;
_t3=i+1;
i=_t3;
goto _l1;
_l2:
return i;
}
