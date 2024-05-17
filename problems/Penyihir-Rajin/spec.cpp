#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e9;
    const int KMAX = 1e9;
    const long long TMAX = 1e18;

    int N, K;
    long long T;

    int ans;
    void InputFormat() {
        LINE(N, K, T);
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
        CONS(1 <= K <= KMAX);
        CONS(0 <= T <= TMAX);
    }

private:
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1 3 4",
        });
        Output({
            "501",
        });
    }

    void SampleTestCase2() {
        Input({
            "5 5 0",
        });
        Output({
            "5",
        });
    }

    void BeforeTestCase(){
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, 10),
                K = rnd.nextInt(1, 10),
                T = rnd.nextInt(1, 10));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, 1000),
                K = rnd.nextInt(1, 1000),
                T = rnd.nextInt(1, 1000));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, 1e5),
                K = rnd.nextInt(1, 1e5),
                T = rnd.nextInt(1, 1e5));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                K = rnd.nextInt(1, KMAX),
                T = rnd.nextInt(1, 1e9));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                K = rnd.nextInt(1, KMAX),
                T = rnd.nextInt(1, TMAX));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                K = rnd.nextInt(1, KMAX),
                T = rnd.nextInt(1, TMAX));
    }

private:
};
