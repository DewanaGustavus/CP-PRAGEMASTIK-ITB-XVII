#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int SUM_NMAX = 2e5;
    const int AMAX = 1e5;
    int T;
    vector<vector<int>> data;
    vector<int> val;

    vector<string> ans;
    void InputFormat() {
        LINE(T);
        LINES(data) % SIZE(3 * T);
    }

    void OutputFormat1() {
        LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<vector<int>> &data){
        int sum_n = 0;
        if(data.size() != 3 * T)return false;
        for(int i = 0; i < T;i += 3) {
            if (data[i].size() != 1) return false;

            int N = data[i][0];
            sum_n += N;
            if(sum_n > SUM_NMAX) return false;

            if (data[i+1].size() != N) return false;
            if (data[i+2].size() != N) return false;

            for (int j = 0; j < N; j++) {
                if (data[i+1][j] < -AMAX || data[i+1][j] > AMAX) return false;
                if (data[i+2][j] < -AMAX || data[i+2][j] > AMAX) return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "5",
            "4 2 1 4 6",
            "6 4 2 6 5",
            "5",
            "1 2 3 4 5",
            "6 6 6 6 6",
        });
        Output({
            "Ya",
            "Tidak",
        });
    }

    void BeforeTestCase(){
        data.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)
            CASE(T = 1, random_data(T, 10, data, AMAX));
        for(int i=0;i<10;i++)
            CASE(T = 10, random_data(T, 100, data, AMAX));
        for(int i=0;i<10;i++)
            CASE(T = 100, random_data(T, 1000, data, AMAX));
        for(int i=0;i<5;i++)
            CASE(T = 2, random_data(T, 1e5, data, AMAX));
        for(int i=0;i<5;i++)
            CASE(T = 20, random_data(T, 1e4, data, AMAX));
        for(int i=0;i<10;i++)
            CASE(T = 1000, random_data(T, 100, data, AMAX));
        for(int i=0;i<10;i++)
            CASE(T = 1e3, random_data(T, 200, data, AMAX));
        for(int i=0;i<10;i++)
            CASE(T = 1e4, random_data(T, 20, data, AMAX));
    }

private:
    void random_data(int t, int nmax, vector<vector<int>>& data, int amax){
        for(int i=0;i<t;i++) {
            int n = rnd.nextInt(1, nmax);
            vector<int> vec_n(1, n);
            data.push_back(vec_n);
            
            vector<int> vec_a = random_array(n, amax);
            vector<int> vec_b = random_array(n, amax);
            data.push_back(vec_a);
            data.push_back(vec_b);
        }
    }
    
    vector<int> random_array(int n, int nmax){
        vector<int> val;
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(0, 2 * nmax) - nmax);
        }
        return val;
    }
};
