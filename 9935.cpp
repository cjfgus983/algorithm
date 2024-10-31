#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string findstr;
    cin >> findstr;

    stack<char> s;
    for(int i=str.size()-1; i >= 0;i--)
    {
        s.push(str[i]);
        if(s.top() == findstr[0])
        {
            string tmp = "";
            if(s.size() < findstr.size())
            {
                continue;
            }
            for(int i=0;i<findstr.size();i++)
            {
                tmp = tmp + s.top();
                s.pop();
            }
            if(tmp != findstr)
            {
                for(int i = tmp.size()-1; i>=0;i--)
                {
                    s.push(tmp[i]);
                }
            }
        }
    }

    if(s.empty())
    {
        cout << "FRULA";
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}