#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        set<string> s;
        for (auto ticket : tickets) {
            s.insert(ticket.first);
            s.insert(ticket.second);
        }
        vector<string> rhash(s.begin(), s.end());
        map<string, int> hash;
        int idx = 1;
        for (auto i = s.begin(), iend = s.end(); i != iend; ++i) {
            hash[*i] = idx++;
        }
        vector<vector<int> > graph(s.size()+1, vector<int>(s.size()+1));
        for (auto ticket : tickets) {
            ++graph[hash[ticket.first]][hash[ticket.second]];
        }
        vector<int> indices;
        findItinerary(graph, hash["JFK"], indices, tickets.size()+1);
        vector<string> ret;
        for (auto index : indices)
            ret.push_back(rhash[index-1]);
        return ret;
    }
    bool findItinerary(vector<vector<int> > &graph, int index, vector<int> &ret, int num) {
        ret.push_back(index);
        if (ret.size() == num)
            return true;
        for (vector<int>::size_type i = 1, iend = graph[index].size(); i != iend; ++i) {
            if (!graph[index][i])
                continue;
            --graph[index][i];
            if (findItinerary(graph, i, ret, num))
                return true;
            ++graph[index][i];
        }
        ret.pop_back();
        return ret.size() == num;
    }
};

int main(void)
{
    // vector<pair<string, string> > tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // vector<pair<string, string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<pair<string, string> > tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    // vector<pair<string, string> > tickets = {{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}};
    Solution s;
    vector<string> ret = s.findItinerary(tickets);
    for (auto t : ret)
        cout << t << endl;
    return 0;
}
