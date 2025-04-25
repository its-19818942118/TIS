#ifndef PACKAGE_TYPES_HPP
#define PACKAGE_TYPES_HPP
/* #pragma once */
    
    namespace
        TIS
    {
        
        enum class
            e_pkgType /* enum for holding package Types */
            {
                
                Preset , /* a preset enum class name for using functions */
                DEFAULT , /* a default enum class name for using functions */
                
                aur , /* Packages from the Arch Users Repository */
                AUR , /* Packages from the Arch Users Repository */
                nix , /* Packages from the Nix packages Repository */
                NIX , /* Packages from the Nix packages Repository */
                deb , /* Packages from the Debian packages Repository */
                DEB , /* Packages from the Debian packages Repository */
                pac , /* Packages from the Packages of Arch Repository */
                PAC , /* Packages from the Packages of Arch Repository */
                
            }
        ;
        
        enum class
            e_pkgTypeStr
            {
                
                // aur , /* Packages from the Arch Users Repository */
                AUR , /* Packages from the Arch Users Repository */
                // deb , /* Packages from the Debian packages Repository */
                DEB , /* Packages from the Debian packages Repository */
                // pac , /* Packages from the Packages of Arch Repository */
                PAC , /* Packages from the Packages of Arch Repository */
                
            }
        ;
        
    } /* namespace TIS */
    
#endif /* PACKAGE_TYPES_HPP */
