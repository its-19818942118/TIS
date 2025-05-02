#ifndef PACKAGES_STRING_HPP
#define PACKAGES_STRING_HPP
/* #pragma once */
    
    // #include <variant>
    
    #include "typeAliases.hpp"
    
    namespace
        TIS
    {
        
        // std::variant
        //   <tuple3Str , str> // this no worky
        std::string
            packagesString
            (
                e_pkgTypeStr
                    pkgType /* =
                { }  */,
                v_strInitList
                    pkgsLst /* =
                { }  */
                // bool
                //     returnall /* =
                // false */
            )
        ;
        
    } /* namespace TIS */
    
#endif /* PACKAGES_STRING_HPP */
