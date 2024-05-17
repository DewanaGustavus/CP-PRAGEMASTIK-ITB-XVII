#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

struct DSU{
    vector<int> link, size;
    int n;
    int component;
    DSU(int length){
        n = length;
        component = length;
        link = vector<int>(n+1);
        size = vector<int>(n+1, 1);
        for (int i = 1; i <= n; i++) link[i] = i;
    }
    
    int find(int x){ // O(log(n))
        int temp=x;
        while(x!=link[x])x=link[x];
        link[temp]=x;
        return x;
    }

    void unite(int a,int b){ // O(log(n))
        a=find(a);
        b=find(b);
        if(a==b)return;
        if(size[a]<size[b])swap(a,b);
        size[a]+=size[b];
        link[b]=a;
        component--;
    }
};

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    int N;
    vector<int> edgesA;
    vector<int> edgesB;

    long long ans;
    void InputFormat() {
        LINE(N);
        LINES(edgesA, edgesB) % SIZE(N-1);
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
        CONS(edges_cons(edgesA, edgesB));
    }

private:
    bool edges_cons(vector<int> edgesA, vector<int> edgesB){
        if(edgesA.size() != N-1 && edgesB.size() != edgesA.size())return false;
        DSU comps(N);
        for(int i=0;i<N-1;i++){
            int a = edgesA[i];
            int b = edgesB[i];
            if(a < 1 || a > N || b < 1 || b > N)return false;
            if(comps.find(a) == comps.find(b)){
                return false;
            }
            comps.unite(a,b);
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void SampleTestCase() {
        Input({
            "5",
            "4 1",
            "1 5",
            "2 4",
            "3 1",
        });
        Output({
            "11"
        });
    }

    void BeforeTestCase(){
        edgesA.clear();
        edgesB.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 10, random_tree(N, edgesA, edgesB));
        for(int i=0;i<10;i++)CASE(N = 100, random_tree(N, edgesA, edgesB));
        for(int i=0;i<10;i++)CASE(N = 1000, random_tree(N, edgesA, edgesB));
        for(int i=0;i<10;i++)CASE(N = 10000, random_tree(N, edgesA, edgesB));
        for(int i=0;i<10;i++)CASE(N = NMAX, random_tree(N, edgesA, edgesB));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(1, NMAX), random_tree(N, edgesA, edgesB));
    }

private:
    void random_tree(int n, vector<int>& edgesA, vector<int>& edgesB){
        DSU container(n);
        for(int i=1;i<n;i++){
            int a,b;
            do{
                a = rnd.nextInt(1, n);
                b = rnd.nextInt(1, n);
            }while(container.find(a) == container.find(b));
            edgesA.push_back(a);
            edgesB.push_back(b);
            container.unite(a,b);
        }
    }
};
