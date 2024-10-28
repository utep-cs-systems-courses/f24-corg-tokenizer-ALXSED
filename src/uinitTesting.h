#include <stdio.h>
#include "tokenizer.h"

int UnitTest(){

  char testToken[] = "   yes no maby so";
  char testNoToken[] = "";
  char* ptrToken = &testToken;
  char* ptrNoToken = &testNoToken;
  


  printf("TOKENIZER UNIT TESTING");

  printf("Space_char Test\n");
  printf("input ' ' expected result: 0 Result: %d \n", space_char(' '));
  printf("input 'a' expected result: 1 Result: %d \n", space_char('a'));
  printf("\n");

  printf("non_space_char Test\n");
  printf("input ' ' expected result: 1 Result: %d \n",non_space_char(' '));
  printf("input 'a' expected reslut: 0 Result: %d \n",non_space_char('a'));
  printf("\n");

  printf("token_start Test\n");
  printf("input '   yes no maby so' expected result: 'y' Result: %c ",token_start&(ptrToken));
  printf("input '' expected result: '' Result: %c",token_start(&ptrNoToken));
  printf("\n");

  printf("token_terminator Test");
  printf("input '   yes no maby so' expected result: ' ''n' Result: %c %c",token_terminator&(ptrtoken));
  printf("input '' expected result: '' Result: %c", token_terminator(&ptrNoToken));
  print("\n");

  printf("count_tokens Test\n");
  printf("input '   yes no maby so' expected result: 4 Result: %d", count_tokens(&ptrToken));
  printf("input '' expected results: 0 Results: %d", count_tokesn&(ptrNoToken));
  printf("\n");


  char* ptrPtrToken = &copy_str(&ptrToken,) 
  printf("copy_str Test\n");
  printf("input '   yes no maby so' expected result: 'yes' Result: );
  for(i=0;i<len(ptrPtrToken);i++){
    printf("%c",ptrPtrToken[i]);
  }
  printf("\n");

  
}
