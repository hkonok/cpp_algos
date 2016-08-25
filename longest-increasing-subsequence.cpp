/*
 * Longest increasing subsequence 
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 #include <algorithm>
 using namespace std;
 #define N 100000
 int arr[N];
 int p[N];
 int L;
 int n;

 void init(){
 	L=0;
 	memset(arr, 0, sizeof(arr));
 	memset(p, 0, sizeof(p));
 }

 int lis_bs(int val){
 	int s=1,e=L,mid;
 	while(s>e){
 		mid = (s+e)/2;
 		if(arr[p[mid]]<val){
 			s = mid + 1;
 		}else if(arr[p[mid]]>val){
 			e = mid - 1;
 		}else{
 			return mid - 1;
 		}
 	}

 	return e;
 }


 int lis(){
 	int index;
 	for(int i=1; i<=n; i++){
 		index = lis_bs(arr[i]);
 		if(index == L){
 			L++;
 			p[L] = i;
 		}else if(arr[p[index+1]]>arr[i]){
 			p[index + 1] = i;
 		}
 	}

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


