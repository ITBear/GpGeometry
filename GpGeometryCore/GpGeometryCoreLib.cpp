#include <GpGeometry/GpGeometryCore/GpGeometryCoreLib.hpp>
#include <GpCore2/GpUtils/Other/GpLinkedLibsInfo.hpp>

GP_STATIC_INITIALIZER_IMPL(GpGeometryCore)
GP_LIB_REGISTRATOR(GpGeometryCoreLib)

void    GpGeometryCore_StaticInitializer::OnInitialize (void)
{
    GpGeometryCoreLib::SRegisterSelf();
}
