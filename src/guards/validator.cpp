#include <cstdlib>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include "logger.hpp"
// #include "installer.hpp"
#include "validator.hpp"
#include "argsParser.hpp"
#include "typeAliases.hpp"
// #include "packageTypes.hpp"

using
    TIS::logger::spdLog ,
    TIS::logger::logLevel ,
    TIS::logger::funcLevel
;

int
    TIS::validator
    ( int argc , char** argv )
{
    
    if
        ( argc < 2 )
    {
        
        spdlog::set_level(spdlog::level::trace);
        
         printf("from validator Number of arguments: %d\n", argc);
         
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
        
        ArgsParser parser
            ( argc , argv )
        ;
        
        system
            ( "read" ) // we are here works 
        ;
        
        exit
            ( EXIT_FAILURE )
        ;
        
    }
    
    else
    {
        
        ArgsParser parser ( argc , argv )
        ;
        
    }
    
    return 0;
    // works uptil here
}
