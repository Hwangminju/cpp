#include <iostream>
#include <algorithm>

using namespace std;

int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
int MAX = 0;
int sum = 0;
int N,M;
int A[500][500];
int visited[500][500] = {0};

int dfs(int,int,int);
int exc(int,int);

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cin >> A[i][j];
        }
    }


    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            MAX = max(MAX,dfs(1,i,j));
            MAX = max(MAX,exc(i,j));
        }
    }
    cout << MAX << endl;
}

int dfs(int n,int i,int j)
{
    if (n==4) return A[i][j];
    int next_i, next_j;
    int MAX_ij = A[i][j];
    visited[i][j] = 1;
    for (int k=0;k<4;k++)
    {
        next_i = i+di[k];
        next_j = j+dj[k];
        if (visited[next_i][next_j] == 0 && next_i>=0 && next_i<N && next_j>=0 && next_j<M)
            MAX_ij = max(MAX_ij, A[i][j] + dfs(n+1,next_i,next_j));
        else
            continue;
    }
    visited[i][j] = 0;
    return MAX_ij;
}

int exc(int i,int j)
{
    int MIN = 1001;
    int cnt = 0;
    int next_i, next_j;
    int sum = A[i][j]; // 가운데 칸만 더해 놓고
    for (int k=0;k<4;k++)
    {
        next_i = i+di[k];
        next_j = j+dj[k];
        if (next_i>=0 && next_i<N && next_j>=0 && next_j<M)
        {
            cnt ++;
            if (MIN > A[next_i][next_j])
                MIN = A[next_i][next_j];
            sum += A[next_i][next_j];
        }
    }

    if (cnt == 4)
        sum -= MIN;
    return sum;
}
