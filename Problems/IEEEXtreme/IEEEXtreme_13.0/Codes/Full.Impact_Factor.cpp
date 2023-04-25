#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct pub {
	string title,id;
	int nPub,nCit;
	pub(string _title, string _id, int _nPub) {
		title = _title;
		id = _id;
		nPub = _nPub;
		nCit = 0;
	}
};

int nR;
vector<pub> pubs;
map<string,int> hashh;

bool comp(pub a, pub b) {
	int x = a.nCit * b.nPub;
	int y = b.nCit * a.nPub;
	if( x != y )
		return x > y;
	return a.title.compare(b.title) < 0;
}

int conv2int(string& str) {
	int numb = 0;
	int len = str.length();
	for( int i = 0 ; i < len ; i++ ) {
		int dig = str[i] - '0';
		numb *= 10;
		numb += dig;
	}
	return numb;
}

string getAttr(string& str, string key, int& index) {
	int lenS = (int) str.length();
	int lenK = (int) key.length();
	while(index + lenK <= lenS && str.substr(index, lenK).compare(key) != 0)
		index++;
	if(index > lenS - lenK)
		return "";
	index += lenK + 5;
	string attr = "";
	while(str[index] != '"')
		attr += str[index++];
	return attr;
}

void parseArt(string& str) {
	int index = 0;
	string id = getAttr(str, "publicationNumber", index);
	string year = getAttr(str, "year", index);
	if(year == "2017" || year == "2018") {
		map<string,int>::iterator mit = hashh.find(id);
		if(mit != hashh.end()) {
			int index = hashh[id];
			pubs[index].nCit++;
		}
	}
}

void getArt(string& str, int& index) {
	int cnt = 1;
	int left = index;
	int right = index+1;
	while(cnt) {
		if(str[right] == '{')
			cnt++;
		else if(str[right] == '}')
			cnt--;
		right++;
	}
	string sub = str.substr(left, right-left);
	parseArt(sub);
	index = right;
}

void readArticle() {
	string str;
	getline(cin,str);
	int len = str.length();
	int index = -1;
	for( int i = 1 ; i < len && index == -1 ; i++ )
		if(str[i] == '{')
			index = i;
	if(index == -1)
		return;
	int index2 = -1;
	for( int i = index+1 ; i < len && index2 == -1 ; i++ )
		if(str[i] == '{')
			index2 = i;
	if(index2 == -1)
		return;
	while(index2 < len-3) {
		getArt(str, index2);
		index2++;
	}
}

void parsePub(string& str) {
	int index = 0;
	string title = getAttr(str, "publicationTitle", index);
	string id = getAttr(str, "publicationNumber", index);
	int nPub = 0;
	while(true) {
		string year = getAttr(str, "year", index);
		if( year == "" )
			break;
		if( year != "2017" && year != "2018" )
			continue;
		string articleCount = getAttr(str, "articleCount", index);
		int numb = conv2int(articleCount);
		nPub += numb;
	}
	hashh[id] = (int) pubs.size();
	pubs.pb(pub(title,id,nPub));
}

void getPub(string& str, int& index) {
	int cnt = 1;
	int left = index;
	int right = index+1;
	while(cnt) {
		if(str[right] == '{')
			cnt++;
		else if(str[right] == '}')
			cnt--;
		right++;
	}
	string sub = str.substr(left, right-left);
	parsePub(sub);
	index = right;
}

void readPublication() {
	string str;
	getline(cin,str);
	int len = str.length();
	int index = -1;
	for( int i = 1 ; i < len && index == -1 ; i++ )
		if(str[i] == '{')
			index = i;
	if(index == -1)
		exit(0);
	while(index < len-2) {
		getPub(str, index);
		index++;
	}
}

void output() {
	sort(pubs.begin(), pubs.end(), comp);
	for( int i = 0 ; i < (int) pubs.size() ; i++ )
		printf("%s: %.2lf\n", pubs[i].title.c_str(), (double) pubs[i].nCit / pubs[i].nPub);
}

int main() {
	scanf("%d\n",&nR);
	if(nR == 0)
		return 0;
	readPublication();
	for( int i = 1 ; i < nR ; i++ )
		readArticle();
	output();
	return 0;
}
