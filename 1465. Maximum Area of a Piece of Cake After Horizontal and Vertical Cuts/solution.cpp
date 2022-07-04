class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {   
        hC.push_back(h);
        sort(hC.begin(), hC.end());
		int maxh = hC[0];
        int n= hC.size();
        for(int i=1; i<n; ++i){
            maxh = max(maxh, hC[i] - hC[i-1]);
        }
        
        vC.push_back(w);
        sort(vC.begin(), vC.end());
		int maxv = vC[0];
        int m= vC.size();
        for(int i=1; i<m; ++i){
            maxv = max(maxv, vC[i] - vC[i-1]);
        }
		
        return (1LL*maxh*maxv) % 1000000007;
    }
};
