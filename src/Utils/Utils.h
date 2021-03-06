/**
 * @file    Utils.h
 * @ingroup Utils
 * @brief   Shared utility macros and functions.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
/**
 * @defgroup  Utils Utils
 * @brief     Shared utilities.
 */
/**
 * @dir     Utils Utils
 * @brief   Shared utilities.
 * @ingroup Utils Utils
 */
#pragma once

/**
 * @brief   Shared utilities.
 * @ingroup Utils Utils
 */
namespace Utils {
} // namespace Utils

#include <cstddef>

/**
 * @brief A macro to disallow the copy constructor and operator= functions.
 *
 * This should be used in the private: declarations for a class
 *
 * @param[in] TypeName  Class name to protect
 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName)  \
    TypeName(const TypeName&);              \
    void operator=(const TypeName&)

#ifdef _MSC_VER
#if _MSC_VER < 1600
/// A macro to enable the use of the nullptr keyword (NULL on older MSVC compilers, as they does not accept "nullptr_t")
#define nullptr NULL
#endif
#else
#ifndef __GXX_EXPERIMENTAL_CXX0X__
/**
 * @brief nullptr_t is the type of the null pointer literal, nullptr.
*/
class nullptr_t {   // NOLINT
public:
    template<typename T>
    inline operator T* () const {       ///< convertible to any type of null non-member pointer...
        return 0;
    }

    template<typename C, typename T>
    inline operator T C::* () const {   ///< convertible to any type of null member pointer...
        return 0;
    }

private:
    void operator&() const;  ///< Can't take address of nullptr NOLINT
};

/**
 * @brief Better way to enable nullptr on older GCC/Clang compilers
*/
const nullptr_t nullptr = {};
#endif
#endif

// A macro for snprintf support in Visual Studio
#if _MSC_VER
#define snprintf _snprintf
#endif
