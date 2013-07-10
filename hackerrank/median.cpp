#include <iostream>
#include <set>
#include <iterator>
#include <limits>

double getMedian(std::multiset<int>& maxSet, std::multiset<int>& minSet);
void balance(std::multiset<int>& maxSet, std::multiset<int>& minSet);
void dump(std::multiset<int>& s);

int main() {
    std::multiset<int> maxSet;
    std::multiset<int> minSet;
    std::multiset<int>::iterator it;
    std::cout.precision(std::numeric_limits<double>::digits10);
    size_t sz;
    char op;
    int num;
    int n;
    std::cin >> n;

    double median = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        std::cin >> op >> num;
        switch(op) {
            case 'a':
                if (num < median)
                    maxSet.insert(num);
                else
                    minSet.insert(num);

                balance(maxSet, minSet);
                median = getMedian(maxSet, minSet);
                std::cout << median << std::endl;
                break;
            case 'r':
                it = maxSet.find(num);
                if (it != maxSet.end()) {
                    maxSet.erase(it);
                    balance(maxSet, minSet);
                    if (maxSet.size() + minSet.size() == 0) {
                        std::cout << "Wrong!" << std::endl;
                        break;
                    }
                    median = getMedian(maxSet, minSet);
                    std::cout << median << std::endl;
                    break;
                } else {
                    it = minSet.find(num);
                    if (it != minSet.end()) {
                        minSet.erase(it);
                        balance(maxSet, minSet);
                        if (maxSet.size() + minSet.size() == 0) {
                            std::cout << "Wrong!" << std::endl;
                            break;
                        }
                        median = getMedian(maxSet, minSet);
                        std::cout << median << std::endl;
                        break;
                    } else {
                        std::cout << "Wrong!" << std::endl;
                        break;
                    }
                }
                break;
            default:
                std::cout << "Incorrect operation" << std::endl;
        }
    }
}

void balance(std::multiset<int>& maxSet, std::multiset<int>& minSet) {
    if (maxSet.size() > minSet.size() && maxSet.size() - minSet.size() > 1) {
        minSet.insert(*maxSet.rbegin());
        std::multiset<int>::iterator it = maxSet.find(*maxSet.rbegin());
        maxSet.erase(it);
    } else if (minSet.size() > maxSet.size() && minSet.size() - maxSet.size() > 1) {
        maxSet.insert(*minSet.begin());
        minSet.erase(minSet.begin());
    }
}

double getMedian(std::multiset<int>& maxSet, std::multiset<int>& minSet) {
    size_t sz = maxSet.size() + minSet.size();
        
    if (sz % 2) { // odd
        if (maxSet.size() > minSet.size()) {
            return *maxSet.rbegin();
        } else {
            return *minSet.begin();
        }
    } else { // even
        double c = *maxSet.rbegin();
        c += *minSet.begin();
        return c / 2;
    }
}

void dump(std::multiset<int>& s) {
    for (std::multiset<int>::iterator it = s.begin(); it != s.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
}

