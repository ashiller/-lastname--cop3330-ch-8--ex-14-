/*
*  UCF COP3330 Fall 2021 Assignment 5 Solution
*  Copyright 2021 Anthony Shiller
*/
#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

vector<int> get_sizes(const vector<string>& vs)
{
	vector<int> res(vs.size());
	for (int i =0; i<vs.size(); ++i)
		res[i] = vs[i].size();
	return res;
}
int longest(const vector<string>& v)
{
	if (v.size()==0) error("longest(): empty vector");
	int m = v[0].size();
	int max_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (m<v[i].size()) {
			max_index = i;
			m = v[i].size();
		}
	return max_index;
}
string& shortest(vector<string>& v)
{
	if (v.size()==0) error("shortest(): empty vector");

	int m = v[0].size();
	int min_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[i].size()<m) {
			min_index = i;
			m = v[i].size();
		}
	return v[min_index];
}
string lex_first(const vector<string>& v)
{
	if (v.size()==0) return "";

	int first_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[i]<v[first_index])
			first_index = i;
	return v[first_index];
}
void lex_last(vector<string>& v, int& last)
{
	if (v.size()==0) {
		last = -1;
		return;
	}
	int last_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[last_index]<v[i])
			last_index = i;
	last = last_index;
}
int main()
try
{
	vector<string> vs;
	vs.push_back("Technicalities");
	vs.push_back("a");
	vs.push_back("A");
	vs.push_back("hellohellohell");
	vs.push_back("Hellohellohell");

	vs.push_back("Technicalities");
	vs.push_back("!");
	cout << "sizes: ";
	vector<int> lengths = get_sizes(vs);
	for (int i=0; i<lengths.size(); ++i) cout << lengths[i] << ' ';
	cout << '\n';
	int i = longest(vs);
	cout << "longest(): index==" << i << "; string=='" << vs[i] << "'\n";
	cout << "shortest(): '" << shortest(vs) << "'\n";
	cout << "lex_first(): '" << lex_first(vs) << "'\n";
	lex_last(vs,i);
	cout << "lex_last(): index==" << i << "; string=='" << vs[i] << "'\n";

	keep_window_open("~");
}
catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}

