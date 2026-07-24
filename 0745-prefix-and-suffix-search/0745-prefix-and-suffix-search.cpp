class WordFilter {
    unordered_map<string, int> mp;

public:
    WordFilter(vector<string>& words) {
        for (int idx = 0; idx < words.size(); idx++) {
            string &w = words[idx];
            int n = w.size();

            for (int i = 0; i <= n; i++) {
                string pre = w.substr(0, i);

                for (int j = 0; j <= n; j++) {
                    string suf = w.substr(n - j, j);
                    mp[pre + "#" + suf] = idx;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        if (mp.count(key))
            return mp[key];
        return -1;
    }
};

