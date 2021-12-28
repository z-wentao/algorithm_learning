#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        string a;
        cin >> a;
        int t = a.size();
        int z = 0;
        for (int i = 0; i < a.size(); i ++ )
            if (a[i] == 'B')    
                z ++ ;
        if (z * 2 == t)
            puts("YES");
        else 
            puts("NO");
    }

    return 0;
}
