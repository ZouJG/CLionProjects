//
// Created by jack on 17-10-18.
//

#ifndef MASKCORESO_NMMASK_H
#define MASKCORESO_NMMASK_H

#insing namespace std;


//全局变量，加静态成员变量
static int times = 1;
class NmMask: public MaskFunction {
public:
    NmMask() :
            LEN(0), SCALE(0) {
    }
    void find(type_anymap &inputt);
    void mask(type_anymap &input);
    ~NmMask() {

    }
private:
    string RETNAME, COL;
    int LEN,SCALE;
//    clude "MaskFunction.h"
//u
};

#endif //MASKCORESO_NMMASK_H
