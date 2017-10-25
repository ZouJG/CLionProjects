#include <iostream>
#include <dlfcn.h>
#include "MaskFunction.h"
//#include "MaskFunChoose.h"
using namespace std;

int main() {

    std::cout << "Hello, World!" << std::endl;

    void *so_handle = dlopen("libChMask.so",  RTLD_GLOBAL | RTLD_LAZY);
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
    MaskFunction *mf1 = create_mf(1);
    MaskFunction *mf2 = create_mf(1);
    MaskFunction *mf3 = create_mf(2);


    destory_maskfunction *dm = (destory_maskfunction *) dlsym(so_handle, "destory_mf");
    dm(1);

    dlclose(so_handle);



    return 0;
}