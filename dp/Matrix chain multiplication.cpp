pii ar[105];
int dp[105][105];
int mcm(int low,int hi) {
    if(low>=hi) return 0;
    if(dp[low][hi]!=-1) return dp[low][hi];
    int ans=1e9;
    for(int mid=low; mid<hi; mid++) {
        int total=mcm(low,mid)+mcm(mid+1,hi)+ar[low].first*ar[mid].second*ar[hi].second;
        ans=min(ans,total);
    }
    return dp[low][hi]=ans;
}

