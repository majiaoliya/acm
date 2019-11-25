#include <set>
#define ll long long int
class Solution {
public:
    /** 无脑暴力
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        for(int i=0, k=0; i<t.length(); i++) {
            if(s[k] == t[i])
                k++;
            if(k == s.length()) return true;
        }
        return false;
    }
    */
    /**
     * 二分, 配置好t串的下标, 二分s的每个位置
     */
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        vector<int> vs[26];
        for(int i=0, pos; i<t.length(); i++) {
            pos = t[i] - 'a';
            vs[pos].push_back(i);
        }
        for(int i=0, pos, now=-1; i<s.length(); i++) {
            pos = s[i] - 'a';
            vector<int>& v = vs[pos];
            ll lef = 0, rig = vs[pos].size()-1, mid, ret = -1;
            while(lef <= rig) {
                mid = (lef + rig) >> 1;
                if(v[mid]>now) ret = v[mid], rig = mid-1;
                else lef = mid+1;
            }
            if(ret == -1) return false;
            else now = ret;
        }
        return true;
    }
};
