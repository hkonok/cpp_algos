/*
 * knuth morris pratt algorithm
 */
 #include <cstdio>
 #include <iostream>
 #include <cstdlib>
 using namespace std;
 #define N 100000

 char arr[N];
 int p[N];

 void pre_kmp(char *arr){
 	int L=0;
 	p[0] = -1;
 	for(int i=1; arr[i]; i++){
 		while(L>=0 && arr[L]!= arr[i]){
 			L = p[L];
 		}
 		L++;
 		p[i] = L;
 	}
 }

 void kmp(char *arr, char *inp){

 }

 int main(){
 	cin>>arr;
 	return 0;
 }
