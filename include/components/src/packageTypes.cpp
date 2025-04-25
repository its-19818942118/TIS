#include <unordered_map>

#include "Namespaces.hpp"
#include "packageTypes.hpp"

namespace
    TIS
{
    
    
    extern const
      std::unordered_map /* unordered map type to validate combos */
      <e_pkgType , str_v>
        e_validPkgTypeCombos =
        {
            
            { e_pkgType::aur , { "aur" } } ,
            { e_pkgType::AUR , { "AUR" } } ,
            { e_pkgType::deb , { "deb" } } ,
            { e_pkgType::DEB , { "DEB" } } ,
            { e_pkgType::nix , { "nix" } } ,
            { e_pkgType::NIX , { "NIX" } } ,
            { e_pkgType::pac , { "pac" } } ,
            { e_pkgType::PAC , { "PAC" } } ,
            
        }
    ;
    
} /* namespace TIS */
