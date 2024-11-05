#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int freq;
	char ch;
	Node *left, *right;
	Node(char character, int frequency)
	{
		freq = frequency;
		ch = character;
		left = right = nullptr;
	}
};

struct Compare
{
	bool operator()(Node *left, Node *right)
	{
		return left->freq > right->freq;
	}
};

void encode(Node *root, string str, unordered_map<char, string> &huffManCode)
{
	if (!root)
		return;

	if (!root->left and !root->right)
	{
		huffManCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffManCode);
	encode(root->right, str + "1", huffManCode);
}

unordered_map<char, string> buildHuffmanTree(unordered_map<char, int> &freq)
{
	priority_queue<Node *, vector<Node *>, Compare> pq;

	for (auto pair : freq)
	{
		pq.push(new Node(pair.first, pair.second));
	}

	while (pq.size() != 1)
	{
		Node *left = pq.top();
		pq.pop();
		Node *right = pq.top();
		pq.pop();

		int sum = left->freq + right->freq;
		Node *node = new Node('\0', sum);
		node->left = left;
		node->right = right;

		pq.push(node);
	}

	Node *root = pq.top();
	unordered_map<char, string> huffManCode;
	encode(root, "", huffManCode);
	return huffManCode;
}

int main()
{
	unordered_map<char, int> freq = {{'A', 5}, {'B', 9}, {'C', 12}, {'D', 13}, {'E', 16}};
	unordered_map<char, string> huffManCode = buildHuffmanTree(freq);
	for (auto i : huffManCode)
	{
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}