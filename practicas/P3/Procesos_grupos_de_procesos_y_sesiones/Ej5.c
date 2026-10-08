#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv){

    __pid_t pid = getpid();
    __pid_t ppid = getppid();
    __pid_t pgid = getpgid(pid);
    __pid_t sid = getsid(pid);

    fprintf(stdout, "PID: %d\nPPID: %d\nPGID: %d\nSID: %d\n", pid, ppid, pgid, sid);

    return 0;
}