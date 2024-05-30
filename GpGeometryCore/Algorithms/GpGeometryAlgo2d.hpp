#pragma once

#include "../GpLine2d.hpp"

#include <GpCore2/GpUtils/Types/Units/SI/GpUnitsSI_Angle.hpp>

namespace GPlatform {

class GpGeometryAlgo2d
{
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpGeometryAlgo2d)

public:
    //
    constexpr inline static double          SDotProduct             (const GpPoint2d& aPointA,
                                                                     const GpPoint2d& aPointB) noexcept;
    constexpr inline static GpPoint2d       SNormalize              (const GpPoint2d& aPoint) noexcept;
    constexpr inline static GpPoint2d       SLineToNormalizedDir    (const GpLine2d& aLine) noexcept;

    //Angle
    inline static angle_rad_t               SAngleFast              (const GpPoint2d& aPointA,
                                                                     const GpPoint2d& aPointB) noexcept;
    inline static angle_rad_t               SAngleFastX             (const GpPoint2d& aPoint) noexcept;
    inline static angle_rad_t               SAngleFastY             (const GpPoint2d& aPoint) noexcept;

    inline static angle_rad_t               SAngle                  (const GpLine2d& aLineA,
                                                                     const GpLine2d& aLineB) noexcept;
    inline static angle_rad_t               SAngleX                 (const GpLine2d& aLineA) noexcept;
    inline static angle_rad_t               SAngleY                 (const GpLine2d& aLineA) noexcept;

    //Rotation
    inline static GpPoint2d                 SRotate                 (const angle_rad_t  aAngle,
                                                                     const GpPoint2d&   aPoint);
    inline static GpPoint2d                 SRotate                 (const angle_rad_t  aAngle,
                                                                     const GpPoint2d&   aAxisPoint,
                                                                     const GpPoint2d&   aPoint);

    //Distance
    constexpr inline static double          SLength                 (const GpPoint2d& aPoint) noexcept;
    constexpr inline static double          SLengthSquare           (const GpPoint2d& aPoint) noexcept;
    constexpr inline static double          SDistance               (const GpPoint2d& aPointA,
                                                                     const GpPoint2d& aPointB) noexcept;
    constexpr inline static double          SDistanceSquare         (const GpPoint2d& aPointA,
                                                                     const GpPoint2d& aPointB) noexcept;

    //Search
    constexpr inline static GpPoint2d       SNearestPoint           (const GpPoint2d&   aPoint,
                                                                     const GpLine2d&    aLine) noexcept;
    constexpr inline static GpPoint2d       SNearestPoint           (const GpPoint2d&   aPoint,
                                                                     const GpPoint2d&   aLinePointA,
                                                                     const GpPoint2d&   aLinePointB) noexcept;
};

constexpr double    GpGeometryAlgo2d::SDotProduct
(
    const GpPoint2d& aPointA,
    const GpPoint2d& aPointB
) noexcept
{
    return aPointA.X() * aPointB.X() +
           aPointA.Y() * aPointB.Y();
}

constexpr GpPoint2d GpGeometryAlgo2d::SNormalize (const GpPoint2d& aPoint) noexcept
{
    const double length = SLength(aPoint);

    if (length > 0.0)
    {
        return GpPoint2d
        (
            aPoint.X() / length,
            aPoint.Y() / length
        );
    } else
    {
        return GpPoint2d(0.0, 0.0);
    }
}

constexpr GpPoint2d GpGeometryAlgo2d::SLineToNormalizedDir (const GpLine2d& aLine) noexcept
{
    const GpPoint2d& start  = aLine.Start();
    const GpPoint2d& end    = aLine.End();

    return SNormalize(end - start);
}

angle_rad_t GpGeometryAlgo2d::SAngleFast
(
    const GpPoint2d& aPointA,
    const GpPoint2d& aPointB
) noexcept
{
    const double angle  = acos(SDotProduct(aPointA, aPointB));
    const double sign   = NumOps::SSign(aPointA.Y() * aPointB.X() - aPointA.X() * aPointB.Y());

    return angle_rad_t::SMake(sign * angle);
}

angle_rad_t GpGeometryAlgo2d::SAngleFastX (const GpPoint2d& aPoint) noexcept
{
    return SAngleFast
    (
        aPoint,
        GpPoint2d(1.0, 0.0)
    );
}

