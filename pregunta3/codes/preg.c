/* IEE240 - Organizacion y Arquitectura de Computadoras */
/* C-wrapper for assembly functions */

#include <stdio.h>
#include <stdlib.h>
#include "readimglib.h"

void effectC(unsigned char *A, unsigned char *Cc, int imgSize);
extern void effectASM(unsigned char *A, unsigned char *Cc, int imgSize);

int main (int argc, char **argv){ 

    char filenameA[] = "../data/baboon.pgm";
    
    int Nrows, Ncols, imgSize;
    unsigned char *A, *Cc, *Casm;   
    
    struct timespec time1, time2; 

    read_headppm(filenameA, &Nrows, &Ncols,"P5");

    posix_memalign((void **)&A, 16, Nrows * Ncols * sizeof(unsigned char));
    posix_memalign((void **)&Cc, 16, Nrows * Ncols * sizeof(unsigned char));
    posix_memalign((void **)&Casm, 16, Nrows * Ncols * sizeof(unsigned char));
        
    read_ppm2uchar(filenameA, A, Nrows*Ncols, "P5");
    imgSize = Nrows * Ncols;
 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);  
    effectC(A,Cc,imgSize);  
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);   
    double tC = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9); 

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    effectASM(A,Casm,imgSize);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2); 
    double tASM = (double)((time2.tv_sec-time1.tv_sec) + (time2.tv_nsec-time1.tv_nsec)/1e9);
    
    printf("El tiempo de ejecución en C es: %.5f ms\n", tC*1e3);
    printf("El tiempo de ejecución en ASM es: %.5f ms\n", tASM*1e3);
    printf("El speed-up es: %.2f \n", tC/tASM);

    write_uchar2ppm("outputImgC.pgm", Cc, Nrows, Ncols, "P5"); 
    write_uchar2ppm("outputImgASM.pgm", Casm, Nrows, Ncols, "P5");

    free(A);
    free(Cc);
    free(Casm);
    
    return 0;
}

void effectC(unsigned char *A, unsigned char *Cc, int imgSize){
    for(int i=0; i<imgSize; i++){
        Cc[i] = ~A[i];
    }
}
