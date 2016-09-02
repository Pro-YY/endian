#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Little-endian format:
    stores the least significant byte at the first location
    with the most significant byte being stored last
小尾端：将最低有效位存储在最低地址（先存最低位)
*/

int is_little_endian() {
    int x = 0x12345678;
    // first stored byte equals least significant byte
    return *((char *)&x) == (x & 0xFF);
}

int main(int argc, char *argv[]) {
    int a = 0x87654321;
    int i = -1;

    printf("a: %x (size int: %lu bytes) address: %p\n", a, sizeof(a), &a);
    if(is_little_endian()) printf("little endian!\n");
    for (i = 0; i < 4; i++) {
        printf("[%d] %hhx\n", i, *((char *)&a + i));
    }

    return EXIT_SUCCESS;
}
