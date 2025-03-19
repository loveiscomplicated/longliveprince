#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int num_case;
    cin >> num_case;

    for (int i = 0; i < num_case; i++) {
        int num_player;
        cin >> num_player;

        vector<int> money_vec;
        vector<string> name_vec;
        for (int j = 0; j < num_player; j++) {
            int money;
            string name;
            
            cin >> money >> name;

            money_vec.push_back(money);
            name_vec.push_back(name);
        }

        int max_idx = 0;
        for (int k = 0; k < num_player; k++) if (money_vec[max_idx] < money_vec[k]) max_idx = k;

        cout << name_vec[max_idx] << endl;
    }
    return 0;
}