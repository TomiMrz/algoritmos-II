#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}
static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}
unsigned int data_from_file(const char *path,unsigned int indexes[],char letters[],unsigned int max_size){
    FILE *p;
    unsigned int i = 0;
    unsigned int l;
    p = fopen(path, "r");
    while (!feof(p) && i < max_size)
    {
        fscanf(p, "%u '%c'\n", &indexes[i], &letters[i]);
        //fscanf(p, "%u\n", &indexes[i]);
        //fscanf(p, "%*c%c%*c\n", &letters[i]);
        i++;
    }
    l = i;
    fclose(p);
    return l;
  }
int main(int argc, char *argv[]) {
    char *filepath = NULL;
    //FILE *file;
    filepath = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    printf("%u\n", length);
    // dump(indexes,length);
    dump(letters,length);
    for (unsigned int j = 0; j < length; ++j) {
        unsigned int pos = indexes[j];
        sorted[pos] = letters[j];
    }
    dump(sorted, length);
    return EXIT_SUCCESS;
}
