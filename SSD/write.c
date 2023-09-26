#include "common.h"

void W(int address, char* value) {
    FILE* fp = fopen("nand.txt", "r+");
    if (fp == NULL) {
        fp = fopen("nand.txt", "w");
        for (int i = 0; i < 100; ++i) {
            fputs("0x00000000", fp);
        }
        fclose(fp);
        fp = fopen("nand.txt", "r+");
    }

    fseek(fp, address * 10, SEEK_SET);
    fprintf(fp, value);
    fclose(fp);

    return 0;
}
