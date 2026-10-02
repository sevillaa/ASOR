
// int link(const char *oldpath, const char *newpath); -» HARD LINK
// int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);
// int symlinkat(const char *target, int newdirfd, const char *linkpath);

//0 success -1 error


//AT_EMPTY_PATH -» If the pathname is an empty string, then the link is created to the file referred to by olddirfd.
//    In this case, newpath must be a non-empty string. If olddirfd is AT_FDCWD, then the current working directory is used. 
//    If oldpath is not an empty string, then olddirfd is ignored and oldpath is interpreted relative to the current working directory.
//AT_SYMLINK_FOLLOW -» If oldpath is a symbolic link, then the link is created to the file that the symbolic link refers to, 
//    rather than to the symbolic link itself

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) return 0;

    if (lstat(argv[1], &st) == 0 && S_ISREG(st.st_mode)) {
        char hard[strlen(argv[1]) + 6];
        char sym[strlen(argv[1]) + 5];

        sprintf(hard, "%s.hard", argv[1]);
        sprintf(sym, "%s.sym", argv[1]);

        char *nombre = strrchr(argv[1], '/');
        if (nombre) nombre++;
        else nombre = argv[1];

        link(argv[1], hard);
        symlink(nombre, sym);
    }

    return 0;
}