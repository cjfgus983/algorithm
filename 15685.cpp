#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> map(101, vector<bool>(101,0));

int dr[4] = {1,0,-1,0};
int dc[4] = {0,-1,0,1};
// 오른쪽 위 왼쪽 아래
int result;

void check(int startR, int startC, int dir, int cnt)
{
    vector<int> dirArr;
    // 0 세대 저장
    dirArr.push_back(dir);
    // 1 세대 저장
    if(cnt >= 1)
    {
        int nextdir = ((dir+1) + 4) % 4;
        dirArr.push_back(nextdir);
    }
    // 이후 방향 저장
    for(int k=2;k<=cnt;k++)
    {
        int nowSize = dirArr.size();
        // dirArr의 절반만큼은 그대로 추가 
        for(int i = 0;i<nowSize/2; i++)
        {
            int nextdir = (dirArr[i] + 2) % 4;
            dirArr.push_back(nextdir);
        }
        // 나머지는 반대 방향으로 추가
        for(int i=nowSize/2;i<nowSize;i++)
        {
            dirArr.push_back(dirArr[i]);
        }
    }
    // 방향대로 정점 체크
    int nowR = startR;
    int nowC = startC;
    map[nowR][nowC] = true;
    for(int i = 0; i<dirArr.size();i++)
    {
        int nextdir = dirArr[i];
        nowR = nowR + dr[nextdir];
        nowC = nowC + dc[nextdir];
        map[nowR][nowC] = true;
    }
}

bool findSquare(int r, int c)
{
    if(map[r][c + 1] && map[r+1][c] && map[r+1][c+1])
    {
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> n;
    while(n--)
    {
        int startR,startC, dir, cnt;
        cin >> startR >> startC >> dir >> cnt;
        check(startR, startC, dir, cnt);
    }

    // 4각형 찾기
    for(int i=0;i<=99;i++)
    {
        for(int j=0;j<=99;j++)
        {
            if(map[i][j] == true && findSquare(i,j))
            {
                result++;
            }
        }
    }
    cout << result;
}