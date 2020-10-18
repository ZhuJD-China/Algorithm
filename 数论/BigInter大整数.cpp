#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//存储高精度非负整数
struct BigInteger {
    static const int BASE = 10000000;   //10^8
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long num = 0) { *this = num; }  //构造函数

    BigInteger operator = (long long num) {         //赋值运算符 =num
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }

    BigInteger operator = (const string& str) {     //赋值运算符 =string
        s.clear();
        int x;
        int len = (str.length() - 1)/WIDTH + 1;
        for(int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator + (const BigInteger& b) const { //算术运算符 +
        BigInteger c;
        c.s.clear();
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }

    BigInteger operator += (const BigInteger& b) {	//赋值运算符，+=
        *this = *this + b;
        return *this;
    }

	//关系运算符：<  >  <=  >=  !=  ==
    bool operator < (const BigInteger& b) const {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size()-1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;   //equal
    }
    bool operator > (const BigInteger& b) const { return b < *this; }
    bool operator <= (const BigInteger& b) const { return !(b < *this); }
    bool operator >= (const BigInteger& b) const { return !(*this < b); }
    bool operator != (const BigInteger& b) const { return b < *this || *this < b; }
    bool operator == (const BigInteger& b) const { return !(b < *this) && !(*this < b); }
};

//输出运算符 <<
ostream& operator << (ostream &out, const BigInteger& x) {
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}
//输入运算符 >>
istream& operator >> (istream &in, BigInteger& x) {
    string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
}

int main()
{
    BigInteger x = 987654321;
    cout<<x<<endl;

    BigInteger y = 123456789;
    cout<< x+y <<endl;

    x += 111111111;
    cout<< x <<endl;

    if(x < y) cout<<"x<y"<<endl;
    else if(x == y) cout<<"x==y"<<endl;
    else cout<<"x>y"<<endl;
    return 0;
}

