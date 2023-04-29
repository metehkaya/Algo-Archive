#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct Racer {
	int score;
	vector<int> cnt;
	string name;
	string surname;
	string fullname;
};

struct Team {
	int score;
	string name;
};

bool compTeam(Team* t1 , Team* t2) {
	if(t1->score != t2->score)
		return t1->score > t2->score;
	return t1->name.compare(t2->name) < 0;
}

bool compRacer(Racer* r1 , Racer* r2) {
	if(r1->score != r2->score)
		return r1->score > r2->score;
	for( int i = 0 ; i < 8 ; i++ )
		if(r1->cnt[i] != r2->cnt[i])
			return r1->cnt[i] > r2->cnt[i];
	// return r1->fullname.compare(r2->fullname) < 0;
	int comp = r1->surname.compare(r2->surname);
	if(comp != 0)
		return comp < 0;
	return r1->name.compare(r2->name) < 0;
}

int nRaces,n,m;
vector<Team*> teams;
vector<Racer*> racers;
map<string,int> idxTeam;
map<string,int> idxRacer;
const int p8[8] = {10,8,6,5,4,3,2,1};

void readTeam(string& team , int len0) {
	char str[256];
	gets(str);
	int idx = 25-len0;
	int len = strlen(str);
	for( int i = idx ; i < len-1 ; i++ ) {
		char c = str[i];
		if(c == '.')
			break;
		team.pb(str[i]);
	}
}

void readTrashString() {
	string trash;
	cin >> trash;
}

void readTrashChar() {
	char c;
	scanf("%c",&c);
}

void readTrashLine() {
	char trash[256];
	gets(trash);
}

void dealTeam(string& name , int place) {
	int idx;
	map<string,int>::iterator iter = idxTeam.find(name);
	if(iter == idxTeam.end()) {
		idx = m++;
		Team* t = new Team();
		t->score = 0;
		t->name = name;
		teams.pb(t);
		idxTeam[name] = idx;
	}
	else
		idx = iter->second;
	teams[idx]->score += p8[place];
}

void dealPlayer(string& name , string& surname , int place) {
	int idx;
	string fullname = surname + " " + name;
	map<string,int>::iterator iter = idxRacer.find(fullname);
	if(iter == idxRacer.end()) {
		idx = n++;
		Racer* r = new Racer();
		r->score = 0;
		r->cnt.clear();
		for( int i = 0 ; i < 8 ; i++ )
			r->cnt.push_back(0);
		r->name = name;
		r->surname = surname;
		r->fullname = fullname;
		racers.pb(r);
		idxRacer[fullname] = idx;
	}
	else
		idx = iter->second;
	racers[idx]->score += p8[place];
	racers[idx]->cnt[place]++;
}

void output(int tc) {
	printf("Season %d:\n",tc);
	puts("Drivers Standing:");
	for( int i = 0 ; i < n ; i++ ) {
		cout << racers[i]->name << " " << racers[i]->surname;
		int rem = 25 - racers[i]->name.length() - racers[i]->surname.length();
		while(rem--)
			printf(" ");
		cout << racers[i]->score << endl;
	}
	puts("");
	puts("Teams Standing:");
	for( int i = 0 ; i < m ; i++ ) {
		cout << teams[i]->name;
		int rem = 26 - teams[i]->name.length();
		while(rem--)
			printf(" ");
		cout << teams[i]->score << endl;
	}
	puts("");
}

void reset() {
	for( int i = 0 ; i < n ; i++ )
		delete racers[i];
	for( int i = 0 ; i < m ; i++ )
		delete teams[i];
	n = m = 0;
	teams.clear();
	racers.clear();
	idxTeam.clear();
	idxRacer.clear();
}

int main() {
	for( int tc = 1 ; true ; tc++ ) {
		reset();
		scanf("%d\n",&nRaces);
		if(nRaces == 0)
			break;
		while(nRaces--) {
			readTrashLine();
			readTrashLine();
			for( int i = 0 ; i < 8 ; i++ ) {
				int pos;
				cin >> pos;
				pos--;
				string name,surname,team;
				cin >> name >> surname;
				readTeam(team,name.length()+surname.length());
				dealPlayer(name,surname,pos);
				dealTeam(team,pos);
			}
			readTrashString();
			readTrashChar();
		}
		sort(racers.begin(),racers.end(),compRacer);
		sort(teams.begin(),teams.end(),compTeam);
		output(tc);
	}
	return 0;
}
