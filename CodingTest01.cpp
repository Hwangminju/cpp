#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
    int arr[16][2];
    int num;
    cout << "N의 값을 입력하세요: ";
    cin >> N;

    for (int i=1; i<=N; i++)
    {
        cout << "====" << i << "일차" << endl;
        for (int j=0; j<2; j++)
            cin >> arr[i][j];
    }

    int res = 0;
    for (int i=1; i<=N; i++) // 1부터 출발, 2부터 출발~~~
        res = max(res, dfs(i));

    cout << res << endl;
    return 0;
}

int dfs(int index)
{
    if (index + arr[index][0] > N+1) // 더한 값이 8보다 커지면 안됨.
        return 0;
    int num = arr[index][1]; // 수행함으로써 받을 수 있는 금액
    int MAX = 0;
    for (int i=index+arr[index][0]; i<=N; i++)
    {
        MAX = max(MAX, dfs(i));
    }
    return MAX+num;
}
