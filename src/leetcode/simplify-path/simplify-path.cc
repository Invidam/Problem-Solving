class Solution
{
public:
    string simplifyPath(string path)
    {
        string ret = "";
        vector<string> words;
        int pathLength = path.length();
        for (int i = 0; i < pathLength; ++i)
        {
            if (path[i] != '/')
                words.back().push_back(path[i]);
            else if (words.empty() || words.back() != "")
                words.push_back("");
        }
        if (!words.empty() && words.back() == "")
            words.pop_back();
        for (int i = 0; i < words.size(); ++i)
        {
            string &word = words[i];
            if (word == "..")
            {
                if (i == 0)
                {
                    words.erase(words.begin() + i, words.begin() + i + 1);
                    --i;
                    continue;
                }
                words.erase(words.begin() + i - 1, words.begin() + i + 1);
                i -= 2;
            }
            else if (word == ".")
            {
                words.erase(words.begin() + i, words.begin() + i + 1);
                --i;
            }
        }

        for (auto &word : words)
        {
            ret.push_back('/');
            for (auto &ch : word)
                ret.push_back(ch);
        }
        return ret == "" ? "/" : ret;
    }
};