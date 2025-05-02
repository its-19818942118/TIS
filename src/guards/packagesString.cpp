// #include <tuple>
#include <sstream>
#include <variant>
#include <stdexcept>

#include "typeAliases.hpp"
#include "packageTypes.hpp"
#include "packagesString.hpp"

namespace
    TIS
{
    
    // std::variant
    //   <tuple3Str , str> // this doesnt work currently.
    std::string
        packagesString
        (
            
            e_pkgTypeStr
                pkgType =
            { } ,
            v_strInitList
                pkgsLst =
            { }
            // bool
            //     returnall =
            // false
            
        )
    {
        
        std::ostringstream
            ossAur ,
            ossPac ,
            ossDeb
        ;
        
        // Create package string for pacman
        std::visit
            (
                
                [ & ]
                    ( auto && arg )
                {
                    using
                      T =
                        std::decay_t <decltype ( arg )>
                    ;
                    
                    if
                      constexpr
                        (
                            std::is_same_v
                              <T , vectStr_t>
                        )
                    {
                        
                        for
                            ( const auto& pkg : arg )
                        {
                            
                            ossAur
                                << pkg
                                <<  " "
                            ;
                            
                            ossDeb  << pkg
                                <<  " "
                            ;
                            
                            ossPac  << pkg
                                <<  " "
                            ;
                            
                        }
                        
                    }
                    
                    else if
                      constexpr
                        (
                            std::is_same_v
                              <T , strInitList>
                        )
                    {
                        
                        for
                            ( const auto& pkg : arg )
                        {
                            
                            ossAur
                                << pkg
                                << " "
                            ;
                            
                            ossDeb
                                << pkg
                                << " "
                            ;
                            
                            ossPac
                                << pkg
                                << " "
                            ;
                            
                        }
                        
                    }
                    
                } ,
                
                pkgsLst
                
            )
        ;
        
        // Trim trailing spaces
        str
            packagesStringAur =
            ossAur.str
            ( )
        ;
        
        str
            packagesStringDeb =
            ossDeb.str
            ( )
        ;
        
        str
            packagesStringPac =
            ossPac.str
            ( )
        ;
        
        if
            ( !packagesStringAur.empty ( ) )
        {
            
            packagesStringAur.erase
                ( )
            ;
            
        }
        
        if
            ( !packagesStringDeb.empty ( ) )
        {
            
            packagesStringDeb.erase
                ( )
            ;
            
        }
        
        if
            ( !packagesStringPac.empty ( ) )
        {
            
            packagesStringPac.erase
                ( )
            ;
            
        }

        switch
            ( pkgType )
        {
            
            case
                TIS::e_pkgTypeStr::AUR:
                packagesStringAur =
                    "yay -Sy " + packagesStringAur
                ;
                break
            ;
            
            case
                TIS::e_pkgTypeStr::PAC:
                packagesStringPac =
                "sudo pacman -Sy " + packagesStringPac
                ;
                
                break
            ;
            
            case
                TIS::e_pkgTypeStr::DEB:
                packagesStringDeb =
                    "sudo apt install " + packagesStringDeb
                ;
                
                break
            ;
        }
        
        // if
        //     ( returnall )
        // {
            
        //     return
        //         std::make_tuple
        //         (
        //             packagesStringAur ,
        //             packagesStringDeb ,
        //             packagesStringPac
        //         )
        //     ;
            
        // } // tuple function doesnt work properly
        
        switch
            ( pkgType )
        {
            
            case
                TIS::e_pkgTypeStr::AUR:
                return
                    packagesStringAur
                ;
                
                break
            ;
            
            case
                TIS::e_pkgTypeStr::DEB:
                return
                    packagesStringDeb
                ;
                
                break
            ;
            
            case
                TIS::e_pkgTypeStr::PAC:
                return
                    packagesStringPac
                ;
                
                break
            ;
            
            default:
                throw
                    std::invalid_argument
                    (
                        "Invalid package type"
                    )
                ;
            ;
            
        }
        
    }

} /* namespace TIS */
