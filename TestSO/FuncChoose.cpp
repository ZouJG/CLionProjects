//
// Created by jack on 17-10-18.
//
#include <iostream>
#include "FuncChoose.h"
#include <dlfcn.h>
#include "TestMath.h"
using namespace std;

int FuncChoose::choose(int a){
    void *so_handle;
    if (a==1){
        so_handle = dlopen("libTestADD.so",  RTLD_GLOBAL | RTLD_LAZY);
    }else{
        so_handle = dlopen("libTestSUB.so",  RTLD_GLOBAL | RTLD_LAZY);
    }



    if (!so_handle) {
        cerr << "dlopen failed: " << dlerror() << '\n';
        return -1;
    }


    create_math *create = (create_math*) dlsym(so_handle, "create");
    const char * dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'create' : " << dlsym_error << '\n';
        return -1;
    }
    TestMath *tm = create();
    //    dm(tm);
//    dlclose(so_handle);
    return tm->cal(1,1) ;
}
extern "C" {
FuncChoose *create_c(void) // 注意：create函数必须返回Base的对象，不能直接返回A的
//      对象，否则后面调用A::add()的时候会提示错误。
{
    return new FuncChoose;
}

void destory_c(FuncChoose *p) {
    if (p) delete p;
}
}
