#include <stdio.h>

int main() {
	printf("Hello, World!\n");
	
	// Run a system command.
	printf("Running 'ls -l' command:\n");
	system("ls -l");

	return 0;
}