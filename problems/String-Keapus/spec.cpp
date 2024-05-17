#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    string s, t;

    int ans;
    void InputFormat() {
        LINE(s);
        LINE(t);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= s.size() <= NMAX);
        CONS(1 <= t.size() <= NMAX);
        CONS(string_cons(s));
        CONS(string_cons(t));
    }

private:
    bool string_cons(string &val){
        for(char c : val){
            if(c < 'a' || c > 'z')return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "gema",
            "gemagemagggma",
        });
        Output({
            "5"
        });
    }

    void SampleTestCase2() {
        Input({
            "abcdef",
            "bcdefg",
        });
        Output({
            "-1"
        });
    }

    void BeforeTestCase(){
        s.clear();
        t.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(s = randomString(10, 3),
                t = randomString(10, 3));
        for(int i=0;i<10;i++)
            CASE(s = randomString(100, 5),
                t = randomString(100, 5));
        for(int i=0;i<10;i++)
            CASE(s = randomString(1000, 15),
                t = randomString(1000, 15));
        for(int i=0;i<10;i++)
            CASE(s = randomString(NMAX, 25),
                t = randomString(NMAX, 25));
        for(int i=0;i<10;i++)
            CASE(s = randomString(100, 3),
                t = randomString(NMAX, 3));
        for(int i=0;i<10;i++)
            CASE(s = randomString(rnd.nextInt(1, NMAX), 3),
                t = randomString(rnd.nextInt(1, NMAX), 3));
        for(int i=0;i<10;i++)
            CASE(s = randomString(rnd.nextInt(1, NMAX), 3),
                t = randomString(NMAX, 3));
        for(int i=0;i<10;i++)
            CASE(s = randomString(NMAX, 3),
                t = randomString(rnd.nextInt(1, NMAX), 3));

                
        for(int i=0;i<10;i++)
            CASE(s = randomString(100, 3),
                t = randomString(1000, 5));
        for(int i=0;i<10;i++)
            CASE(s = randomString(1000, 15),
                t = randomString(1000, 10));
    }

private:
    string randomString(int n, int c) {
        string str = "";
        for (int i = 0; i < n; i++) {
            str += (char)(rnd.nextInt(0, c) + 'a');
        }
        return str;
    }
};
