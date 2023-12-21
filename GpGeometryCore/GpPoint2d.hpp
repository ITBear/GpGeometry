#pragma once

#include "Utils/GpGeometryPrecision.hpp"
#include "Utils/GpGeometryTypes.hpp"

#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>

namespace GPlatform {

class GpPoint2dType_UNIT;

class GpPoint2d
{
public:
    CLASS_DD(GpPoint2d)

public:
    constexpr                           GpPoint2d   (void) noexcept = default;
    constexpr inline                    GpPoint2d   (const GpPoint2d& aPoint) noexcept;
    constexpr inline                    GpPoint2d   (GpPoint2d&& aPoint) noexcept;
    constexpr inline                    GpPoint2d   (const double   aX,
                                                     const double   aY) noexcept;
#if  (__cplusplus >= CPP_VERSION_20)
    constexpr                           ~GpPoint2d  (void) noexcept = default;
#else
                                        ~GpPoint2d  (void) noexcept = default;
#endif//#if  (__cplusplus >= CPP_VERSION_20)

    constexpr inline void               Reset       (void) noexcept;

    constexpr inline bool               operator==  (const GpPoint2d& aPoint) const noexcept;
    constexpr inline GpPoint2d&         operator=   (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         operator=   (GpPoint2d&& aPoint) noexcept;
    constexpr inline GpPoint2d&         operator+=  (const GpPoint2d& aPoint) noexcept;
    constexpr inline friend GpPoint2d   operator+   (const GpPoint2d& aLeft,
                                                     const GpPoint2d& aRight) noexcept;
    constexpr inline GpPoint2d&         operator-=  (const GpPoint2d& aPoint) noexcept;
    constexpr inline friend GpPoint2d   operator-   (const GpPoint2d& aLeft,
                                                     const GpPoint2d& aRight) noexcept;
    constexpr inline friend GpPoint2d   operator*   (const GpPoint2d&   aLeft,
                                                     const double       aValue) noexcept;

    constexpr double                    X           (void) const noexcept {return iXY[0];}
    constexpr double                    Y           (void) const noexcept {return iXY[1];}
    constexpr inline GpPoint2d&         SetX        (const double aX) noexcept;
    constexpr inline GpPoint2d&         SetY        (const double aY) noexcept;
    constexpr inline GpPoint2d&         Set         (const double aX,
                                                     const double aY) noexcept;
    constexpr inline GpPoint2d&         Set         (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Sub         (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Sub         (const double aX,
                                                     const double aY) noexcept;
    constexpr inline GpPoint2d&         Add         (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Add         (const double aX,
                                                     const double aY) noexcept;
    constexpr inline GpPoint2d&         Mul         (const double aValue) noexcept;

private:
    std::array<double, 2>               iXY = {0.0, 0.0};
};

constexpr GpPoint2d::GpPoint2d (const GpPoint2d& aPoint) noexcept:
iXY(aPoint.iXY)
{
}

constexpr GpPoint2d::GpPoint2d (GpPoint2d&& aPoint) noexcept:
iXY(std::move(aPoint.iXY))
{
}

constexpr GpPoint2d::GpPoint2d
(
    const double    aX,
    const double    aY
) noexcept:
iXY{aX, aY}
{
}

constexpr void  GpPoint2d::Reset (void) noexcept
{
    iXY.fill(0.0);
}

constexpr bool  GpPoint2d::operator== (const GpPoint2d& aPoint) const noexcept
{
    return    NumOps::SIsEqualToDelta(X(), aPoint.X(), GpGeometryPrecision::SEqualDelta())
           && NumOps::SIsEqualToDelta(Y(), aPoint.Y(), GpGeometryPrecision::SEqualDelta());
}

constexpr GpPoint2d&    GpPoint2d::operator= (const GpPoint2d& aPoint) noexcept
{
    Set(aPoint);
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::operator= (GpPoint2d&& aPoint) noexcept
{
    Set(std::move(aPoint));
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::operator+= (const GpPoint2d& aPoint) noexcept
{
    return Add(aPoint);
}

constexpr GpPoint2d operator+
(
    const GpPoint2d& aLeft,
    const GpPoint2d& aRight
) noexcept
{
    GpPoint2d res(aLeft);
    return res.Add(aRight);
}

constexpr GpPoint2d&    GpPoint2d::operator-= (const GpPoint2d& aPoint) noexcept
{
    return Sub(aPoint);
}

constexpr GpPoint2d operator-
(
    const GpPoint2d& aLeft,
    const GpPoint2d& aRight
) noexcept
{
    GpPoint2d res(aLeft);
    return res.Sub(aRight);
}

constexpr GpPoint2d operator*
(
    const GpPoint2d&    aLeft,
    const double        aValue
) noexcept
{
    GpPoint2d res(aLeft);
    return res.Mul(aValue);
}

constexpr GpPoint2d&    GpPoint2d::SetX  (const double aX) noexcept
{
    iXY[0] = aX;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::SetY (const double aY) noexcept
{
    iXY[1] = aY;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Set
(
    const double aX,
    const double aY) noexcept
{
    SetX(aX);
    SetY(aY);

    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Set (const GpPoint2d& aPoint) noexcept
{
    iXY = aPoint.iXY;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Sub
(
    const GpPoint2d& aPoint
) noexcept
{
    return Sub
    (
        aPoint.X(),
        aPoint.Y()
    );
}

constexpr GpPoint2d&    GpPoint2d::Sub
(
    const double    aX,
    const double    aY
) noexcept
{
    iXY[0] -= aX;
    iXY[1] -= aY;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Add
(
    const GpPoint2d& aPoint
) noexcept
{
    return Add
    (
        aPoint.X(),
        aPoint.Y()
    );
}

constexpr GpPoint2d&    GpPoint2d::Add
(
    const double    aX,
    const double    aY
) noexcept
{
    iXY[0] += aX;
    iXY[1] += aY;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Mul (const double aValue) noexcept
{
    iXY[0] *= aValue;
    iXY[1] *= aValue;
    return *this;
}

}//namespace GPlatform
