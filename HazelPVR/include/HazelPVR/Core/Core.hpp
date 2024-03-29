#pragma once

#include <memory>

#ifdef HZPVR_PLATFORM_WINDOWS
#    if HZ_DYNAMIC_LINK
#        ifdef HZPVR_BUILD_DLL
#            define HAZELPVR_API __declspec(dllexport)
#        else
#            define HAZELPVR_API __declspec(dllimport)
#        endif
#    else
#        define HAZELPVR_API
#    endif
#elif defined HZPVR_PLATFORM_MACOS
#    define HAZELPVR_API
#elif defined HZPVR_PLATFORM_LINUX
#    define HAZELPVR_API
#else
#    error "Unknown operating system!"
#endif

#ifdef HZPVR_DEBUG
#    if defined(HZPVR_PLATFORM_WINDOWS)
#        define HZPVR_DEBUGBREAK() __debugbreak()
#    elif defined(HZPVR_PLATFORM_LINUX)
#        include <signal.h>
#        define HZPVR_DEBUGBREAK() raise(SIGTRAP)
#    elif defined(HZPVR_PLATFORM_MACOS)
#        define HZPVR_DEBUGBREAK() __builtin_trap();
#    else
#        error "Platform doesn't support debugbreak yet!"
#    endif
#    define HZPVR_ENABLE_ASSERTS
#else
#    define HZPVR_DEBUGBREAK()
#endif

#ifdef HZPVR_ENABLE_ASSERTS
#    define HZPVR_ASSERT(x, ...)                                                                                                           \
        {                                                                                                                                  \
            if (!(x))                                                                                                                      \
            {                                                                                                                              \
                HZPVR_ERROR("Assertion Failed: {0}", __VA_ARGS__);                                                                         \
                HZPVR_DEBUGBREAK();                                                                                                        \
            }                                                                                                                              \
        }
#    define HZPVR_CORE_ASSERT(x, ...)                                                                                                      \
        {                                                                                                                                  \
            if (!(x))                                                                                                                      \
            {                                                                                                                              \
                HZPVR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);                                                                    \
                HZPVR_DEBUGBREAK();                                                                                                        \
            }                                                                                                                              \
        }
#else
#    define HZPVR_ASSERT(x, ...)
#    define HZPVR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HZPVR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace HazelPVR
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
} // namespace HazelPVR
