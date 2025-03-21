#include <iostream>

using namespace std;

int main() {

    int num_case;
    cin >> num_case;

    int arr[num_case];

    for (int i = 0; i < num_case; i++) {
        int num;
        cin >> num;
        arr[i] = num;    
    }

    int q;
    cin >> q;

    int ans = 0;

    for (int i = 0; i < num_case; i++) {
        if (q == arr[i]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}