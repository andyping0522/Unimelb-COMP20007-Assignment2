/* * * * * * *
 * Text Analysis module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#include "text_analysis.h"
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// Build a character level trie for a given set of words.
//
// The input to your program is an integer N followed by N lines containing
// words of length < 100 characters, containing only lowercase letters.
//
// Your program should built a character level trie where each node indicates
// a single character. Branches should be ordered in alphabetic order.
//
// Your program must output the post-order traversal of the characters in
// the trie, on a single line.
void problem_2_a() {
  Trie* trie = new_trie(); 
  construct_trie(trie); // construct the trie
  Node *node = trie -> root;
  print_trie(node); // print out the result
  free_trie(node);
  free(trie);
  return;
}

void construct_trie(Trie* trie){
  // construct the trie
  int n = 0;
  char s[MAX_INPUT + 1];
  Node *node = trie -> root;
  scanf("%d\n", &n);
  while (scanf("%s\n", s) == 1){
    insert_string(trie, s);
  }
  n = assign_freq(node);
  return;
}


Trie *new_trie(){
  // create an empty trie
  Trie *trie = malloc(sizeof(*trie));
  assert(trie);
  char *c = "^";
  trie -> root = new_node(c);
  assert(trie -> root);
  return trie;
}

Node *new_node(char *data){
  // create a new node
  Node *node = malloc(sizeof(*node));
  node -> child = new_node_arr();
  strcpy(node -> c, data);
  node -> freq = 0;
  node -> isLeaf = 0;
  return node;
}

Node **new_node_arr(){
  /* create a new node array to store child nodes and initialise all pointers
   to NULL */
  int i;
  Node ** arr;
  arr = (Node**)malloc((ALPHABET+1)*sizeof(Node*));
  for (i=0; i<ALPHABET+1; i++){
    arr[i] = NULL;
  }
  return arr;
}

void insert_string(Trie *trie, char *s){
  // insert each string to the trie
  int i = 0, index = 0;
  Node *curr = trie -> root;
  while (i < strlen(s)+1){
    char f[2]; // manually add \0 for strcmp
    if (i < strlen(s)){
      f[0] = s[i];
      f[1] = '\0';
      index = get_index(f); // map the character to an index
    }else{
      index = NULL_CHARACTER; 
      strcpy(f, "$");
    }
    if (curr -> child[index] == NULL){
      // found position
      curr -> child[index] = new_node(f);
    }
    if(index == NULL_CHARACTER){
      // reached the end of string, add frequency and indicate leaf
       curr -> child[index] -> freq ++;
       curr -> child[index] -> isLeaf = 1;
    }
    // move to next node
    curr = curr -> child[index];
    i ++;
  }
  return;
}

int assign_freq(Node *node){
  /* recursive function to assign frequency value to each parent node
  by taking the sum of their children nodes */
  int i, sum = 0;
  if (node == NULL){
    return 0;
  }
  if (node -> isLeaf){
    return node -> freq;
  }
  // not a leaf and has children, sum up all children nodes
  for (i=0; i<ALPHABET+1; i++){
    sum = sum + assign_freq(node -> child[i]);
  }
  node -> freq = sum;
  return sum;
}

void print_trie(Node* node){
  int i;
  /* recursive function to print each character in the trie by using
  pre-order traversal */
  if (node == NULL){
    return;
  }
  printf("%s\n", node -> c);
  for (i=0; i< ALPHABET+1; i++){
    print_trie(node -> child[i]);
  }
  return;
}

void free_trie(Node* node){
  // free allocated memory for each node
  int i;
  if (node == NULL){
    return;
  }
  for (i=0; i< ALPHABET+1; i++){
    free_trie(node-> child[i]);
  }
  free(node);
}

