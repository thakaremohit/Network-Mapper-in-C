/* netmap.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "/home/kali/Desktop/network_mapper/birchutils.h"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;  // Corrected int32 to be a 32-bit type.

