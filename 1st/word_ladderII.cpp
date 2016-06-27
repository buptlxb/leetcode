#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
    public:
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
        {
            result_.clear();
            dict.insert(end);
            unordered_map<string, vector<string>> prevMap;
            for(auto iter = dict.begin(); iter != dict.end(); ++iter)
                prevMap[*iter] = vector<string>();
            vector<unordered_set<string>> candidates(2);
            int current = 0;
            int previous = 1;
            candidates[current].insert(start);
            while(true)
            {
                current = !current;
                previous = !previous;
                for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
                    dict.erase(*iter);
                candidates[current].clear();

                for(auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
                {
                    for(size_t pos = 0; pos < iter->size(); ++pos)
                    {
                        string word = *iter;
                        for(int i = 'a'; i <= 'z'; ++i)
                        {
                            if(word[pos] == i)continue;
                            word[pos] = i;
                            if(dict.count(word) > 0)
                            {
                                cout << word << endl;
                                prevMap[word].push_back(*iter);
                                candidates[current].insert(word);
                            }
                        }
                    }
                }
                if (candidates[current].size() == 0) {
                    cout << "================" << endl;
                    return result_;
                }
                if (candidates[current].count(end)) break;
            }
            vector<string> path;
            GeneratePath(prevMap, path, end);
            copy(path.begin(), path.end(), ostream_iterator<string>(cout, ", "));
            return result_;
        }

    private:
        void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path, const string& word)
        {
            cout << word << endl;
            if (prevMap[word].size() == 0)
            {
                path.push_back(word);
                vector<string> curPath = path;
                reverse(curPath.begin(), curPath.end());
                result_.push_back(curPath);
                path.pop_back();
                return;
            }
            path.push_back(word);
            for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
                GeneratePath(prevMap, path, *iter);
            path.pop_back();
        }
        vector<vector<string>> result_;
};


int main(void)
{
    Solution s;
    string array[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(array, array+sizeof(array)/sizeof(string));
    vector<vector<string> > ret = s.findLadders("hit", "cog", dict);
    for (vector<vector<string> >::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        copy(i->begin(), i->end(), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }
    return 0;
}
