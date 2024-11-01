#include <iostream>
#include <string>
#include <vector>

using namespace std;

int s;
string n;

int main()
{
    cin >> s;
    cin >> n;

    int row = 2 * s + 3;
    int col = (s + 2) * n.size();

    // 가로 한칸에 s + 2 라는 거잖아
    vector<string> arr(row);
    // 꼭대기 행 
    for(int i=0;i<n.size();i++) // 자리수 하나 확인
    {
        if(n[i] == '1' || n[i] == '4') // 1이나 4라면
        {
            for(int j=0;j<s+2;j++)
            {
                arr[0] = arr[0] + ' ';
            }
        }
        else
        {
            arr[0] = arr[0] + ' ';
            for(int k=0;k<s;k++)
            {
                arr[0] = arr[0] + '-';
            }
            arr[0] = arr[0] + ' ';
        }
        arr[0] = arr[0] + ' ';
    }
    // 1번행 ~ 중간 전 까지
    for(int i=0;i<n.size();i++)
    {
        for(int j=1;j<row/2;j++)
        {
            if(n[i] == '5' || n[i] == '6') // 앞에 넣는 경우
            {
                arr[j] = arr[j] + '|';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + ' ';
            }
            else if(n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7') // 뒤에 넣는 경우
            {
                arr[j] = arr[j] + ' ';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + '|';
            }
            else // 둘 다 넣는 경우
            {
                arr[j] = arr[j] + '|';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + '|';
            }
            arr[j] = arr[j] + ' ';
        }
    }

    // 중간 행
    for(int i=0;i<n.size();i++)
    {
        if(n[i] == '1' || n[i] == '7' || n[i] == '0') // 1이나 4라면
        {
            for(int j=0;j<s+2;j++)
            {
                arr[row/2] = arr[row/2] + ' ';
            }
        }
        else
        {
            arr[row/2] = arr[row/2] + ' ';
            for(int k=0;k<s;k++)
            {
                arr[row/2] = arr[row/2] + '-';
            }
            arr[row/2] = arr[row/2] + ' ';
        }
        arr[row/2] = arr[row/2] + ' ';
    }
    // 중간부터 마지막 전
    for(int i=0;i<n.size();i++)
    {
        for(int j=row/2 + 1;j<row - 1;j++)
        {
            if(n[i] == '2') // 앞에 넣는 경우
            {
                arr[j] = arr[j] + '|';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + ' ';
            }
            else if(n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5'|| n[i] == '7'|| n[i] == '9') // 뒤에 넣는 경우
            {
                arr[j] = arr[j] + ' ';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + '|';
            }
            else // 둘 다 넣는 경우
            {
                arr[j] = arr[j] + '|';
                for(int k=0;k<s;k++)
                {
                    arr[j] = arr[j] + ' ';
                }
                arr[j] = arr[j] + '|';
            }
            arr[j] = arr[j] + ' ';
        }
    }
    // 마지막 행
    for(int i=0;i<n.size();i++)
    {
        if(n[i] == '1' || n[i] == '4' || n[i] == '7') // 1이나 4라면
        {
            for(int j=0;j<s+2;j++)
            {
                arr[row-1] = arr[row-1] + ' ';
            }
        }
        else
        {
            arr[row-1] = arr[row-1] + ' ';
            for(int k=0;k<s;k++)
            {
                arr[row-1] = arr[row-1] + '-';
            }
            arr[row-1] = arr[row-1] + ' ';
        }
        arr[row-1] = arr[row-1] + ' ';
    }


    // 결과 출력
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] <<'\n';
    }
}