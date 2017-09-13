#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char** argv) {
    char* out = "/tmp/out.fifo";
    char* in = "/tmp/in.fifo";

    unlink(out);
    unlink(in);

    mkfifo(out, 0777);
    mkfifo(in, 0777);

    int fd_in = open(in, O_RDWR);
    int fd_out = open(out, O_WRONLY);


    if (fd_in < 0) {
        return 1;
    }

    if (fd_out < 0) {
        return 1;
    }

    int max_count = 128;
    char buf[128];
    while (1) {
        int count = read(fd_in, (void*)buf, max_count);
        //std::cout << buf << std::endl;
        write(fd_out, (void*)buf, count);
        //write(fd_out, buf, count);
    }

    return 0;
}
