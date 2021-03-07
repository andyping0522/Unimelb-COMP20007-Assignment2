/* * * * * * *
 * Hashing module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Jiachen Ping
 */

#include "hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Implements a solution to Problem 1 (a), which reads in from stdin:
//   N M
//   str_1
//   str_2
//   ...
//   str_N
// And outputs (to stdout) the hash values of the N strings 1 per line.
void problem_1_a(){
  int N = 0, M = 0, hash_val = 0;
  char s[MAX_INPUT + 1];
  scanf("%d %d\n", &N, &M);
  while (scanf("%s\n", s) == 1){
    // read strings line by line
    hash_val = get_hash(s, M);
    printf("%d\n", hash_val);
  }
}


int get_hash(char* s, int M){
  int hash_val = 0, i, chrVal = 0, base = BASE_NUM;
  for(i=0; i<MAX_INPUT; i++){
    // manually add \0 for strcmp
    char f[2];
    f[0] = s[i];
    f[1] = '\0';
    // terminate if end of string
    if (s[i] == '\0'){
      break;
    }
    chrVal = get_chrVal(f);
    // formula derived from Horner's Method
    hash_val = (hash_val*base+chrVal) % M;
  }
  return hash_val;
}


int get_chrVal(char *c){
  // determine chr(c)
  if(strcmp(c, "a") == 0){
    return LOWER_A;
  }else if(strcmp(c, "b") == 0){
    return LOWER_B;
  }else if(strcmp(c, "c") == 0){
    return LOWER_C;
  }else if(strcmp(c, "d") == 0){
    return LOWER_D;
  }else if(strcmp(c, "e") == 0){
    return LOWER_E;
  }else if(strcmp(c, "f") == 0){
    return LOWER_F;
  }else if(strcmp(c, "g") == 0){
    return LOWER_G;
  }else if(strcmp(c, "h") == 0){
    return LOWER_H;
  }else if(strcmp(c, "i") == 0){
    return LOWER_I;
  }else if(strcmp(c, "j") == 0){
    return LOWER_J;
  }else if(strcmp(c, "k") == 0){
    return LOWER_K;
  }else if(strcmp(c, "l") == 0){
    return LOWER_L;
  }else if(strcmp(c, "m") == 0){
    return LOWER_M;
  }else if(strcmp(c, "n") == 0){
    return LOWER_N;
  }else if(strcmp(c, "o") == 0){
    return LOWER_O;
  }else if(strcmp(c, "p") == 0){
    return LOWER_P;
  }else if(strcmp(c, "q") == 0){
    return LOWER_Q;
  }else if(strcmp(c, "r") == 0){
    return LOWER_R;
  }else if(strcmp(c, "s") == 0){
    return LOWER_S;
  }else if(strcmp(c, "t") == 0){
    return LOWER_T;
  }else if(strcmp(c, "u") == 0){
    return LOWER_U;
  }else if(strcmp(c, "v") == 0){
    return LOWER_V;
  }else if(strcmp(c, "w") == 0){
    return LOWER_W;
  }else if(strcmp(c, "x") == 0){
    return LOWER_X;
  }else if(strcmp(c, "y") == 0){
    return LOWER_Y;
  }else if(strcmp(c, "z") == 0){
    return LOWER_Z;
  }else if(strcmp(c, "A") == 0){
    return UPPER_A;
  }else if(strcmp(c, "B") == 0){
    return UPPER_B;
  }else if(strcmp(c, "C") == 0){
    return UPPER_C;
  }else if(strcmp(c, "D") == 0){
    return UPPER_D;
  }else if(strcmp(c, "E") == 0){
    return UPPER_E;
  }else if(strcmp(c, "F") == 0){
    return UPPER_F;
  }else if(strcmp(c, "G") == 0){
    return UPPER_G;
  }else if(strcmp(c, "H") == 0){
    return UPPER_H;
  }else if(strcmp(c, "I") == 0){
    return UPPER_I;
  }else if(strcmp(c, "J") == 0){
    return UPPER_J;
  }else if(strcmp(c, "K") == 0){
    return UPPER_K;
  }else if(strcmp(c, "L") == 0){
    return UPPER_L;
  }else if(strcmp(c, "M") == 0){
    return UPPER_M;
  }else if(strcmp(c, "N") == 0){
    return UPPER_N;
  }else if(strcmp(c, "O") == 0){
    return UPPER_O;
  }else if(strcmp(c, "P") == 0){
    return UPPER_P;
  }else if(strcmp(c, "Q") == 0){
    return UPPER_Q;
  }else if(strcmp(c, "R") == 0){
    return UPPER_R;
  }else if(strcmp(c, "S") == 0){
    return UPPER_S;
  }else if(strcmp(c, "T") == 0){
    return UPPER_T;
  }else if(strcmp(c, "U") == 0){
    return UPPER_U;
  }else if(strcmp(c, "V") == 0){
    return UPPER_V;
  }else if(strcmp(c, "W") == 0){
    return UPPER_W;
  }else if(strcmp(c, "X") == 0){
    return UPPER_X;
  }else if(strcmp(c, "Y") == 0){
    return UPPER_Y;
  }else if(strcmp(c, "Z") == 0){
    return UPPER_Z;
  }else if(strcmp(c, "0") == 0){
    return ZERO;
  }else if(strcmp(c, "1") == 0){
    return ONE;
  }else if(strcmp(c, "2") == 0){
    return TWO;
  }else if(strcmp(c, "3") == 0){
    return THREE;
  }else if(strcmp(c, "4") == 0){
    return FOUR;
  }else if(strcmp(c, "5") == 0){
    return FIVE;
  }else if(strcmp(c, "6") == 0){
    return SIX;
  }else if(strcmp(c, "7") == 0){
    return SEVEN;
  }else if(strcmp(c, "8") == 0){
    return EIGHT;
  }else if(strcmp(c, "9") == 0){
    return NINE;
  }
  return 0;
}





