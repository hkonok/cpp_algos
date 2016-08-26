/*
 * knuth morris pratt algorithm
 */
 #include <cstdio>
 #include <iostream>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 using namespace std;
 #define N 100000

 char arr[N];
 int p[N];

 void pre_kmp(char *arr){
 	int L=-1;
 	p[0] = -1;
 	for(int i=1; arr[i]; i++){
 		while(L>=0 && arr[L+1]!=arr[i]){
 			L = p[L];
 		}

 		if(arr[L+1] == arr[i]){
            L++;
            p[i] = L;
 		}else{
            p[i] = L;
 		}
 	}
 }

 void kmp(char *inp, char *arr, int len){

 	int L=-1;
 	for(int i=0; inp[i]; i++){
 		while(L>=0 && arr[L+1]!=inp[i]){
 			L = p[L];
 		}

 		if(arr[L+1] == inp[i]){
            L++;
 		}

 		if(L==(len-1)){
 			cout<<"pos: "<<i<<endl;
 			for(int j=i-len+1; j<=i; j++){
 				cout<<inp[j];
 			}
 			cout<<endl;
 			L = p[L];
 		}

 	}
 }

 int main(){
 	char inp[N];
 	cin>>arr;
 	cin>>inp;



 	pre_kmp(arr);

    for(int i=0; arr[i]; i++){
        cout<<arr[i]<<" ";
 	}
 	cout<<endl;
 	for(int i=0; arr[i]; i++){
        cout<<p[i]<<" ";
 	}
 	cout<<endl;


 	kmp(inp, arr, strlen(arr));
 	return 0;
 }
