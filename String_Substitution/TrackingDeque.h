#ifndef TrackingDeque_H
#define TrackingDeque_H

#include<deque>

using namespace std;
template <class T>
class TrackingDeque:public deque<T>
{
    public:
        TrackingDeque();
        void push_back(T a);
        void push_front(T a);
        ~TrackingDeque();
        int max_size;
};
#endif
