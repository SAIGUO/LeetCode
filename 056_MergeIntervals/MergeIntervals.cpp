#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//冒泡排序换成自定义sort排序后，由280ms提升至8ms
vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() == 0) return{};
	vector<Interval> Res;
	/*for (int i = 0; i < intervals.size() - 1; ++i)
	{
		for (int k = 0; k < intervals.size() - 1 - i; ++k)
		{
			if (intervals[k].start > intervals[k + 1].start)
			{
				Interval Second = intervals[k];
				intervals[k] = intervals[k + 1];
				intervals[k + 1] = Second;
			}
		}
	}*/
	sort(intervals.begin(), intervals.end(), [](Interval& First, Interval& Second) { return First.start < Second.start; });
	Interval Temp = intervals[0];
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (Temp.end >= intervals[i].start)
		{
			Temp.end = intervals[i].end;
		}
		else
		{
			Res.push_back(Temp);
			Temp = intervals[i];
		}
	}
	Res.push_back(Temp);
	return Res;
}

void main()
{
	vector<Interval> Input = { Interval(4,5), Interval(1,4), Interval(0,1) };
	vector<Interval> Res = merge(Input);
	for (int i = 0; i < Res.size(); ++i)
	{
		std::cout << " [" << Res[i].start << "," << Res[i].end << "] ";
	}
	std::cout << std::endl;
}