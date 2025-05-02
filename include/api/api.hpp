/* Under Construction */

#ifndef API_HPP
#define API_HPP
/* #pragma once */
    
    #include "Namespaces.hpp"
    
    namespace
        TIS::api::presets
    {
        
        
        using
          optPkgType_t =
            std::optional
            <TIS::e_pkgType>
        ;
        
        using
          optPkgTypeVectStr_t =
            std::pair
            <vectStr_t , optPkgType_t>
        ;
        
        class
            UseInstallerPreset
            {
                
              public:
                
                
            }
        ;
        
    }
    
#endif /* API_HPP */
