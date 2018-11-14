//¥π÷±…®√Ë
/*
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		int Len = strs[0].size();
		string Result;
		for (int i = 0; i < Len; i++)
		{
			char Temp = strs[0][i];
			for (int k = 1; k < strs.size(); k++)
			{
				if (strs[k][i] == Temp)
					continue;
				else return Result;
			}
			Result = strs[0].substr(0, i + 1);
		}
		return Result;
	}
};*/

/*
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		return LCP(strs, 0, strs.size() - 1);
	}

	string LCP(vector<string>& strs, int vLeft, int vRight)
	{
		if (vLeft == vRight)
			return strs[vLeft];
		else
		{
			int Mid = (vLeft + vRight) / 2;
			string LCPLeft = LCP(strs, vLeft, Mid);
			string LCPRight = LCP(strs, Mid + 1, vRight);
			return compareStrings(LCPLeft, LCPRight);
		}
	}

	string compareStrings(string vLeft, string vRight)
	{
		int MinLen = min(vLeft.size(), vRight.size());
		for (int i = 0; i < MinLen; i++)
		{
			if (vLeft[i] != vRight[i])
				return vLeft.substr(0, i);
		}
		return vLeft.substr(0, MinLen);
	}
};*/