#include <cstdlib>
#include <iostream>
#include <variant>
#include <optional>
#include <type_traits>

#include "logger.hpp"
#include "installer.hpp"
#include "packageTypes.hpp"
#include "typeAliases.hpp"
#include "packagesString.hpp"

namespace
    TIS
{
    
    void
        Installer
        (
            std::optional
              <v_boolsv>
                outStream =
            std::nullopt ,
            v_pkgOpt
                pkgsType =
            { } ,
            v_strInitList
                pkgsLst =
            { }
        )
    {
        
        std::unordered_set <bool>
            validBools =
            {
                true ,
                false
            }
        ;
        
        std::unordered_set <std::string_view>
            validStrings =
            {
                "outstream"
            }
        ;
        
        if
            (
                outStream.has_value ( ) &&
                (
                    (
                        std::holds_alternative <bool> ( *outStream ) &&
                        validBools.count ( std::get <bool> ( *outStream ) )
                    ) ||
                    (
                        std::holds_alternative
                        <std::string_view> ( *outStream ) &&
                        validStrings.count
                        (
                            std::get <std::string_view> ( *outStream )
                        )
                    )
                )
            )
        {
            
            
            std::vector <std::string>
                packages
            ;
            
            std::visit
                (
                    
                    [ &packages ]
                    ( auto && arg)
                    {
                        
                        using
                          T =
                            std::decay_t <decltype ( arg )>
                        ;
                        
                        using
                          compareVec_t =
                            std::is_same <T , vectStr_t>
                        ;
                        
                        using
                          compareStrInit_t =
                            std::is_same <T , strInitList>
                        ;
                        
                        if constexpr
                            ( compareVec_t::value )
                        {
                            
                            packages.insert
                                (
                                    
                                    packages.end ( ) ,
                                    arg.begin ( ) ,
                                    arg.end ( )
                                    
                                )
                            ;
                            
                        }
                        
                        else if constexpr
                            ( compareStrInit_t::value )
                        {
                            
                            packages.insert
                                (
                                    
                                    packages.end ( ) ,
                                    arg.begin ( ) ,
                                    arg.end ( )
                                    
                                )
                            ;
                            
                        }
                        
                    } ,
                    
                    pkgsLst
                    
                )
            ;
            
            vectStr_t test = {"sine package test"};
            
            str pkg = packagesString(e_pkgTypeStr::PAC, test);
            
            std::cout
            
                <<  "ruinnig command"
                <<  pkg
            ;
            
            system
                (
                    pkg.c_str()
                    
                )
            ;
            
            for
                ( const auto& pkgs : packages )
            {
                
                packages.push_back ( pkgs );
                
                packagesString(e_pkgTypeStr::PAC, pkgsLst);
                
                logger::spdLog
                    (
                        logger::logLevel::INFO ,
                        logger::funcLevel::INSTALLER ,
                        "Installing package `{}`",
                        pkgs
                    )
                ;
                
            }
            
        }
        
    }
    
} /* namespace TIS */
