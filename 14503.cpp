#include <iostream>
#include <vector>

using namespace std;

int n,m;
int firstR, firstC;
int dir;
vector<vector<int>> map;
vector<vector<bool>> clean;
int result = 0;
int dR[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dC[4] = {0,1,0,-1};

int main()
{
    cin >> n >> m;
    cin >> firstR >> firstC >> dir; // 0=북 1=동 2=남 3=서
    map = vector<vector<int>>(n,vector<int>(m,0));
    clean = vector<vector<bool>>(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1) // 벽이라면 클린 트루로
                clean[i][j] = true;
        }
    }

    int nowR = firstR;
    int nowC = firstC;
    bool operate = true;
    while(operate)
    {   
        // 1번 
        if(clean[nowR][nowC] == false)
        {
            result++;
            clean[nowR][nowC] = true;
        }
        // 2번 & 3번
        bool check = false;
        for(int i=0;i<4;i++)
        {
            int nextR = nowR + dR[i];
            int nextC = nowC + dC[i];
            if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= m)
            {
                continue; // 범위를 벗어난 경우
            }
            if(clean[nextR][nextC] == false) // 청소되지 않은 빈칸이 있는 경우
            {
                check = true;
                break;
            }
        }
        // 2번 주위에 청소되지 않은 빈칸이 없는 경우
        if(check == false)
        {
            int tmpDir = (dir + 2) % 4;
            nowR = nowR + dR[tmpDir];
            nowC = nowC + dC[tmpDir];
            if(map[nowR][nowC] == 1) // 2-2 벽이라면
            {
                operate = false;
            }
        }
        // 3번 청소되지 않은 빈칸이 있는 경우 
        if(check == true)
        {
            while(1)
            {
                dir = ((dir - 1) + 4 ) % 4; // 3-1
                int nextR = nowR + dR[dir];
                int nextC = nowC + dC[dir];
                if(clean[nextR][nextC] == false) // 청소 안된 칸이면 전진
                {
                    nowR = nextR;
                    nowC = nextC;
                    break;
                }
            }
        }
    }
    cout << result;
}