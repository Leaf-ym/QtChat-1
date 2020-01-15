#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SQLHANDLER_LIB)
#  define SQLHANDLER_EXPORT Q_DECL_EXPORT
# else
#  define SQLHANDLER_EXPORT Q_DECL_IMPORT
# endif
#else
# define SQLHANDLER_EXPORT
#endif
