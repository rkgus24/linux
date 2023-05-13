#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define IOCTL_START_BUZZER      _IOW('b', 0x07, int)
#define IOCTL_END_BUZZER        _IOW('b', 0x09, int)
#define IOCTL_SET_TONE          _IOW('b', 0x0b, int)
#define IOCTL_SET_VOLUME        _IOW('b', 0x0c, int)
#define IOCTL_GET_TONE          _IOW('b', 0x0d, int)
#define IOCTL_GET_VOLUME        _IOW('b', 0x0e, int)

long freqToTone(double freq) {
        double tone;
        tone = (1.0f / freq) * 1000000000;
        return (long) tone;
}
void playTone(long tone, int volume, int time) {
        int buzzer_fd = open("/dev/buzzer", O_RDONLY);

        ioctl(buzzer_fd, IOCTL_SET_VOLUME, volume);
        ioctl(buzzer_fd, IOCTL_SET_TONE, tone);
        printf("Tone:%lu, Volume: %d\n", tone, volume);

        ioctl(buzzer_fd, IOCTL_START_BUZZER, 0);
        usleep(time);
        ioctl(buzzer_fd, IOCTL_END_BUZZER, 0);
        close(buzzer_fd);
}

int main(int argc, char **argv) {
    double TONEHZ[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

    int i = 0;
    for (i = 0; i < 8; i++) {
        long tone = freqToTone((TONEHZ[i]));
        playTone(tone, 25000, 100 * 1000);
    }
    return 0;
}