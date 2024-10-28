#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float pot = 1e-12; //inicializar variables
    for (unsigned int i=0; i<N; i++){
      pot += x[i]*x[i];

    }
    
    return 10*log10(pot/N);
}

float compute_am(const float *x, unsigned int N) {
   
  
   float a = 1e-12; //inicializar variables
    for (unsigned int i=0; i<N; i++){
      if(x[i]<0){
        a += -x[i];
      }
      else{
        a += x[i];
      }
    }
    return a/N;

}

float compute_zcr(const float *x, unsigned int N, float fm) {
   float numzeros = 1e-12;
   
    for (unsigned int i=1; i<N+1; i++){
     if ((x[i]<0 && x[i-1]>0)||(x[i]>0 && x[i-1]<0))
        numzeros += 1;
    }
    return (fm*numzeros)/(2*(N-1));
}