angle_rad_t GpGeometryAlgo2d::SAngleFastY (const GpPoint2d& aPoint) noexcept
{
    return SAngleFast
    (
        aPoint,
        GpPoint2d(0.0, 1.0)
    );
}

angle_rad_t GpGeometryAlgo2d::SAngle
(
    const GpLine2d& aLineA,
    const GpLine2d& aLineB
) noexcept
{
    const GpPoint2d dirA = SLineToNormalizedDir(aLineA);
    const GpPoint2d dirB = SLineToNormalizedDir(aLineB);

    return SAngleFast(dirA, dirB);
}

angle_rad_t GpGeometryAlgo2d::SAngleX (const GpLine2d& aLineA) noexcept
{
    return SAngle
    (
        aLineA,
        GpLine2d(0.0, 0.0, 1.0, 0.0)
    );
}

angle_rad_t GpGeometryAlgo2d::SAngleY (const GpLine2d& aLineA) noexcept
{
    return SAngle
    (
        aLineA,
        GpLine2d(0.0, 0.0, 0.0, 1.0)
    );
}

GpPoint2d   GpGeometryAlgo2d::SRotate
(
    const angle_rad_t   aAngle,
    const GpPoint2d&    aPoint
)
{
    const double x = aPoint.X();
    const double y = aPoint.Y();

    const double s = sin(aAngle.Value());
    const double c = cos(aAngle.Value());

    const double rx = c*x - s*y;
    const double ry = s*x + c*y;

    return GpPoint2d(rx, ry);
}

GpPoint2d   GpGeometryAlgo2d::SRotate
(
    const angle_rad_t   aAngle,
    const GpPoint2d&    aAxisPoint,
    const GpPoint2d&    aPoint
)
{
    const GpPoint2d p = aPoint - aAxisPoint;

    const double x = p.X();
    const double y = p.Y();

    const double s = sin(aAngle.Value());
    const double c = cos(aAngle.Value());

    const double rx = x*c - y*s;
    const double ry = y*c + x*s;

    return GpPoint2d(rx, ry) + aAxisPoint;
}

constexpr double    GpGeometryAlgo2d::SLength (const GpPoint2d& aPoint) noexcept
{
    return NumOps::SSqrt<double>(SLengthSquare(aPoint));
}

constexpr double    GpGeometryAlgo2d::SLengthSquare (const GpPoint2d& aPoint) noexcept
{
    const double x = aPoint.X();
    const double y = aPoint.Y();

    return x*x + y*y;
}

constexpr double    GpGeometryAlgo2d::SDistance
(
    const GpPoint2d& aPointA,
    const GpPoint2d& aPointB
) noexcept
{
    return NumOps::SSqrt<double>(SDistanceSquare(aPointA, aPointB));
}

constexpr double    GpGeometryAlgo2d::SDistanceSquare
(
    const GpPoint2d& aPointA,
    const GpPoint2d& aPointB
) noexcept
{
    const double dx = (aPointA.X() - aPointB.X());
    const double dy = (aPointA.Y() - aPointB.Y());

    return dx*dx + dy*dy;
}

constexpr GpPoint2d GpGeometryAlgo2d::SNearestPoint
(
    const GpPoint2d&    aPoint,
    const GpLine2d&     aLine
) noexcept
{
    return SNearestPoint
    (
        aPoint,
        aLine.Start(),
        aLine.End()
    );
}

constexpr GpPoint2d GpGeometryAlgo2d::SNearestPoint
(
    const GpPoint2d&    aPoint,
    const GpPoint2d&    aLinePointA,
    const GpPoint2d&    aLinePointB
) noexcept
{
    const double ax = aLinePointA.X();
    const double ay = aLinePointA.Y();
    const double bx = aLinePointB.X();
    const double by = aLinePointB.Y();

    const double A = aPoint.X() - ax;
    const double B = aPoint.Y() - ay;
    const double C = bx - ax;
    const double D = by - ay;

    const double dot    = A * C + B * D;
    const double len_sq = C * C + D * D;
    double param        = -1;

    if (NumOps::SIsNotEqual(len_sq, 0.0))
    {
        param = dot / len_sq;
    } else
    {
        return aLinePointA;
    }

    double xx, yy;

    if (param < 0.0)
    {
        xx = ax;
        yy = ay;
    } else if (param > 1.0)
    {
        xx = bx;
        yy = by;
    } else
    {
        xx = ax + param * C;
        yy = ay + param * D;
    }

    return GpPoint2d(xx, yy);
}

}// namespace GPlatform
