//
// Created by jack on 17-10-10.
//

#ifndef TESTSO_TESTMATH_H
#define TESTSO_TESTMATH_H
class TestMath{
public:
    virtual int cal(int a,int b){
        return 0;
    }

};

extern "C" {
TestMath *create(void);

void destroy(TestMath *p);


typedef TestMath *create_math(void);  // create factory
typedef void destory_math(TestMath *); // destory
}

// typedef 
// typedef 

#endif //TESTSO_TESTMATH_H
