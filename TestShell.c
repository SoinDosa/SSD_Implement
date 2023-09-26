#include <stdio.h>
#include <stdlib.h>

char comm[10];
int address;
char values[11];
char buffer[11];

void write(int address, char values[11]) {
	char str[100];

	sprintf(str, "./ssd W %d %s", address, values);
	system(str);
}

void read(int address) {
	char str[100];

	sprintf(str, "./ssd R %d", address);
	system(str);

	FILE* fp = fopen("./result.txt", "r");
	fread(buffer, 10, 1, fp);
	fclose(fp);

	printf("%s\n", buffer);
}

void fullwrite(char values[11]) {
	char str[100];

	for (int i = 0; i < 100; i++) {
		sprintf(str, "./ssd W %d %s", i, values);
		system(str);
	}
}

void fullread() {
	char str[100];

	for (int i = 0; i < 100; i++) {
		sprintf(str, "./ssd R %d", i);
		system(str);

		FILE* fp = fopen("./result.txt", "r");
		fread(buffer, 10, 1, fp);
		fclose(fp);
		printf("%s\n", buffer);
	}
}

void testapp1() {
	fullwrite("0X67891234");
	fullread();
}

void testapp2() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j <= 5; j++) {
			write(j, "0XAAAABBBB");
		}
	}

	for (int i = 0; i <= 5; i++) {
		write(i, "0X12345678");
	}

	for (int i = 0; i <= 5; i++) {
		read(i);
	}
}

int main() {
	while (1) {
		printf(">> ");
		scanf("%s", comm);

		if (!strcmp(comm, "write")) {
			scanf("%d %s", &address, values);
			write(address, values);
		}
		else if (!strcmp(comm, "read")) {
			scanf("%d", &address);
			read(address);
		}
		else if (!strcmp(comm, "exit")) {
			break;
		}
		else if (!strcmp(comm, "help")) {
			printf("write [address] [values] : write value at a specific address\n");
			printf("read [address] : read value at a specific address\n");
			printf("fullwrite [values] : write value at all addresses\n");
			printf("fullread : read values at all addresses\n");
			printf("exit : exit shell\n");
		}
		else if (!strcmp(comm, "fullwrite")) {
			scanf("%s", values);
			fullwrite(values);
		}
		else if (!strcmp(comm, "fullread")) {
			fullread();
		}
		else if (!strcmp(comm, "testapp1")) {
			testapp1();
		}
		else if (!strcmp(comm, "testapp2")) {
			testapp2();
		}
	}

	return 0;
}
