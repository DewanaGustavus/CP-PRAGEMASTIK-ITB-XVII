#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const long long NMAX = 1e9;
    long long N;

    int ans;
    void InputFormat() {
        LINE(N);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(2 <= N <= NMAX);
        CONS(N % 2 == 0);
    }

private:
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {
        Input({
            "6",
        });
        Output({
            "3"
        });
    }

    void BeforeTestCase(){
    }

    void TestCases() {
        for(int i=1;i<=10;i++)CASE(N = 2 * i);
        for(int i=0;i<10;i++)CASE(N = 2 * rnd.nextLongLong(1,1000));
        for(int i=0;i<10;i++)CASE(N = 2 * rnd.nextLongLong(1,1e5));
        for(int i=0;i<10;i++)CASE(N = 2 * rnd.nextLongLong(1,1e7));
        for(int i=0;i<10;i++)CASE(N = 2 * rnd.nextLongLong(1,NMAX / 2));
    }

private:
};
