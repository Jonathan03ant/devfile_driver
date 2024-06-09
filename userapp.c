#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int  main() {
	int success = open("/dev/devicefile_dr", O_RDONLY);
	if (success == -1) {
		printf("opening was not successfull!\n");
		return -1;
	}
	printf("Opening was successfull!\n");
	close(success);
	return 0;
	
}; 

