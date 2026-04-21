#include <bits/stdc++.h>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    Evil(int st_ = 0, int ed_ = 0, int val_ = 0) : st(st_), ed(ed_), val(val_), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 0;
        if (len > 0) {
            data = new int[len];
            for (int i = 0; i < len; ++i) data[i] = 0;
        } else {
            data = nullptr;
        }
    }

    Evil(const Evil &other) : st(other.st), ed(other.ed), val(other.val), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 0;
        if (len > 0) {
            data = new int[len];
            for (int i = 0; i < len; ++i) data[i] = other.data[i];
        }
    }

    int &operator[](int i) {
        if (ed >= st && data) {
            if (i < st || i > ed) {
                return data[0];
            }
            return data[i - st];
        } else {
            if (!data) {
                data = new int[1];
                data[0] = 0;
                st = ed = st;
            }
            return data[0];
        }
    }

    Evil &operator=(const Evil &other) {
        if (this == &other) return *this;
        delete[] data;
        data = nullptr;
        st = other.st;
        ed = other.ed;
        val = other.val;
        int len = (ed >= st) ? (ed - st + 1) : 0;
        if (len > 0) {
            data = new int[len];
            for (int i = 0; i < len; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    Evil &operator++() { ++val; return *this; }
    Evil operator++(int) { Evil tmp(*this); ++val; return tmp; }

    friend ostream &operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int len = (e.ed >= e.st) ? (e.ed - e.st + 1) : 0;
        for (int i = 0; i < len; ++i) os << e.data[i] << " ";
        os << '\n';
        return os;
    }

    ~Evil() { delete[] data; data = nullptr; }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int type;
        cin >> type;

        int test_0_st, test_0_ed, test_0_val;
        cin >> test_0_st >> test_0_ed >> test_0_val;
        Evil test_0_0(test_0_st, test_0_ed, test_0_val);

        if (type == 0){
            test_0_0.Print();
            Evil test_0_1;
            test_0_1.Print();
        }
        if(type == 1){
            Evil test_1_1;
            test_1_1 = test_0_0;
            test_1_1.Print(); 
        }
        if(type == 2){
            for(int i = test_0_st;i <= test_0_ed;++i) test_0_0[i] = i;
            test_0_0[test_0_st-1] = test_0_st-1;
            cout << test_0_0[test_0_st-1] << " " << test_0_0[test_0_ed+1] <<" ";
            test_0_0.Print();
        }
        if(type == 3){
            test_0_0++;
            test_0_0++;
            test_0_0.Print();
            
            ++test_0_0; ++test_0_0;
            test_0_0.Print();
        }
        if(type == 4){
            cout << test_0_0;
        }
    }
    return 0;
}
