 #include <fcntl.h>
 #include <stdio.h>
 #include <unistd.h>

 int main(int argc, char *argv[]) {
    int ch, file;
    if(argc != 2){
        fprintf(stderr,"Error argumentos");
        return 0;
    }

    file = open(argv[1],O_CREAT, 0645);
    close(file);
    
    return 0;
  
 }