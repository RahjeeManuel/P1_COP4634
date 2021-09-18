#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
	int pid = getpid();
	for (int i = 0; i < 10; i++) {
		sleep(1);
		printf("slow %6d : %d\n", pid, i);
		fflush(NULL);
	}
	return 0;
}