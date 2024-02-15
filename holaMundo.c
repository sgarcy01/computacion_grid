#include <omp.h>
#include <stdio.h>

int main(){
    int nthreads, tid;
    #pragma omp parallel private(tid) //Create a group of threads
    {
        //Each thread has a copy of the variable tid
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("Hello from thread %d of %d threads \n", tid, nthreads);
    }
    //All threads ends and only exists the master thread (tid == 0)
    return 0;
}