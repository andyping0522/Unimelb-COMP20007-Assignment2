#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>




int main(int argc, char **argv){
  int N = 0, M = 0, i = 0, j,f;
  char s[256];
  scanf("%d %d\n", &N, &M);
  char **table;
  table = (char**)malloc((N)*sizeof(char*));
  assert(table);
  for (f=0; f<N; f++){
      if(table[i]==NULL){
          printf("dd");
      }
  }
  while (scanf("%s\n", s) == 1){    
    table[i] = (char*)malloc((strlen(s)+1)*sizeof(char));
    assert(table[i]);
    strcpy(table[i], s);
    i++;
  }
  for (j=0; j<N; j++){
    printf("j = %d, %s\n", j, table[j]);
      
    table[j] = NULL;
  }
  free(table);
  return 0;
}


  