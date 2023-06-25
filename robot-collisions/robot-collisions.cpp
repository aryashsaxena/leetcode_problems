class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hlth, string drct) {
        
        vector<pair<int,int>> v;

        for(int i=0;i<pos.size();i++){
            v.push_back({pos[i],i});
        }

        sort(v.begin(),v.end());

        stack<pair<int,int>> st;
        st.push(v[v.size()-1]);

        int i=v.size()-2;
        while(i>=0){
            if(!st.empty()){
                    auto p=st.top();

                    if((drct[p.second]=='L' && drct[v[i].second]=='R')){
                        if(hlth[p.second] == hlth[v[i].second]){
                            st.pop();
                        }
                        else if(hlth[p.second]>hlth[v[i].second]){
                            hlth[p.second]--;
                        }
                        else{
                            st.pop();
                            hlth[v[i].second]--;

                            int flag=0;
                            while(!st.empty() && (drct[st.top().second]=='L' && drct[v[i].second]=='R')){
                                    if(hlth[st.top().second] == hlth[v[i].second]){
                                        st.pop();
                                        flag=1;
                                        break;
                                    }
                                    else if(hlth[st.top().second]>hlth[v[i].second]){
                                        hlth[st.top().second]--;
                                        flag=1;
                                        break;
                                    }
                                    else{
                                        st.pop();
                                        hlth[v[i].second]--;
                                    }
                            }
                            
                            if(flag==0)
                            st.push(v[i]);
                        }
                    }
                    else{
                        st.push(v[i]);
                    }
            }
            else
            st.push(v[i]);
            
            i--;
        }

        vector<pair<int,int>> nums;
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            nums.push_back({p.second,hlth[p.second]});
        }

        sort(nums.begin(),nums.end());
        vector<int> ans;

        for(int j=0;j<nums.size();j++)
        ans.push_back(nums[j].second);

        return ans;
    }
};