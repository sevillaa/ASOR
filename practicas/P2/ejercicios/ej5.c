#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){

    int fd = open(argv[1], O_CREAT, 0645);
    close(fd);
    return 0;
}