TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 2
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=fb8b5911-5f90-47ca-8afa-8babb402787b
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_GEOMETRY_CORE_LIBRARY
PACKET_NAME     = GpGeometryCore
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES +=

HEADERS += \
    GpAabb2d.hpp \
    GpGeometryCore.hpp \
    GpGeometryCore_global.hpp \
    GpLine2d.hpp \
    GpPoint2d.hpp \
    Utils/GpGeometryPrecision.hpp \
    Utils/GpGeometryUtils.hpp
