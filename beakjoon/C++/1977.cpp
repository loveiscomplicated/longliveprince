#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m;
    int n;

    cin >> m;
    cin >> n;

    int min = -1;
    int add = 0;

    for (int i = m; i <= n; i++)
    {
        if (sqrt(i) == floor(sqrt(i)))
        {
            if (min == -1) min = i;
            add += i;
        }
    }

    if (min == -1) cout << min << endl;
    else 
    {
        cout << add << endl;
        cout << min << endl;
    }
    
    return 0;
}