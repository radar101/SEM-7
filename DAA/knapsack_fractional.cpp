#include <bits/stdc++.h>
using namespace std;

struct Item
{
	int weight;
	int value;
	Item(int w, int v) : weight(w), value(v) {}
};

bool compare(Item a, Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
	sort(items.begin(), items.end(), compare);

	int curWeight = 0;
	double finalValue = 0.0;
	for (auto i : items)
	{
		if (curWeight + i.weight <= W)
		{
			curWeight += i.weight;
			finalValue += i.value;
		}
		else
		{
			int rem = W - curWeight;
			finalValue += i.value * ((double)rem / i.weight);
		}
	}

	return finalValue;
}

int main()
{
	int W = 50;

	vector<Item> item = {{10, 60}, {20, 100}, {30, 120}};
	double ans = fractionalKnapsack(W, item);
	cout << ans << endl;
}