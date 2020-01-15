#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(NETWORKHANDLER_LIB)
#  define NETWORKHANDLER_EXPORT Q_DECL_EXPORT
# else
#  define NETWORKHANDLER_EXPORT Q_DECL_IMPORT
# endif
#else
# define NETWORKHANDLER_EXPORT
#endif
