#include "Bohr.h"
#define K 26

Bohr::Bohr()
{
	child.resize(K);
	child.assign(K, nullptr);
	go.resize(K);
	go.assign(K, nullptr);
	parent = nullptr;
	suffLink = nullptr;
	up = nullptr;
	isLeaf = false;
	charToParent = 0;
}

char Bohr::SYM(const char ch) 
{
	return tolower(ch) - 'a';
}

/*void Bohr::out(Bohr* n) 
{
	stack<Bohr*> q;
	q.push(n);
	while (!q.empty()) 
	{
		Bohr* cur = q.top();
		q.pop();
		if (cur->charToParent != 0)
			cout << cur->charToParent;
		if (!cur->leafPatternNumber.empty())
			cout << "!";
		cout << " ";
		if (cur->isLeaf) 
		{
			cout << endl;
		}
		else 
			for (int i = K - 1; i >= 0; i--) 
			{
				if (cur->child[i] != nullptr)
					q.push(cur->child[i]);
			}
	}
}*/

void Bohr::addString(const string & s, int patternNumber, Bohr* root) 
{
	Bohr* cur = root;
	for (size_t i = 0; i < s.length(); i++) 
	{
		char ch = s[i];
		char c = SYM(ch);
		if (cur->child[c] == nullptr) 
		{
			cur->child[c] = new Bohr;
			cur->child[c]->parent = cur;
			cur->child[c]->charToParent = ch;
		}
		cur->isLeaf = false;
		cur = cur->child[c];
	}
	cur->isLeaf = true;
	cur->leafPatternNumber.push_back(patternNumber);
}

Bohr* Bohr::getSuffLink(Bohr* v, Bohr* root) 
{
	if (v->suffLink == nullptr) 
	{
		if ((v == root) || (v->parent == root))
			v->suffLink = root;
		else
			v->suffLink = getLink(getSuffLink(v->parent, root), v->charToParent, root);
	}
	return v->suffLink;
}

Bohr* Bohr::getLink(Bohr* v, char c, Bohr* root) 
{
	char nc = SYM(c);
	if (v->go[nc] == nullptr) 
	{
		if (v->child[nc])
			v->go[nc] = v->child[nc];
		else if (v == root)
			v->go[nc] = root;
		else
			v->go[nc] = getLink(getSuffLink(v, root), c, root);
	}
	return v->go[nc];
}

Bohr* Bohr::getUp(Bohr* v, Bohr* root) 
{
	if (v->up == nullptr) 
	{
		if (getSuffLink(v, root)->isLeaf)
			v->up = getSuffLink(v, root);
		else if (getSuffLink(v, root) == root)
			v->up = root;
		else
			v->up = getUp(getSuffLink(v, root), root);
	}
	return v->up;
}