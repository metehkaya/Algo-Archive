#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 15;

int D, I, S, C, B;

struct Street {
    int id, begin_id, end_id, duration, car_count;
    string name;
} streets[MAXN];

struct Car {
    int id, path_size;
    vector<int> path;
} cars[MAXN];

struct Intersection {
    int id;
    vector<int> in_streets;
    vector<int> out_streets;
} intersections[MAXN];

unordered_map<string, int> street_ids;
vector<int> streets_to_print[MAXN];

inline bool compare (int &id_1, int &id_2) {
    return streets[id_1].car_count > streets[id_2].car_count;
}

void read_input() {
    cin >> D >> I >> S >> C >> B;

    for ( int i=0 ; i < I ; i++ ) {
        intersections[i].id = i;
    }

    for ( int i=0 ; i < S ; i++ ) {
        cin >> streets[i].begin_id >> streets[i].end_id >> streets[i].name >> streets[i].duration;
        streets[i].id = i;
        street_ids[streets[i].name] = i;
        intersections[streets[i].begin_id].out_streets.push_back(i);
        intersections[streets[i].end_id].in_streets.push_back(i);
    }

    for( int i=0 ; i < C ; i++ ) {
        cin >> cars[i].path_size;

        for ( int j=0 ; j < cars[i].path_size ; j++ ) {
            string street_name;
            cin >> street_name;
            int street_id = street_ids[street_name];

            cars[i].path.push_back(street_id);

            if (j < cars[i].path_size - 1 ) {
                streets[street_id].car_count++;
            }
        }

        cars[i].id = i;
    }
}

void print_output() {
    int i_print = 0;

    for (int i=0 ; i < I ; i++ ) {
        for( int street_id : intersections[i].in_streets ) {
            if (streets[street_id].car_count > 0) {
                streets_to_print[i].push_back(street_id);
            }
        }

        if (streets_to_print[i].size() > 0) {
            i_print++;
        }

        // sort(streets_to_print[i].begin(), streets_to_print[i].end(), compare);
    }

    cout << i_print << endl;

    for ( int i=0 ; i < I ; i++ ) {
        if (streets_to_print[i].size() == 0) {
            continue;
        }

        cout << i << endl;

        cout << streets_to_print[i].size() << endl;

        int total = 0;
        for ( int j=0 ; j < streets_to_print[i].size() ; j++ ) {
            total += streets[streets_to_print[i][j]].car_count;
        }

        for ( auto g: streets_to_print[i] ) {
            cout << streets[g].name << " " << max(1, streets[g].car_count * 3 / total) << endl;
        }
    }
}

int main() {
    srand(time(0));

    read_input();
    print_output();

    return 0;
}