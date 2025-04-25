#include "logger.hpp"
#include "argsParser.hpp"
#include "Namespaces.hpp"

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
            ( cmdArgC != 2 )
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
