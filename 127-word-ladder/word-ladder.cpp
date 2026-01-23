class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string currString = q.front().first;
            int step = q.front().second;
            q.pop();

            if(currString == endWord)return step;
            for(int i = 0;i<currString.size();i++){
                char originalWord = currString[i];
                for(char ch = 'a';ch<='z';ch++){
                    currString[i] = ch;

                    if(st.find(currString)!=st.end()){
                        st.erase(currString);
                        q.push({currString,step+1});
                    }
                }
                currString[i] = originalWord;
            }
        }

        return 0;
    }
};