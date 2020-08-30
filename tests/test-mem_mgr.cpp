//
// Created by karthikeyan on 30/08/20.
//

#include "catch.hpp"
#include<iostream>
#include "../src/mem_mgr.h"

TEST_CASE("Copying mem_mgr"){
    eigwrap::mem_ptr<int> t,x,y;
    t.create_mem(10);
    REQUIRE(t.get_cnt()==1);
    x=t;
    REQUIRE(x.get_cnt()==2);
    REQUIRE(x.get_size()==10);
    t.free_mem();
    REQUIRE(t.get_size()==0);
    REQUIRE(x.get_cnt()==1);
    REQUIRE(x.get_size()==10);
    x.free_mem();
    REQUIRE(x.get_size()==0);
}