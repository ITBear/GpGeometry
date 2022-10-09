#pragma once

#include "GpPoint2d.hpp"
#include "GpLine2d.hpp"

namespace GPlatform {

class GpAabb2d
{
public:
    CLASS_DD(GpAabb2d)

    using IntersectLineRes = std::optional<GpLine2d>;

private:
    constexpr inline                    GpAabb2d            (const GpPoint2d&   aMin,
                                                             const GpPoint2d&   aMax,
                                                             const GpPoint2d&   aCenter,
                                                             const double       aHalfSizeX,
                                                             const double       aHalfSizeY,
                                                             const double       aRadius) noexcept;

public:
    constexpr inline                    GpAabb2d            (void) noexcept = default;
    constexpr inline                    GpAabb2d            (const GpAabb2d& aAABB) noexcept;
    constexpr inline                    GpAabb2d            (GpAabb2d&& aAABB) noexcept;
    constexpr                           ~GpAabb2d           (void) noexcept = default;

    constexpr inline static GpAabb2d    SFromCentralPoint   (const GpPoint2d&   aCenter,
                                                             const double       aSizeX,
                                                             const double       aSizeY) noexcept;
    constexpr inline static GpAabb2d    SFromPoint          (const GpPoint2d&   aPoint) noexcept;
    constexpr inline static GpAabb2d    SFromPoints         (const GpPoint2d&   aPointA,
                                                             const GpPoint2d&   aPointB) noexcept;
    constexpr inline static GpAabb2d    SFromMinMax         (const GpPoint2d&   aPointMin,
                                                             const GpPoint2d&   aPointMax) noexcept;

    constexpr inline void               Reset               (void) noexcept;

    constexpr inline GpAabb2d&          operator=           (const GpAabb2d& aAABB) noexcept;
    constexpr inline GpAabb2d&          operator=           (GpAabb2d&& aAABB) noexcept;
    constexpr inline bool               operator==          (const GpAabb2d& aAABB) const noexcept;

    constexpr const GpPoint2d&          Min                 (void) const noexcept {return iMin;}
    constexpr const GpPoint2d&          Max                 (void) const noexcept {return iMax;}
    constexpr const GpPoint2d&          Center              (void) const noexcept {return iCenter;}
    constexpr double                    HalfSizeX           (void) const noexcept {return iHalfSizeX;}
    constexpr double                    HalfSizeY           (void) const noexcept {return iHalfSizeY;}
    constexpr double                    Radius              (void) const noexcept {return iRadius;}

    constexpr inline GpAabb2d&          Set                 (const GpAabb2d& aAABB) noexcept;

