class Solution {
public:
    static bool my_comp(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]) {
            return (a[1] > b[1]);
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), my_comp);

        vector<int> tmp;
        tmp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++){
            int curr_elem = envelopes[i][1];
            if (tmp.back() < curr_elem)
            {
                tmp.push_back(curr_elem);
                // cout<<"if: "<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
            }
            else
            {
                int idx = lower_bound(tmp.begin(), tmp.end(), curr_elem) - tmp.begin();
                tmp[idx] = curr_elem;
                // cout<<"else: "<<idx<<" "<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
            }

        }
        return tmp.size();
    }
};