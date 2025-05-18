
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> memo;
    vector<int> nextNode;
    int n;

    int hamming(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i] && ++diff > 1)
                return diff;
        }
        return diff;
    }

    int dfs(int u) {
        if (memo[u] != 0) return memo[u];
        int bestLen = 1;
        int bestNext = -1;
        for (int v : edges[u]) {
            int len = 1 + dfs(v);
            if (len > bestLen) {
                bestLen = len;
                bestNext = v;
            }
        }
        nextNode[u] = bestNext;
        return memo[u] = bestLen;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        n = words.size();
        edges.assign(n, {});

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j] && words[i].size() == words[j].size()) {
                    if (hamming(words[i], words[j]) == 1) {
                        edges[i].push_back(j);
                    }
                }
            }
        }

        memo.assign(n, 0);
        nextNode.assign(n, -1);

        int bestLen = 0;
        int startIdx = 0;
        for (int i = 0; i < n; ++i) {
            int len = dfs(i);
            if (len > bestLen) {
                bestLen = len;
                startIdx = i;
            }
        }

        
        vector<string> result;
        int cur = startIdx;
        while (cur != -1) {
            result.push_back(words[cur]);
            cur = nextNode[cur];
        }
        return result;
    }
};