int get_index(char *c){
  // determine chr(c)
  if(strcmp(c, "a") == 0){
    return A;
  }else if(strcmp(c, "b") == 0){
    return B;
  }else if(strcmp(c, "c") == 0){
    return C;
  }else if(strcmp(c, "d") == 0){
    return D;
  }else if(strcmp(c, "e") == 0){
    return E;
  }else if(strcmp(c, "f") == 0){
    return F;
  }else if(strcmp(c, "g") == 0){
    return G;
  }else if(strcmp(c, "h") == 0){
    return H;
  }else if(strcmp(c, "i") == 0){
    return I;
  }else if(strcmp(c, "j") == 0){
    return J;
  }else if(strcmp(c, "k") == 0){
    return K;
  }else if(strcmp(c, "l") == 0){
    return L;
  }else if(strcmp(c, "m") == 0){
    return M;
  }else if(strcmp(c, "n") == 0){
    return N;
  }else if(strcmp(c, "o") == 0){
    return O;
  }else if(strcmp(c, "p") == 0){
    return P;
  }else if(strcmp(c, "q") == 0){
    return Q;
  }else if(strcmp(c, "r") == 0){
    return R;
  }else if(strcmp(c, "s") == 0){
    return S;
  }else if(strcmp(c, "t") == 0){
    return T;
  }else if(strcmp(c, "u") == 0){
    return U;
  }else if(strcmp(c, "v") == 0){
    return V;
  }else if(strcmp(c, "w") == 0){
    return W;
  }else if(strcmp(c, "x") == 0){
    return X;
  }else if(strcmp(c, "y") == 0){
    return Y;
  }else if(strcmp(c, "z") == 0){
    return Z;
  }else if(strcmp(c, "$") == 0){
    return NULL_CHARACTER;
  }
  return -1;
}
// Using the trie constructed in Part (a) this program should output all
// prefixes of length K, in alphabetic order along with their frequencies
// with their frequencies. The input will be:
//   n k
//   str_0
//   ...
//   str_(n-1)
// The output format should be as follows:
//   an 3
//   az 1
//   ba 12
//   ...
//   ye 1
void problem_2_b() {
  Trie* trie = new_trie(); // construct trie
  int n = 0, k = 0, i = 0;
  char s[MAX_INPUT + 1];
  char buffer[MAX_INPUT + 1];
  Node *trie_root = trie -> root;
  scanf("%d %d\n", &n, &k);
  while (scanf("%s\n", s) == 1){
    insert_string(trie, s); // insert string
  }
  n = assign_freq(trie_root); // find all frequencies
  print_freq(trie_root, i, k, buffer); // print out the words with length k
  free_trie(trie_root);
  free(trie);
}


void print_freq(Node* node, int i, int k, char buffer[MAX_INPUT + 1]){
  /* recursive function to output all frequencies of prefix 
  with length k*/
  int j;
  //printf("%s\n", buffer);
  if (node == NULL || node -> isLeaf || i > k){
    return;
  }
  if (i == k){
    // reach the end, clear buffer and print
    buffer[i-1] = 0;
    printf("%s%s %d\n", buffer, node ->c, node -> freq);
    return;
  }
  for (j=1; j<ALPHABET+1; j++){
    if(node -> child[j] != NULL){
      if (i > 0 ){ // ensures "^" in root is ignored
        buffer[i-1] = node -> c[0]; // store the character in the buffer
      }
      print_freq(node -> child[j], i+1, k, buffer);
    }
  }
  return;
}



