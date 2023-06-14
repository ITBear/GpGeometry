#pragma once

#include "../GpPolyline2d.hpp"
#include "../GpAabb2d.hpp"
#include "../Utils/GpGeometryTypes.hpp"

namespace GPlatform {

class GP_GEOMETRY_CORE_API GpGeometryIntersectAlgo2d
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpGeometryIntersectAlgo2d)

public:
    //static GpPolyline2d::C::Vec::Val  STrimByInfLine      (const GpPolyline2d&                aPolyline,
    //                                                       GeometryTypes::IntersectLine2dFnT  aIntersectFn);

    //static GpPolyline2d::C::Vec::Val  STrimByAabbEdge     (const GpPolyline2d&    aPolyline,
    //                                                       const GpAabb2d&        aAabb,
    //                                                       const GpAabb2d::Edge   aAabbEdge);

    //static GpPolyline2d::C::Vec::Val  STrimByAabb         (const GpPolyline2d&    aPolyline,
    //                                                       const GpAabb2d&        aAabb);
};

}//namespace GPlatform
