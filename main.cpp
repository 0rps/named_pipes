#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char** argv) {
    int fd_out = mkfifo("/tmp/fifo.out", );
    int fd_in = mkfifo("tmp/fifo.in", );


    return 0;
}
