#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
	int a[] = {1, 2, 3};
	int i=0;
	printf("pid=%d\n", getpid());
	while (1) {
		sleep(1);
		printf("i=%d\n",i);
	}
	return 0;
}
