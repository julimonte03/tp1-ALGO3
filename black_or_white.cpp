#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 201
#define INF 1e9

using namespace std;


int matrix[MAXN][MAXN][MAXN];  

int f(vector<int>& numbers,int index, int last_black, int last_white) {
    if (index == numbers.size()) {
        return 0;
    }

    // Si ya lo tengo, lo devuelvo
    if (matrix[index][last_black + 1][last_white + 1] != -1) {
        
        return matrix[index][last_black + 1][last_white + 1];
    }

    int res;
    int noPinto,black = INF,white = INF;

    // no pinto
    noPinto = 1 + f(numbers,index + 1, last_black, last_white);   

    // ointo black
    if (last_black == -1 || numbers[index] > numbers[last_black]) {
        black  = f(numbers,index + 1, index, last_white);
    }

    // pinto white
    if (last_white == -1 || numbers[index] < numbers[last_white]) {
        white = f(numbers,index + 1, last_black, index);
    }

    res = min(noPinto, min(black, white));


    return matrix[index][last_black+1][last_white+1] = res;
}

int main() {

    int N;
    while (cin >> N && N != -1) {

        vector<int> numbers(N);

        for (int i = 0; i < N; i++) {

            cin >> numbers[i];
        }

        memset(matrix, -1, sizeof(matrix));

        int sol_opt = f(numbers,0, -1, -1);  

        cout << sol_opt << endl;
    }

    return 0;
}
