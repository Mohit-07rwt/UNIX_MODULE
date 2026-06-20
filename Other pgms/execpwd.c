#include"header.h"
void main()
{
	printf("HELLO\n");
	execl("/bin/pwd","pwd",NULL);
	printf("HAI.....\n");
}
