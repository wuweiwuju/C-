class Solution {
public:
	/* struct Compare
	 {
		 bool operator()(pair<string,int>& a,pair<string,int>& b)
		 {
			 if(a.second != b.second)
				 return a.second < b.second;
			 else
				 return a.first > b.first;
		 }
	 };*/
	vector<string> topKFrequent(vector<string>& words, int k) {
		//将其装入到map容器中，并统计其次数
		map<string, int> countMap;
		vector<string> str;
		for (auto& e : words)
		{
			countMap[e]++;
		}
		/*  //可以用最小堆解决这个问题
		  priority_queue<pair<string,int>,vector<pair<string, int>>,Compare> v;
		  for (auto& e : countMap)
		  {
			  v.push(e);
		  }
		  for (int i = 0; i < k; ++i)
		  {
			  str.push_back(v.top().first);
			  v.pop();
		  }*/
		  //用multimap也可以
		multimap<int, string, greater<int>> v;
		for (auto& e : countMap)
		{
			v.insert(pair<int, string>(e.second, e.first));
		}
		auto it = v.begin();
		while (k--)
		{
			str.push_back(it->second);
			++it;
		}
		return str;
	}
};