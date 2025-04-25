#include <cstdlib>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include "logger.hpp"
#include "argsParser.hpp"
#include "Namespaces.hpp"

using
    TIS::logger::spdLog ,
    TIS::logger::logLevel ,
    TIS::logger::funcLevel
;

int
    TIS::validator
    ( int argc , char* argv [ ] )
{
    
    if
        ( argc == 1 )
    {
        
        spdlog::set_level(spdlog::level::trace);
        
        spdLog
            (
                logLevel::ERROR ,
                funcLevel::VALIDATOR ,
                "{}" ,
                "No arguments provided!"
            )
        ;
        
        spdLog
            (
                logLevel::INFO ,
                funcLevel::VALIDATOR ,
                "{}" ,
                "Please provide atleast 1 argument..."
            )
        ;
        
        TIS::ArgsParser
            ( argc , argv )
        ;
        
        system
            ( "read" )
        ;
        
        exit
            ( EXIT_FAILURE )
        ;
        
    }
    
    return 0;
    
}
