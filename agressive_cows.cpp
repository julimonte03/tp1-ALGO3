#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_place_cows(vector <int> stalls, int C, int mid){
    int cows_placed = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last_pos >= mid){
            cows_placed++;
            if (cows_placed == C) return true;
            last_pos = stalls[i];
        }
    }
    
    return false;

}

int min_dist(vector<int> stalls, int C){

    int low = 1;
    int high = stalls[stalls.size() - 1] - stalls[0];
    int res = high;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (can_place_cows(stalls, C, mid)){

            res = mid;
            low = mid + 1;

        }
        else high = mid -1;
    }
    
    return res;
}

int main(){
    int T;
    cin >> T; 
    
    for (int t = 0; t < T; t++) {
        int N, C;
        cin >> N >> C;
        
        vector<int> stalls(N);
        for (int i = 0; i < N; i++) {
            cin >> stalls[i];
        }
        
        sort(stalls.begin(), stalls.end()); 
        
        int res = min_dist(stalls, C);
        
        cout << res << endl; 
    }

    return 0;
}