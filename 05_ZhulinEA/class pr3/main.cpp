#include <iostream>
#include "Thermometr.h"
#include <vector> 
#include <string>  
#include <sstream>

// 03.12.2021
// пример ввода:	adflj appind_inv 12.12.1245 al 17:23 aldfj 15.0	
// adflj appind_inv 12.12.1245 al 18:23 aldfj 19.0
// adf get average_value adlfjlkdj 
// adlf get cout_value_in_date 12.12.1245 17:23 
// //надо дописать считывание функции
using namespace std;

int levenshtein_distance(const std::string& s1, const std::string& s2) {
	int m = s1.size();
	int n = s2.size();

	vector <vector <int>> d(m + 1, vector <int> (n + 1));

	for (int i = 0; i <= m; i++) d[i][0] = i;
	for (int j = 0; j <= n;	j++) d[0][j] = j;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) {  
				d[i][j] = d[i - 1][j - 1];
			}
			else {                   
				d[i][j] = 1 + min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
			}
		}
	}
	return d[m][n];                  
}
/*
void pars_date(string date, inv a){
	string s1 = "";
	string s2 = "";
	string s3 = "";
	int y, m, d; 
	int i;
	for (i = 0; i < 2; i++) {
		s1 += date[i]; 
	}
	i += 2;
	for (i; i < 5; i++) {
		s2 += date[i]; 
	}
	i++;
	for (i; i < 10; i++) {
		s3 += date[i]; 
	}
	string s4 = "";
	int ind; 
	a.day = stoi(s1); 
	a.month = stoi(s2);
	a.year = stoi(s3); 
}	

void pars_time(string s, inv a) {
	int ind;
	string s4 = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			ind = i; 
		}
	}
	s4 += s[ind - 2]; 
	s4 += s[ind - 1]; 
	a.hours = stoi(s4); 
} */


inv sDate(string x) {
	inv a; 
	int i = 0; 
	string date; 
	string value; 

	while (i < x.size()) {
		string s = "";
		int count_point = 0;
		while (x[i] != ' ' and i != x.size()) {
			s += x[i];
			if (x[i] == '.') {
				count_point++;
			}
			i++;
		}
		if (count_point == 2) {
			date = s; 
		}
		else if (count_point == 1) {
			value = s;
		}
		i++;
	}
	string s1 = "";
	string s2 = "";
	string s3 = "";
	int y, m, d;
	int j;
	for (j = 0; j < 2; j++) {
		s1 += date[j];
	}
	j++;
	for (j; j < 5; j++) {
		s2 += date[j];
	}
	j++;
	for (j; j < 10; j++) {
		s3 += date[j];
	}
	a.day = stoi(s1);
	a.month = stoi(s2);
	a.year = stoi(s3);
	int ind;
	string s4 = "";
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == ':') {
			ind = i;
			break; 
		}
	}
	s4 += x[ind - 2];
	s4 += x[ind - 1];
	a.hours = stoi(s4);
	if (!value.empty()) {
		a.value = stod(value);
	}
	return a;
}



// apple
// orange
// banana
// Lenevstein distance
// aple ¬ apple

// get average_value_in_day 12.03.2025
// get 
// append_inv 12:30 20/03/2014

int main() {
	Thermometr a; 
	inv b; 
	cout << "if u want to break this programm: cin - end!!!" << endl;

	while (true) {
		string s;
		vector<string> words;
		cout << "cout string:" << endl;
		getline(cin, s); 
		if (s == "end") {
			return 0;
		}

		istringstream ss(s);
		string word;
		while (ss >> word) {
			words.push_back(word);
		}
		int ind_alf = -1;
		int ind_bet = -1;

		for (int i = 0; i < words.size(); i++) {
			int alf = levenshtein_distance(words[i], "get");
			int bet = levenshtein_distance(words[i], "append_inv");
			if (alf <= 1) {
				ind_alf = i;
			}
			if (bet <= 2) {
				ind_bet = i;
			}
		}

		if (ind_bet != -1) {
			a.append_inv(sDate(s));
		}
		if (ind_alf != -1) {
			if (words[ind_alf + 1] == "cout_min_date") {
				a.cout_min_date();
			}
			else if (words[ind_alf + 1] == "cout_value_in_date") {
				inv g = sDate(s);
				a.cout_value_in_date(g.year, g.month, g.day, g.hours);
			}
			else if (words[ind_alf + 1] == "average_value_in_day") {
				inv g = sDate(s);
				a.average_value_in_day(g.year, g.month, g.day);
			}
			else if (words[ind_alf + 1] == "average_value_in_month") {
				inv g = sDate(s);
				a.average_value_in_month(g.year, g.month);
			}
			else if (words[ind_alf + 1] == "average_value") {
				double h = a.average_value();
				cout << h;
			}
			else if (words[ind_alf + 1] == "average_value_in_month_dn") {
				inv g = sDate(s);
				a.average_value_in_month_dn(g.year, g.month);
			}
			else {
				cout << "Unknown command :'\'";
			}
		}
	} 
}