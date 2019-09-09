#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(const pair<float, int>& a, const pair<float, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int gamer[502];
	memset(gamer, 0, sizeof(gamer));
	vector<pair<float, int>> fail;
	int sum = stages.size();//ÃÑ »ç¶÷ ¼ö
	for (int i = 0; i < stages.size(); i++)
	{
		gamer[stages[i]]++;
	}
	float failure;
	int s = sum;
	for (int i = 1; i <= N; i++)
	{
		failure = (float)gamer[i] / (float)s;
		fail.push_back(make_pair(failure, i));
		s -= gamer[i];
	}

	sort(fail.begin(), fail.end(), cmp);

	for (int i = 0; i < fail.size(); i++)
	{
		answer.push_back(fail[i].second);
	}

	return answer;
}