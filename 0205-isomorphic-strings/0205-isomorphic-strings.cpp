class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>stot;
        unordered_map<char,char>ttos;
        for(int i=0;i<s.length();i++) {
            char sc=s[i];
            char tc=t[i];
            if(stot.count(sc) &&stot[sc] != tc) return false;
            if(ttos.count(tc)&& ttos[tc]!=sc) return false;
            stot[sc]=tc;
            ttos[tc]=sc;
        }
        
       return true;
    }
};