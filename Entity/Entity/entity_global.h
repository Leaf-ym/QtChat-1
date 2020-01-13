#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ENTITY_LIB)
#  define ENTITY_EXPORT Q_DECL_EXPORT
# else
#  define ENTITY_EXPORT Q_DECL_IMPORT
# endif
#else
# define ENTITY_EXPORT
#endif
