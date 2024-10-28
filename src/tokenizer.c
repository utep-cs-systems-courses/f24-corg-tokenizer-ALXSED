#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return 1;
  }
  return 0;
}


/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c != '\0' && c != '\t' && c != ' '){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  while(space_char(*str)){
    str++;
    if(*str == '\0'){
      return NULL;
    }
  }


  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  if(*token == '\0'){
    return NULL;
  }

  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  while(*str != '\0'){
    char *start = token_start(str);

    if(start == NULL){
      break;
    }
    count++;
    char *end = token_terminator(start);

    if(end != NULL){
      str = end;
    }else{
      break;
    }
    
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newStr = (char*) malloc(len + 1);

  for(int i = 0;i < len;i++){
    newStr[i] = inStr[i];

  }
  newStr[len] = '\0';

  return newStr;

}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int count  = count_tokens(str);
  int token_length;
  char **tokens = (char **)malloc((count + 1) * sizeof(char *));
  

  for (int i = 0; i < count; i++) {

    char *start = token_start(str);
        
    char *end = token_terminator(start);

    if (end != NULL) {
      token_length = end - start;
    } else {
      token_length = strlen(start);
    }
        
    tokens[i] = copy_str(start, token_length);

    if (end != NULL) {
        str = end;
    } else {
        break;
    }
  }


  tokens[count] = NULL;

  return tokens;

}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
    
  while (tokens[i] != NULL) {
    printf("Token %d: %s\n", i, tokens[i]);
    i++;
  }

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i = 0;
    
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

