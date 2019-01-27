#include "getWord.h"

int main(int argc, char const *argv[])
{
    if(argc < 2){
        printf("No File provided for reading\n");
        return 1; 
    }

    FILE *fd = fopen(argv[1], "r");

    if(fd == 0)
    {
        printf("Unable to open the file\n");
    }

    char *word = "Start";

    while(word != NULL){
        word = getNextWord(fd);
    }
    

    return 0;
}
