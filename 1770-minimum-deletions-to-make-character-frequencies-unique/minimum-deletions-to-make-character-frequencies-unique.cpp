class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;

        priority_queue<int> pq;
        for(auto i:m){
            pq.push(i.second);
        }

        int count=0;
        unordered_set<int> st;
        while(pq.size()!=0){
            int i=pq.top();
            pq.pop();

            while(st.count(i) && i>0){
                i--;
                count++;
            }
            cout<<i<<" ";
            st.insert(i);
        }
        return count;
    }
};