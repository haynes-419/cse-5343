double lpc()
{
  double autocorr[16];
  double E;
  double sum;
  double temp2;
  double temp3;
  double temp1;
  double coeff[4];
  double temp_gain;
  int i;
  int m;
  int n;
  int r;
  double temp4;
  double temp5;
  double temp_filt[320];
  double _t230;
  int _t110;
  double _t231;
  double _t111;
  double _t232;
  int _t112;
  int _t233;
  double _t113;
  double _t234;
  int _t114;
  int _t235;
  double _t104;
  int _t225;
  int _t105;
  int _t226;
  double _t106;
  int _t227;
  double _t107;
  double _t228;
  double _t108;
  int _t229;
  int _t109;
  double signal[320];
  double _t220;
  int _t100;
  double _t221;
  double _t101;
  int _t222;
  double _t102;
  double _t223;
  double _t103;
  int _t224;
  int _t214;
  int _t215;
  int _t216;
  int _t217;
  double _t218;
  double _t219;
  double _t210;
  double _t211;
  double _t212;
  double _t213;
  double _t29;
  double _t203;
  double _t204;
  double _t205;
  double _t206;
  double _t25;
  double _t207;
  double _t26;
  double _t208;
  double _t27;
  double _t209;
  double alpha[16];
  int _t28;
  int _t21;
  int _t22;
  double _t23;
  int voiced;
  int _t24;
  double _t2;
  double _t1;
  double _t4;
  int _t3;
  int _t20;
  double _t6;
  double _t5;
  double _t8;
  double _t7;
  int _t9;
  double _t200;
  double _t201;
  double _t202;
  double _t18;
  int _t19;
  int _t14;
  double _t15;
  double _t16;
  double _t17;
  int _t10;
  double _t11;
  double _t12;
  double window[320];
  int _t13;
  double _t150;
  double _t151;
  double _t152;
  double _t153;
  double _t154;
  double _t155;
  double _t156;
  double _t157;
  double _t158;
  double _t148;
  double _t149;
  double beta14;
  double filtered[320];
  double _t47;
  double _t48;
  double tmp;
  double _t49;
  double _t43;
  double autoc[64];
  int ib;
  int _t44;
  int _t45;
  double pitch;
  double denom;
  double _t46;
  double _t40;
  double _t41;
  double _t42;
  double _t260;
  double _t140;
  double _t261;
  double _t141;
  int _t262;
  double _t142;
  double _t263;
  double _t143;
  double _t264;
  double _t144;
  double _t265;
  double _t145;
  double _t266;
  double _t146;
  double _t267;
  double _t147;
  int _t268;
  double _t137;
  double _t258;
  double beta23;
  double _t138;
  double _t259;
  double _t139;
  int _t36;
  double _t37;
  int _t38;
  double IFout[64];
  double _t39;
  double _t32;
  double _t33;
  double _t34;
  int _t35;
  int _t30;
  double _t31;
  double est2;
  int _t60;
  double est1;
  double _t250;
  double _t130;
  double _t251;
  double _t131;
  double _t252;
  double _t132;
  double _t253;
  double _t133;
  double _t254;
  double decimated[64];
  double _t134;
  double _t255;
  double _t135;
  double _t256;
  double gain;
  double _t136;
  double _t257;
  double _t126;
  int _t247;
  double _t127;
  double _t248;
  double _t128;
  double _t249;
  double _t129;
  double _t69;
  int _t65;
  int _t66;
  double _t67;
  double _t68;
  double _t61;
  double _t62;
  int _t63;
  double _t64;
  int _t240;
  double _t120;
  int _t241;
  double _t121;
  double _t242;
  double _t122;
  int _t243;
  int _t123;
  double _t244;
  double _t124;
  int _t245;
  int _t125;
  double _t246;
  int _t115;
  double _t236;
  int _t116;
  int _t237;
  int _t117;
  double _t238;
  double _t118;
  double _t239;
  double _t58;
  int _t119;
  int _t59;
  double _t54;
  int _t55;
  double _t56;
  double _t57;
  int _t50;
  double _t51;
  int _t52;
  double _t53;
  double _t80;
  double _t81;
  double _t82;
  double _t190;
  double _t191;
  double _t192;
  double _t193;
  double _t194;
  double _t195;
  double _t196;
  double _t197;
  double _t198;
  double _t199;
  double _t87;
  int _t88;
  double _t89;
  double temp_vect[16];
  double _t83;
  double _t84;
  double _t85;
  double _t86;
  double _t70;
  int _t71;
  double _t180;
  double _t181;
  double _t182;
  double _t183;
  double hamming[320];
  double _t184;
  double _t185;
  double _t186;
  double _t187;
  double _t188;
  double _t189;
  double _t76;
  double _t77;
  double _t78;
  double _t79;
  double _t72;
  double _t73;
  double _t74;
  double _t75;
  double _t170;
  double _t171;
  double _t172;
  double _t173;
  double _t174;
  double _t175;
  double _t176;
  double _t177;
  double _t178;
  double _t179;
  double ct2;
  double _t90;
  double ct1;
  double _t91;
  int _t92;
  double ct3;
  double alpha14;
  double _t93;
  double _t160;
  double _t161;
  double _t162;
  double _t163;
  double _t164;
  double _t165;
  double _t166;
  double _t167;
  double _t168;
  double _t169;
  double _t159;
  double _t98;
  double _t99;
  double _t94;
  double alpha23;
  double _t95;
  double _t96;
  int _t97;
_t1=2.0*3.141592654;
_t2=_t1/320.0;
ct1=_t2;
ct2=0.54;
ct3=0.46;
tmp=0.0;
i=0;
_l1:
_t3=i<320;
if (! _t3) goto _l2;
_t5=ct3*ct1;
_t6=_t5*tmp;
_t7=ct2-_t6;
hamming[i]=_t7;
_t8=tmp+1.0;
tmp=_t8;
_t9=i+1;
i=_t9;
goto _l1;
_l2:
tmp=0.0;
i=0;
_l3:
_t10=i<320;
if (! _t10) goto _l4;
window[i]=tmp;
_t12=tmp+1.1;
tmp=_t12;
_t13=i+1;
i=_t13;
goto _l3;
_l4:
m=0;
_l5:
_t14=m<320;
if (! _t14) goto _l6;
_t18=window[m]*hamming[m];
signal[m]=_t18;
_t19=m+1;
m=_t19;
goto _l5;
_l6:
m=0;
_l7:
_t20=m<16;
if (! _t20) goto _l8;
_t21=320-m;
r=_t21;
sum=0.0;
n=0;
_l9:
_t22=n<r;
if (! _t22) goto _l10;
_t24=n+m;
_t26=signal[n]*signal[_t24];
_t27=sum+_t26;
sum=_t27;
_t28=n+1;
n=_t28;
goto _l9;
_l10:
autocorr[m]=sum;
_t30=m+1;
m=_t30;
goto _l7;
_l8:
E=autocorr[0];
_t34=autocorr[1]/E;
alpha[1]=_t34;
m=2;
_l11:
_t35=m<16;
if (! _t35) goto _l12;
_t36=m-1;
_t38=m-1;
_t40=alpha[_t36]*alpha[_t38];
_t41=1.0-_t40;
_t42=_t41*E;
E=_t42;
temp3=autocorr[m];
n=1;
_l13:
_t44=n<m;
if (! _t44) goto _l14;
_t45=m-n;
_t48=autocorr[_t45]*alpha[n];
_t49=temp3-_t48;
temp3=_t49;
_t50=n+1;
n=_t50;
goto _l13;
_l14:
_t51=temp3/E;
temp3=_t51;
n=1;
_l15:
_t52=n<m;
if (! _t52) goto _l16;
_t55=m-n;
_t57=alpha[_t55]*temp3;
_t58=alpha[n]-_t57;
temp_vect[n]=_t58;
_t59=n+1;
n=_t59;
goto _l15;
_l16:
n=1;
_l17:
_t60=n<m;
if (! _t60) goto _l18;
alpha[n]=temp_vect[n];
_t63=n+1;
n=_t63;
goto _l17;
_l18:
alpha[m]=temp3;
_t65=m+1;
m=_t65;
goto _l11;
_l12:
temp_gain=0.0;
n=1;
_l19:
_t66=n<16;
if (! _t66) goto _l20;
_t69=alpha[n]*autocorr[n];
_t70=temp_gain+_t69;
temp_gain=_t70;
_t71=n+1;
n=_t71;
goto _l19;
_l20:
_t73=autocorr[0]-temp_gain;
gain=_t73;
_t75=0.164352414*window[0];
temp1=_t75;
temp_filt[0]=temp1;
_t77=0.049970733*temp1;
temp3=_t77;
filtered[0]=temp3;
_t80=0.164352414*window[1];
_t81=0.835647585*temp1;
_t82=_t80+_t81;
temp2=_t82;
temp_filt[1]=temp2;
_t85=0.049970733*temp2;
_t86=1.864166884*temp3;
_t87=_t85+_t86;
filtered[1]=_t87;
m=2;
_l21:
_t88=m<320;
if (! _t88) goto _l22;
_t91=0.164352414*window[m];
_t92=m-1;
_t94=0.835647585*temp_filt[_t92];
_t95=_t91+_t94;
temp_filt[m]=_t95;
_t97=m-1;
_t99=0.049970733*temp_filt[_t97];
_t100=m-1;
_t102=1.864166884*filtered[_t100];
_t103=_t99+_t102;
_t104=0-0.914137618;
_t105=m-2;
_t107=_t104*filtered[_t105];
_t108=_t103+_t107;
filtered[m]=_t108;
_t109=m+1;
m=_t109;
goto _l21;
_l22:
m=0;
_l23:
_t110=m<64;
if (! _t110) goto _l24;
_t112=m*5;
decimated[m]=filtered[_t112];
_t114=m+1;
m=_t114;
goto _l23;
_l24:
m=0;
_l25:
_t115=m<5;
if (! _t115) goto _l26;
temp1=0.0;
n=0;
_l27:
_t116=64-m;
_t117=n<_t116;
if (! _t117) goto _l28;
_t119=n+m;
_t121=decimated[n]*decimated[_t119];
_t122=temp1+_t121;
temp1=_t122;
_t123=n+1;
n=_t123;
goto _l27;
_l28:
autocorr[m]=temp1;
_t125=m+1;
m=_t125;
goto _l25;
_l26:
temp1=autocorr[0];
temp2=autocorr[1];
temp3=autocorr[2];
temp4=autocorr[3];
temp5=autocorr[4];
_t131=temp2+temp3;
_t132=temp2+temp3;
_t133=_t131*_t132;
_t134=temp1+temp4;
_t135=temp1+temp2;
_t136=_t134*_t135;
_t137=_t133-_t136;
_t138=_t137*2.0;
denom=_t138;
_t139=temp2+temp5;
_t140=temp1+temp2;
_t141=_t139*_t140;
_t142=temp2+temp3;
_t143=temp3+temp4;
_t144=_t142*_t143;
_t145=_t141-_t144;
_t146=_t145/denom;
alpha14=_t146;
_t147=temp1+temp4;
_t148=temp3+temp4;
_t149=_t147*_t148;
_t150=temp2+temp5;
_t151=temp2+temp3;
_t152=_t150*_t151;
_t153=_t149-_t152;
_t154=_t153/denom;
alpha23=_t154;
_t155=temp2-temp3;
_t156=temp2-temp3;
_t157=_t155*_t156;
_t158=temp1-temp4;
_t159=temp1-temp2;
_t160=_t158*_t159;
_t161=_t157-_t160;
_t162=_t161*2.0;
denom=_t162;
_t163=temp2-temp5;
_t164=temp1-temp2;
_t165=_t163*_t164;
_t166=temp2-temp3;
_t167=temp3-temp4;
_t168=_t166*_t167;
_t169=_t165-_t168;
_t170=_t169/denom;
beta14=_t170;
_t171=temp1-temp4;
_t172=temp3-temp4;
_t173=_t171*_t172;
_t174=temp2-temp5;
_t175=temp2-temp3;
_t176=_t174*_t175;
_t177=_t173-_t176;
_t178=_t177/denom;
beta23=_t178;
_t179=alpha14+beta14;
temp1=_t179;
_t180=alpha23+beta23;
temp2=_t180;
_t181=alpha23-beta23;
temp3=_t181;
_t182=alpha14-beta14;
temp4=_t182;
coeff[0]=temp1;
coeff[1]=temp2;
coeff[2]=temp3;
coeff[3]=temp4;
IFout[0]=decimated[0];
_t192=decimated[0]*temp1;
_t193=decimated[1]+_t192;
IFout[1]=_t193;
_t197=decimated[1]*temp1;
_t198=decimated[2]+_t197;
_t200=decimated[0]*temp2;
_t201=_t198+_t200;
IFout[2]=_t201;
_t205=decimated[2]*temp1;
_t206=decimated[3]+_t205;
_t208=decimated[1]*temp2;
_t209=_t206+_t208;
_t211=decimated[0]*temp3;
_t212=_t209+_t211;
IFout[3]=_t212;
temp1=decimated[4];
m=4;
_l29:
_t214=m<64;
if (! _t214) goto _l30;
n=0;
_l31:
_t215=n<3;
if (! _t215) goto _l32;
_t216=m-1;
_t217=_t216-n;
_t220=decimated[_t217]*coeff[n];
_t221=temp1+_t220;
temp1=_t221;
_t222=n+1;
n=_t222;
goto _l31;
_l32:
IFout[m]=temp1;
_t224=m+1;
m=_t224;
goto _l29;
_l30:
m=0;
_l33:
_t225=m<64;
if (! _t225) goto _l34;
temp1=0.0;
n=0;
_l35:
_t226=64-m;
_t227=n<_t226;
if (! _t227) goto _l36;
_t229=n+m;
_t231=IFout[n]*IFout[_t229];
_t232=temp1+_t231;
temp1=_t232;
_t233=n+1;
n=_t233;
goto _l35;
_l36:
autoc[m]=temp1;
_t235=m+1;
m=_t235;
goto _l33;
_l34:
temp1=autoc[0];
m=0;
_l37:
_t237=m<64;
if (! _t237) goto _l38;
_t239=autoc[m]+temp1;
autoc[m]=_t239;
_t240=m+1;
m=_t240;
goto _l37;
_l38:
ib=1;
_t241=ib+1;
ib=_t241;
temp3=autoc[_t241];
_t243=ib-1;
ib=_t243;
temp2=autoc[_t243];
_t245=ib-1;
ib=_t245;
temp1=autoc[_t245];
_t247=ib+1;
ib=_t247;
_t250=autoc[_t247]-autoc[0];
_t251=_t250/4.0;
temp4=_t251;
_t252=0.322745*temp1;
_t253=0.878039*temp2;
_t254=_t252+_t253;
_t255=0.158147*temp3;
_t256=_t254-_t255;
est1=_t256;
_t257=0.322745*temp3;
_t258=0.878039*temp2;
_t259=_t257+_t258;
_t260=0.158147*temp1;
_t261=_t259-_t260;
est2=_t261;
sum=0.0;
tmp=0.0;
i=0;
_l39:
_t262=i<16;
if (! _t262) goto _l40;
_t263=111.222*tmp;
_t265=_t263*alpha[i];
_t266=sum+_t265;
sum=_t266;
_t267=tmp+1.0;
tmp=_t267;
_t268=i+1;
i=_t268;
goto _l39;
_l40:
return sum;
}
