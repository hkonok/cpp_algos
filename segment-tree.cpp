/*
 * segment tree algorithm
 */
#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 #include <algorithm>
 using namespace std;
 #define N 100000
 #define MAX_VAL 1000000

 class st_node{
 public:
 	int val;
 	st_node *left, *right;
 };

st_node *root;

void st_init(int start, int end, int val, st_node *node){
	node->val = val;
	if(start == end){
		node->left = NULL;
		node->right = NULL;
	}
	node->left = new st_init();
	node->right = new st_init();


}