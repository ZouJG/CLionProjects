//
// Created by jack on 17-10-18.
//

#ifndef MASKCORESO_MASKFUNCHOOSE_H
#define MASKCORESO_MASKFUNCHOOSE_H
class MaskFunChoose{
public:
    virtual int choose(int a);

};

extern "C" {
MaskFunChoose *create_mfc(void);

void destroy_mfc(MaskFunChoose *p);


typedef MaskFunChoose *create_choose(void);  // create factory
typedef void destory_choose(MaskFunChoose *); // destory
}

#endif //MASKCORESO_MASKFUNCHOOSE_H
