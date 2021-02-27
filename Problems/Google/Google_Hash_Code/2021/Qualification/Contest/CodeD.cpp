#include <bits/stdc++.h>
#include<fstream>
#define inf 1000000000
#define N 100005
#define MP make_pair
using namespace std;



class Streets{ 
public:
    map<string,int> st_int; 
    map<int,string> int_st;
    map<int, pair<pair<int,int>, int> > streetsHelper;
    // baslangic, bitis lengets
    int lt=0;
    Streets(){
        lt=0;
    }
    string getStreetName(int& a) {
        return int_st[a];
    }
    int getStreetId(string& a) {
        if(st_int.count(a))
            return st_int[a];
        lt++;
        st_int[a]=lt;
        int_st[lt]=a;
        return st_int[a];
    }
}st;




int used_roads_in[N];

// B E L 
bool cmp(pair<int,int> a , pair<int,int> b) { 
    return a.second < b.second;
}

class Intersec{ 
public:
    vector<int> out_streets;
    vector<int> in_streets;
    vector<pair<int,int> > answer;
    map<int,int> start;
    int avgWaitTime=0; 

    Intersec() {
    }

    void print(int id) {
        if(answer.size()==0) return;
        cout << id << endl;
        cout << answer.size() << endl;
        for (auto it : answer)
        {
            cout << st.getStreetName(it.first) << " " << it.second << endl;
        }
    }


    void basic_ans() {
        answer.clear(); 
        int mn = inf;
        for(auto it : in_streets) {
            if(used_roads_in[it]) { 
                mn = min(mn,used_roads_in[it]);
            }
        }
        for(auto it: start) { 
            answer.push_back(MP(it.first,it.second));
        }
        reverse(answer.begin(),answer.end());
        int sum = 0;
        for(auto it : in_streets) {
            if(used_roads_in[it] && start.count(it)==0)
                answer.push_back(MP(it,1));
        }
        avgWaitTime=0;
        for(auto it: answer)
            avgWaitTime += it.second;       
    }

}v[100005];


vector<int> paths[100005];

vector<int> yol[100005];


class Cars{
public:

};
class Service
{
public:
    string filename = "a.txt";
    int Deadline;
    int numInter;
    int numStreets;
    int numCars;
    int BonusPoint;

    Service(string filename) { 
        this->filename = filename;
        ifstream myfile(filename);
        myfile >> Deadline;
        myfile >> numInter;
        myfile >> numStreets;
        myfile >> numCars;
        myfile >> BonusPoint;
        for (int i = 0; i < numStreets; i++)
        {
            int B, E, L ;
            string name;
            myfile >> B >> E;
            myfile >> name;
            myfile >> L;

            int id = st.getStreetId(name);
            v[B].out_streets.push_back(id);
            v[E].in_streets.push_back(id);
            st.streetsHelper[id]  = MP(MP(B,E), L);
        }
        for (int i = 0; i < numCars; i++)
        {
            int P;
            myfile >> P;
            string o;
            int id;
            for (int j = 0; j < P; j++)
            {
                myfile >> o;
                id = st.getStreetId(o);
                if(j==0 && P>1 && j!=P-1) { 
                    v[st.streetsHelper[id].first.second].start[id]++;
                }
                paths[i].push_back(st.streetsHelper[id].first.second);
                used_roads_in[id]++;          
                yol[i].push_back(id); 

            }
            used_roads_in[id]--;           
            paths[i].push_back(st.streetsHelper[id].first.second);
        }
        myfile.close();
    }


    void eraseCars() {
        vector<pair<int,int> > cars;
        for (int i = 0; i < numCars; i++){ 
            int total_time = 0;
            for(int j=0 ; j< yol[i].size() ; j++) { 
                total_time += st.streetsHelper[yol[i][j]].second;
                if(j== yol[i].size()-1)
                    total_time += v[st.streetsHelper[yol[i][j]].first.second].avgWaitTime;
            }
            cars.push_back(MP(i,total_time));
        }
        sort(cars.begin(),cars.end(),cmp);
        reverse(cars.begin(),cars.end());

        for(int i = 0 ;i<cars.size()/10 ; i++) {
            for(int j=0; j<((int)yol[cars[i].first].size())-1;j++) {
                auto it = yol[cars[i].first][j];
//                cerr << it << endl;
                used_roads_in[it]--;
            }
        }

    }
};

int main(int argc, char *argv[]) {
    Service s(argv[1]);

    for (int i = 0; i < s.numInter; i++) 
        v[i].basic_ans();
//    s.eraseCars();

    int interCnt=0;
    for (int i = 0; i < s.numInter; i++)
        if(v[i].answer.size())
            interCnt++;
    cout << interCnt << endl;
    for (int i = 0; i < s.numInter; i++)
        v[i].print(i);
    
}
