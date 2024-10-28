#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *history = init_history();
  printf("Welcome to my Tokenizer type H for history !# for history index and Q for quit\n");
  printf("Type anything bellow glhf!\n");
  

  while(1){
    char userInput[1000];

    printf("> ");
    fgets(userInput,100,stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    if(userInput[0] == 'Q' && strlen(userInput) == 1){
      break;

    }else if(userInput[0] == '!'){
      int indexId = 0;

      for(int i =1;i<strlen(userInput);i++){
        indexId *= 10;
        indexId += (userInput[i] - '0');
      }
      printf("%s\n",get_history(history,indexId));

    }else if(userInput[0] == 'H'){

      print_history(history);

    }

    add_history(history,userInput);

  }
  free_history(history);
  return 0;
}
