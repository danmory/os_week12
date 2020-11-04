#include <stdio.h>

int main()
{
	FILE* rand = fopen("/dev/random", "r");
	for (int i = 0; i < 20; i++){
		printf("%c", fgetc(rand));
    }
	printf("\n");
	fclose(rand);
	return 0;
}