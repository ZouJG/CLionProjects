//
// Created by jack on 17-10-18.
//

#ifndef TESTSO_FUNCCHOOSE_H
#define TESTSO_FUNCCHOOSE_H


class FuncChoose{
public:
    virtual int choose(int a);

};

extern "C" {
FuncChoose *create_c(void);

void destroy_c(FuncChoose *p);


typedef FuncChoose *create_choose(void);  // create factory
typedef void destory_choose(FuncChoose *); // destory
}

#endif //TESTSO_FUNCCHOOSE_H
