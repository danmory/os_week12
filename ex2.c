#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int optionCount = 0;
    if (argc > 1 && argv[1] == "-a"){
        optionCount = 1;
    }
    int fileCount = argc - optionCount - 1;
    FILE **files = malloc(fileCount * sizeof(FILE));
    char *mode;
    if (optionCount){
        mode = "a";
    }else{
        mode = "w";
    } 
    for (int i = 0; i < fileCount; ++i)
        files[i] = fopen(argv[i + optionCount + 1], mode);
    char buf[256];
    while (fgets(buf, 255, stdin)) {
        printf("%s", buf);
        for (int i = 0; i < fileCount; ++i)
            fprintf(files[i], "%s", buf);
    }
    for (int i = 0; i < fileCount; ++i)
        fclose(files[i]);
    free(files);
}