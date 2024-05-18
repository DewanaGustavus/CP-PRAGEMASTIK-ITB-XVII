#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const long long KMAX = 1000000000000000000;
    const int A_LEN_MAX = 100;
    int N;
    long long K;
    vector<string> val;

    int ans;
    void InputFormat() {
        LINE(N, K);
        LINES(val);
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
        CONS(array_cons(val));
    }

private:
    bool array_cons(vector<string> &val){
        if(val.size() != N)return false;
        for(string s : val){
            if(s.length() > A_LEN_MAX || s.empty()) return false;
            for(char c : s) {
                int v = (int)c - '0';
                if(v < 0 || v > 9) return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3 3",
            "1",
            "4",
            "7"
        });
        Output({
            "9"
        });
    }

    void SampleTestCase2() {
        Input({
            "2 3",
            "1",
            "1"
        });
        Output({
            "0"
        });
    }

    void BeforeTestCase(){
        val.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(N = 10,
                K = 10,
                random_array(N, val, 1));
        for(int i=0;i<10;i++)
            CASE(N = 100,
                K = 1000,
                random_array(N, val, 10));
        for(int i=0;i<10;i++)
            CASE(N = 1000,
                K = 1e5,
                random_array(N, val, 30));
        for(int i=0;i<10;i++)
            CASE(N = NMAX,
                K = KMAX,
                random_array(N, val, A_LEN_MAX));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                K = rnd.nextLongLong(1, KMAX),
                random_array(N, val, rnd.nextInt(1, A_LEN_MAX)));
    }

private:
    void random_array(int n, vector<string>& val, int a_len_max){
        for(int i=0;i<n;i++){
            val.push_back(random_int_string(rnd.nextInt(1, a_len_max)));
        }
    }

    string random_int_string(int len) {
        string s;
        for(int i = 0; i < len; i++) {
            int x = rnd.nextInt(0, 9);
            s.push_back(x + '0');
        }
        if (s[0] == '0') {
            s[0] = '1';
        }
        return s;
    }
};
