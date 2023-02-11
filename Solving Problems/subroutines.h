#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <type_traits>

using namespace std;

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

class CoreProblem {
private:
    void virtual testCases() = 0;
};


// fill randomly vector


// Overloading operator<< for any kind of vector.
// std::vector<T>
// std::vector< std::vector< ...> >
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        os << T(*i);
        if (i + 1 != vec.end())
            os << ", ";
    }
    os << "]";

    return os;
}

template<typename... T>
//typename enable_if<are_streamable<T ...>::value, ostream&>::type
std::ostream&
operator<<(std::ostream& os, const std::priority_queue<T ...>& pq) {
    priority_queue<T ...> pq_temp(pq);
    
    os << "[ ";

    while (!pq_temp.empty()) {
        os << pq_temp.top() << " ";
        pq_temp.pop();
    }
    os << "]";

    return os;
}

// Overloading operator<< for any kind of vector.
template<class T1, class T2>
std::ostream& operator<<(ostream& os, const vector<pair<T1, T2>>& pairs) {
    os << "[";

    for (auto i = pairs.begin(); i != pairs.end(); ++i) {
        os << "(" << i->first << ", " << i->second << ")";
        if (i + 1 != pairs.end())
            os << " ";
    }
    os << "]";

    return os;
}
