#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void  make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for(int i=0; i<N; i++)
    {
        make_set(i);
    }

    int V,E;
    cin>>V>>E;

    vector<vector<int>> edges;
    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());

    int cost =0;
    int c[E];
    int count_=0;

    cout << "MST" << endl;
    for(auto i:edges)
    {
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)
        {
            continue;
        }
        else
        {
            cout <<u<<" -- "<<v<<endl;
            cost+=w;
            c[count_]=w;
            count_++;

            union_sets(u,v);
        }

    }
    cout << "Weight: ";
    for(int i=0; i<count_; i++)
    {
        cout<<c[i];
        if(i!=count_-1)
            cout<<"+";
    }
    cout << " = " <<cost;
}
