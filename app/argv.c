#include <stdio.h>

int main(int argc, char const *argv[])
{
    if(argc < 2){
        printf("Missing command line argument.\n");
        return 1;
    }
    else if (argc > 2){
        printf("To many command line arguments.\n");
        return 2;
    }
    
    printf("Hello, %s\n", argv[1]);
    return 0;
}
