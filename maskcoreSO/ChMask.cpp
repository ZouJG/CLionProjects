//
// Created by jack on 17-10-18.
//
#include "ChMask.h"


// 设置参数
void ChMask::find(type_anymap &input) {

    cout << "ChMask::setParam" << std::endl;

}
// 漂白函数
void ChMask::mask(type_anymap &input) {
    cout << "ChMask::mask" << std::endl;

}

extern "C" {
MaskFunction*create_mf(int pid) // 创建时传进程号
{


    if (call_times!=0){//不是第一次调用时，先检查当前进程是否存在，如果存在，则直接返回
        map<int,obj_times_map>::iterator key = pid_obj.find(pid);//查找进程号是否存在
        if(key!=pid_obj.end())
        {
            obj_times_map::iterator temp_map_ite = pid_obj[pid].begin();//返回obj_times_map的第一个
            return temp_map_ite->first;//
        }
    }
    //第一次调用或者当前进程不存在时，将此次调用存入map
    struct timeval tv;

    gettimeofday(&tv,NULL);//取时间

    MaskFunction* ch_mask_now = new ChMask;//当前对象

    obj_times_map temp;

    temp.insert(pair<MaskFunction*,int>(ch_mask_now,tv.tv_sec));

    pid_obj.insert(pair <int,obj_times_map> (pid,temp));//放入map

    ++call_times;//调用次数+1
//    cout << call_times << std::endl;

    return ch_mask_now;
}

void destory_mf(int pid) {//按进程号删除对象

    struct timeval tv;

    gettimeofday(&tv,NULL);//取时间

    map<int,obj_times_map>::iterator key = pid_obj.find(pid);
    if(key!=pid_obj.end())//查找进程号是否存在，存在则擦除
    {
        pid_obj.erase(key);

    }
    //再按时间查找一次，以防有漏掉的

    map<int,obj_times_map>::iterator pid_ite = pid_obj.begin();
    while(pid_ite!= pid_obj.end()){
        obj_times_map::iterator temp_map_ite = pid_ite->second.begin();
        if (temp_map_ite->second-tv.tv_sec>600) {//存在10分钟以上
            pid_obj.erase(pid_ite);
        }
        ++pid_ite;
    }
}
}