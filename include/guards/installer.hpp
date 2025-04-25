#ifndef INSTALLER_HPP
#define INSTALLER_HPP
/* #pragma once */
    
    #include <optional>
    
    #include "typeAliases.hpp"
    
    namespace
        TIS
    {
        
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
        
    } /* namespace TIS */
    
#endif /* INSTALLER_HPP */
