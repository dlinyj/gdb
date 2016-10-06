#include <unistd.h>
const char greeting[13] = "Hello world\n";
int main() {
	write(1, greeting, sizeof(greeting)); // Here sizeof(greeting) is 13
	return 0;
}
