// #include <iostream>

#include "api.hpp"
#include "installer.hpp"
#include "Namespaces.hpp"
#include "defPackages.hpp"
#include "logger.hpp"
#include "packageTypes.hpp"
#include <cstdlib>

    // #include <spdlog/common.h>
#include <fmt/base.h>
#include <iostream>
    #include <spdlog/spdlog.h>
    // #include <spdlog/spdlog-inl.h>
    #include <spdlog/sinks/stdout_color_sinks.h>
    #include <spdlog/sinks/stdout_color_sinks-inl.h>
#include <string_view>

int
    main
    ( int argc , char* argv [ ] )
{
    
    // std::cout
    //     <<  (70'000ll * 70'000ll)
    // ;
    
    std::string_view test = "bye!";
    
    spdlog::set_level(spdlog::level::trace);
    
    // TIS::Installer
    //     ( TIS::pkgType::PAC , true , { "clang" } )
    // ;
    
    TIS::logger::spdLog
        (
            TIS::logger::logLevel::WARN ,
            TIS::logger::funcLevel::DEF_PKGS_LST ,
            "{} {}! {} {}" ,
            "hi" , "bye" ,
            "ok no not really..." ,
            "ok maybe for real this time!!! it works" 
        )
    ;
    
    TIS::logger::spdLog
        (
            TIS::logger::logLevel::ERROR ,
            TIS::logger::funcLevel::VALIDATOR ,
            "std::string_view format {}",
            test
        )
    ;
    
    // i am adding it right now lol
    
    // auto logger = spdlog::stdout_color_mt("bstest");
    
    // logger->trace("bsbsbsbsb");
    
    // TIS::validator ( argc , argv );
    
    
    
}

