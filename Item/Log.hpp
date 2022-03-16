/* File: Log.hpp */
#ifndef __LOG_HPP__
#define __LOG_HPP__

#include "nonTool.hpp"
#include "nonToolType.hpp"

/* Kelas Log */
template <class T>
class Log : public nonTool {
private:
    /* Atribut */
    T logType;
public:
    // Default Constructor
    Log() : nonTool() {
        T temp;
        setLogType(temp);
    }

    // User-Defined Constructor
    Log(T logType) : nonTool(1+logType.getId(), logType.getName()+"_LOG", "LOG", 0) {
        setLogType(logType);
    }

    // Setter logType
    void setLogType(T logType) {
        this->logType = logType;
    }

    // Getter logType
    T getLogType() const {
        return this->logType;
    }
};

#endif
