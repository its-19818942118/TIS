#include <tuple>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <optional>

#include "Namespaces.hpp"
#include "typeAliases.hpp"
#include "packageTypes.hpp"

namespace
    TIS
{
    
    std::tuple
      <str , str , str>
        packagesString
        (
            TIS::e_pkgTypeStr
                pkgType =
            { } ,
            strInitList
                pkgsLst =
            { }
        )
    {
        
        std::ostringstream
            ossAur ,
            ossPac ,
            ossDeb
        ;
        
        const auto&
          packages =
            pkgsLst
        ;
        
        // Create package string for pacman
        for
            ( const auto& pkgs : packages )
        {
            
            ossAur
                <<  pkgs
                <<  " "
            ;
            
            ossDeb
                <<  pkgs
                <<  " "
            ;
            
            ossPac
                <<  pkgs
                <<  " "
            ;
            
        }
        
        std::string
            packagesStringAur ,
            packagesStringDeb ,
            packagesStringPac
        ;
        
        /* Trim trailing space */
        std::string
            aurList =
            ossAur.str
            ( )
        ;
        
        std::string
            debList =
            ossDeb.str
            ( )
        ;
        
        std::string
            pacList =
            ossPac.str
            ( )
        ;
        
        if
            ( !aurList.empty ( ) )
        {
            
            aurList.pop_back
                ( )
            ;
            
        }
        
        if
            ( !debList.empty ( ) )
        {
            
            debList.pop_back
                ( )
            ;
            
        }
        
        if
            ( !pacList.empty ( ) )
        {
            
            pacList.pop_back
                ( )
            ;
            
        }
        
        switch
            ( pkgType )
        {
            
            case
                TIS::e_pkgTypeStr::AUR:
                    packagesStringAur =
                    "yay -Sy " + ossAur.str ( )
                ;
                
                break
            ;
            
            case
                TIS::e_pkgTypeStr::PAC:
                    packagesStringPac =
                    "sudo pacman -Sy " + ossPac.str ( )
                ;
                
                break
            ;
            
            case
                TIS::e_pkgTypeStr::DEB:
                    packagesStringDeb =
                    "sudo pacman -Sy " + ossPac.str ( )
                ;
                
                break
            ;
            
        }
        
        return
            std::make_tuple
                (
                    packagesStringAur ,
                    packagesStringDeb ,
                    packagesStringPac
                )
            ;
        ;
        
    }
    
} /* namespace TIS */
