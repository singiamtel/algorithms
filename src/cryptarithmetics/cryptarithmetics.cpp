// Solves simple addition cryparithmetic problems
// The main objective of this project is showcasing the algorithm, and would
// need refactoring before being used in a real program
//
// By Singiamtel
#include <bits/stdc++.h>

using namespace std;

// Algorithm is sensitive to lowercase/uppercase
vector<string> summands {"POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO", "POCO"};
string answer = "MUCHO";

// Other examples:
// {"CP", "IS", "FUN"} = "TRUE"
// {"SEND", "MORE"} = "MONEY"

vector<pair<char, int>> letter_dic;

static inline pair<char, int> find_el(char a){
	for(auto i : letter_dic){
		if(i.first == a){
			return i;
		}
	}
	pair<char, int>b('+', -7);
	return b;
}

static inline pair<char, int> find_el(int a){
	for(auto i : letter_dic){
		if(i.second == a){
			return i;
		}
	}
	pair<char, int>b('+', -1);
	return b;
}

bool check_solution(){
	// Translates dictionary back into words, and tests if they're a valid solution
	int sol = 0, sum = 0, tmp = 0;
	for(auto i : summands){
		for(auto j : i){
			tmp*=10;
			tmp+=find_el(j).second;
		}
		sum +=tmp;
		tmp = 0;
	}
	for(auto i : answer){
		sol*=10;
		sol+=find_el(i).second;
	}
	if(sum == sol){
		return true;
	}
	return false;
}

void printletter_dic(){
	for(auto i : letter_dic){
		cout << i.first <<" " << i.second <<" / ";
	}
	cout << endl;
}

bool alldefined(){
	if(find_el(-1).first == '+') {
		return true;
	}
	return false;
}

bool recurse(int j) {
	if(alldefined() && check_solution()){
		printletter_dic();
		return true;
	}
	else if(j == letter_dic.size()){
		return false;
	}
	for(int i=0; i<10; ++i){
		if(find_el(i).first != '+') {
			continue;
		}
		letter_dic[j].second = i;
		// Iterate to next letter in dictionary
		recurse(j+1);
		letter_dic[j].second = -1;
	}
	return false;
}

void solve(){
	// Wrapper to recursive function
	recurse(0);
}

void initialize_dic(){
	for(auto i : summands){
		for(auto j : i){
			if (find(letter_dic.begin(), letter_dic.end(), pair<char, int>(j, -1)) == letter_dic.end())
				letter_dic.push_back(pair<char, int>(j, -1));
		}
	}
	for(auto i : answer){
		if (find(letter_dic.begin(), letter_dic.end(), pair<char, int>(i, -1)) == letter_dic.end())
			letter_dic.push_back(pair<char, int>(i, -1));
	}
}

int main(void) {
	initialize_dic();
	solve();
	return 0;
}
