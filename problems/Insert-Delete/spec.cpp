#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int QMAX = 1e5;
    const int AMAX = 1e5;
    const int KMAX = 10;

    int N, Q;
    vector<int> val;
    vector<int> op;
    vector<vector<int>> data;

    vector<long long> ans;
    void InputFormat() {
        LINE(N);
        LINE(val % SIZE(N));

        LINE(Q);
        LINES(op, data) % SIZE(Q);
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
        CONS(query_cons(op, data));
    }

private:
    bool query_cons(vector<int> &ope, vector<vector<int>> &queRyS){
        if (ope.size() != Q) return false;
        if (queRyS.size() != Q) return false;

        int cnt = N;
        for(int i = 0; i < Q; i++) {
            if (ope[i] < 1 || ope[i] > 6) return false;
            if (ope[i] == 1) {
                if (queRyS[i].size() != 1) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > AMAX) return false;
                cnt++;
            } else if (ope[i] == 2) {
                if (queRyS[i].size() != 1) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > cnt) return false;
                cnt--;
            } else if (ope[i] == 3) {
                if (queRyS[i].size() != 1) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > cnt) return false;
            } else if (ope[i] == 4) {
                if (queRyS[i].size() != 2) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > cnt) return false;
                if (queRyS[i][1] < queRyS[i][0] || queRyS[i][1] > cnt) return false;
            } else if (ope[i] == 5) {
                if (queRyS[i].size() != 1) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > KMAX) return false;
            } else if (ope[i] == 6) {
                if (queRyS[i].size() != 1) return false;
                if (queRyS[i][0] < 1 || queRyS[i][0] > KMAX) return false;
            }
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "5 5 6 6 2",
            "6",
            "1 4",
            "2 6",
            "5 3",
            "6 2",
            "3 2",
            "4 2 4",
        });
        Output({
            "5",
            "17",
        });
    }

    void BeforeTestCase(){
        val.clear();
        op.clear();
        data.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(N = 10,
                random_array(N, val, 10),
                Q = 10,
                random_queRyS(N, Q, 10, 2, op, data));
        for(int i=0;i<10;i++)
            CASE(N = 100,
                random_array(N, val, 100),
                Q = 100,
                random_queRyS(N, Q, 100, 4, op, data));
        for(int i=0;i<10;i++)
            CASE(N = 1000,
                random_array(N, val, 1000),
                Q = 1000,
                random_queRyS(N, Q, 1000, 6, op, data));
        for(int i=0;i<10;i++)
            CASE(N = NMAX,
                random_array(N, val, AMAX),
                Q = QMAX,
                random_queRyS(N, Q, AMAX, KMAX, op, data));
        for(int i=0;i<10;i++)
            CASE(N = rnd.nextInt(1, NMAX),
                random_array(N, val, AMAX),
                Q = rnd.nextInt(1, QMAX),
                random_queRyS(N, Q, AMAX, KMAX, op, data));
    }

private:
    void random_array(int n, vector<int>& val, int nmax){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
    }

    void random_queRyS(int n, int q, int amax, int kmax, vector<int>& ope, vector<vector<int>>& queRyS){
        int cnt = n;
        for(int i=0;i<q;i++) {
            int t;
            do {
                t = rnd.nextInt(1, 6);
            } while(t == 2 && cnt == 1);

            vector<int> IRyS;
            if (t == 1) {
                int x = rnd.nextInt(1, amax);
                IRyS.push_back(x);
                cnt++;
            } else if (t == 2) {
                int x = rnd.nextInt(1, cnt);
                IRyS.push_back(x);
                cnt--;
            } else if (t == 3) {
                int x = rnd.nextInt(1, cnt);
                IRyS.push_back(x);
            } else if (t == 4) {
                int l = rnd.nextInt(1, cnt);
                int r = rnd.nextInt(l, cnt);

                IRyS.push_back(l);
                IRyS.push_back(r);
            } else if (t == 5) {
                int x = rnd.nextInt(1, kmax);
                IRyS.push_back(x);
            } else if (t == 6) {
                int x = rnd.nextInt(1, kmax);
                IRyS.push_back(x);
            }

            ope.push_back(t);
            queRyS.push_back(IRyS);
        }
    }
};
