#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e3;
    const int MMAX = 1e3;
    const int AMAX = 1e9;
    int N, M;
    vector<vector<int>> mat;

    long long ans;
    void InputFormat() {
        LINE(N, M);
        GRID(mat) % SIZE(N, M);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= M <= MMAX);
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
            "5 5",
            "4 10 10 7 5",
            "4 7 5 10 7",
            "1 1 10 7 7",
            "7 2 3 4 2",
            "8 4 7 4 4",
        });
        Output({
            "97"
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
        for(int i=0;i<10;i++)CASE(N = 500, M = 500, random_matrix(N, M, mat, 1e7));
        for(int i=0;i<10;i++)CASE(N = NMAX, M = MMAX, random_matrix(N, M, mat, AMAX));
        for(int i=0;i<10;i++)CASE(N = NMAX, M = rnd.nextInt(1, MMAX), random_matrix(N, M, mat, AMAX));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(1, NMAX), M = MMAX, random_matrix(N, M, mat, AMAX));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(1, NMAX), M = rnd.nextInt(1, MMAX), random_matrix(N, M, mat, AMAX));
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
