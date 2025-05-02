#include <string>
#include <vector>
#include <initializer_list>

#include "Namespaces.hpp"
#include "defPackages.hpp"

//    
namespace
    TIS
{
    
    std::vector <std::string>
        definePackages
        (
            v_pkgOpt
                pkgsType ,
            std::initializer_list <std::string>
                pkgsLst
        )
    {
        
        std::vector <std::string>
            packages
        ;
        
        for
            ( auto& package : pkgsLst )
        {
            
            packages.push_back
                ( package )
            ;
            
        }
        
        return
            packages
        ;
        
    }
    
}
