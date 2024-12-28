#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <assert.h>
#include "reverse/array_helpers.h"
/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);
    stack_elem a[MAX_SIZE];
    unsigned int length = array_from_file(a, MAX_SIZE, filepath);
    stack s = stack_empty();
    for ( unsigned int i = 0; i < MAX_SIZE; i++)
    {
        s = stack_push(s, 'T');
    }
    stack_elem *locura = stack_to_array(s);
    array_dump(locura, length);
    return 0;
}