// Implements a solution to Problem 1 (b), which reads in from stdin:
//   N M K
//   str_1
//   str_2
//   ...
//   str_N
// Each string is inputed (in the given order) into a hash table with size
// M. The collision resolution strategy must be linear probing with step
// size K. If an element cannot be inserted then the table size should be
// doubled and all elements should be re-hashed (in index order) before
// the element is re-inserted.
//
// This function must output the state of the hash table after all insertions
// are performed, in the following format
//   0: str_k
//   1:
//   2: str_l
//   3: str_p
//   4:
//   ...
//   (M-2): str_q
//   (M-1):
void problem_1_b(){
  int N = 0, M = 0, K = 0;
  scanf("%d %d %d\n", &N, &M, &K);
  char **table; // create and initialise hash table
  table = (char**)malloc(M*sizeof(char*));
  assert(table);
  initialise_table(table, M);
  hash_table(table, N, &M, K);
  return;
  free_table(table, M);
  table = NULL;
}

void hash_table(char** table, int N, int *M, int K){
  int hash_val = 0, count = 0;
  char s[MAX_INPUT + 1];
  while (scanf("%s\n", s) == 1){
    hash_val = get_hash(s, *M);
    if (table[hash_val] == NULL){
      // the entry is empty
      table[hash_val] = (char*)malloc((strlen(s)+1)*sizeof(char));
      strcpy(table[hash_val], s);
    }else{
      // collision
      hash_val = find_emptySlot(table, hash_val, *M-1, K);
      if(hash_val != -1){ 
        // solved by linear probing
        table[hash_val] = (char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(table[hash_val], s);
      }else{
        // rehash
      *M = *M*2;
      table = (char**)realloc(table, *M*sizeof(char*));
      rehash(table, *M, K, count, s);
      }
    }
    count++;
  }
  print_table(table, *M);
}

void initialise_table(char** table, int size){
  // set all entries to NULL
  int i;
  for (i=0; i<size; i++){
    table[i] = NULL;
  }
  return;
}

int find_emptySlot(char **table, int initial_hash, int size, int k){
  // find next avaliable position for the string by linear probing
  int i = 0, start_position = 0;
  if (initial_hash + k> size){
    // need to revisit the array
    start_position = -1+(k -(size - initial_hash));
  }else{
    start_position = k + initial_hash;
  }
  i = start_position;
  while(i != initial_hash){
    if(table[i] == NULL){
      // found
      return i;
    }
    if(i + k >size){
      i = -1+(k - (size - i));
    }else{
      i = i + k;
    }
  }
  return -1; // not found, need rehash
}

void rehash(char **table, int M, int K, int count, char* s){
  // rehash existing elements
  int i, hash_val = 0, j = 0;
  char **temp;
  temp = (char**)malloc((count+1)*sizeof(char*));
  assert(temp);
  for (i=0; i<=M/2; i++){
    // store existing elements to a temporary table
    if(i == M/2){
      // insert the last one that did not fit in the original table
      temp[j] = (char*)malloc((strlen(s) + 1 )*sizeof(char));
      strcpy(temp[j], s);
      break;
    }
    if(table[i] != NULL){
      temp[j] = (char*)malloc((strlen(table[i]) + 1 )*sizeof(char));
      strcpy(temp[j], table[i]);
      free(table[i]);
      j++;
    }
    
  }
  initialise_table(table, M);
  for(j=0; j<count+1; j++){
    // find new hash value and deal with collisions by linear probing
    hash_val = get_hash(temp[j], M);
    if(table[hash_val] != NULL){
      hash_val = find_emptySlot(table, hash_val, M - 1, K);
    }
    table[hash_val] = (char*)malloc((strlen(temp[j]) + 1 )*sizeof(char));
    assert(table[hash_val]);
    strcpy(table[hash_val], temp[j]);
    free(temp[j]);
    temp[j] = NULL;
  }
  free(temp);
  temp = NULL;
  return;
}

void print_table(char** table, int size){
  // print the output
  int i;
  for(i=0; i<size; i++){
    printf("%d: ", i);
    if(table[i] == NULL){
      printf("\n");
    }else{
      printf("%s\n", table[i]);
    }
  }
  return;
}

void free_table(char** table, int size){
  int i;
  for(i=0; i<size; i++){
    if(table[i] !=  NULL){

      free(table[i]);
    }
  }
  free(table);
  return;
}