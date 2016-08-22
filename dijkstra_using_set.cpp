/*
 * dijkstra's algorithm using set
 */
 #include <iostream>
 #include <cstdio>
 #include <set>
 #include <vector>
 #include <utility>
 #include <list>
 #include <cstring>
 #include <string>
 using namespace std;
 #define N 1000

list<pair<int,int> > graph[N];
int mat[N];
set<pair<int,int> > pq;

void init_dijkstra(){
	memset(mat, -1, sizeof(mat));
}

void add_edge(int src, int dest, int wt){
	graph[src].push_front(pair<int,int>(dest, wt));
	graph[dest].push_front(pair<int,int>(src, wt));
}

void dijkstra(int src){
	set<pair<int,int> >::iterator it;
	list<pair<int,int> >::iterator i;
	int u,v,wt;
	mat[src] = 0;
	pq.insert(pair<int,int>(0, src));
	while(!pq.empty()){
		it = pq.begin();
		u = it->second;
		pq.erase(it);
		for(i=graph[u].begin(); i!=graph[u].end(); i++){
			v = i->first;
			wt = i->second;
			if(mat[v] == -1){
				mat[v] = mat[u] + wt;
				pq.insert(pair<int,int>(mat[v], v));
			}else if(mat[v]>mat[u]+wt){
				pq.erase(pq.find(pair<int,int>(mat[v],v)));
				mat[v] = mat[u] + wt;
				pq.insert(pair<int,int>(mat[v], v));
			}
		}
	}

	return;
}



int main(){
	int n,m,s;
	cin>>n>>m;
	init_dijkstra();
	while(m--){
		int x,y,r;
		cin>>x>>y>>r;
		add_edge(x, y, r);
	}
	cin>>s;
	dijkstra(s);

	for(int i=0; i<n; i++){
		cout<<mat[i]<<" ";
	}
	cout<<endl;

	return 0;
}
