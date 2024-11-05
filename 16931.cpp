#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int n,m;
vector<vector<int>> arr(100,vector<int>(100,0));

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }
    // 결과값  
    int result = 0;

    // 상판 하판 면적
    int up_down = m*n*2;
    result += up_down;
    
    // 사이사이 면적 확인
    // 1. 가로 먼저 확인
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            result += abs(arr[i][j+1] - arr[i][j]);
        }
    }
    // 2. 세로 확인
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            result += abs(arr[i][j] - arr[i+1][j]);
        }
    }
    // 옆면들 싹 확인
    // 1. 위
    for(int i=0;i<m;i++)
    {
        result += arr[0][i];
    }
    // 2. 아래
    for(int i=0;i<m;i++)
    {
        result += arr[n-1][i];
    }
    // 3. 왼
    for(int i=0;i<n;i++)
    {
        result += arr[i][0];
    }
    // 4. 오른쪽
    for(int i=0;i<n;i++)
    {
        result += arr[i][m-1];
    }
    cout << result;
}