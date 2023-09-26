#include "common.h"

void R(int address) {
	char buffer[11] = {};
	FILE* fp = fopen("nand.txt", "r"); 
	if (fp == NULL) {
		fp = fopen("nand.txt", "w");
		for (int i = 0; i < 100; ++i) {
			fputs("0x00000000", fp);
		}
		fclose(fp);
		fp = fopen("nand.txt", "r");
	}
	fseek(fp, 10 * address, SEEK_SET);
	fread(buffer, 10, 1, fp);
	fclose(fp);

	fp = fopen("result.txt", "w");
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, buffer);

	fclose(fp);

}