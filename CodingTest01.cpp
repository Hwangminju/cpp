#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
    int arr[16][2];
    int num;
    cout << "N�� ���� �Է��ϼ���: ";
    cin >> N;

    for (int i=1; i<=N; i++)
    {
        cout << "====" << i << "����" << endl;
        for (int j=0; j<2; j++)
            cin >> arr[i][j];
    }

    int res = 0;
    for (int i=1; i<=N; i++) // 1���� ���, 2���� ���~~~
        res = max(res, dfs(i));

    cout << res << endl;
    return 0;
}

int dfs(int index)
{
    if (index + arr[index][0] > N+1) // ���� ���� 8���� Ŀ���� �ȵ�.
        return 0;
    int num = arr[index][1]; // ���������ν� ���� �� �ִ� �ݾ�
    int MAX = 0;
    for (int i=index+arr[index][0]; i<=N; i++)
    {
        MAX = max(MAX, dfs(i));
    }
    return MAX+num;
}
