#ifndef EXEC_COMMAND_HPP
#define EXEC_COMMAND_HPP
/* #pragma once */
    
    #include <variant>
    
    #include "typeAliases.hpp"
    
    namespace
        TIS
    {
        
        void
            execCommand
            (
                const
                  std::variant
                    <tuple3Str , str> &
                command
                
            )
        ;
        
    } /* namespace TIS */
    
#endif /* EXEC_COMMAND_HPP */
