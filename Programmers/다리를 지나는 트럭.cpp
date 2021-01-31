#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int on_bridge = 0;
    int clock = 0;
    int truck_id = 0;
    int truck_cnt = 0;

    for (int i = 0; i < bridge_length; i++)
        bridge.push(0);

    while (truck_cnt < truck_weights.size()) {

        if (bridge.front() != 0) {
            on_bridge -= bridge.front();
            truck_cnt++;
        }

        bridge.pop();

        if (on_bridge + truck_weights[truck_id] <= weight) {
            bridge.push(truck_weights[truck_id]);
            on_bridge += truck_weights[truck_id];
            truck_id++;
        }
        else bridge.push(0);

        clock++;

    }

    return clock;
}