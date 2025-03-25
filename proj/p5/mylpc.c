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
  int _t231;
  int _t111;
  double _t232;
  double _t112;
  double _t233;
  int _t113;
  double _t234;
  double _t114;
  double _t235;
  double _t104;
  int _t225;
  double _t105;
  int _t226;
  int _t106;
  int _t227;
  double _t107;
  int _t228;
  double _t108;
  int _t229;
  double _t109;
  double signal[320];
  double _t220;
  double _t100;
  double _t221;
  int _t101;
  double _t222;
  double _t102;
  double _t223;
  double _t103;
  double _t224;
  int _t214;
  int _t215;
  int _t216;
  int _t217;
  int _t218;
  int _t219;
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
  int _t26;
  double _t208;
  double _t27;
  double _t209;
  double alpha[16];
  double _t28;
  int _t21;
  int _t22;
  int _t23;
  int voiced;
  int _t24;
  double _t2;
  double _t1;
  int _t4;
  int _t3;
  int _t20;
  double _t6;
  double _t5;
  double _t8;
  double _t7;
  double _t9;
  double _t200;
  double _t201;
  double _t202;
  double _t18;
  double _t19;
  int _t14;
  int _t15;
  double _t16;
  double _t17;
  int _t10;
  int _t11;
  double _t12;
  double window[320];
  double _t13;
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
  int _t47;
  double _t48;
  double tmp;
  double _t49;
  double _t43;
  double autoc[64];
  int ib;
  double _t44;
  int _t45;
  double pitch;
  double denom;
  int _t46;
  double _t40;
  double _t41;
  double _t42;
  double _t260;
  double _t140;
  double _t261;
  double _t141;
  int _t262;
  double _t142;
  int _t263;
  double _t143;
  double _t264;
  double _t144;
  double _t265;
  double _t145;
  double _t266;
  double _t146;
  double _t267;
  double _t147;
  double _t268;
  double _t137;
  double _t258;
  double beta23;
  double _t138;
  double _t259;
  double _t139;
  int _t36;
  int _t37;
  double _t38;
  double IFout[64];
  int _t39;
  double _t32;
  double _t33;
  double _t34;
  int _t35;
  double _t30;
  double _t31;
  double est2;
  double _t60;
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
  double _t65;
  int _t66;
  int _t67;
  double _t68;
  int _t61;
  int _t62;
  double _t63;
  double _t64;
  double _t240;
  double _t120;
  int _t241;
  int _t121;
  double _t242;
  double _t122;
  int _t243;
  double _t123;
  double _t244;
  double _t124;
  int _t245;
  double _t125;
  double _t246;
  int _t115;
  double _t236;
  int _t116;
  int _t237;
  int _t117;
  int _t238;
  int _t118;
  double _t239;
  double _t58;
  int _t119;
  double _t59;
  int _t54;
  double _t55;
  double _t56;
  int _t57;
  double _t50;
  double _t51;
  double _t52;
  int _t53;
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
  int _t89;
  double temp_vect[16];
  double _t83;
  double _t84;
  double _t85;
  double _t86;
  double _t70;
  double _t71;
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
  double _t92;
  double ct3;
  double alpha14;
  int _t93;
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
  int _t98;
  double _t99;
  double _t94;
  double alpha23;
  double _t95;
  double _t96;
  double _t97;
  (ct1=((2.0*3.141592654)/320.0));
  (ct2=0.54);
  (ct3=0.46);
  (tmp=0.0);
  for ((i=0); (i<320); (i=(i+1)))
   {
     (hamming[i]=(ct2-((ct3*ct1)*tmp)));
     (tmp=(tmp+1.0));
   }
  (tmp=0.0);
  for ((i=0); (i<320); (i=(i+1)))
   {
     (window[i]=tmp);
     (tmp+=1.1);
   }
  for ((m=0); (m<320); (m=(m+1)))
   {
     (signal[m]=(window[m]*hamming[m]));
   }
  for ((m=0); (m<16); (m=(m+1)))
   {
     (r=(320-m));
     (sum=0.0);
     for ((n=0); (n<r); (n=(n+1)))
      {
        (sum+=(signal[n]*signal[(n+m)]));
      }
     (autocorr[m]=sum);
   }
  (E=autocorr[0]);
  (alpha[1]=(autocorr[1]/E));
  for ((m=2); (m<16); (m=(m+1)))
   {
     (E=((1.0-(alpha[(m-1)]*alpha[(m-1)]))*E));
     (temp3=autocorr[m]);
     for ((n=1); (n<m); (n=(n+1)))
      {
        (temp3-=(autocorr[(m-n)]*alpha[n]));
      }
     (temp3=(temp3/E));
     for ((n=1); (n<m); (n=(n+1)))
      {
        (temp_vect[n]=(alpha[n]-(alpha[(m-n)]*temp3)));
      }
     for ((n=1); (n<m); (n=(n+1)))
      {
        (alpha[n]=temp_vect[n]);
      }
     (alpha[m]=temp3);
   }
  (temp_gain=0.0);
  for ((n=1); (n<16); (n=(n+1)))
   {
     (temp_gain+=(alpha[n]*autocorr[n]));
   }
  (gain=(autocorr[0]-temp_gain));
  (temp1=(0.164352414*window[0]));
  (temp_filt[0]=temp1);
  (temp3=(0.049970733*temp1));
  (filtered[0]=temp3);
  (temp2=((0.164352414*window[1])+(0.835647585*temp1)));
  (temp_filt[1]=temp2);
  (filtered[1]=((0.049970733*temp2)+(1.864166884*temp3)));
  for ((m=2); (m<320); (m=(m+1)))
   {
     (temp_filt[m]=((0.164352414*window[m])+(0.835647585*temp_filt[(m-1)])));
     (filtered[m]=(((0.049970733*temp_filt[(m-1)])+(1.864166884*filtered[(m-1)]))+((0-0.914137618)*filtered[(m-2)])));
   }
  for ((m=0); (m<64); (m=(m+1)))
   {
     (decimated[m]=filtered[(m*5)]);
   }
  for ((m=0); (m<5); (m=(m+1)))
   {
     (temp1=0.0);
     for ((n=0); (n<(64-m)); (n=(n+1)))
      {
        (temp1+=(decimated[n]*decimated[(n+m)]));
      }
     (autocorr[m]=temp1);
   }
  (temp1=autocorr[0]);
  (temp2=autocorr[1]);
  (temp3=autocorr[2]);
  (temp4=autocorr[3]);
  (temp5=autocorr[4]);
  (denom=((((temp2+temp3)*(temp2+temp3))-((temp1+temp4)*(temp1+temp2)))*2.0));
  (alpha14=((((temp2+temp5)*(temp1+temp2))-((temp2+temp3)*(temp3+temp4)))/denom));
  (alpha23=((((temp1+temp4)*(temp3+temp4))-((temp2+temp5)*(temp2+temp3)))/denom));
  (denom=((((temp2-temp3)*(temp2-temp3))-((temp1-temp4)*(temp1-temp2)))*2.0));
  (beta14=((((temp2-temp5)*(temp1-temp2))-((temp2-temp3)*(temp3-temp4)))/denom));
  (beta23=((((temp1-temp4)*(temp3-temp4))-((temp2-temp5)*(temp2-temp3)))/denom));
  (temp1=(alpha14+beta14));
  (temp2=(alpha23+beta23));
  (temp3=(alpha23-beta23));
  (temp4=(alpha14-beta14));
  (coeff[0]=temp1);
  (coeff[1]=temp2);
  (coeff[2]=temp3);
  (coeff[3]=temp4);
  (IFout[0]=decimated[0]);
  (IFout[1]=(decimated[1]+(decimated[0]*temp1)));
  (IFout[2]=((decimated[2]+(decimated[1]*temp1))+(decimated[0]*temp2)));
  (IFout[3]=(((decimated[3]+(decimated[2]*temp1))+(decimated[1]*temp2))+(decimated[0]*temp3)));
  (temp1=decimated[4]);
  for ((m=4); (m<64); (m=(m+1)))
   {
     for ((n=0); (n<3); (n=(n+1)))
      {
        (temp1+=(decimated[((m-1)-n)]*coeff[n]));
      }
     (IFout[m]=temp1);
   }
  for ((m=0); (m<64); (m=(m+1)))
   {
     (temp1=0.0);
     for ((n=0); (n<(64-m)); (n=(n+1)))
      {
        (temp1+=(IFout[n]*IFout[(n+m)]));
      }
     (autoc[m]=temp1);
   }
  (temp1=autoc[0]);
  for ((m=0); (m<64); (m=(m+1)))
   {
     (autoc[m]+=temp1);
   }
  (ib=1);
  (temp3=autoc[(ib=(ib+1))]);
  (temp2=autoc[(ib=(ib-1))]);
  (temp1=autoc[(ib=(ib-1))]);
  (temp4=((autoc[(ib=(ib+1))]-autoc[0])/4.0));
  (est1=(((0.322745*temp1)+(0.878039*temp2))-(0.158147*temp3)));
  (est2=(((0.322745*temp3)+(0.878039*temp2))-(0.158147*temp1)));
  (sum=0.0);
  (tmp=0.0);
  for ((i=0); (i<16); (i+=1))
   {
     (sum+=((111.222*tmp)*alpha[i]));
     (tmp+=1.0);
   }
  return sum;
}
