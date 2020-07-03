#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>
#include<algorithm>

#include "../include/process.h"
#include "../include/processor.h"
#include "../include/system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

const string KernelNameFilepath ="/proc/version"; 
const string OSnameFilePath="/etc/os-release";
const string StatFilepath="/proc/stat";
const string UptimeFilepath="/proc/uptime";

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    
    string temp1,temp2;
    string version;
    ifstream fin(KernelNameFilepath);
    if(fin)
    {
        fin>>temp1>>temp2>>version;
    }
    return version;  
}
// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return 0.0; }

// DONE: Return the operating system name
std::string System::OperatingSystem()
{ 
    string OSname,Osversion;
    string temp,temp2,key;
    ifstream fin(OSnameFilePath);
    if(fin)
    {   string line;
        while(getline(fin,line))
        {
            std::replace(line.begin(),line.end(),' ','_');
            std::replace(line.begin(),line.end(),'=',' ');
            std::replace(line.begin(),line.end(),'"',' ');
            istringstream stream(line);
            if(stream>>key>>OSname)
            {
              if(key=="PRETTY_NAME")
                break;
            }
            
        }
        std::replace(OSname.begin(),OSname.end(),'_',' ');
    }
    return OSname; 
}

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() { 
    string key,line,running;
    ifstream fin(StatFilepath);
    while(fin)
    {
        getline(fin,line);
        istringstream stream(line);
        if(stream>>key)
        {
            if(key=="procs_running")
            {
                stream>>running;
                break;
            }
        }
    }  
    return stoi(running); 
}

// DONE: Return the total number of processes on the system
int System::TotalProcesses() { 
   string key,line,totalproc;
    ifstream fin(StatFilepath);
    while(fin)
    {
        getline(fin,line);
        istringstream stream(line);
        if(stream>>key)
        {
            if(key=="processes")
            {
                stream>>totalproc;
                break;
            }
        }
    }  
    return stoi(totalproc); 
}

// DONE: Return the number of seconds since the system started running
long int System::UpTime() { 
    string idle,uptime="0";
    ifstream fin(UptimeFilepath);
    if(fin)
    {
        string line;
        getline(fin,line);
        istringstream stream(line);
        stream>>uptime>>idle;
        
    }
    return stol(uptime);
}