
//
// Created by jack on 17-10-18.
//
#include "NmMask.h"


// 设置参数
void NmMask::find(type_anymap &input) {

    std::cout << "NmMask::setParam" << std::endl;

}
// 漂白函数
void NmMask::mask(type_anymap &input) {
    std::cout << "NmMask::mask" << std::endl;


}

extern "C" {
MaskFunction *create_mf(void) // 注意：create函数必须返回Base的对象，不能直接返回A的
//      对象，否则后面调用A::add()的时候会提示错误。
{

    //        这里先判断这个变量是否为空
//        空的话，创建并加锁，否：直接跳过
    //在这里加上根据id是否创建
    return new NmMask;
}

void destory_mf(MaskFunction *p) {
    if (p) delete p;
}
}