#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>  

using namespace std;

int main() {

    int T;
    cin >> T;
    vector<int> optimal_solutions(T);

    vector<vector<tuple<int, int>>> activities_list(T);  

       for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<tuple<int, int>> activities(N);  

        for (int n = 0; n < N; n++) {
            
            int inicio, fin;
            cin >> inicio >> fin;
            activities[n] = make_tuple(inicio, fin); 
        }

        activities_list[t] = activities;  
    }
    
   for (int i = 0; i < activities_list.size(); i++) {

        int opt_sol = 0;

        sort(activities_list[i].begin(), activities_list[i].end(), [](tuple<int, int> a, tuple<int, int> b) {
            return get<1>(a) < get<1>(b); 
        });

        tuple<int, int> mejor_tupla = activities_list[i][0];
        opt_sol++; 

        for (int j = 1; j < activities_list[i].size(); j++) {

            if (get<0>(activities_list[i][j]) >= get<1>(mejor_tupla)) {

                mejor_tupla = activities_list[i][j];  
                opt_sol++;  

            }
        }

        optimal_solutions[i] = opt_sol;  
    }


    for (int i = 0; i < optimal_solutions.size(); i++) {
        cout << optimal_solutions[i] << endl;
    }

    return 0;
}