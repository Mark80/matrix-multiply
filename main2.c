#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int is_isogram(const char phrase[]){

    if(phrase == NULL)
      return 1;

    int length =  strlen(phrase);
    printf("ciccio %d\n", length);


    for(int i = 0; i < length - 1; i++){
        for(int j= i + 1 ; j < length - 1; j++){
            printf("%dn", phrase[i] );
            printf("%d\n", phrase[j] );

              if(phrase[i] != '-' && phrase[i] == phrase[j])
                  return 0;      
        }
    }
    return 1;
}


int main(int argc, char const *argv[])
{
   
   printf("%lu\n",is_isogram("elev"));
    
}
