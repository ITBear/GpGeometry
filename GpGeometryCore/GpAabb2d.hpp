#pragma once

#include "Algorithms/GpGeometrySpartialAlgo.hpp"
#include "Algorithms/GpGeometryAlgo2d.hpp"
#include "Utils/GpGeometryTypes.hpp"

#include "GpPoint2d.hpp"
#include "GpLine2d.hpp"
#include "GpPolyline2d.hpp"

namespace GPlatform {

class GpAabb2d
{
public:
    CLASS_DD(GpAabb2d)

    enum class Edge
    {
        X_NEG,
        X_POS,
        Y_NEG,
        Y_POS
    };

private:
    constexpr inline                                GpAabb2d            (const GpPoint2d&   aMin,
                                                                         const GpPoint2d&   aMax,
                                                                         const GpPoint2d&   aCenter,
                                                                         const double       aHalfSizeX,
                                                                         const double       aHalfSizeY,
                                                                         const double       aRadius) noexcept;

public:
    constexpr inline                                GpAabb2d            (void) noexcept = default;
    constexpr inline                                GpAabb2d            (const GpAabb2d& aAABB) noexcept;
    constexpr inline                                GpAabb2d            (GpAabb2d&& aAABB) noexcept;

#if  (__cplusplus >= CPP_VERSION_20)
    constexpr                                       ~GpAabb2d           (void) noexcept = default;
#else
                                                    ~GpAabb2d           (void) noexcept = default;
#endif//#if  (__cplusplus >= CPP_VERSION_20)

    constexpr inline static GpAabb2d                SFromCentralPoint   (const GpPoint2d&   aCenter,
                                                                         const double       aSizeX,
                                                                         const double       aSizeY) noexcept;
    constexpr inline static GpAabb2d                SFromPoint          (const GpPoint2d&   aPoint) noexcept;
    constexpr inline static GpAabb2d                SFromPoints         (const GpPoint2d&   aPointA,
                                                                         const GpPoint2d&   aPointB) noexcept;
    constexpr inline static GpAabb2d                SFromMinMax         (const GpPoint2d&   aPointMin,
                                                                         const GpPoint2d&   aPointMax) noexcept;

    constexpr inline void                           Reset               (void) noexcept;

    constexpr inline GpAabb2d&                      operator=           (const GpAabb2d& aAABB) noexcept;
    constexpr inline GpAabb2d&                      operator=           (GpAabb2d&& aAABB) noexcept;
    constexpr inline bool                           operator==          (const GpAabb2d& aAABB) const noexcept;

    constexpr const GpPoint2d&                      Min                 (void) const noexcept {return iMin;}
    constexpr const GpPoint2d&                      Max                 (void) const noexcept {return iMax;}
    constexpr const GpPoint2d&                      Center              (void) const noexcept {return iCenter;}
    constexpr double                                HalfSizeX           (void) const noexcept {return iHalfSizeX;}
    constexpr double                                HalfSizeY           (void) const noexcept {return iHalfSizeY;}
    constexpr double                                Radius              (void) const noexcept {return iRadius;}

    constexpr inline GpAabb2d&                      Set                 (const GpAabb2d& aAABB) noexcept;

    constexpr inline bool                           IsEqual             (const GpAabb2d& aAABB) const noexcept;
    constexpr inline bool                           IsContain           (const GpPolyline2d& aPolyline) const noexcept;
    constexpr inline bool                           IsContain           (const GpPoint2d& aPoint) const noexcept;
    constexpr inline bool                           IsContain           (const double aX,
                                                                         const double aY) const noexcept;
    template<Edge E>
    constexpr bool                                  IsContainE          (const GpPoint2d&   aPoint) const noexcept;
    template<Edge E>
    constexpr bool                                  IsContainE          (const double   aX,
                                                                         const double   aY) const noexcept;

    constexpr inline bool                           IsContainE          (const GpPoint2d&   aPoint,
                                                                         const Edge         aEdge) const noexcept;
    constexpr inline bool                           IsContainE          (const double   aX,
                                                                         const double   aY,
                                                                         const Edge     aEdge) const noexcept;

    constexpr inline bool                           IsIntersect         (const GpAabb2d& aAABB) const noexcept;
    constexpr inline GeometryTypes::TrimLine2dResT  Trim                (const GpLine2d& aLine) const noexcept;
    constexpr inline GeometryTypes::TrimLine2dResT  Trim                (const GpPoint2d&   aPlointA,
                                                                         const GpPoint2d&   aPlointB) const noexcept;

    template<Edge E>
    constexpr GeometryTypes::IntersectLine2dResT    IntersectE          (const GpPoint2d&   aPlointA,
                                                                         const GpPoint2d&   aPlointB) const noexcept;

    inline std::optional<std::array<std::array<size_t, 2>, 2>>
                                                    SpartialIdxIntersect(const GpAabb2d&    aAABB,
                                                                         const size_t       aSpartialResolution) const noexcept;

