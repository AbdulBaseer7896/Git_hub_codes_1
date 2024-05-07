#include<iostream>
#include<cstring>
#include<queue>

const int N=10010;

struct Node{
    int to,cost;
    Node*next;
    Node(int t, int c) : to(t), cost(c) {}
};

Node *adj[N];
int dist[N];
bool used[N];
int V,E;
int head[N],cnt;

void add(int from, int to, int cost){
    adj[++cnt]=new Node(to, cost);
    adj[cnt]->next=head[from];
    head[from]=cnt;
}

struct HeapNode{
    int v,c;
    bool operator < (const HeapNode &x) const{
        return c > x.c;
    }
};

void dijkstra(int s){
    priority_queue<HeapNode> q;
    memset(dist,0x3f,sizeof dist);
    memset(used,0,sizeof used);
    dist[s]=0;
    q.push((HeapNode){s,0});

    while(q.size()){
        HeapNode p=q.top();
        q.pop();
        int v=p.v;
        if(used[v])continue;
        used[v]=true;

        for(int i=head[v];i;i=adj[i].next){
            int u=adj[i].to,c=adj[i].cost;
            if(dist[u]>dist[v]+c){
                dist[u]=dist[v]+c;
                q.push((HeapNode){u,dist[u]});
            }
        }
    }
}

int main(){
    cin>>V>>E;
    int s,t,c;
    for(int i=0;i<E;i++){
        cin>>s>>t>>c;
        add(s,t,c);
    }
    int start;
    cin>>start;
    dijkstra(start);

    for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}

