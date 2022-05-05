#include <iostream>

class   Log
{
public :
    enum    Level
    {
        LvlError, LvlWarning, LvlInfo
    };
   /* const int   LogLvlError = 0;
    const int   LogLvlWarning = 1;
    const int   LogLvlInfo = 2;*/
private:
    Level m_LogLevel = LvlInfo;
public:
    void    SetLvl(Level lvl)
    {
        m_LogLevel = lvl;
    }
    void    Warn(const char *message)
    {
        if (m_LogLevel >= LvlWarning)
        std::cout << "[WARNING]:" << message << std::endl;
    }
    void    Error(const char *message)
    {
        if (m_LogLevel >= LvlError)
        std::cout << "[ERROR]:" << message << std::endl;
    }
    void    Info(const char *message)
    {
        if (m_LogLevel >= LvlInfo)
        std::cout << "[INFO]:" << message << std::endl;
    }
};

int main()
{
    Log log;

    log.SetLvl(Log::LvlInfo);
    log.Warn("Hello \n");
    log.Info("Hello \n");
    log.Error("Hello \n");
    return(0);
}