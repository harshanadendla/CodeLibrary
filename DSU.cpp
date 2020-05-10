struct DSU
{
    int id,members;
}parent[N];

int find(int u)
{
    if(u==parent[u].id) return u;
    return parent[u].id=find(parent[u].id);
}

void unioN(int a,int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b)
    {
        if(parent[a].members<parent[b].members)
        {
            parent[a].id=parent[b].id;
            parent[b].members+=parent[a].members;
        }
        else
        {
            parent[b].id=parent[a].id;
            parent[a].members+=parent[b].members;
        }
    }
}