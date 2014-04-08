#pragma warning(disable:4786)


#if !defined(AFX_VECTORGRAPHLIB_H__B930CCB8_D05A_4B99_83EA_57A398C70287__INCLUDED_)
#define AFX_VECTORGRAPHLIB_H__B930CCB8_D05A_4B99_83EA_57A398C70287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<vector>
#include<string>
using namespace std;

struct NodeC
{
	string text;
	vector<int> leafs;
	vector<string> leaf_strings;
	int command;
	int data;
	NodeC(const NodeC& arg)
	{
		text = arg.text;
		leafs = arg.leafs;
		command = arg.command;
		data = arg.data;
		for(int count = 0;count < arg.leaf_strings.size();count++)
		{
			string temp = arg.leaf_strings[count];
			leaf_strings.push_back(temp);
		}
	};
	NodeC& operator=(const NodeC& arg)
	{
		text = arg.text;
		leafs = arg.leafs;
		command = arg.command;
		data = arg.data;
		for(int count = 0;count < arg.leaf_strings.size();count++)
		{
			string temp = arg.leaf_strings[count];
			leaf_strings.push_back(temp);
		}
		return *this;
	};
	NodeC()
	{

	};

};

class VectorGraphC
{
public:
	int GetData();
	int GetCommand();
	VectorGraphC(int initial_position = 0);
	~VectorGraphC();
	VectorGraphC(const VectorGraphC& arg);
	VectorGraphC& operator=(const VectorGraphC& arg);
	void AddNode(NodeC *arg);
	void Next(int choice);
	string* GetText();
	string* GetChoiceText(int choice);
	int GetNumChoices();
private:
	int position;
	vector<NodeC*> nodes;
	string temps;
};


#endif