#include "Aho.h"

Item::Item(size_t ind, int pN) : index(ind), patternNumber(pN)
{
}

bool compare(const vector<Item>& a, const vector<Item>& b)
{
	if (a.size() != b.size())
		return 0;
	vector<Item>::const_iterator ait;
	vector<Item>::const_iterator bit = b.begin();
	for (ait = a.begin(); (ait < a.end()) && (bit < b.end()); ait++, bit++) 
	{
		if ((ait->index != bit->index) || (ait->patternNumber != bit->patternNumber))
			return 0;
	}
	return 1;
}

void reindex(vector<Item>& res, vector<size_t>& len)
{
	vector<Item>::iterator it;
	for (it = res.begin(); it < res.end(); it++) 
	{
		it->index = it->index + 2 - len[it->patternNumber];
		it->patternNumber++;
	}
}

void actionText(const string& T, Bohr* root, vector<Item>& res)
{
	Bohr* cur = root;
	for (size_t i = 0; i < T.length(); i++) 
	{
		char c = T[i];
		cur = Bohr::getLink(cur, c, root);
		for (Bohr* u = cur; u != root; u = Bohr::getUp(u, root)) 
		{
			if (u->leafPatternNumber.size() != 0)
				for (auto it : u->leafPatternNumber) 
				{
					res.push_back(Item(i, it));
				}
		}
	}
}

vector<Item> doAhoCorasick(const string& T, const vector<string>& P)
{
	vector<Item> res;
	Bohr* bohr = new Bohr;
	size_t size = P.size();
	vector <size_t> len(size);
	int i = 0;
	for (auto it : P) 
	{
		Bohr::addString(it, i, bohr);
		len[i++] = it.length();
	}
	actionText(T, bohr, res);
	reindex(res, len);
	return res;
}
