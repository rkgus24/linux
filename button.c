#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd;
    if (argc <2) {
        printf("./button <device>\n ex: ./button /dev/input/event1\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    struct input_event ev;
    printf("Application Startef!\n");

    while (1)
    {
        read(fd, &ev, sizeof(struct input_event));
        if(ev.type == 1)
        printf("Key Code [%i] = State is %i\n", ev.code,
        ev.value);
    }
}