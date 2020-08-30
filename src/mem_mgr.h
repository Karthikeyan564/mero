//
// Created by karthikeyan on 18/08/20.
//

#ifndef MERO_MEM_MGR_H
#define MERO_MEM_MGR_H

namespace eigwrap{
    template<typename T>
    class mem_ptr{
        T* data_ptr;

        int* cnt;

        long data_size;

        void handle_prev();

    public:
        mem_ptr();

        ~mem_ptr();

        T* get();

        mem_ptr(mem_ptr &t);

        void operator=(const mem_ptr &t);

        void create_mem(long size);

        void free_mem();

        void set(T* t,long size);

        int get_cnt();

        long get_size();

        void init(T element);

        bool operator ==(const T* t);

    };
}


#endif //MERO_MEM_MGR_H
