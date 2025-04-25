#ifndef TYPE_ALIASES_HPP
#define TYPE_ALIASES_HPP
/* #pragma once */
    
    #include <string>
    #include <vector>
    #include <variant>
    #include <optional>
    #include <unordered_set>
    
    #include "packageTypes.hpp"
    
    namespace
        TIS
    {
        
        enum class
            e_pkgType
        ;
        
        namespace
            logger
        {
            
            enum class
                funcLevel
            ;
            
            using
              funcLevelSt =
                std::unordered_set
                <funcLevel>
            ;
            
        } /* namespace logger */
        
    } /* namespace TIS */
    
    using
      str =
        std::string
    ;
    
    using
      str_v =
        std::string_view
    ;
    
    using
      v_boolsv = /* type to hold variants of bool and str_view */
        std::variant <bool , str_v>
    ;
    
    using
      strInitList = /* type to hold init list of str type */
        std::initializer_list <str>
    ;
    
    using
      vectStr_t = /* type to hold init list of str type */
        std::vector <std::string>
    ;
    
    using
      v_strInitList = /* type to hold init list of str type */
        std::variant <strInitList , vectStr_t>
    ;
    
    using
      e_pkgOpt_t = /* type to hold optional enum pkgType */
        std::optional <TIS::e_pkgType>
    ;
    
    using
      v_pkgOpt = /* type to hold variant e_pkgOpt_t and str_view */
        std::variant <e_pkgOpt_t , str_v>
    ;
    
#endif /* TYPE_ALIASES_HPP */
