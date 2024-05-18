#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int KMAX = 10;
    const int AMAX = 1e7;
    int N, K;
    vector<int> val;

    long long ans;
    void InputFormat() {
        LINE(N, K);
        LINE(val % SIZE(N));
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
        CONS(0 <= K <= KMAX);
        CONS(array_cons(val));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > AMAX || x < -AMAX)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 2",
            "100 2 3 -33 -4000",
        });
        Output({
            "16265194"
        });
    }

    void BeforeTestCase(){
        val.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(N = 10,
                K = 0,
                random_array(N, val, 10));
        for(int i=0;i<10;i++)
            CASE(N = 100,
                K = 2,
                random_array(N, val, 1000));
        for(int i=0;i<10;i++)
            CASE(N = 1000,
                K = 5,
                random_array(N, val, 1e4));
        for(int i=0;i<10;i++)
            CASE(N = 1e4,
                K = 7,
                random_array(N, val, 1e5));
        for(int i=0;i<10;i++)
            CASE(N = NMAX,
                K = KMAX,
                random_array(N, val, AMAX));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                K = rnd.nextInt(0, KMAX),
                random_array(N, val, rnd.nextInt(1, AMAX)));
    }

private:
    void random_array(int n, vector<int>& val, int nmax){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(0, 2 * nmax) - nmax);
        }
    }
};
