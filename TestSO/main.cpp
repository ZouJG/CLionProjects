#include <iostream>
#include <dlfcn.h>
#include "FuncChoose.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    void *so_handle = dlopen("libFC.so",  RTLD_GLOBAL | RTLD_LAZY);
    if (!so_handle) {
        cerr << "dlopen failed: " << dlerror() << '\n';
        return -1;
    }


    create_choose *create_c = (create_choose *) dlsym(so_handle, "create_c");
    const char * dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'create' : " << dlsym_error << '\n';
        return -1;
    }
    FuncChoose *tm = create_c();

    cout << "The area is : " << tm->choose(1) << '\n';
    cout << "The area is : " << tm->choose(2) << '\n';

    destory_choose *dm = (destory_choose *) dlsym(so_handle, "destory");

    // int a = tm->TestADD


    dm(tm);
    dlclose(so_handle);




//    void *so_handle = dlopen("libTestADD.so",  RTLD_GLOBAL | RTLD_LAZY);
//    if (!so_handle) {
//        cerr << "dlopen failed: " << dlerror() << '\n';
//        return -1;
//    }
//
//
//    create_math *create = (create_math*) dlsym(so_handle, "create");
//    const char * dlsym_error = dlerror();
//    if (dlsym_error) {
//        cerr << "Cannot load symbol 'create' : " << dlsym_error << '\n';
//        return -1;
//    }
//    TestMath *tm = create();
//
//    cout << "The area is : " << tm->cal(1,2) << '\n';
//
//    destory_math *dm = (destory_math*) dlsym(so_handle, "destory");
//
//    // int a = tm->TestADD
//
//
//    dm(tm);
//    dlclose(so_handle);




    return 0;



}