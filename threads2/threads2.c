#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void * thread_func(void * arg)
{
	int i=0;
	int loc_id = * (int *) arg;
	sem_post(&sem);
	printf("********* Thread %i is running *********\n", loc_id);
	while (i!=1) {
		printf("********* Thread#%d i=%d *********\n",loc_id, i);
		sleep(1);
	}
	printf("********* Yippee! We did it! Thread#%d *********\n", loc_id);
}

int main(int argc, char * argv[])
{
	int id, result;
	pthread_t thread1, thread2;
	id = 1;
	sem_init(&sem, 0, 0);
	result = pthread_create(&thread1, NULL, thread_func, &id);
	if (result != 0) {
		perror("Creating the first thread");
		return EXIT_FAILURE;
	}
	sem_wait(&sem);
	id = 2;
	result = pthread_create(&thread2, NULL, thread_func, &id);
	if (result != 0) {
		perror("Creating the first thread");
		return EXIT_FAILURE;
	}
	result = pthread_join(thread1, NULL);
	if (result != 0) {
		perror("Joining the first thread");
		return EXIT_FAILURE;
	}
	result = pthread_join(thread2, NULL);
	if (result != 0) {
		perror("Joining the first thread");
		return EXIT_FAILURE;
	}
	sem_destroy(&sem);
	printf("Done\n");
	return EXIT_SUCCESS;
}
