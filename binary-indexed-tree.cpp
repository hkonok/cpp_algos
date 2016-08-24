/*
 * binary-indexed-tree algorithm
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 #include <algorithm>
 using namespace std;
 #define N 100000
 int bit[N];

 void init(){
 	fill(bit, bit+N, 0);
 }

 void set(int index, int val){
 	while(index < N){
 		bit[index] += val;
 		index = (index + (index&(-index)));
 	}
 }

 int get(int index){
 	int res = 0;
 	while(index){
 		res +=bit[index];
 		index ^= (index&(-index));
 	}

 	return res;
 }


 int main(){
 	int a,b;
 	init();
 	for(int i=1; i<=10; i++){
 		set(i, i);
 		cout<<get(i)<<endl;
 	}
 	
 	return 0;
 }

