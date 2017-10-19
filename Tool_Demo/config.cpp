#include "config.h"

Config* Config::_instance = NULL;

Config::Config()
{
    pthread_mutex_init(mutex,NULL);
}

void trimString(std::string &str)
{
    int s = str.find_first_not_of(" ");
    int e = str.find_last_not_of(" ");
    str = str.substr(s,e-s+1);
}

static Config* Config::GetInstance()
{

    if(NULL == _instance)
    {
//        pthread_mutex_lock(mutex);
        _instance = new ConfigManage();
//        pthread_mutex_unlock(mutex);
    }
    return _instance;

}

bool Config::ReadConfig(const std::string &filename)
{
    std::ifstream infile(filename);
    if(!infile)
    {
//        LOG4CXX_ERROR(logger,"config file open error");
        return false;
    }
//    LOG4CXX_INFO(logger,"config file open sucess!");
    std::string line,value;
    while(getline(infile,line))
    {
        AnalyseLine(line,  value);
    }
    infile.close();

//    LOG4CXX_INFO(logger,"localport : " << LocalPort);
//    LOG4CXX_INFO(logger,"critical_value : " << critical_value);
//    LOG4CXX_INFO(logger,"ModelPath : " << Model_Path);
//    LOG4CXX_INFO(logger,"heartbeat_timeout : " << heartbeat_timeout);
    return true;
}

bool Config::AnalyseLine(const std::string& line,std::string& value)
{
    if (line.empty())
        return false;

    int start_pos = 0, end_pos = line.size() - 1, pos;
    if ((pos = line.find(COMMENT_CHAR)) != -1) {
        if (0 == pos) {  // 行的第一个字符就是注释字符
            return false;
        }
        end_pos = pos - 1;
    }
    std::string new_line = line.substr(start_pos, start_pos + 1 - end_pos);  // 预处理，删除注释部分

    if ((pos = new_line.find('=')) == -1)
        return false;  // 没有=号
    std::string key;
    key = new_line.substr(0, pos);
    value = new_line.substr(pos + 1, end_pos + 1- (pos + 1));

    trimString(key);
    trimString(value);

    if(key == "url")
    {
        configInfo.s_Url = value;
    }
    if(key == "estateId")
    {
        configInfo.s_estateId = value;
    }
    if(key == "token")
    {
        configInfo.s_token = value;
    }
    if(key == "model")
    {
        std::istringstream is(value);
        int temp;
        is >> temp;
        configInfo.model = (RUN_MODEL)temp;
    }
    if(key == "threadcount")
    {
        std::istringstream is(value);
        is >> configInfo.i_threadCount;
    }
    if(key == "imgpath")
    {
        configInfo.s_imgPath = value;
    }
    if(key == "heartbeat_timeout")
    {
        std::istringstream is(value);
        is >> configInfo.heartbeat_timeout;
}
