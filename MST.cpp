int n,m;
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> edges;

struct ds
{
    int id,members;
}parent[N];

int find(int u)
{
    if(u==parent[u].id) return u;
    return parent[u].id=find(parent[u].id);
}

void unioN(int x,int y)
{
    x=find(x);
    y=find(y);
    
    if(parent[x].members < parent[y].members)
    {
        parent[x].id=parent[y].id;
        parent[y].members+=parent[x].members;
    }
    else
    {
        parent[y].id=parent[x].id;
        parent[x].members+=parent[y].members;
    }
}

int mst()
{
    int e=0;

    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
    }

    while(e<n-1)
    {
        auto edge=edges.top();
        edges.pop();

        int set1=edge.s.f;
        int set2=edge.s.s;

        if(find(set1)!=find(set2))
        {
            e++;
            ans+=edge.f;
            unioN(set1,set2);
        }
    }

    return ans;
}