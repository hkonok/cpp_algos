/*
 * Longest increasing subsequence using binary indexed tree
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

 int arr[N];
 int bit[MAX_VAL];
 /*
  * if values are very big user sorted values and map
  *
  */
 int L;
 int n;

 void init(){
 	L=0;
 	memset(bit, 0, sizeof(bit));
 }

 int get_bit(int index){
 	int res = 0;
 	while(index){
 		if(bit[index]>res){
 			res = bit[index];
 		}
 		index ^= (index&(-index));
 	}

 	return res;
 }

 void set_bit(int index, int val){
 	while(index < MAX_VAL){
 		if(bit[index]<val){
 			bit[index] = val;
 		}
 		index += (index&(-index));
 	}
 }

 int lis(){
 	int index, cur_lcs;
 	for(int i=1; i<=n; i++){
 		cur_lcs = get_bit(arr[i]-1);
 		set_bit(arr[i], cur_lcs+1);
 	}

 	L = get_bit(MAX_VAL-1);

 	return L;
 }


 int main(){
 	cin>>n;
 	init();
 	for(int i=1; i<=n; i++){
 		cin>>arr[i];
 	}
 	cout<<lis()<<endl;

 	return 0;
 }
