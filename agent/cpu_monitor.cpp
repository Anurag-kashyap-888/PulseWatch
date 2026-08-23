#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using LL = long long;

 typedef struct{
    LL user;
    LL nice;
    LL system;
    LL idle;
    LL iowait;
    LL irq;
    LL softirq;
    LL steal;
    LL guest;
    LL guest_nice;
    bool valid;
} CpuStats;

CpuStats readCpuStats(){
    CpuStats temp;
    temp.valid=false;
    std::ifstream file("/proc/stat");
    if (!file.is_open()){
        std::cout << "failed to open /proc/stat\n";
        return temp;
    }
    std::string line;
    std::getline(file,line);
    std::istringstream newStream(line);
    std::string cpuLabel;
    newStream >> cpuLabel;
    newStream >> temp.user;
    newStream >> temp.nice;
    newStream >> temp.system;
    newStream >> temp.idle;
    newStream >> temp.iowait;
    newStream >> temp.irq;
    newStream >> temp.softirq;
    newStream >> temp.steal;
    newStream >> temp.guest;
    newStream >> temp.guest_nice;
    temp.valid=true;
    return temp;
}

CpuStats calculateCpuDelta(CpuStats T1,CpuStats T2){
    CpuStats temp;
    temp.valid=false;
    temp.user=T2.user-T1.user;
    temp.nice=T2.nice-T1.nice;
    temp.system=T2.system-T1.system;
    temp.idle=T2.idle-T1.idle;
    temp.iowait=T2.iowait-T1.iowait;
    temp.irq=T2.irq-T1.irq;
    temp.softirq=T2.softirq-T1.softirq;
    temp.steal=T2.steal-T1.steal;
    temp.guest=T2.guest-T1.guest;
    temp.guest_nice=T2.guest_nice-T1.guest_nice;
    temp.valid=true;
    return temp;
}

calculateCpuUsage(Delta){
}

int main(){
    CpuStats T1=readCpuStats();
    delay(1);
    CpuStats T2=readCpuStats();
    CpuStats T;
    T.valid=false;
    if(T1.valid && T2.valid) T=calculateCpuDelta(T1,T2);
    //pausing here
    return 0;
}