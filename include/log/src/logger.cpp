#include <iostream>
#include <string_view>

#include "logger.hpp"
#include "Namespaces.hpp"

namespace
    TIS::logger
{
    
    std::string
        logLevelStr
        ( logLevel lgLevel )
    {
        
        switch
            ( lgLevel )
        {
            
            case logLevel::INFO:
                return "[INFO]"
            ;
            
            case logLevel::WARN:
                return "[WARN]"
            ;
            
            case logLevel::DEBUG:
                return "[DEBUG]"
            ;
            
            case logLevel::ERROR:
                return "[ERROR]"
            ;
            
            case logLevel::TRACE:
                return "[TRACE]"
            ;
            
            default:
                return "[UNKNOWN]"
            ;
            
        }
        
    }
    
    std::string
        funcLevelStr
        ( funcLevel fnLevel )
    {
        
        switch
            ( fnLevel )
        {
            
            case
                TIS::logger::funcLevel::DEF_PKGS:
                return "[DEF_PKGS]"
            ;
            
            case TIS::logger::funcLevel::INSTALLER:
                return "[INSTALLER]"
            ;
            
            case TIS::logger::funcLevel::PKG_TYPES:
                return "[PKG_TYPES]"
            ;
            
            case TIS::logger::funcLevel::VALIDATOR:
                return "[VALIDATOR]"
            ;
            
            case TIS::logger::funcLevel::ARGS_PARSER:
                return "[ARGS_PARSER]"
            ;
            
            case TIS::logger::funcLevel::DEF_PKGS_LST:
                return "[DEF_PKGS_LST]"
            ;
            
            default:
                return "[UNKNOWN]"
            ;
            
        }
        
    }
    
    extern const
      std::unordered_map
      <logger::logLevel , logger::funcLevelSt>
        validLogCombos =
        {
            
            {
                
                logLevel::INFO , /* First Pair */
                {
                    funcLevel::DEF_PKGS ,
                    funcLevel::INSTALLER ,
                    funcLevel::PKG_TYPES ,
                    funcLevel::VALIDATOR ,
                    funcLevel::ARGS_PARSER ,
                    funcLevel::DEF_PKGS_LST ,
                    
                } /* Second Pair */
                
            },
            
            {
                
                logLevel::WARN , /* First Pair */
                {
                    funcLevel::DEF_PKGS ,
                    funcLevel::INSTALLER ,
                    funcLevel::PKG_TYPES ,
                    funcLevel::VALIDATOR ,
                    funcLevel::ARGS_PARSER ,
                    funcLevel::DEF_PKGS_LST ,
                    
                } /* Second Pair */
                
            },
            
            {
                
                logLevel::DEBUG , /* First Pair */
                {
                    funcLevel::DEF_PKGS ,
                    funcLevel::INSTALLER ,
                    funcLevel::PKG_TYPES ,
                    funcLevel::VALIDATOR ,
                    funcLevel::ARGS_PARSER ,
                    funcLevel::DEF_PKGS_LST ,
                    
                } /* Second Pair */
                
            },
            
            {
                
                logLevel::ERROR , /* First Pair */
                {
                    funcLevel::DEF_PKGS ,
                    funcLevel::INSTALLER ,
                    funcLevel::PKG_TYPES ,
                    funcLevel::VALIDATOR ,
                    funcLevel::ARGS_PARSER ,
                    funcLevel::DEF_PKGS_LST ,
                    
                } /* Second Pair */
                
            },
            
            {
                
                logLevel::TRACE , /* First Pair */
                {
                    funcLevel::DEF_PKGS ,
                    funcLevel::INSTALLER ,
                    funcLevel::PKG_TYPES ,
                    funcLevel::VALIDATOR ,
                    funcLevel::ARGS_PARSER ,
                    funcLevel::DEF_PKGS_LST ,
                    
                } /* Second Pair */
                
            },
            
        }
    ;
    
    #pragma region TIS::LOG
    
    /* #region TIS::LOG */
    
    void
        log
        (
            logger::logLevel lgLevel ,
            logger::funcLevel fnLevel ,
            const
                logMessage&
            msgLog
        )
    {
        
        auto
            lgl =
            lgLevel
        ;
        
        auto
            fnl =
            fnLevel
        ;
        
        auto
            it =
            validLogCombos.find ( lgLevel )
        ;
        
        if
            (
                
                it != validLogCombos.end ( ) &&
                it->second.count ( fnLevel ) > 0 &&
                msgLog.message.has_value ( )
                
            )
        {
            
            std::cout
                <<  logLevelStr ( lgl )
                <<  ' '
                <<  "at "
                <<  funcLevelStr( fnl )
                <<  ' '
                <<  msgLog.message.value ( )
                <<  '\n'
            ;
            
        }
        
        else
        {
            
            std::cerr
                <<  logLevelStr ( lgl )
                <<  ' '
                <<  "at "
                <<  funcLevelStr( fnl )
                <<  "FROM [LOGGER] UNKNOWN ERROR OCCURED!"
                <<  '\n'
            ;
            
        }
        
    }
    
    /* #endregion TIS::LOG */
    
    #pragma endregion TIS::LOG
    
    /* ===================================================================== */
    
    #pragma region TIS::spdLog
    
    /* #region TIS::spdLog */
    
    #ifndef LOGGER_HPP
    #define LOGGER_HPP
    // #ifndef T_LOGGER_TPP
    // #define T_LOGGER_TPP
        
        template
            <typename ... Args>
        void
            spdLog
            (
                logLevel lgLevel ,
                funcLevel fnLevel ,
                std::string_view
                    format
                // Args &&
                //     ...
                // args
            )
        {
            
            std::string
                loggerName = funcLevelStr( fnLevel )
            ;
            
            auto
                lgl =
                lgLevel
            ;
            
            auto
                fnl =
                fnLevel
            ;
            
            auto
                logger =
                spdlog::get( loggerName )
            ;
            
            // std::string_view 
            
            if
                ( !logger )
            {
                
                logger =
                    spdlog::stdout_color_mt
                    ( loggerName )
                ;
                
            }
            
            auto
                it =
                validLogCombos.find ( lgLevel )
            ;
            
            if
                (
                    
                    it != validLogCombos.end ( ) &&
                    it->second.count ( fnLevel ) > 0
                    
                )
            {
                
                switch
                    ( lgLevel )
                {
                    
                    case
                        TIS::logger::logLevel::TRACE :
                            logger->trace ( std::forward <Args> ( args ) ... )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::DEBUG :
                            logger->debug ( std::forward <Args> ( args ) ... )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::ERROR :
                            logger->error ( std::forward <Args> ( args ) ... )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::INFO :
                            logger->info ( std::forward <Args> ( args ) ... )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::WARN :
                            logger->warn ( std::forward <Args> ( args ) ... )
                        ;
                        
                        break
                    ;
                    
                    default:
                        std::cerr
                            <<  "An Error occurred! Invalid log level!"
                            <<  '\n'
                        ;
                    ;
                    
                }
                
            }
            
            else
            {
                
                std::cerr
                    <<  "[ERROR]: "
                    <<  "Invalid log level or function level combination!"
                    <<  '\n'
                ;
                
            }
            
        }
        
    // #endif /* T_LOGGER_TPP */
    #endif /* LOGGER_HPP */
    
    /* #endregion TIS::spdLog */
    
    #pragma endregion TIS::spdLog
    
}
