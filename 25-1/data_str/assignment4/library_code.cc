// library_code.cc

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;


// Question 3 - Word Transformation Sequence
void question3() {
    std::string beginWord, endWord;
    int N;
    std::cin >> beginWord >> endWord >> N;

    std::unordered_set<std::string> wordSet;
    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;
        wordSet.insert(word);
    }

    // if endWord is not in wordList.
    if (wordSet.find(endWord) == wordSet.end()) {
        std::cout << 0 << std::endl;
        return;
    }

    std::queue<std::pair<std::string, int>> q;
    q.push({beginWord, 1}); // Since it includes the starting word, start from step 1

    std::unordered_set<std::string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        std::string current_word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current_word == endWord) {
            std::cout << steps << std::endl;
            return;
        }

        // Navigate by changing each letter of the current word
        for (int i = 0; i < current_word.length(); ++i) {
            char original_char = current_word[i]; // Save the original word
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == original_char) continue; // Skip identical letters

                current_word[i] = c; // change letters

                // If the changed word is in wordSet and has not been visited yet,
                if (wordSet.count(current_word) && visited.find(current_word) == visited.end()) {
                    visited.insert(current_word);
                    q.push({current_word, steps + 1});
                }
            }
            current_word[i] = original_char; // Restore original text for next text change
        }
    }

  
    std::cout << 0 << std::endl;
}

// Question 4 - Minimum Cost to Reach City With Discounts
void question4() {
    // Define INF inside the function for scope and clarity
    const long long INF = numeric_limits<long long>::max();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: number of cities, M: number of highways
    cin >> N >> M;

    // Adjacency list: adj[u] stores pairs of {v, cost} for highways from u to v
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c}); // Bidirectional highway
    }

    int D; // Maximum number of discounts allowed
    cin >> D;

    // dist[city][discounts_used] stores the minimum cost to reach 'city' using 'discounts_used'
    // 'discounts_used' can range from 0 to D, so size is D + 1
    vector<vector<long long>> dist(N, vector<long long>(D + 1, INF));

    // Priority queue for Dijkstra's: {current_cost, city, discounts_used}
    // std::greater ensures the smallest cost is at the top
    priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
    > pq;

    // Start from city 0 with 0 cost and 0 discounts used
    dist[0][0] = 0;
    pq.push({0, 0, 0}); // {cost, city, discounts_used}

    while (!pq.empty()) {
        auto [current_cost, u, discounts_used] = pq.top();
        pq.pop();

        // If a shorter path to this state (u, discounts_used) has already been found, skip
        if (current_cost > dist[u][discounts_used]) {
            continue;
        }

        // Explore neighbors of city u
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int c = edge.second;

            // Option 1: Travel without using a discount
            long long new_cost_no_discount = current_cost + c;
            if (new_cost_no_discount < dist[v][discounts_used]) {
                dist[v][discounts_used] = new_cost_no_discount;
                pq.push({new_cost_no_discount, v, discounts_used});
            }

            // Option 2: Travel using a discount (if available)
            if (discounts_used < D) {
                long long discounted_c = c / 2; // Integer division
                long long new_cost_with_discount = current_cost + discounted_c;
                if (new_cost_with_discount < dist[v][discounts_used + 1]) {
                    dist[v][discounts_used + 1] = new_cost_with_discount;
                    pq.push({new_cost_with_discount, v, discounts_used + 1});
                }
            }
        }
    }

    // Find the minimum cost to reach city N-1 across all possible discount usages
    long long final_min_cost = INF;
    for (int j = 0; j <= D; ++j) {
        final_min_cost = min(final_min_cost, dist[N - 1][j]);
    }

    // Output the result: -1 if impossible, otherwise the minimum cost
    if (final_min_cost == INF) {
        cout << -1 << endl;
    } else {
        cout << final_min_cost << endl;
    }
}

// Question 5 - Valve Control: Efficient Pressure Release Scheduling
const int MAX_TIME = 30;
const int MAX_N = 70;
const int MAX_K = 15; // Not used in the provided logic.

vector<pair<int, int>> adj[MAX_N];
int valve_flow_rates[MAX_N];
int dist[MAX_N][MAX_N];

map<string, int> valve_name_to_id;
int next_valve_id = 0;

vector<int> important_valve_ids;
map<int, int> real_id_to_bitmask_idx;

