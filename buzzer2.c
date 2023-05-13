#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define IOCTL_START_BUZZER      _IOW('b', 0x07, int)
#define IOCTL_END_BUZZER        _IOW('b', 0x09, int)
#define IOCTL_SET_TONE          _IOW('b', 0x0b, int)
#define IOCTL_SET_VOLUME        _IOW('b', 0x0c, int)
#define IOCTL_GET_TONE          _IOW('b', 0x0d, int)
#define IOCTL_GET_VOLUME        _IOW('b', 0x0e, int)

long freeToTone(double freq);
void startBuzzer();
void changeTone(long tone, int volume);
void stopBuzzer();

int buzzer_fd;

long freqToTone(double freq) {
    double tone;
    tone = (1.0f / freq) * 1000000000;
    return (long) tone;
}
void startBuzzer() {
    ioctl(buzzer_fd, IOCTL_START_BUZZER, 0);
};
void stopBuzzer() {
    ioctl(buzzer_fd, IOCTL_END_BUZZER, 0);
};

void changeTone(long tone, int volume) {
    ioctl(buzzer_fd, IOCTL_SET_VOLUME, volume);
    ioctl(buzzer_fd, IOCTL_SET_TONE, tone);
    printf("Tone:%lu, Volume: %d\n", tone, volume);
}
int main(int arc, char **argv) {
    buzzer_fd = open("/dev/buzzer", O_RDONLY);
    int fd;
    fd = open("/dev/input/event1", O_RDONLY);
    struct input_event ev;
    printf("Application Started!\n");

    while(1) {
        read(fd, &ev, sizeof(struct input_event));
        if (ev.type == 1) {
            printf("key Code [%i] = State is %i\n", ev.code, ev.value);
            long tone;

            switch(ev.code) {
                case 158:
                    tone : freqToTone(523);
                    break;
                case 172:
                    tone = freqToTone(587);
                    break;
                case 139:
                    tone : freqToTone(659);
                    break;
            }
            changeTone(tone, 10000);

            if(ev.value == 1) {
                startBuzzer();
            }
            else {
                stopBuzzer();
            }
        }
    }
}