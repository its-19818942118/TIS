#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP
/* #pragma once */
    
    #include <unordered_map>
    
    #include "typeAliases.hpp"
    
    namespace
        TIS
    {
        
        extern const
          std::unordered_map /* unordered map type to validate cmd combos */
          <int , str_v>
            validCommandCombos
        ;
        
        class
            ArgsParser
            {
                
              private:
                
                int
                    cmdArgC
                ;
                
                char**
                    cmdArgV
                ;
                
              public:
                
                ArgsParser
                    ( int argc , char** argv )
                ;
                
                void
                    parseCmd
                    ( )
                ;
                
            }
        ;
        
    } /* namespace TIS */
    
#endif /* ARGS_PARSER_HPP */
