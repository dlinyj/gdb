#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char * argv[])
{
	int pid, status;
	pid = fork();
	if (pid == 0) {
		printf("We are the child pid=%d",getpid());
		int i = 0;
		while (i!=1) {
			printf("********* i=%d *********\n", i);
			sleep(1);
			}
		printf("********* Yippee! We did it! *********\n");
		return EXIT_FAILURE; // Never get there normally
	}
	else {
	  if (wait(&status) == -1) {
		 perror("wait");
		 return EXIT_FAILURE;
	  }
	  if (WIFEXITED(status))
		 printf("Child terminated normally with exit code %i\n", WEXITSTATUS(status));
	  if (WIFSIGNALED(status))
		 printf("Child was terminated by a signal #%i\n", WTERMSIG(status));
	  if (WCOREDUMP(status))
		 printf("Child dumped core\n");
	  if (WIFSTOPPED(status))
		 printf("Child was stopped by a signal #%i\n", WSTOPSIG(status));
	}
	return EXIT_SUCCESS;
}
