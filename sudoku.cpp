/*
    백준을 풀다가 스도쿠문제를 보았다. 평소 생각해 본적 없는 스도쿠를 푸는 알고리즘을 짜는 것이었는데
    막상 생각해 보니 생각보다 간단한 알고리즘으로 해답을 찾을 수 있었다. 문제를 입력을 받을 때 빈칸을
    받을 때 마다 벡터에 그 좌표를 푸시백 하고 그 좌표에서 들어갈 수 있는 숫자를 하나씩 순서대로 넣으면서
    다음 좌표로 넘어가다가 들어갈 수 있는 숫자가 없는 경우 백트래킹을 해서 다른 수를 넣는다.
    다른사람들의 코드와 비교해 보아 길이는 다소 길었으나 시간면에서는 최적화가 된 코드다.
*/
#include <cstdio>
#include <vector>
using namespace std;
int sdk[9][9];
vector<pair<int, int> > blank;
void input()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &sdk[i][j]);
            if(!sdk[i][j])
                blank.push_back({i, j});
        }

}
bool solve()
{
    static int pos=0;
    int x=blank[pos].first, y=blank[pos].second;
    bool num[10]={};
    for(int i=0; i<9; i++)
    {
        num[sdk[x][i]]=true;
        num[sdk[i][y]]=true;
    }
    int fx=x/3*3, fy=y/3*3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            num[sdk[fx+i][fy+j]]=true;

    for(int i=1; i<=9; i++)
    {
        if(!num[i])
        {
            sdk[x][y]=i;
            if(pos==blank.size()-1)
                return true;

            pos++;
            if(solve())
                return true;
        }

    }
    pos--, sdk[x][y]=0;
    return false;
}
void print()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d ", sdk[i][j]);

        printf("\n");
    }
}
int main()
{
    input();
    if(!blank.empty())
        solve();
    print();
}
