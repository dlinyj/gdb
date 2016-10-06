#include <stdio.h>
#include <stdlib.h>


void recurse (void) {
	static int i;
	if (++i==3) {
		abort();
	} else {
		recurse();
	}
}

int main () {
	recurse ();
}
