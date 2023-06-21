#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
vector<bool> vis;
vector<vector<int>> adj;

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

struct Edge
{
    int u, v;
};


void connected_components(int p[], int V, vector<vector<int>> edges)
{
    /// implement this
    for(int i=0; i<N; i++)
    {
        make_set(i);
    }
    for(auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)
        {
            continue;
        }
        else
        {
            //cout <<u<<" -- "<<v<<endl;
            //cost+=w;
            //c[count_]=w;
            //count_++;

            union_sets(u,v);
        }

    }
}

bool same_component(int p[], int u, int v)
{
    /// implement this
    if(find_set(u)==find_set(v))
        return true;
    else
        return false;
}

int main()
{
    /// This code is for an undirected graph

    int V, E;
    /// take the number of vertices V and
    /// the number of edges E as input from user
    ///...
    cin >> V >> E;
    adj = vector<vector<int>> (V);
    vis = vector<bool>(V,0);

    /// take the E edges as input from the user
    vector<vector<int>> edges;
    for (int i=0; i<E; i++)
    {
        ///...
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    /// create the parent array for a disjoint set of V elements
    int p[V];

    /// call the function connected_components
    connected_components(p, V, edges);


    while(1)
    {
        /// take an integer "option" as input.
        int option;
        ///...
        cin >> option;

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1)
        {
            ///...
            int x;
            cin >> x;

            if(x >= 0 && x < N)
            {
                cout << x << " is an element of the disjoint set" << endl;
                int root = find_set(x);
                cout << "Root of "<< x << " is : "<< root << endl;
            }
            else
                cout << x << " is not an element of the disjoint set" << endl;


        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print whether they belong to the
        /// same connected component or not
        else if (option==2)
        {
            ///...
            int x,y;
            cin >> x >> y;

            if((x >= 0 && x < N) && (y >= 0 && y < N))
            {
                //cout << x << " and " << y << " is an element of the disjoint set" << endl;
                if(same_component(p,x,y)==true)
                    cout << x << " and " << y <<" are in the same component" << endl;
                else
                    cout << x << " and " << y <<" are not in the same component" << endl;
            }
            else
                cout << x << " and " << y << " is not an element of the disjoint set" << endl;

        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print if there is a path from x to y or not.
        else if (option==3)
        {
            ///...
            int x,y;
            cin >> x >> y;

            if((x >= 0 && x < N) && (y >= 0 && y < N))
            {
                //cout << x << " and " << y << " is an element of the disjoint set" << endl;
                if(find_set(x)==find_set(y))
                    cout << "there is a path between " << x << " and " << y << endl;
                else
                    cout << "there is no path between " << x << " and " << y << endl;
            }
            else
                cout << x << " and " << y << " is not an element of the disjoint set" << endl;

        }

        /// if "option" is 4, print all the roots of this disjoint set
        else if (option==4)
        {
            ///...
            for(int i=0; i<N; i++)
            {
                cout << find_set(i) << " ";
            }
            cout << endl;
        }

        /// if "option" is 5, print the vertices of each connected components
        /// in each line
        else if (option==5)
        {
            ///...
            /// 0 1 5
            /// 2 3
            /// 4
            for(int i=0; i<E; i++)
            {

            }
        }

        else
        {
            return 0;
        }
    }

}

