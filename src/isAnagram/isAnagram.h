#ifndef IS_ANAGRAM_H

class IsAnagramSolution {
    public:
        bool isAnagram(string s, string t) {
            // record是一个伪hash表，里面记录26个不同字母出现的次数，初始为0
            int record[26] = {0};
            // 出现一次+1
            for (int i = 0; i < s.size(); i++)
            {
                record[s[i] - 'a']++;
            }
            // 出现一次-1
            for (int j = 0; j < t.size(); j++)
            {
                record[t[j] - 'a']--;
            }
            for (int i = 0; i < 26; i++)
            {
                if (record[i] != 0) {
                    return false;
                    break;
                }
            }
            return true;
        }
    };

#endif //
