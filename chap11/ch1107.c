#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
}

int initsem(key_t semkey) {
    union semun semunarg;
    int status = 0, semid;

    semid = semget(semkey, 1, IPC_CREAT|IPC_EXCL|0600);
    if(semid == -1) {
        if(errno == EEXIST)
            semid = semget(semkey, 1, 0);
    }
    else {
        semunarg.val = 1;
        status = semctl(semid, 0, SETVAL, semunarg);
    }
    if(semid == -1 || status == -1) {
        perror("initsem");
        return(-1);
    }
    return semid;
}
