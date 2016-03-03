#include"TrackingDeque.h"
#include<iostream>

template <class T>
TrackingDeque<T>::TrackingDeque()
{
    max_size=0;
}

template <class T>
void TrackingDeque<T>::push_back(T a)
{
    deque<T>::push_back(a);
    max_size = max_size < deque<T>::size()?deque<T>::size():max_size;
}

template <class T>
void TrackingDeque<T>::push_front(T a)
{
    deque<T>::push_front(a);
    max_size = max_size < deque<T>::size()?deque<T>::size():max_size;
}

template <class T>
TrackingDeque<T>::~TrackingDeque()
{
    cout  << "--> "<<max_size<<" <--"<<endl;
}

template class TrackingDeque<char>;
