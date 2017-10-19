#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <pthread.h>


class Config
{
public:
    static Config* GetInstance();
    bool ReadConfig(const std::string &filename);

    bool AnalyseLine(const std::string& line,std::string& value);

protected:
    Config();

private:
    static Config& _instance;
//    pthread_mutex_t* mutex;
};

#endif // CONFIG_H
