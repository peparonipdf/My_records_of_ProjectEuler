#include <iostream>
#include <vector>
using namespace std;

void Solve(vector<vector<int>> &A, vector<vector<int>> &B) {
    int i = 0;
    int j = 0;
    int p = 0;
    int q = 0;
    int flag = 0;
    int check = 0;
    
    while (p <= 8) {
        i = p;
        j = q;
        if (B[i][j] == 0) {
            A[i][j]++;
            check = 0;
            
            while (A[i][j] < 10 and flag == 0) {
                for (int a = 1; a <= 8; a++) {
                    if (i % 3 == 0 and j % 3 == 0) {
                        if (A[i][j] == A[i + 1][j + 1] or A[i][j] == A[i + 2][j + 1] or A[i][j] == A[i + 2][j + 1] or A[i][j] == A[i + 2][j + 2]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 0 and j % 3 == 1) {
                        if (A[i][j] == A[i + 1][j - 1] or A[i][j] == A[i + 1][j + 1] or A[i][j] == A[i + 2][j - 1] or A[i][j] == A[i + 2][j + 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 0 and j % 3 == 2) {
                        if (A[i][j] == A[i + 1][j - 2] or A[i][j] == A[i + 1][j - 1] or A[i][j] == A[i + 2][j - 2] or A[i][j] == A[i + 2][j - 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 1 and j % 3 == 0) {
                        if (A[i][j] == A[i - 1][j + 1] or A[i][j] == A[i - 1][j + 2] or A[i][j] == A[i + 1][j + 1] or A[i][j] == A[i + 1][j + 2]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 1 and j % 3 == 1) {
                        if (A[i][j] == A[i - 1][j - 1] or A[i][j] == A[i - 1][j + 1] or A[i][j] == A[i + 1][j - 1] or A[i][j] == A[i + 1][j + 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 1 and j % 3 == 2) {
                        if (A[i][j] == A[i - 1][j - 2] or A[i][j] == A[i - 1][j - 1] or A[i][j] == A[i + 1][j - 2] or A[i][j] == A[i + 1][j - 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 2 and j % 3 == 0) {
                        if (A[i][j] == A[i - 2][j + 1] or A[i][j] == A[i - 2][j + 2] or A[i][j] == A[i - 1][j + 1] or A[i][j] == A[i - 1][j + 2]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 2 and j % 3 == 1) {
                        if (A[i][j] == A[i - 2][j - 1] or A[i][j] == A[i - 2][j + 1] or A[i][j] == A[i - 1][j - 1] or A[i][j] == A[i - 1][j + 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i % 3 == 2 and j % 3 == 2) {
                        if (A[i][j] == A[i - 2][j - 2] or A[i][j] == A[i - 2][j - 1] or A[i][j] == A[i - 1][j - 2] or A[i][j] == A[i - 1][j - 1]) {
                            A[i][j]++;
                            break;
                        }
                    }
                    if (i + a <= 8 and A[i + a][j] == A[i][j]) {
                        A[i][j]++;
                        break;
                    }
                    if (i - a >= 0 and A[i - a][j] == A[i][j]) {
                        A[i][j]++;
                        break;
                    }
                    if (j + a <= 8 and A[i][j + a] == A[i][j]) {
                        A[i][j]++;
                        break;
                    }
                    if (j - a >= 0 and A[i][j - a] == A[i][j]) {
                        A[i][j]++;
                        break;
                    }
                    if (a == 8) {
                        flag = 1;
                    }
                }
            }

            flag = 0;

            if (A[i][j] <= 9) {
                if (q == 8) {
                    p++;
                    q = 0;
                }
                else {
                    q++;
                }
            }
            else {
                A[i][j] = 0;
                check = 1;
                if (q == 0) {
                    p--;
                    q = 8;
                }
                else {
                    q--;
                }
            }
        }

        else if (B[i][j] == 1 and check == 0) {
            if (q == 8) {
                p++;
                q = 0;
            }
            else {
                q++;
            }
        }
        else {
            if (q == 0) {
                p--;
                q = 8;
            }
            else {
                q--;
            }
        }
    }
}

int main() {
   vector<vector<int>> A(9, vector<int>(9));
   vector<vector<int>> B(9, vector<int>(9));

   for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        cin >> A[i][j];
    }
   }

   for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        if (A[i][j] == 0) {
            B[i][j] = 0;
        }
        else {
            B[i][j] = 1;
        }
    }
   }

   
    Solve(A, B);

    cout << endl;

   for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        cout << A[i][j] << " ";
    }
    cout << endl;
   }
}