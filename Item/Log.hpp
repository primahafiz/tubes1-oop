/* File: Log.hpp */
#ifndef __LOG_HPP__
#define __LOG_HPP__

#include "nonTool.hpp"
#include "nonToolType.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas Log */
template <class T>
class Log : public nonTool {
private:
    /* Atribut */
    T logType;
public:
    // Default Constructor
    Log() : nonTool()
    {
        T temp;
        setLogType(temp);
    }

    // User-Defined Constructor
    Log(T logType, int quantity) : nonTool(get<0>(itemConfig.find(logType.getName()+"_LOG")->second), logType.getName()+"_LOG", get<1>(itemConfig.find(logType.getName()+"_LOG")->second), quantity)
    {
        setLogType(logType);
    }

    // Setter logType
    void setLogType(T logType)
    {
        this->logType = logType;
    }

    // Getter logType
    T getLogType() const
    {
        return this->logType;
    }
};

#endif
