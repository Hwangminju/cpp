#include <iostream>
#include <vector>

using namespace std;

int M;
int N;
vector<vector<int>> Pic;

int flood_fill(int m,int n,int col)
{
    int sum = 0;
    if (col == 0) {
        return 0;
    }
    if (n > 0 && col == Pic[m][n-1])
    {
        Pic[m][n] = 0;
        sum += flood_fill(m,n-1,col);
    }
    if (n < N-1 && col == Pic[m][n+1])
    {
        Pic[m][n] = 0;
        sum += flood_fill(m,n+1,col);
    }
    if (m > 0 && col == Pic[m-1][n])
    {
        Pic[m][n] = 0;
        sum += flood_fill(m-1,n,col);
    }
    if (m < M-1 && col == Pic[m+1][n])
    {
        Pic[m][n] = 0;
        sum += flood_fill(m+1,n,col);
    }

    Pic[m][n] = 0;
    return sum + 1;
}

vector<int> solution(int m,int n,vector<vector<int>> picture)
{
    int cnt_area,max_area,temp;
    Pic.clear();
    Pic = picture;
    M = m;
    N = n;
    cnt_area = 0;
    max_area = 0;
    temp = 0;
    vector<int> answer;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
        {
            max_area = flood_fill(i,j,Pic[i][j]);
            if (max_area != 0)
            {
                cnt_area++;
                if (temp < max_area)
                    temp = max_area;
                max_area = 0;
            }
        }
    }
    answer.push_back(cnt_area);
    answer.push_back(temp);

    return answer;
}

int main(void)
{
    vector<int> sol = solution(6,4,{{1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3}});
    cout << "[" << sol[0] << ", " << sol[1] << "]" << endl;
}
