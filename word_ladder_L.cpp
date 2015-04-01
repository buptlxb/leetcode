#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::unordered_set;
using std::pair;


class Solution { 
public: 
     int ladderLength(string start, string end, unordered_set<string> &dict) { 
         dict.erase(start); 
         dict.insert(end); 
     
         next.push(make_pair(start, 1)); 
         pair<string, int> i; 
         for (i = next.front(); end.compare(i.first) != 0;) { 
             for (auto ptr = dict.begin(); ptr != dict.end();) { 
                 if (compare(i.first, *ptr)) { 
                     next.push(make_pair(*ptr, i.second + 1)); 
                     ptr = dict.erase(ptr); 
                 } 
                 else 
                     ptr++; 
             } 
             next.pop(); 
             if (next.size() > 0) 
                 i = next.front(); 
             else  
                 break; 
         } 
          
         if (end.compare(i.first)) 
             return 0; 
         else 
             return i.second; 
     } 
      
private: 
     queue<pair<string, int> > next; 
     bool compare(string a, string b) { 
         int len = a.size(); 
         int dif = 0; 
         for (int i = 0; i < len; i++) { 
             if (a[i] != b[i]) 
                 dif++; 
             if (dif > 1) 
                 return false; 
         } 
          
         return true; 
     } 
}; 


int main(void)
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("doj");
    dict.insert("lot");
    dict.insert("log");
    cout << Solution().ladderLength(start, end, dict) << endl;
    return 0;
}
