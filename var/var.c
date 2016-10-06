#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "print_count.h"


int print_var (int var){
	static int count=0;
	printf("var=%d\n",var);
	count++;
	print_count(count);
	return count;
}

int main(int argc, char * argv[])
{
	int var, c;
	if (argc < 2) {
		printf("Usage: %s command, [arg1 [arg2]...]\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("Our param == %s...\n", argv[1]);
	var=100;
	c=print_var(var);
	var+=c;
	print_var(var);
	return 0;
}
