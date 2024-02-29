#include <omp.h>
#include <stdio.h>
#define CHUNKSIZE 2
#define N 10

int main (){
	int i, chunk;
	int nthreads, tid;
	int a[N],b[N],c[N];
	
	for (i=0;i<N;i++)
		a[i]=b[i]=i*1.0;
	chunk=CHUNKSIZE;
	//Las variables a, b, c, chunk son de tipo compartido
	//Las variables i, tid son privadas a cada thread
	
	#pragma omp parallel private(tid,i) shared(a, b, c, chunk)
	{
		//Asignación estática de iteraciones en la que el 
		//tamaño del bloque se fija a chunk
		#pragma omp for schedule(static, chunk) //nowait
		for (i=0;i<N;i++){
			//.........Get ID of thread
			//.........Get number of threads
			tid = omp_get_thread_num();
        	nthreads = omp_get_num_threads();
			c[i]=a[i]+b[i];
			printf("El thread %d, de %d threads, calcula la iteración i = %d\n", tid, nthreads, i);
		}
	} //Fin de la región paralela
}