// Again using the trie data structure you implemented for Part (a) you will
// provide a list (up to 5) of the most probable word completions for a given
// word stub.
//
// For example if the word stub is "al" your program may output:
//   0.50 algorithm
//   0.25 algebra
//   0.13 alright
//   0.06 albert
//   0.03 albania
//
// The probabilities should be formatted to exactly 2 decimal places and
// should be computed according to the following formula, for a word W with the
// prefix S:
//   Pr(word = W | stub = S) = Freq(word = W) / Freq(stub = S)
//
// The input to your program will be the following:
//   n
//   stub
//   str_0
//   ...
//   str_(n-1)
// That is, there are n + 1 strings in total, with the first being the word
// stub.
//
// If there are two strings with the same probability ties should be broken
// alphabetically (with "a" coming before "aa").
void problem_2_c(){
  int n = 0, arr_len = 0, index = 0;
  char stub[MAX_INPUT + 1], s[MAX_INPUT + 1], buffer[MAX_INPUT + 1];
  Trie *trie = new_trie(); // construct trie
  scanf("%d\n", &n);
  scanf("%s\n", stub);
  while(scanf("%s\n", s) == 1){
    insert_string(trie, s); // insert strings
  }
  n = assign_freq(trie -> root);
  Node *prefix = search_stub(stub, trie); // find the where the stub is
  if (prefix != NULL){
    wwp **suffix_array = malloc(n *sizeof(wwp*));
    assert(suffix_array);
    initialise_wwp(suffix_array, n);
    assign_wwps(suffix_array, prefix, buffer, &index, prefix -> freq,
    arr_len); // find all suffixs after stubs
    sort_print_wwp(suffix_array, index, stub, prefix -> freq); // sort and print
    free_wwps(suffix_array, n);
  }
  free_trie(trie -> root);
  free(trie);
  return;
}

Node *search_stub(char *stub, Trie* trie){
  // search a stub in the trie and return its pointer
  int curr_length = 0, length = strlen(stub), j;
  Node *curr = trie -> root;
  char letter[2], stub_letter[2];
  while (curr_length < length){
    // manually add null character for strcmp
    stub_letter[0] = stub[curr_length];
    stub_letter[1] = '\0';
    for (j=1; j < ALPHABET + 1; j++){
      if (curr -> child[j] == NULL){
        continue;
      }
      // compare
      letter[0] = curr -> child[j] -> c[0];
      letter[1] = '\0';
      if(strcmp(stub_letter, letter) == 0){
        // character is a match, increase the level
        curr_length ++;
        if (curr_length == length){
          return curr -> child[j]; // found
        }
        curr = curr -> child[j];
        break;
      }
      // not match, try next node
    }  
  }
  return NULL; // not found
}

void assign_wwps(wwp **arr, Node *node, char buffer[MAX_INPUT + 1], int *index,
int root_freq, int i){
  // find all suffixs and frequencies, store them in an array
  int j;
  if (node == NULL){
    return;
  }
  if (node -> isLeaf){
    // reach the end, clear buffer and store
    buffer[i-1] = 0;
    strcpy(arr[*index] -> word, buffer);
    arr[*index] -> freq = node -> freq ;
    *index = *index + 1;
    return;
  }
  for (j=0; j<ALPHABET+1; j++){
    if(node -> child[j] != NULL){
      // including the root node
      if (i > 0){
        buffer[i-1] = node -> c[0]; 
      }else{
        buffer[i] = node -> c[0];
      }
      assign_wwps(arr, node -> child[j], buffer, index, root_freq, i+1);
    }
  }
  return;
} 


void sort_print_wwp(wwp** array, int size, char *stub, int stub_freq){
  /* implement insertion sort as it preserves the original order
  and does not require extra memory, and print out the result */
  int i, j;
  double prob = 0;
  for (i=1; i < size; i++){
    j = i - 1;
    while (j >= 0 && (array[j+1] -> freq) > (array[j] -> freq)){
      //swap
      wwp *temp;
      temp = array[j+1];
      array[j+1] = array[j];
      array[j] = temp;
      j--;
    }
  }
  // print out the result
  for (i=0; i < 5; i++){
    if(i == size){
      break;
    }
    prob = (double)array[i] -> freq / (double)stub_freq;
    printf("%.2f %s%s\n", prob, stub, array[i] -> word);
  }
  return;
}

void initialise_wwp(wwp** array, int n){
  // initialse the array
  int i;
  for (i=0; i<n; i++){
    array[i] = (wwp*)malloc(sizeof(wwp));
    assert(array[i]);
  }
  return;
}

void free_wwps(wwp** array, int n){
  // free the array
  int i;
  for (i=0; i<n; i++){
    free(array[i]);
  }
  free(array);
}

