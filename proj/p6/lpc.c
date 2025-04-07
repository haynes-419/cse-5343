double lpc()
{
double window[320];
double hamming[320];
double filtered[320];
double signal[320];
double decimated[64];
double IFout[64];
double autoc[64];
double alpha[16];
double autocorr[16];
double temp_vect[16];
double coeff[4];
double temp_filt[320];

double gain;
double pitch;
int voiced;


  int i;
  double ct1;
  double ct2;
  double ct3;
  double est1;
  double est2;
  double tmp;

  double E;

  double temp_gain;
  double sum;
  double temp3;

  int m;
  int n;
  int r;

  double denom;
  double alpha14;
  double alpha23;
  double beta14;
  double beta23;

  double temp1;
  double temp2;
  double temp4;
  double temp5;

  int ib;


  ct1 = 2.0 * 3.141592654 / 320.0;
  ct2 = 0.54;
  ct3 = 0.46;

  tmp = 0.0;
  for (i = 0; i < 320; i=i+1) {
    hamming[i] = ct2 - ct3 * ct1 * tmp;
    tmp = tmp + 1.0;
  }

  tmp = 0.0;
  for (i = 0; i < 320; i=i+1) { window[i] = tmp; tmp += 1.1; }

  for (m = 0; m < 320; m=m+1) {
    signal[m]=window[m]*hamming[m];
  }


  for (m = 0; m < 16 ; m=m+1) {
    r = 320 - m;
    sum = 0.0;
    for (n = 0; n < r; n=n+1) {
      sum += signal[n] * signal[n+m];
    }
    autocorr[m] = sum;
  }

  E = autocorr[0];

  alpha[1] = autocorr[1]/E;

  for (m = 2; m < 16; m=m+1) {
    E = (1.0 - alpha[m-1] * alpha[m-1]) * E;

    temp3 = autocorr[m];
    for (n = 1; n < m; n=n+1) {
      temp3 -= autocorr[m-n] * alpha[n];
    }

    temp3 = temp3 / E;
    for (n = 1; n < m; n=n+1) {
      temp_vect[n] = alpha[n] - (alpha[m-n] * temp3);
    }

    for (n = 1; n < m; n=n+1) {
      alpha[n]=temp_vect[n];
    }

    alpha[m] = temp3;
  }

  temp_gain = 0.0;
  for (n = 1; n < 16; n=n+1) {
    temp_gain += alpha[n] * autocorr[n];
  }

  gain = autocorr[0] - temp_gain;

  temp1 = 0.164352414 * window[0];
  temp_filt[0] = temp1;
  temp3 = 0.049970733 * temp1;
  filtered[0] = temp3;
  temp2 = (0.164352414 * window[1]) + (0.835647585 * temp1);
  temp_filt[1] = temp2;
  filtered[1] = (0.049970733 * temp2) + (1.864166884 * temp3);

  for (m = 2; m < 320; m=m+1) {
    temp_filt[m] = (0.164352414 * window[m]) + (0.835647585 * temp_filt[m-1]);
    filtered[m] = (0.049970733 * temp_filt[m-1]) + (1.864166884 * filtered[m-1]) + ((0-0.914137618) * filtered[m-2]);
  }

  for (m = 0; m < 64; m=m+1) {
    decimated[m] = filtered[m*5];
  }
  for (m = 0; m < 5 ; m=m+1) {
    temp1 = 0.0;

    for (n = 0; n < 64 - m; n=n+1) {
      temp1 += decimated[n] * decimated[n+m];
    }
    autocorr[m] = temp1;
  }

  temp1 = autocorr[0];
  temp2 = autocorr[1];
  temp3 = autocorr[2];
  temp4 = autocorr[3];
  temp5 = autocorr[4];

  denom =(((temp2 + temp3) * (temp2 + temp3)) -
           ((temp1 + temp4) * (temp1 + temp2))) * 2.0;

  alpha14=(((temp2 + temp5) * (temp1 + temp2)) -
           ((temp2 + temp3) * (temp3 + temp4))) / denom;

  alpha23=(((temp1 + temp4) * (temp3 + temp4)) -
           ((temp2 + temp5) * (temp2 + temp3))) / denom;

  denom =(((temp2 - temp3) * (temp2 - temp3)) -
           ((temp1 - temp4) * (temp1 - temp2))) * 2.0;

  beta14 =(((temp2 - temp5) * (temp1 - temp2)) -
           ((temp2 - temp3) * (temp3 - temp4))) / denom;

  beta23 =(((temp1 - temp4) * (temp3 - temp4)) -
           ((temp2 - temp5) * (temp2 - temp3))) / denom;

  temp1 = alpha14 + beta14;
  temp2 = alpha23 + beta23;
  temp3 = alpha23 - beta23;
  temp4 = alpha14 - beta14;

  coeff[0] = temp1;
  coeff[1] = temp2;
  coeff[2] = temp3;
  coeff[3] = temp4;




  IFout[0] = decimated[0];

  IFout[1] = decimated[1] + decimated[0] * temp1 ;

  IFout[2] = decimated[2] + decimated[1] * temp1 + decimated[0] * temp2;

  IFout[3] = decimated[3] + decimated[2] * temp1 + decimated[1] * temp2 +
                          decimated[0] * temp3;


  temp1 = decimated[4];
  for (m = 4; m < 64; m=m+1) {
    for (n = 0; n < 3; n=n+1) {
      temp1 += decimated[m-1-n] * coeff[n];
    }
    IFout[m] = temp1;
  }
  for (m = 0; m < 64 ; m=m+1) {
    temp1 = 0.0;
    for (n = 0; n < 64 - m; n=n+1) {
      temp1 += IFout[n] * IFout[n+m];
    }
    autoc[m] = temp1;

  }



  temp1 = autoc[0];
  for (m = 0; m < 64; m=m+1) {
    autoc[m] += temp1;
  }








  ib = 1;
  temp3 = autoc[ib=ib+1];
  temp2 = autoc[ib=ib-1];
  temp1 = autoc[ib=ib-1];

  temp4 = ((autoc[ib=ib+1] - autoc[0]) / 4.0);



  est1 = 0.322745 * temp1 + 0.878039 * temp2 - 0.158147 * temp3;
  est2 = 0.322745 * temp3 + 0.878039 * temp2 - 0.158147 * temp1;

  sum = 0.0; tmp = 0.0;
  for (i = 0; i < 16; i+=1) { sum+= 111.222*tmp*alpha[i]; tmp +=1.0; }

  return sum;

}

