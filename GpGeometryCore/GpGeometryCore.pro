# ----------- Config -----------
TEMPLATE        = lib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=fb8b5911-5f90-47ca-8afa-8babb402787b
PACKET_NAME     = GpGeometryCore
DEFINES        += GP_GEOMETRY_CORE_LIBRARY
_VER_MAJ        = 2
_VER_MIN        = 1
_VER_PAT        = 6
DIR_LEVEL       = ./../..

include($$DIR_LEVEL/../QtGlobalPro.pri)

equals(var_link, "static") {
	CONFIG += staticlib
}

# ----------- Libraries -----------
equals(var_os, "windows") {
	LIBS += -lGpUtils$$TARGET_POSTFIX
}

equals(var_os, "linux") {
	LIBS += -lGpUtils$$TARGET_POSTFIX
}

# ----------- Sources and headers -----------
SOURCES += \
	Algorithms/GpGeometryIntersectAlgo2d.cpp \
	GpGeometryCoreLib.cpp

HEADERS += \
    Algorithms/GpGeometryAlgo2d.hpp \
    Algorithms/GpGeometryAlgorithms.hpp \
	Algorithms/GpGeometryIntersectAlgo2d.hpp \
    Algorithms/GpGeometrySpartialAlgo.hpp \
    GpAabb2d.hpp \
	GpGeometryCoreLib.hpp \
    GpGeometryCore_global.hpp \
    GpLine2d.hpp \
    GpPoint2d.hpp \
    Utils/GpGeometryPrecision.hpp \
	Utils/GpGeometryTypes.hpp \
	Utils/GpGeometryUtils.hpp \
	GpPolyline2d.hpp
