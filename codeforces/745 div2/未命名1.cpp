#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int a[N];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        int x;
        cin >> x;
        int y = 2 * x;
        int ans = 0;
        for (int i = 1; i <= y; i ++ ) a[i] = i;
        do{
            int cnt = 0;
            for (int i = 1; i <= y; i ++ )
                if (a[i] <= a[i + 1])
                    cnt ++ ;
            if (cnt >= x) ans ++ ;
        }while (next_permutation(a + 1, a + y + 1));
    
        cout << ans << endl;
    }
    
    return 0;
}