map<tuple<int, int, int>, int> memo;

// Precomputes shortest distances between all valve pairs.
void precompute_distances(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = (i == j) ? 0 : numeric_limits<int>::max();
        }
        queue<pair<int, int>> q;

        q.push({i, 0});
        dist[i][i] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int current_time = q.front().second;
            q.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (dist[i][v] > current_time + 1) {
                    dist[i][v] = current_time + 1;
                    q.push({v, current_time + 1});
                }
            }
        }
    }
}

// Calculates current flow rate from opened valves.
int calculate_current_flow(int opened_valves_bitmask) {
    int current_flow = 0;
    for (int i = 0; i < important_valve_ids.size(); ++i) {
        if ((opened_valves_bitmask >> i) & 1) {
            current_flow += valve_flow_rates[important_valve_ids[i]];
        }
    }
    return current_flow;
}

// DP function: returns max pressure from current state.
int solve(int time_left, int current_valve_id, int opened_valves_bitmask) {
    if (time_left <= 0) {
        return 0;
    }

    tuple<int, int, int> current_state = {time_left, current_valve_id, opened_valves_bitmask};
    if (memo.count(current_state)) {
        return memo[current_state];
    }

    // Base pressure: pressure gained if no further actions are taken.
    int current_flow_rate_per_min = calculate_current_flow(opened_valves_bitmask);
    int max_pressure_released = current_flow_rate_per_min * time_left;

    // Option 1: Open the current valve.
    auto it_bitmask_idx = real_id_to_bitmask_idx.find(current_valve_id);
    if (it_bitmask_idx != real_id_to_bitmask_idx.end()) {
        int bitmask_idx = it_bitmask_idx->second;
        if (!((opened_valves_bitmask >> bitmask_idx) & 1)) {
            int time_to_open = 1;
            int new_time_left = time_left - time_to_open;

            if (new_time_left >= 0) {
                int new_opened_valves_bitmask = opened_valves_bitmask | (1 << bitmask_idx);
                max_pressure_released = max(max_pressure_released,
                                            current_flow_rate_per_min * time_to_open +
                                            solve(new_time_left, current_valve_id, new_opened_valves_bitmask));
            }
        }
    }

    // Option 2: Move to another important valve.
    for (int next_important_valve_id : important_valve_ids) {
        if (current_valve_id == next_important_valve_id) continue;

        int time_to_move = dist[current_valve_id][next_important_valve_id];
        if (time_to_move == numeric_limits<int>::max() || time_to_move >= time_left) {
            continue;
        }

        int next_bitmask_idx = real_id_to_bitmask_idx[next_important_valve_id];
        if (!((opened_valves_bitmask >> next_bitmask_idx) & 1)) {
            int new_time_left = time_left - time_to_move;

            if (new_time_left >= 0) {
                max_pressure_released = max(max_pressure_released,
                                            current_flow_rate_per_min * time_to_move +
                                            solve(new_time_left, next_important_valve_id, opened_valves_bitmask));
            }
        }
    }

    return memo[current_state] = max_pressure_released;
}

// Main function to solve Question 5.
void question5() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string name;
        int flow_rate, k_connected;
        cin >> name >> flow_rate >> k_connected;

        int current_id;
        if (valve_name_to_id.find(name) == valve_name_to_id.end()) {
            current_id = next_valve_id++;
            valve_name_to_id[name] = current_id;
        } else {
            current_id = valve_name_to_id[name];
        }

        valve_flow_rates[current_id] = flow_rate;

        if (flow_rate > 0) {
            important_valve_ids.push_back(current_id);
            real_id_to_bitmask_idx[current_id] = important_valve_ids.size() - 1;
        }

        for (int j = 0; j < k_connected; ++j) {
            string connected_name;
            cin >> connected_name;
            int connected_id;
            if (valve_name_to_id.find(connected_name) == valve_name_to_id.end()) {
                connected_id = next_valve_id++;
                valve_name_to_id[connected_name] = connected_id;
            } else {
                connected_id = valve_name_to_id[connected_name];
            }
            adj[current_id].push_back({connected_id, 1});
        }
    }

    precompute_distances(N);

    int start_valve_id = valve_name_to_id["AA"];
    cout << solve(MAX_TIME, start_valve_id, 0) << endl;
}