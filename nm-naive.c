#include "nm-naive.h"
#include <arpa/inet.h>  // For inet_addr function
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <unistd.h>     // For close function
#include <assert.h>     // For assert function
#include <string.h>     // For strlen function

int16 port;
in_addr_t current, ending;

in_addr_t generate() {
    int8 buf[16];
    int size;
    int8 *p; // Correct type to match buf

    if ((!current) && (!ending)) {
        zero(buf, 16);
        fgets((char *)buf, 15, stdin);
        size = (int)strlen((char *)buf);

        if (size < 7)
            return (in_addr_t)0;
        size--;
        p = buf + size;

        if ((*p == '\n') || (*p == '\r'))
            *p = 0;

        return inet_addr((char *)buf);
    }
    if (current >= ending) // Correct comparison operator
        return (in_addr_t)0;

    else
        current++;

    return current;
}

int8 *header(int s, in_addr_t ip) {
    int16 i;
    int8 *p;
    static int8 buf[256];

    zero(buf, 256);
    i = read(s, (char *)buf, 255);
    if (i < 2)
        printf("0x%x\n", ip);
    else {
        i--;
        p = buf + i;
        if ((*p == '\n') || (*p == '\r'))
            *p = 0;

        printf("0x%x: %s\n", ip, buf);
    }

    return buf;
}

bool tcpconnect(in_addr_t ip, int16 port) {
    struct sockaddr_in sock;
    int s, ret;

    s = socket(AF_INET, SOCK_STREAM, 0);
    assert(s > 0);
    sock.sin_family = AF_INET;
    sock.sin_port = htons((int)port);
    sock.sin_addr.s_addr = ip;

    ret = connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr));

    if (ret) { 
        close(s);
        return false;
    } else {
        header(s, ip);
        close(s);
        return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    in_addr_t ip;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port> [start ip addr] [end ip addr]\n", *argv);
        return -1;
    }

    if (argc > 2) {
        current = inet_addr(argv[2]);
        ending = (argc > 3) ? inet_addr(argv[3]) : inet_addr("223.255.254.255");

        if ((current == INADDR_NONE) || (ending == INADDR_NONE) || (ending < current)) {
            fprintf(stderr, "Usage: %s <port> [start ip addr] [end ip addr]\n", *argv);
            return -1;
        }
    }

    port = (int16)atoi(argv[1]);
    while ((ip = generate()))
        tcpconnect(ip, port);

    return 0;
}
