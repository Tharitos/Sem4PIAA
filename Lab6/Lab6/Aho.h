#pragma once
#ifndef AHO_H
#define AHO_H
#include <vector>
#include "Bohr.h"

using namespace std;

struct Item
{
	size_t index;
	int patternNumber;
	Item(size_t ind, int pN);
};

bool compare(const vector<Item>& a, const vector<Item>& b);
void reindex(vector<Item>& res, vector<size_t>& len);
void actionText(const string& T, Bohr* root, vector<Item>& res);
vector<Item> doAhoCorasick(const string & T, const vector<string>& P);

#endif