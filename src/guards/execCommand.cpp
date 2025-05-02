#include <string>
#include <variant>

#include "logger.hpp"
#include "execCommand.hpp"
#include "typeAliases.hpp"

namespace
    TIS
{
    
    using
      logLevel =
        logger::logLevel
    ;
    
    using
      funcLevel =
        logger::funcLevel
    ;
    
    void
        execCommand
        (
            const
              std::variant
                <tuple3Str , str> &
            command
        )
    {
        
        if
            ( std::holds_alternative <str> ( command ) )
        {
            
            const
            std::string &
                cmdStr =
                std::get
                <str>
                ( command )
            ;
            
            spdLog
                (
                    logLevel::TRACE ,
                    funcLevel::INSTALLER ,
                    "{ }" ,
                    cmdStr
                )
            ;
            
            system
                ( cmdStr.c_str ( ) )
            ;
            
        }
        
    }
    
} /* namespace TIS */
