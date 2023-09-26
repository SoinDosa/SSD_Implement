#include <string.h>
#include "read.h"
#include "write.h"

int main(int argc, char* argv[]) {
	if(argc < 3){
		printf("INVALID COMMAND\n");
		return 0;
	}

    if (strcmp(argv[1], "W") != 0 && strcmp(argv[1], "R") != 0)
    {
        printf("INVALID COMMAND\n");
        return 0;
    }

    int id = atoi(argv[2]);
    if (strcmp(argv[1], "W") == 0) {
        if (argc != 4)
        {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (id < 0 || id >= 100) {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (id == 0 && strcmp(argv[2], "0"))
        {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (strlen(argv[3]) > 10) {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (argv[3][0] != '0' || argv[3][1] != 'X')
        {
            printf("INVALID COMMAND\n");
            return 0;
        }

        for (int i = 2; i < 10; i++)
        {
            if (!(('0' <= argv[3][i] && '9' >= argv[3][i]) || ('A' <= argv[3][i] && 'F' >= argv[3][i]))) {
                printf("INVALID COMMAND\n");
                return 0;
            }
        }

        W(atoi(argv[2]), argv[3]);
    }
    else if (strcmp(argv[1], "R") == 0) {
        if (argc != 3)
        {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (id < 0 || id >= 100)
        {
            printf("INVALID COMMAND\n");
            return 0;
        }

        if (id == 0 && strcmp(argv[2], "0")) {
            printf("INVALID COMMAND\n");
            return 0;
        }

        R(atoi(argv[2]));
    }
    return 0;
}
