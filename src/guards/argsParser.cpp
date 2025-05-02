#include <cstdlib>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include "logger.hpp"
#include "argsParser.hpp"

namespace
    TIS
{
    
    ArgsParser::ArgsParser
        ( int argc , char** argv )
          :
        cmdArgC ( argc ) ,
        cmdArgV ( argv )
    {
        
        if
            ( cmdArgC < 2 )
        {
            
            logger::spdLog
                (
                    logger::logLevel::ERROR ,
                    logger::funcLevel::ARGS_PARSER ,
                    "{}{}",
                    "No arguments passed!" ,
                    "Please provide atleast 1 valid argument..."
                )
            ;
            
            logger::spdLog
                (
                    logger::logLevel::ERROR ,
                    logger::funcLevel::ARGS_PARSER ,
                    "{}",
                    "testing from parsecmd"
                )
            ;
            
            exit
                ( EXIT_FAILURE )
            ;
            
        }
        
        else
        {
            
            parseCmd
                ( )
            ;
            
        }
        
    }
    
    void
        ArgsParser::parseCmd
        ( )
    {
        
        if
            ( cmdArgC == 1 )
        {
            
            logger::spdLog
                (
                    logger::logLevel::ERROR ,
                    logger::funcLevel::ARGS_PARSER ,
                    "{}",
                    ""
                )
            ;
            
        }
        
    }
    
} /* namespace TIS */
