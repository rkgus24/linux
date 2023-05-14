#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <linux/input.h>

struct linux_rtc_time {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

#define RTC_RD_TIME     _IOR('p', 0x09, struct linux_rtc_time)

int main(int argc, char **argv) {
    int fd, rc;
    struct linux_rtc_time st;
    fd = open("/dev/rtc", O_RDONLY);
    rc = ioctl(fd, RTC_RD_TIME, &st);
    printf("%d년 %d월 %d일 %d시 %d분 %d초\n", (st.tm_year + 1900), (st.tm_mon + 1), st.tm_mday, (st.tm_hour + 9), st.tm_min, st.tm_sec);
}