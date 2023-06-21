#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+6;
vector<int> sz(n);

/// Final task: implement path compression and union by rank
void make_set(int p[], int x)
{
    p[x] = x;
    sz[x] = 1;
    cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x)
{
    if (x!=p[x])
        return p[x] = find_set(p, p[x]);
    return p[x];
}

void _union(int p[], int x, int y)
{
    int a = find_set(p, x);
    int b = find_set(p, y);
    //p[a] = b;
    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
    cout << "union "<<a << " and "<<b<< endl;
}

int main()
{


    int N;
    /// take N input from user
    cin >> N;

    /// create the parent array for a disjoint set of N elements
    int p[N];
    for (int i=0; i<N; i++)
    {
        make_set(p, i);
    }

    while(1)
    {
        /// take an integer "option" as input.
        int option;
        cin >> option;


        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1)
        {
            int x;
            cin >> x;

            if(x >= 0 && x < N)
            {
                cout << x << " is an element of the disjoint set" << endl;
                int root = find_set(p,x);
                cout << "Root is : "<< root << endl;
            }
            else
                cout << x << " is not an element of the disjoint set" << endl;


        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are check if they belong to the same set or not
        else if (option==2)
        {
            int x,y;
            cin >> x >> y;

            if((x >= 0 && x < N) && (y >= 0 && y < N))
            {
                cout << x << " and " << y << " is an element of the disjoint set" << endl;
                if(find_set(p,x) == find_set(p,y))
                    cout << "they belong to the same set"<< endl;
                else
                    cout << "they belong not the same set"<< endl;
            }
            else
                cout << x << " and " << y << " is not an element of the disjoint set" << endl;



        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are then union them
        else if (option==3)
        {
            int x,y;
            cin >> x >> y;

            if((x >= 0 && x < N) && (y >= 0 && y < N))
            {
                cout << x << " and " << y << " is an element of the disjoint set" << endl;
                _union(p,x,y);
            }
            else
                cout << x << " and " << y << " is not an element of the disjoint set" << endl;


        }

        else
        {
            return 0;
        }
    }

}

