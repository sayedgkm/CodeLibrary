    int ar[N];
    int F[N];
    /// brute force with complexity O(2^N*2^N)
    for(int mask = 0;mask < (1<<N); ++mask){
        for(int i = 0;i < (1<<N); ++i){
            if((mask&i) == i){
                F[mask] += A[i];
            }
        }
    }


    /// iterate over all the masks//Complexity O(3^N)
    for (int mask = 0; mask < (1<<n); mask++){
        F[mask] = ar[0];
        // iterate over all the subsets of the mask
        for(int i = mask; i > 0; i = (i-1) & mask){
        	F[mask] += ar[i];
        }
    }

///Complexity O(N*2^N) Memory O ( N*2^N)
    for(int mask = 0; mask < (1<<N); ++mask){
        dp[mask][-1] = A[mask];	//handle base case separately (leaf states)
        for(int i = 0;i < N; ++i){
            if(mask & (1<<i))
                dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
            else
                dp[mask][i] = dp[mask][i-1];
        }
        F[mask] = dp[mask][N-1];
    }
///memory optimized, super easy to code. Complexity O(N*2^N) Memory O ( 2^N)
    for(int i = 0; i<(1<<N); ++i)
        F[i] = A[i];
    for(int i = 0;i < N; ++i)
        for(int mask = 0; mask < (1<<N); ++mask){
            if(mask & (1<<i))
                F[mask] += F[mask^(1<<i)];
    }