    constexpr inline bool               IsEqual             (const GpAabb2d& aAABB) const noexcept;
    constexpr inline bool               IsContain           (const GpPoint2d& aPoint) const noexcept;
    constexpr inline bool               IsContain           (const double aX,
                                                             const double aY) const noexcept;
    constexpr inline bool               IsIntersect         (const GpAabb2d& aAABB) const noexcept;
    constexpr inline IntersectLineRes   Intersect           (const GpLine2d& aLine) const noexcept;

private:
    GpPoint2d                           iMin;
    GpPoint2d                           iMax;
    GpPoint2d                           iCenter;
    double                              iHalfSizeX      = 0.0;
    double                              iHalfSizeY      = 0.0;
    double                              iRadius         = 0.0;
};

constexpr   GpAabb2d::GpAabb2d
(
    const GpPoint2d&    aMin,
    const GpPoint2d&    aMax,
    const GpPoint2d&    aCenter,
    const double        aHalfSizeX,
    const double        aHalfSizeY,
    const double        aRadius
) noexcept:
iMin(aMin),
iMax(aMax),
iCenter(aCenter),
iHalfSizeX(aHalfSizeX),
iHalfSizeY(aHalfSizeY),
iRadius(aRadius)
{
}

constexpr   GpAabb2d::GpAabb2d (const GpAabb2d& aAABB) noexcept:
iMin(aAABB.iMin),
iMax(aAABB.iMax),
iCenter(aAABB.iCenter),
iHalfSizeX(aAABB.iHalfSizeX),
iHalfSizeY(aAABB.iHalfSizeY),
iRadius(aAABB.iRadius)
{
}

constexpr   GpAabb2d::GpAabb2d (GpAabb2d&& aAABB) noexcept:
iMin(std::move(aAABB.iMin)),
iMax(std::move(aAABB.iMax)),
iCenter(std::move(aAABB.iCenter)),
iHalfSizeX(std::move(aAABB.iHalfSizeX)),
iHalfSizeY(std::move(aAABB.iHalfSizeY)),
iRadius(std::move(aAABB.iRadius))
{
}

constexpr GpAabb2d  GpAabb2d::SFromCentralPoint
(
    const GpPoint2d&    aCenter,
    const double        aSizeX,
    const double        aSizeY
) noexcept
{
    const double    halfSizeX   = aSizeX*0.5;
    const double    halfSizeY   = aSizeY*0.5;
    const GpPoint2d halfSize(halfSizeX, halfSizeY);
    const GpPoint2d minPoint    = aCenter - halfSize;
    const GpPoint2d maxPoint    = aCenter + halfSize;

    return
    {
        minPoint,
        maxPoint,
        aCenter,
        halfSizeX,
        halfSizeY,
        aCenter.Distance(maxPoint)
    };
}

constexpr GpAabb2d  GpAabb2d::SFromPoint (const GpPoint2d&  aPoint) noexcept
{
    return SFromCentralPoint
    (
        aPoint,
        0.0,
        0.0
    );
}

constexpr GpAabb2d  GpAabb2d::SFromPoints
(
    const GpPoint2d&    aPointA,
    const GpPoint2d&    aPointB
) noexcept
{
    const double ax         = aPointA.X();
    const double ay         = aPointA.Y();
    const double bx         = aPointB.X();
    const double by         = aPointB.Y();
    const double halfDirX   = (ax - bx) * 0.5;
    const double centerX    = bx + halfDirX;
    const double halfDirY   = (ay - by) * 0.5;
    const double centerY    = by + halfDirY;

    return SFromCentralPoint
    (
        {centerX, centerY},
        std::fabs(halfDirX)*2.0,
        std::fabs(halfDirY)*2.0
    );
}

constexpr GpAabb2d  GpAabb2d::SFromMinMax
(
    const GpPoint2d&    aPointMin,
    const GpPoint2d&    aPointMax
) noexcept
{
    const GpPoint2d center      = GpLine2d::SMiddle(aPointMin, aPointMax);
    const double    halfSizeX   = center.X() - aPointMin.X();
    const double    halfSizeY   = center.Y() - aPointMin.Y();

    return
    {
        aPointMin,
        aPointMax,
        center,
        halfSizeX,
        halfSizeY,
        center.Distance(aPointMax)
    };
}

constexpr void  GpAabb2d::Reset (void) noexcept
{
    iMin.Reset();
    iMax.Reset();
    iCenter.Reset();
    iHalfSizeX  = 0.0;
    iHalfSizeY  = 0.0;
    iRadius     = 0.0;
}

constexpr GpAabb2d& GpAabb2d::operator= (const GpAabb2d& aAABB) noexcept
{
    return Set(aAABB);
}

constexpr GpAabb2d& GpAabb2d::operator= (GpAabb2d&& aAABB) noexcept
{
    return Set(std::move(aAABB));
}

constexpr bool  GpAabb2d::operator== (const GpAabb2d& aAABB) const noexcept
{
    return IsEqual(aAABB);
}

constexpr GpAabb2d& GpAabb2d::Set (const GpAabb2d& aAABB) noexcept
{
    iMin        = aAABB.iMin;
    iMax        = aAABB.iMax;
    iCenter     = aAABB.iCenter;
    iHalfSizeX  = aAABB.iHalfSizeX;
    iHalfSizeY  = aAABB.iHalfSizeY;
    iRadius     = aAABB.iRadius;

    return *this;
}

constexpr bool  GpAabb2d::IsEqual (const GpAabb2d& aAABB) const noexcept
{
    return (iMin == aAABB.iMin) && (iMax == aAABB.iMax);
}

constexpr bool  GpAabb2d::IsContain (const GpPoint2d& aPoint) const noexcept
{
    return IsContain
    (
        aPoint.X(),
        aPoint.Y()
    );
}

constexpr bool  GpAabb2d::IsContain
(
    const double aX,
    const double aY
) const noexcept
{
    return     (aX > iMin.X())
            && (aX < iMax.X())
            && (aY > iMin.Y())
            && (aY < iMax.Y());
}

constexpr bool  GpAabb2d::IsIntersect (const GpAabb2d& aAABB) const noexcept
{
    const GpPoint2d centerB     = aAABB.Center();
    const double    distance    = iCenter.Distance(centerB);

    if (distance >= (iRadius + aAABB.Radius()))
    {
        return false;
    }

    return     (std::fabs(iCenter.X() - centerB.X()) < (iHalfSizeX + aAABB.HalfSizeX()))
            && (std::fabs(iCenter.Y() - centerB.Y()) < (iHalfSizeY + aAABB.HalfSizeY()));
}

constexpr GpAabb2d::IntersectLineRes    GpAabb2d::Intersect (const GpLine2d& aLine) const noexcept
{
    const bool isContainStart   = IsContain(aLine.Start());
    const bool isContainEnd     = IsContain(aLine.End());

    if (isContainStart == isContainEnd)
    {
        if (isContainStart)
        {
            return aLine;
        } else
        {
            return std::nullopt;
        }
    }

    GpLine2d line = aLine;

    line.TrimMinX(iMin.X());
    line.TrimMaxX(iMax.X());
    line.TrimMaxY(iMax.Y());
    line.TrimMinY(iMin.Y());

    return line;
}

}//namespace GPlatform
