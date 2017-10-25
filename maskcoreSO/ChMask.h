//
// Created by jack on 17-10-18.
//

#ifndef MASKCORESO_CHMASK_H
#define MASKCORESO_CHMASK_H

#include "MaskFunction.h"
//using namespace std;
static int call_times = 0;//当前so被调用的次数
typedef map <MaskFunction* ,int> obj_times_map;//对象指针与时间map
static map <int,obj_times_map> pid_obj;//进程号与对象指针map
class ChMask: public MaskFunction {
public:
    ChMask() :
            LEN(0), SCALE(0) {
    }
    void find(type_anymap &input);
    void mask(type_anymap &input);
    ~ChMask() {

    }
private:
    string RETNAME, COL;
    int LEN, SCALE;
};

#endif //MASKCORESO_CHMASK_H
