/* * * * * * *
 * Text Analysis module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H


#define MAX_INPUT 256
#define ALPHABET 26
#define NULL_CHARACTER 0
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11
#define L 12
#define M 13
#define N 14
#define O 15
#define P 16
#define Q 17
#define R 18
#define S 19
#define T 20
#define U 21
#define V 22
#define W 23
#define X 24
#define Y 25
#define Z 26


typedef struct node Node;
typedef struct word_with_prob wwp;
typedef struct trie Trie;

struct node{
    int freq;
    int isLeaf; // 0 if not a leaf, 1 if leaf
    char c[2];
    Node **child;
};

struct trie{
    Node *root;
};

struct word_with_prob{
    char word[MAX_INPUT];
    int freq;
};
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
void problem_2_a();
Node *new_node(char data[2]);
Node **new_node_arr();
void insert_string(Trie *trie, char *s);
void construct_trie(Trie *trie);
Trie *new_trie();
int assign_freq(Node *node);
void print_trie(Node* node);
int get_index(char *c);
void assign_wwps(wwp **arr, Node *node, char buffer[MAX_INPUT + 1], int *index,
int root_freq, int i);
void sort_print_wwp(wwp** array, int size, char *stub, int stub_freq);
void free_wwps(wwp** array, int n);
void initialise_wwp(wwp** array, int n);
void free_trie(Node* node);
Node *search_stub(char *stub, Trie* trie);
void print_freq(Node* node, int i, int k, char buffer[MAX_INPUT + 1]);
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
void problem_2_b();

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
void problem_2_c();

#endif
