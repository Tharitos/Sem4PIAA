#pragma once
#ifndef BOHR_H
#define BOHR_H
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Bohr
{
	vector<Bohr*> child;
	vector<Bohr*> go;
	Bohr* parent;
	char charToParent;
	Bohr* suffLink;
	Bohr* up;
	bool isLeaf;
public:
	vector<int> leafPatternNumber;
	Bohr();
	static char SYM(const char ch);
	static void addString(const string& s, int patternNumber, Bohr* root);
	static void out(Bohr* n);
	static Bohr* getSuffLink(Bohr* v, Bohr* root);
	static Bohr* getLink(Bohr* v, char c, Bohr* root);
	static Bohr* getUp(Bohr* v, Bohr* root);
};
#endif