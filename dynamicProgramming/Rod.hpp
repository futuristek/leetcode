#include <vector>
#include <iostream>

class Rod {
public:
    Rod(const std::vector<int>& price): r(price.size() + 1),
                                        s(price.size() + 1),
                                        p(price.size() + 1) {
        p[0] = 0;
        for (int i = 1; i < p.size(); i++) {
            p[i] = price[i - 1];
        }
    };
    void extBottomUpCut();
    void printCut();

private:
    std::vector<int> p;
    std::vector<int> r;
    std::vector<int> s;
};

/*
idx 0 -> length = 1
idx n - 1 -> length = n
*/
void Rod::extBottomUpCut() {
    for (int i = 1; i < r.size(); i++) {
        auto subr = 0;
        for (int j = 1; j <= i; j++) {
            auto tmpr = p[j] + r[i - j];
            if (tmpr > subr) {
                subr = tmpr;
                s[i] = j;
            }
        }
        r[i] = subr;
    }
}

void Rod::printCut() {
    std::cout << "i " << "r[i] " << "s[i]" << std::endl;
    for (int i = 0; i < p.size(); i++) {
        std::cout << i << " " << r[i] << " " << s[i] << std::endl;
    }
}