#pragma once

#include <optional>
#include <functional>

namespace GPlatform {

class GpPoint2d;
class GpLine2d;

namespace GeometryTypes {

enum class IntersectState
{
    A_INSIDE_B_OUTSIDE,
    B_INSIDE_A_OUTSIDE,
    A_INSIDE_B_INSIDE,
    NOT_INTERSECTED
};

//Test if 2d Point is inside geometry primitive
using IsInsidePoint2dFnT    = std::function<bool(const GpPoint2d&)>;

//Result of intersection (2d Point)
using Point2dOptT   = std::optional<GpPoint2d>;
using Line2dOptT    = std::optional<GpLine2d>;

//Intersect 2d Line with geometry primitive
using IntersectLine2dResT   = std::tuple<IntersectState, GpPoint2d>;
using IntersectLine2dFnT    = std::function<IntersectLine2dResT(const GpPoint2d& a, const GpPoint2d& b)>;

//Trim 2d Line with geometry primitive
using TrimLine2dResT        = Line2dOptT;
using TrimLine2dFnT         = std::function<TrimLine2dResT(const GpPoint2d& a, const GpPoint2d& b)>;

//Sort function
using SortLine2dFnT = std::function<bool(const GpPoint2d& a, const GpPoint2d& b)>;

}// namespace GPlatform::GeometryTypes

}// namespace GPlatform
