//
// Created by jack on 17-10-18.
//
#include "MaskFunction.h"
#include "MaskFunChoose.h"
#include <dlfcn.h>
int MaskFunChoose::choose(int a) {
    type_anymap test_input ;
    void *so_handle;
    if (a==1){
        so_handle = dlopen("libNmMask.so",  RTLD_GLOBAL | RTLD_LAZY);
    }else{
        so_handle = dlopen("libChMask.so",  RTLD_GLOBAL | RTLD_LAZY);
    }



    if (!so_handle) {
        cerr << "dlopen failed: " << dlerror() << '\n';
        return -1;
    }


    create_maskfunction *create_mf = (create_maskfunction *) dlsym(so_handle, "create_mf");
    const char * dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'create' : " << dlsym_error << '\n';
        return -1;
    }
    MaskFunction *mf = create_mf();
    mf->setParam(test_input,test_input);
    mf->mask(test_input,test_input);

    destory_maskfunction *dm = (destory_maskfunction *) dlsym(so_handle, "destory_mf");
    dm(mf);

    dlclose(so_handle);
    return 0;
}

extern "C" {
MaskFunChoose *create_mfc(void) // 注意：create函数必须返回Base的对象，不能直接返回A的
//      对象，否则后面调用A::add()的时候会提示错误。
{
    return new MaskFunChoose;
}

void destory_mfc(MaskFunChoose *p) {
    if (p) delete p;
}
}