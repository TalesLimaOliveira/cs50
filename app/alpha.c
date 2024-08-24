#include <stdio.h>

void print_alpha(int n){
    for(int i = 0; i < n; i++){
        printf('%c ', 'a'+i);
    }
}

int main(void){
    for(int i = 0; i < 26; i++){
        print_alpha(i);
    }
    return 0;
}