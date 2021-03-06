//
// Created by 周亮 on 2019/4/17.
//
//#include"head/LL.h"
#include "head/LR.h"
#include<iostream>
#include<string>
#include "head/LL.h"
using namespace std;

void test_ll(){
    string test[4];

    /*
        A->BAt|a;
        B->b|@;
        推导不出First(A)包含t;//包含左递归了，但是按照算法3.2无法除去左递归
    */

    //这样可以推导出First(A)中包含t
    test[0] = "L->E;L|@";
    test[1] = "E->E+T|E-T|T";
    test[2] = "T->T*F|T/F|T$mod$F|F";
    test[3] = "F->(E)|$id$|$num$";


    //test[2] = "A1->c$A1$|ad$A1$|@";

    ll_grammar::GrammarLeft c(test, 4);

    c.sim("$id$+$id$*$id$;#");

}

void test_lr(){
    string test[4];

    /*
    A->BAt|a;
    B->b|@;
    推导不出First(A)包含t;//包含左递归了，但是按照算法3.2无法除去左递归???????????????
    */

    //这样可以推导出First(A)中包含t

    test[0] = "E->E-T|T";//"L->E;L|@";
    test[1] = "T->T*F|F";//"E->E+T|E-T|T";
    test[2] = "F->-F|$id$";//"T->T*F|T/F|T$mod$F|F";
    //test[3] = "F->(E)|$id$|$num$";

    //test[2] = "A1->c$A1$|ad$A1$|@";

    lr_grammar::GrammarLR c(test, 3);

    c.sim("$id$--$id$*$id$#");

}


int main(){
    //test_ll();
    test_lr();
    return 0;
}