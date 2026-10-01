#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv){

        umask(0020);
	
	int fd = open(argv[1], O_CREAT, 0645);
	close(fd);
    
    return 0;
}
