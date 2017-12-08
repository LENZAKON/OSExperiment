#include <stdio.h>
#define MAX_LINE 1024

int main() {

    FILE *pFile = fopen("/home/linzikang/code/code/os/readFile/data", "r");

//    char strLine[MAX_LINE];

//    while (!feof(pFile)){
//        fgets(strLine, MAX_LINE,pFile);
//        printf("%s", strLine);
//    }

    char data[15][MAX_LINE];

    for (int i = 0; i < 15; i++) {
        fscanf(pFile, "%s", data[i]);
        printf("%s\n", data[i]);
    }



    return 0;
}