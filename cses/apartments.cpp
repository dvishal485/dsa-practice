// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    ss << cin.rdbuf();

    int n, m, k;
    ss >> n >> m >> k;
    vector<int> needs, rooms;
    needs.reserve(n);
    rooms.reserve(m);

    for (int i = 0; i < n; i++) {
        int need;
        ss >> need;
        needs.push_back(need);
    }
    for (int i = 0; i < m; i++) {
        int room;
        ss >> room;
        rooms.push_back(room);
    }

    sort(needs.begin(), needs.end());
    sort(rooms.begin(), rooms.end());

    size_t room_ptr = 0;

    int served = 0;
    int curr_room = rooms[room_ptr];
    for (auto const need : needs) {
        while (curr_room < need - k) {
            room_ptr += 1;
            if (room_ptr >= needs.size()) {
                goto finish;
            }
            curr_room = rooms[room_ptr];
        }
        if (curr_room > need + k) {
            continue;
        }

        served += 1;
        room_ptr += 1;
        if (room_ptr >= needs.size()) {
            goto finish;
        }
        curr_room = rooms[room_ptr];
    }

finish:
    cout << served << endl;
    return 0;
}