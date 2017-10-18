//
// Created by jack on 17-10-10.
//

#include "TestSUB.h"
int TestSUB::cal(int a, int b) {
    return a-b;
}


extern "C" {
TestMath *create(void) // 注意：create函数必须返回Base的对象，不能直接返回A的
//      对象，否则后面调用A::add()的时候会提示错误。
{
    return new TestSUB;
}

void destory(TestMath *p) {
    if (p) delete p;
}
}