    inline std::array<GpPoint2d, 4>                 ToPoints            (void) const noexcept;

private:
    GpPoint2d                                       iMin;
    GpPoint2d                                       iMax;
    GpPoint2d                                       iCenter;
    double                                          iHalfSizeX      = 0.0;
    double                                          iHalfSizeY      = 0.0;
    double                                          iRadius         = 0.0;
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
        GpGeometryAlgo2d::SDistance(aCenter, maxPoint)
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
        GpPoint2d{centerX, centerY},
        NumOps::SAbs(halfDirX)*2.0,
        NumOps::SAbs(halfDirY)*2.0
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
        GpGeometryAlgo2d::SDistance(center, aPointMax)
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

constexpr bool  GpAabb2d::IsContain (const GpPolyline2d& aPolyline) const noexcept
{
    const std::vector<GpPoint2d>&   points      = aPolyline.Points();
    const size_t                    pointsCount = points.size();

    for (size_t pointId = 0; pointId < pointsCount; pointId++)
    {
        if (IsContain(points[pointId]) == false)
        {
            return false;
        }
    }

    return true;
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
    return     (aX >= iMin.X())
            && (aX <= iMax.X())
            && (aY >= iMin.Y())
            && (aY <= iMax.Y());
}

template<GpAabb2d::Edge E>
constexpr bool  GpAabb2d::IsContainE (const GpPoint2d& aPoint) const noexcept
{
    return IsContainE<E>
    (
        aPoint.X(),
        aPoint.Y()
    );
}

template<GpAabb2d::Edge E>
constexpr bool  GpAabb2d::IsContainE
(
    const double    aX,
    const double    aY
) const noexcept
{
    switch (E)
    {
        case Edge::X_NEG: return aX >= iMin.X();
        case Edge::X_POS: return aX <= iMax.X();
        case Edge::Y_NEG: return aY >= iMin.Y();
        case Edge::Y_POS: return aY <= iMax.Y();
    }

    return false;
}

constexpr bool  GpAabb2d::IsContainE
(
    const GpPoint2d&    aPoint,
    const Edge          aEdge
) const noexcept
{
    return IsContainE
    (
        aPoint.X(),
        aPoint.Y(),
        aEdge
    );
}

constexpr bool  GpAabb2d::IsContainE
(
    const double    aX,
    const double    aY,
    const Edge      aEdge
) const noexcept
{
    switch (aEdge)
    {
        case Edge::X_NEG: return aX >= iMin.X();
        case Edge::X_POS: return aX <= iMax.X();
        case Edge::Y_NEG: return aY >= iMin.Y();
        case Edge::Y_POS: return aY <= iMax.Y();
    }

    return false;
}

constexpr bool  GpAabb2d::IsIntersect (const GpAabb2d& aAABB) const noexcept
{
    const GpPoint2d centerB     = aAABB.Center();
    const double    distance    = GpGeometryAlgo2d::SDistance(iCenter, centerB);

    if (distance >= (iRadius + aAABB.Radius()))
    {
        return false;
    }

    return     (NumOps::SAbs(iCenter.X() - centerB.X()) < (iHalfSizeX + aAABB.HalfSizeX()))
            && (NumOps::SAbs(iCenter.Y() - centerB.Y()) < (iHalfSizeY + aAABB.HalfSizeY()));
}

constexpr  GeometryTypes::TrimLine2dResT    GpAabb2d::Trim (const GpLine2d& aLine) const noexcept
{
    return Trim
    (
        aLine.Start(),
        aLine.End()
    );
}

constexpr  GeometryTypes::TrimLine2dResT    GpAabb2d::Trim
(
    const GpPoint2d&    aPlointA,
    const GpPoint2d&    aPlointB
) const noexcept
{
    return GpLine2d::STrim
    (
        aPlointA,
        aPlointB,
        iMin.X(),
        iMin.Y(),
        iMax.X(),
        iMax.Y()
    );
}

template<GpAabb2d::Edge E>
constexpr GeometryTypes::IntersectLine2dResT    GpAabb2d::IntersectE
(
    const GpPoint2d&    aPlointA,
    const GpPoint2d&    aPlointB
) const noexcept
{
    switch (E)
    {
        case Edge::X_NEG:
        {
            return GpLine2d::SIntersectMinX(aPlointA, aPlointB, iMin.X());
        } break;
        case Edge::X_POS:
        {
            return GpLine2d::SIntersectMaxX(aPlointA, aPlointB, iMax.X());
        } break;
        case Edge::Y_NEG:
        {
            return GpLine2d::SIntersectMinY(aPlointA, aPlointB, iMin.Y());
        } break;
        case Edge::Y_POS:
        {
            return GpLine2d::SIntersectMaxY(aPlointA, aPlointB, iMax.Y());
        } break;
    }

    return
    {
        GeometryTypes::IntersectState::NOT_INTERSECTED,
        GpPoint2d()
    };
}

std::optional<std::array<std::array<size_t, 2>, 2>> GpAabb2d::SpartialIdxIntersect
(
    const GpAabb2d& aAABB,
    const size_t    aSpartialResolution
) const noexcept
{
    const auto resX = GpGeometrySpartialAlgo::SCalcIdxsBounds(iMin.X(), iMax.X(), aAABB.iMin.X(), aAABB.iMax.X(), aSpartialResolution);
    const auto resY = GpGeometrySpartialAlgo::SCalcIdxsBounds(iMin.Y(), iMax.Y(), aAABB.iMin.Y(), aAABB.iMax.Y(), aSpartialResolution);

    if (   resX.has_value()
        && resY.has_value())
    {
        return std::array<std::array<size_t, 2>, 2>{resX.value(), resY.value()};
    } else
    {
        return std::nullopt;
    }
}

std::array<GpPoint2d, 4>    GpAabb2d::ToPoints (void) const noexcept
{
    //CW
    return
    {
        GpPoint2d{iMin.X(), iMin.Y()},
        GpPoint2d{iMin.X(), iMax.Y()},
        GpPoint2d{iMax.X(), iMax.Y()},
        GpPoint2d{iMax.X(), iMin.Y()},
    };
}

}//namespace GPlatform
