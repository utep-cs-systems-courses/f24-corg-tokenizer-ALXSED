#include <stdio.h>
#include "tokenizer.h"

int main(){
  printf("Welcome to my Tokenizer type t for unit testing and q for quit\n");
  printf("Type anything bellow glhf!\n");

  while(1){
    char userInput[100];
    printf("> ");
    fgets(userInput,100,stdin);

    if(userInput[0] == 'Q'){
      return 0;
    }

    printf("%s",userInput);
  }

  return 0;
}
