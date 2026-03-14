#include "hash.hpp"

#ifdef __has_include

    #if __has_include("fast_hash.hpp")
        #include "fast_hash.hpp"

        std::uint32_t hash32(std::string_view s) {
            return fast_hash32(s);
        }

    #else
        std::uint32_t hash32(std::string_view s) {
            std::uint32_t h = 0;
            for (unsigned char c : s) {
                h = h * 31 + c;
            }
            return h;
        }
    #endif

#else
    #error "функция has_include не поддерживается этим компилятором"
#endif