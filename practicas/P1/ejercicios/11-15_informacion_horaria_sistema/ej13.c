#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tiempo1;
    struct timeval tiempo2;
    gettimeofday(&tiempo1, NULL);
    int suma = 0;
    for (int i = 0; i < 1000000;i++){
        suma += i;
    }
    gettimeofday(&tiempo2, NULL);

    printf("Solucion: %d\n", tiempo2.tv_usec - tiempo1.tv_usec);
}