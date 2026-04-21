#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    // 构造函数：默认值为0，data初始化为nullptr或全0数组
    Evil(int st_ = 0, int ed_ = 0, int val_ = 0) : st(st_), ed(ed_), val(val_), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 0;
        if (len > 0) {
            data = new int[len];
            for (int i = 0; i < len; ++i) data[i] = 0;
        } else {
            data = nullptr;
        }
    }

    // 拷贝构造函数（为安全与赋值一致，避免浅拷贝）
    Evil(const Evil &other) : st(other.st), ed(other.ed), val(other.val), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 0;
        if (len > 0) {
            data = new int[len];
            for (int i = 0; i < len; ++i) data[i] = other.data[i];
        }
    }

    // 下标运算符重载：返回对第i天能量值的引用；若不在范围，返回第st天的能量值
    int &operator[](int i) {
        if (ed >= st && data) {
            if (i < st || i > ed) {
                return data[0];
            }
            return data[i - st];
        } else {
            // 当没有有效区间时，确保返回一个可写引用；创建一个长度为1的data
            if (!data) {
                data = new int[1];
                data[0] = 0;
                st = ed = st; // 区间无效情况下保持st==ed
            }
            return data[0];
        }
    }

    // 赋值运算符重载：深拷贝
    Evil &operator=(const Evil &other) {
        if (this == &other) return *this;

        // 释放原有资源
        delete[] data;
        data = nullptr;

        // 拷贝基本成员
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

    // 前缀++：val加1并返回自身引用
    Evil &operator++() {
        ++val;
        return *this;
    }

    // 后缀++：val加1，返回自增前的拷贝
    Evil operator++(int) {
        Evil tmp(*this);
        ++val;
        return tmp;
    }

    // 输出重载：输出val与data[st..ed]
    friend ostream &operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int len = (e.ed >= e.st) ? (e.ed - e.st + 1) : 0;
        for (int i = 0; i < len; ++i) {
            os << e.data[i] << " ";
        }
        os << '\n';
        return os;
    }

    // 析构函数：释放data
    ~Evil() {
        delete[] data;
        data = nullptr;
    }

    // 为与题面等价，保留Print函数
    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif//EVIL_HPP

