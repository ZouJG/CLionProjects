//
// Created by jack on 17-10-18.
//

#ifndef MASKCORESO_MASKFUNCTION_H
#define MASKCORESO_MASKFUNCTION_H

#include <iostream>
#include <map>
#include <string>
#include <boost/any.hpp>
#include <sys/time.h>
using namespace std;
typedef std::map<std::string, boost::any> type_anymap;
class MaskFunction {
public:
//构造函数
    MaskFunction() {
    }
// 参数设置
// info-参数
// ret-返回信息
    virtual void find(type_anymap &info) {
    }
// 漂白函数
// info -
// out-漂白输出
    virtual void mask(type_anymap &info) {
    }

};

extern "C" {
MaskFunction *create_mf(int pid);

void destroy_mf(int pid);


typedef MaskFunction *create_maskfunction(int pid);  // create factory
typedef void destory_maskfunction(int pid); // destory
}


#endif //MASKCORESO_MASKFUNCTION_H
