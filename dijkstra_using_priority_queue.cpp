/*
 * dijkstra's algorithm using priority queue
 */
 #include <iostream>
 #include <cstdio>
 #include <set>
 #include <vector>
 #include <utility>
 #include <list>
 #include <cstring>
 #include <string>
 #include <queue>
 using namespace std;
 #define N 1000

class point{
public:
	int node;
	int val;
};

class my_cmp{
public:
	bool operator()(const point &a, const point &b){
		return a.val>b.val;
	};
};

vector<point> graph[N];
int mat[N];
bool taken[N];
priority_queue<point, vector<point>, my_cmp> pq;

void init_dijkstra(){
	memset(mat, -1, sizeof(mat));
	memset(taken, 0, sizeof(taken));
}

void add_edge(int src, int dest, int wt){
	point p;
	p.node = dest;
	p.val = wt;
	graph[src].push_back(p);
	p.node = src;
	graph[dest].push_back(p);
}

void dijkstra(int src){
	point p,q,r;

	mat[src] = 0;
	p.node = src;
	p.val = 0;
	pq.push(p);
	while(!pq.empty()){
		p = pq.top();
		pq.pop();

		if(taken[p.node] == false){
			taken[p.node] = true;

			for(int i=0; i<graph[p.node].size(); i++){
				q = graph[p.node][i];
				if(mat[q.node] == -1){
					mat[q.node] = mat[p.node] + q.val;
					r.node = q.node;
					r.val = mat[q.node];
					pq.push(r);
				}else if(mat[q.node]>mat[p.node]+q.val){
					mat[q.node] = mat[p.node] + q.val;
					r.node = q.node;
					r.val = mat[q.node];
					pq.push(r);
				}
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
