
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define pb push_back
#define mp make_pair

int main()
{
    int arr[9];
    ifstream input("test.txt",ios_base::in);
    for(int i=0; i<9; i++)
    {
        input>>arr[i];
        
    }
    for(auto i:arr)
    {
        cout<<i+1<<endl;
    }

    return 0;
}