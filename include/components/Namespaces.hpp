#ifndef NAMESPACES_HPP
#define NAMESPACES_HPP
/* #pragma once */
    
    #include <string>
    #include <vector>
    #include <optional>
    // #include <string_view>
    #include <unordered_map>
    #include <unordered_set>
    
    #include "typeAliases.hpp"
    #include "packageTypes.hpp"
    
    namespace
        TIS
    {
        
        enum class
            e_pkgType /* enum for holding package Types */
        ;
        
        extern const
          std::unordered_map /* unordered map type to validate combos */
          <e_pkgType , str_v>
            validPkgTypeCombos
        ;
        
        std::variant
          <tuple3Str , str>
            packagesString
            (
                TIS::e_pkgTypeStr
                    pkgType =
                { } ,
                v_strInitList
                    pkgsLst =
                { } ,
                bool
                    returnall =
                false
            )
        ;
        
        std::vector <std::string>
            definePackages /* define packages to use for the installer */
            (
                v_pkgOpt
                    pkgsType =
                { },
                strInitList
                    pkgsLst =
                { }
            )
        ;
        
        void
            execCommand
            (
                const
                std::variant
                    <tuple3Str , str> &
                command
            )
        ;
        
        void
            Installer /* void function to handle Installation */
            (
                
                std::optional
                  <v_boolsv>
                    outstream ,
                v_pkgOpt
                    pkgsType ,
                v_strInitList
                    pkgsLst
                
            )
        ;
        
        // class
        //     ArgsParser
        // ;
        
        int
            validator /* validate given arguments */
            ( int argc , char** argv )
        ;
        
        namespace
            logger
        {
            
            enum class /* enum to hold logLevels */
                logLevel
            ;
            
            enum class /* enum to hold functionLevels */
                funcLevel
            ;
            
            std::string
                logLevelStr /* Function to convert logLevels to string */
                ( logLevel lgLevel )
            ;
            
            using
              funcLevelSt = /* unordered set type for functionLevels */
                std::unordered_set
                <logger::funcLevel>
            ;
            
            extern const
              std::unordered_map /* unordered map type to validate combos */
              <logger::logLevel , logger::funcLevelSt>
                validLogCombos
            ;
            
            struct
                logMessage /* struct type to add a log message */
            ;
            
            void
                log /* void type function to log debug the installer */
                (
                    logLevel lgLevel ,
                    funcLevel fnLevel ,
                    const
                        logMessage&
                    msgLog
                )
            ;
            
            // template
            //     <typename ... Args>
            // void
            //     spdLog /* void function 2 log & debug the installer (spdlog) */
            //     (
            //         logLevel lgLevel ,
            //         funcLevel fnLevel ,
            //         std::string_view
            //             format ,
            //         Args &&
            //             ...
            //         args
            //     )
            // ;
            
            // #include "logger.hpp"
            
        } /* namespace logger */
        
        // namespace
        //     packagesType
        // {
            
        //     namespace
        //         ArchLinux
        //     {
                
        //         extern std::vector <std::string>
        //             packagesAur
        //         ;
                
        //         extern std::vector <std::string>
        //             packagesPacman
        //         ;
                
        //     } /* namespace ArchLinux */
            
        //     namespace
        //         NixOS
        //     {
                
        //         extern std::vector <std::string>
        //             packagesNix
        //         ;
                
        //     } /* namespace NixOS */
            
        //     namespace
        //         Debian
        //     {
                
        //         extern std::vector <std::string>
        //             packagesApt
        //         ;
                
        //     } /* namespace Debian */
            
        // }
        
        // namespace
        //     api
        // {
            
        //     namespace
        //         presets
        //     {
                
        //         class
        //             UseInstallerPreset
        //         ;
                
                
                
        //         // std::vector <std::string>
        //         //     ArchHyprLuna
        //         //     (
        //         //         std::initializer_list <std::string>
        //         //             pkgsListAur ,
        //         //         std::initializer_list <std::string>
        //         //             pkgsListPacman
        //         //     )
        //         // ;
                
                
        //     } /* namespace presets */
            
        // } /* namespace api */
        
    } /* namespace TIS */
    
#endif /* NAMESPACES_HPP */
