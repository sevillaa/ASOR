#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char** argv){

	struct stat sb;

	int control = stat(argv[1], &sb);
	
	if(-1==control){
		perror("Stat");
	}
	
	printf("ID of containing device:  [%x,%x]\n", major(sb.st_dev), minor(sb.st_dev));


	return 0;
}

