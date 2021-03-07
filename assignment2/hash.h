/* * * * * * *
 * Hashing module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#ifndef HASH_H
#define HASH_H

#define MAX_INPUT 256
#define BASE_NUM 64
#define LOWER_A 0
#define LOWER_B 1
#define LOWER_C 2
#define LOWER_D 3
#define LOWER_E 4
#define LOWER_F 5
#define LOWER_G 6
#define LOWER_H 7
#define LOWER_I 8
#define LOWER_J 9
#define LOWER_K 10
#define LOWER_L 11
#define LOWER_M 12
#define LOWER_N 13
#define LOWER_O 14
#define LOWER_P 15
#define LOWER_Q 16
#define LOWER_R 17
#define LOWER_S 18
#define LOWER_T 19
#define LOWER_U 20
#define LOWER_V 21
#define LOWER_W 22
#define LOWER_X 23
#define LOWER_Y 24
#define LOWER_Z 25
#define UPPER_A 26
#define UPPER_B 27
#define UPPER_C 28
#define UPPER_D 29
#define UPPER_E 30
#define UPPER_F 31
#define UPPER_G 32
#define UPPER_H 33
#define UPPER_I 34
#define UPPER_J 35
#define UPPER_K 36
#define UPPER_L 37
#define UPPER_M 38
#define UPPER_N 39
#define UPPER_O 40
#define UPPER_P 41
#define UPPER_Q 42
#define UPPER_R 43
#define UPPER_S 44
#define UPPER_T 45
#define UPPER_U 46
#define UPPER_V 47
#define UPPER_W 48
#define UPPER_X 49
#define UPPER_Y 50
#define UPPER_Z 51
#define ZERO 52
#define ONE 53
#define TWO 54
#define THREE 55
#define FOUR 56
#define FIVE 57
#define SIX 58
#define SEVEN 59
#define EIGHT 60
#define NINE 61


// Implements a solution to Problem 1 (a), which reads in from stdin:
//   N M
//   str_1
//   str_2
//   ...
//   str_N
// And outputs (to stdout) the hash values of the N strings 1 per line.
void problem_1_a();
int get_chrVal(char *c);
int get_hash(char* s, int M);
void initialise_table(char** table, int size);
void rehash(char **table, int M, int K, int count, char* s);
int find_emptySlot(char **table, int initial_hash, int size, int k);
void free_table(char** table, int size);
void print_table(char** table, int size);
void hash_table(char** table, int N, int *M, int K);
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
void problem_1_b();

#endif
