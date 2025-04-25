#ifndef LOGGER_HPP
#define LOGGER_HPP
/* #pragma once */
    
    #include <utility>
    #include <iostream>
    #include <fmt/base.h>
    #include <fmt/args.h>
    #include <unordered_map>
    #include <unordered_set>
    #include <spdlog/common.h>
    #include <spdlog/spdlog.h>
    #include <spdlog/sinks/stdout_color_sinks.h>
    
    #include "Namespaces.hpp"
    #include "typeAliases.hpp"
    
    namespace
        TIS::logger
    {
        
        enum class
            logLevel
            {
                
                INFO ,
                WARN ,
                DEBUG ,
                ERROR ,
                TRACE ,
                
            }
        ;
        
        enum class
            funcLevel
            {
                
                DEF_PKGS ,
                INSTALLER ,
                PKG_TYPES ,
                VALIDATOR ,
                ARGS_PARSER ,
                DEF_PKGS_LST ,
                
            }
        ;
        
        extern const
          std::unordered_map /* unordered map type to validate log combos */
          <logger::logLevel , logger::funcLevelSt>
            validLogCombos
        ;
        
        void
            log
            (
                logLevel
                    lgLevel ,
                funcLevel
                    fnLevel ,
                const
                    logMessage&
                msgLog
            )
        ;
        
        template
            <typename ... Args>
        void
            spdLog
            (
                logLevel
                    lgLevel ,
                funcLevel
                    fnLevel ,
                std::string_view
                    format ,
                Args &&
                    ...
                args
                // const
                //     logMessage&
                // msgLog
            )
        {
            
            std::string
                loggerName =
                funcLevelStr ( fnLevel )
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
                
                std::string
                    formattedMessage =
                    fmt::vformat
                    (
                        
                        format ,
                        fmt::make_format_args
                        ( std::forward <Args> ( args ) ... )
                        
                    )
                ;
                
                /* Patterns for different logger types */
                
                std::string
                    default_pattern =
                    {
                        "[%H:%M:%S] [%^%l%$] \e[1;97m%v\e[0m"
                    } ,
                    
                    info_pattern =
                    {
                        "\e[36m \e[0m[\e[0;1;36m%l\e[0m] ⨳ [%H:%M:%S]\e[36m\n"
                        "∟ ⁂ ⤷ \e[1m%n\e[0;36m\n "
                        "∟ ⁂ ⧻∷⟝⟶ \e[0;3;97m\"%v\"\e[0m"
                    } ,
                    
                    debug_pattern =
                    {
                        "\e[34m \e[0m[\e[0;1;34m%l\e[0m] ⨳ [%H:%M:%S]\e[34m\n"
                        "∟ ⁂ ⤷ \e[1m%n\e[0;34m\n "
                        "∟ ⁂ ⧻∷⟝⟶ \e[0;3;97m\"%v\"\e[0m"
                    } ,
                    
                    error_pattern =
                    {
                        "\e[31m \e[0m[\e[0;1;31m%l\e[0m] ⨳ [%H:%M:%S]\e[31m\n"
                        "∟ ⁂ ⤷ \e[1m%n\e[0;31m\n "
                        "∟ ⁂ ⧻∷⟝⟶ \e[0;3;97m\"%v\"\e[0m"
                    } ,
                    
                    warning_pattern =
                    {
                        "\e[33m \e[0m[\e[0;1;33m%l\e[0m] ⨳ [%H:%M:%S]\e[33m\n"
                        "∟ ⁂ ⤷ \e[1m%n\e[0;33m\n "
                        "∟ ⁂ ⧻∷⟝⟶ \e[0;3;97m\"%v\"\e[0m"
                    } ,
                    
                    trace_pattern =
                    {
                        "\e[35m \e[0m[\e[0;1;35m%l\e[0m] ⨳ [%H:%M:%S]\e[35m\n"
                        "∟ ⁂ ⤷ \e[1m%n\e[0;35m\n "
                        "∟ ⁂ ⧻∷⟝⟶ \e[0;3;97m\"%v\"\e[0m"
                    }
                ;
                
                switch
                    ( lgLevel )
                {
                    
                    case
                        TIS::logger::logLevel::INFO :
                        
                        logger->set_pattern
                            ( info_pattern )
                        ;
                        
                        logger->info
                            ( formattedMessage )
                        ;
                        
                        logger->set_pattern
                            ( default_pattern )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::WARN :
                        
                        logger->set_pattern
                            ( warning_pattern )
                        ;
                        
                        logger->warn
                            ( formattedMessage )
                        ;
                        
                        logger->set_pattern
                            ( default_pattern )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::DEBUG :
                        logger->set_pattern
                            ( debug_pattern )
                        ;
                        
                        logger->debug
                            ( formattedMessage )
                        ;
                        
                        logger->set_pattern
                            ( default_pattern )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::ERROR :
                        
                        logger->set_pattern
                            ( error_pattern )
                        ;
                        
                        logger->error
                            ( formattedMessage )
                        ;
                        
                        logger->set_pattern
                            ( default_pattern )
                        ;
                        
                        break
                    ;
                    
                    case
                        TIS::logger::logLevel::TRACE :
                        
                        logger->set_pattern
                            ( trace_pattern )
                        ;
                        
                        logger->trace
                            ( formattedMessage )
                        ;
                        
                        logger->set_pattern
                            ( default_pattern )
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
                    <<  "From:: [LOGGER]"
                    <<  "Invalid log level or function level combination!"
                    <<  "You may have forgotten to add "
                    <<  "a new Function level or Logger level combination!"
                    <<  "||>visit log/logger.hpp to update it!"
                    <<  '\n'
                ;
                
            }
            
        }
        
    } /* namespace TIS::logger */
    
#endif /* LOGGER_HPP */
