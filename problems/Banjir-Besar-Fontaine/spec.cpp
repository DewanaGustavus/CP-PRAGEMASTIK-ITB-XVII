#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMMAX = 4e5;
    const int AMAX = 1e9;
    int N, M;
    vector<vector<int>> mat;

    vector<vector<int>> ans;
    void InputFormat() {
        LINE(N, M);
        GRID(mat) % SIZE(N, M);
    }

    void OutputFormat1() {
        GRID(ans) % SIZE(N, M);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N * M <= NMMAX);
        CONS(matrix_cons(mat));
    }

private:
    bool matrix_cons(vector<vector<int>> &mat){
        if(mat.size() != N)return false;
        for(int i = 0; i < N; i++) {
            if(mat[i].size() != M)return false;
            for(int j = 0; j < M; j++) {
                if(mat[i][j] > AMAX || mat[i][j] <= 0)return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1 3",
            "5 2 4",
        });
        Output({
            "3 1 2"
        });
    }

    void BeforeTestCase(){
        mat.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 5, M = 5, random_matrix(N, M, mat, 10));
        for(int i=0;i<10;i++)CASE(N = 20, M = 20, random_matrix(N, M, mat, 100));
        for(int i=0;i<10;i++)CASE(N = 50, M = 50, random_matrix(N, M, mat, 1e4));
        for(int i=0;i<10;i++)CASE(N = 100, M = 100, random_matrix(N, M, mat, 1e6));
        for(int i=0;i<10;i++)CASE(N = 500, M = 500, random_matrix(N, M, mat, AMAX));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(1, NMMAX), M = NMMAX / N, random_matrix(N, M, mat, AMAX));
    }

private:
    void random_matrix(int n, int m, vector<vector<int>>& mat, int amax){
        mat = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                mat[i][j] = (rnd.nextInt(1, amax));
            }
        }
    }
};
