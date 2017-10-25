
//
// Created by jack on 17-10-18.
//
#include "NmMask.h"


// 设置参数
void NmMask::find(type_anymap &input) {

    std::cout << "NmMask::setParam" << std::endl;
//    type_kvmap RET;
    string error,values;
//// 设置漂白字段
    error = getBoostAnyValue<string>(input, COL, "COL");
    RETURN_ERROR(error, ret);
//    string error = getBoostAnyValue<string>(input, value, COL);
//    RETURN_ERROR(error, ret);
//// 变换数据过程
//// 设置字段长度
//    error = getBoostAnyValue<string>(input, len, "LEN");
//    RETURN_ERROR(error, ret);
//// 设置漂白函数返回值
//    error = getBoostAnyValue<type_kvmap>(input, RET, "RET");
//    RETURN_ERROR(error, ret);
//    if (RET.empty()) {
//        ret["error"] = (string) ("漂白函数的返回参数没有设置.");
//        return;
//    } else {
//        type_kvmap::iterator itRet = RET.begin();
//        RETNAME = itRet->first;
//    }
//    LEN = atoi(len.c_str());
//    if (!scale.empty())
//        SCALE = atoi(scale.c_str());
//    else
//        SCALE = -1;
}
// 漂白函数
void NmMask::mask(type_anymap &input) {
    std::cout << "NmMask::mask" << std::endl;

//    string value, srcValue;
//// 获取字段值
//    if (!srcValue.empty() && strcmp(value.c_str(), SELF_NULL)) {
//        int num = value.size();
//        for (int i = 0; i < num; ++i) {
//            value[i] = value[i] + 1;
//        }
//    }
//    ret[RETNAME] = value; // 设置返回值
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