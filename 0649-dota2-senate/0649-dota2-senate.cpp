class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') R.push(i);
            else                   D.push(i);
        }

        while (!R.empty() && !D.empty()) {
            int rIdx = R.front(); R.pop();
            int dIdx = D.front(); D.pop();

            if (rIdx < dIdx)
                R.push(rIdx + n);   // R wins, re-enters next round
            else
                D.push(dIdx + n);   // D wins, re-enters next round
        }

        return R.empty() ? "Dire" : "Radiant";
    }
};