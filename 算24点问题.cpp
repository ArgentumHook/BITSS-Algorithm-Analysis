
#include <iostream>
#include <algorithm>
const double eps = 1e-6;
using namespace std;
double a[5];
int seq[5];
int flag;
char s[4];
void init()
{
    for (int i = 1; i <= 4; i++)
        seq[i] = i;
}

double doityourself(double x, char ch, double y)
{
    switch (ch)
    {
        case '*':
            return x * y;
            break;
        case '/':
            return x / y;
            break;
        case '+':
            return x + y;
            break;
        case '-':
            return x - y;
            break;
        default:
            break;
    }
    return 0;
}

void calculate()
{
    if (abs(doityourself(doityourself(doityourself(a[seq[1]],s[1],a[seq[2]]),s[2],a[seq[3]]),s[3],a[seq[4]])-24)<eps)
    {
        flag = true;
        return;
    }
    if (abs(doityourself(doityourself(a[seq[1]],s[1],a[seq[2]]),s[2],doityourself(a[seq[3]],s[3],a[seq[4]]))-24)<eps)
    {
        flag = true;
        return;
    }
    if (abs(doityourself(doityourself(a[seq[1]],s[1],doityourself(a[seq[2]],s[2],a[seq[3]])),s[3],a[seq[4]])-24)<eps)
    {
        flag = true;
        return;
    }
    if (abs(doityourself(a[seq[1]],s[1],doityourself(doityourself(a[seq[2]],s[2],a[seq[3]]),s[3],a[seq[4]]))-24)<eps)
    {
        flag = true;
        return;
    }
    if (abs(doityourself(a[seq[1]],s[1],doityourself(a[seq[2]],s[2],doityourself(a[seq[3]],s[3],a[seq[4]])))-24)<eps)
        flag = true;
}

void dfs(int depth)
{
    if (depth >= 4)
    {
        calculate();
        return;
    }
    s[depth] = '+';
    dfs(depth + 1);
    s[depth] = '-';
    dfs(depth + 1);
    s[depth] = '*';
    dfs(depth + 1);
    s[depth] = '/';
    dfs(depth + 1);
}

int main()
{
    scanf("%lf%lf%lf%lf",a+1,a+2,a+3,a+4);
    init();
    flag = 0;
    do
    {
        // cout << a[seq[1]] << " " << a[seq[2]] << " " << a[seq[3]] << " " << a[seq[4]] << endl;
        dfs(1);
    } while (next_permutation(seq + 1, seq + 5) && !flag);
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
