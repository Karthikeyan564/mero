//
// Created by karthikeyan on 18/08/20.
//

#include "mem_mgr.h"

#include<iostream>

#define err(condition) if(condition){std::cerr<<"\n"<<__FILE__<<":"<<__LINE__<<": "<<#condition<<'\n';}


namespace eigwrap {

    template<typename T>
    void mem_ptr<T>::handle_prev() {
        if (data_ptr != nullptr) {
            if (*cnt == 1) {

                delete[] data_ptr;
                delete cnt;
            } else {
                *cnt = *cnt - 1;
            }
        }
        data_ptr = nullptr;
        cnt = nullptr;
        data_size = 0;
    }

    template<typename T>
    mem_ptr<T>::mem_ptr(){
        cnt = nullptr;
        data_ptr = nullptr;
    }
    template<typename T>
    mem_ptr<T>::~mem_ptr(){
        handle_prev();
    }
    template<typename T>
    T* mem_ptr<T>::get(){
        return data_ptr;
    }

    template<typename T>
    mem_ptr<T>::mem_ptr(mem_ptr &t){
        if(t.data_ptr != data_ptr){
            handle_prev();
            data_ptr = t.data_ptr;
            cnt = t.cnt;
            *cnt+=1;
            data_size= t.data_size;
        }
    }
    template<typename T>
    void mem_ptr<T>::create_mem(long size){
        err(size<1)
        handle_prev();
        data_ptr = new T[size];
        cnt = new int{1};
        data_size=size;
    }

    template<typename T>
    void mem_ptr<T>::free_mem(){
        handle_prev();
    }
    template<typename T>
    void mem_ptr<T>::set(T* t,long size){
        if(t != data_ptr){
            handle_prev();
            data_ptr = t;
            cnt = new int{1};
            data_size = size;
        }
    }
    template<typename T>
    void mem_ptr<T>::operator=(const mem_ptr &t){
        if(t.data_ptr != data_ptr){
            handle_prev();
            data_ptr = t.data_ptr;
            cnt = t.cnt;
            *cnt+=1;
            data_size= t.data_size;
        }
    }
    template<typename T>
    int mem_ptr<T>::get_cnt(){

        err(cnt==nullptr)
        return *cnt;
    }
    template<typename T>
    long mem_ptr<T>::get_size(){
        return data_size;
    }
    template<typename T>
    void mem_ptr<T>::init(T element){
        for(int i=0;i<data_size;i++){
            *(data_ptr+i)=element;
        }
    }
    template<typename T>
    bool mem_ptr<T>::operator ==(const T* t){
        return (t==data_ptr)?true:false;
    }
    template class mem_ptr<int>;
}



