#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int QMAX = 1e5;
    const int AMAX = 1e6;
    int N, Q;
    vector<int> val;
    vector<int> X, L, R;

    vector<int> ans;
    void InputFormat() {
        LINE(N);
        LINE(val % SIZE(N));
        LINE(Q);
        LINES(X, L, R) % SIZE(Q);
    }

    void OutputFormat1() {
        LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= Q <= QMAX);
        CONS(array_cons(val));
        CONS(query_cons(X, L, R));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > AMAX || x <= 0)return false;
        }
        return true;
    }

    bool query_cons(vector<int> &X, vector<int> &L, vector<int> &R){
        if(X.size() != Q) return false;
        if(L.size() != Q) return false;
        if(R.size() != Q) return false;

        for (int i = 0; i < Q; i++) {
            if(X[i] <= 0) return false;
            if(L[i] <= 0) return false;
            if(R[i] < L[i]) return false;
            
            if(X[i] > N) return false;
            if(R[i] > N) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "4 2 3 4 2",
            "5",
            "1 3 5",
            "2 1 5",
            "3 2 4",
            "4 2 4",
            "5 1 5",
        });
        Output({
            "2",
            "0",
            "1",
            "2",
            "0",
        });
    }

    void BeforeTestCase(){
        val.clear();
        X.clear();
        L.clear();
        R.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(N = 10,
                Q = 10,
                random_array(N, val, 50),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = 100,
                Q = 100,
                random_array(N, val, 1000),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = 1000,
                Q = 1000,
                random_array(N, val, 1e4),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = NMAX,
                Q = 10,
                random_array(N, val, AMAX),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = 10,
                Q = QMAX,
                random_array(N, val, AMAX),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = 10000,
                Q = 10000,
                random_array(N, val, 1e5),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = NMAX,
                Q = QMAX,
                random_array(N, val, AMAX),
                random_query(N, Q, X, L, R));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                Q = rnd.nextInt(1, QMAX),
                random_array(N, val, AMAX),
                random_query(N, Q, X, L, R));
    }

private:
    void random_array(int n, vector<int>& val, int amax){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(1, amax));
        }
    }

    void random_query(int n, int q, vector<int> &X, vector<int> &L, vector<int> &R){
        for(int i=0;i<q;i++){
            X.push_back(rnd.nextInt(1, n));
            L.push_back(rnd.nextInt(1, n));
            R.push_back(rnd.nextInt(L[i], n));
        }
    }
};
