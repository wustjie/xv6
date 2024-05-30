#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define R 0
#define W 1

int 
main(int argc, char *argv[])
{
    int p2c[2];
    int c2p[2];

    pipe(p2c);
    pipe(c2p);

    char flag='f';

    int pid = fork();
    if(pid == 0) {
        close(p2c[W]);
        close(c2p[R]);

        if (read(p2c[R], &flag, sizeof(char)) != sizeof(char)) {
            printf("child read error!\n");
            exit(1);
        } else {
            printf("child received ping\n");
        }

        if (write(c2p[W], &flag, sizeof(char)) != sizeof(char)) {
            printf("child write error!\n");
            exit(1);
        }

        close(p2c[R]);
        close(c2p[W]);


    } else if(pid > 0) {
        close(p2c[R]);
        close(c2p[W]);


        if (write(p2c[W], &flag, sizeof(char)) != sizeof(char)) {
            printf("parent write error!\n");
            exit(1);
        }


        if (read(c2p[R], &flag, sizeof(char)) != sizeof(char)) {
            printf("parent read error!\n");
            exit(1);
        } else {
            printf("parent received pong\n");
        }

        close(p2c[W]);
        close(c2p[R]);

    } else {
        printf("fork error\n");
        close(p2c[W]);
        close(c2p[R]);
        close(p2c[R]);
        close(c2p[W]);

        exit(1);
    }

    exit(0);
}