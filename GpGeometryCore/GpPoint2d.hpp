#pragma once

#include "Utils/GpGeometryUtils.hpp"

namespace GPlatform {

class GpPoint2dType_UNIT;

class GpPoint2d final: protected GpUnit<double, 2, GpPoint2dType_UNIT, std::ratio<intmax_t(1), intmax_t(1)> , decltype("point2d"_template_str)>
{
public:
    CLASS_DD(GpPoint2d)

public:
    constexpr inline                    GpPoint2d       (void) noexcept;
    constexpr inline                    GpPoint2d       (const GpPoint2d& aPoint) noexcept;
    constexpr inline                    GpPoint2d       (GpPoint2d&& aPoint) noexcept;
    constexpr inline                    GpPoint2d       (const double   aX,
                                                         const double   aY) noexcept;
    constexpr                           ~GpPoint2d      (void) noexcept = default;

    constexpr inline void               Reset           (void) noexcept;

    constexpr inline bool               operator==      (const GpPoint2d& aPoint) const noexcept;
    constexpr inline GpPoint2d&         operator=       (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         operator=       (GpPoint2d&& aPoint) noexcept;
    constexpr inline GpPoint2d&         operator+=      (const GpPoint2d& aPoint) noexcept;
    constexpr inline friend GpPoint2d   operator+       (const GpPoint2d& aLeft,
                                                         const GpPoint2d& aRight) noexcept;
    constexpr inline GpPoint2d&         operator-=      (const GpPoint2d& aPoint) noexcept;
    constexpr inline friend GpPoint2d   operator-       (const GpPoint2d& aLeft,
                                                         const GpPoint2d& aRight) noexcept;
    constexpr inline friend GpPoint2d   operator*       (const GpPoint2d&   aLeft,
                                                         const double       aValue) noexcept;

    constexpr double                    X               (void) const noexcept {return Container()[0];}
    constexpr double                    Y               (void) const noexcept {return Container()[1];}
    constexpr inline GpPoint2d&         SetX            (const double aX) noexcept;
    constexpr inline GpPoint2d&         SetY            (const double aY) noexcept;
    constexpr inline GpPoint2d&         Set             (const double aX,
                                                         const double aY) noexcept;
    constexpr inline GpPoint2d&         Set             (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Sub             (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Sub             (const double aX,
                                                         const double aY) noexcept;
    constexpr inline GpPoint2d&         Add             (const GpPoint2d& aPoint) noexcept;
    constexpr inline GpPoint2d&         Add             (const double aX,
                                                         const double aY) noexcept;
    constexpr inline GpPoint2d&         Mul             (const double aValue) noexcept;

    constexpr inline double             Distance        (const GpPoint2d& aPoint) const noexcept;
    constexpr inline double             DistanceSquare  (const GpPoint2d& aPoint) const noexcept;
};

constexpr GpPoint2d::GpPoint2d (void) noexcept:
GpUnit()
{
}

constexpr GpPoint2d::GpPoint2d (const GpPoint2d& aPoint) noexcept:
GpUnit(aPoint)
{
}

constexpr GpPoint2d::GpPoint2d (GpPoint2d&& aPoint) noexcept:
GpUnit(std::move(aPoint))
{
}

constexpr GpPoint2d::GpPoint2d
(
    const double    aX,
    const double    aY
) noexcept:
GpUnit(container_type{aX, aY})
{
}

constexpr void  GpPoint2d::Reset (void) noexcept
{
    SetX(0.0);
    SetY(0.0);
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
    Container()[0] = aX;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::SetY (const double aY) noexcept
{
    Container()[1] = aY;
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
    GpUnit::Set(aPoint);
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
    Container()[0] -= aX;
    Container()[1] -= aY;
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
    Container()[0] += aX;
    Container()[1] += aY;
    return *this;
}

constexpr GpPoint2d&    GpPoint2d::Mul (const double aValue) noexcept
{
    Container()[0] *= aValue;
    Container()[1] *= aValue;
    return *this;
}

constexpr double    GpPoint2d::Distance (const GpPoint2d& aPoint) const noexcept
{
    return sqrt(DistanceSquare(aPoint));
}

constexpr double    GpPoint2d::DistanceSquare (const GpPoint2d& aPoint) const noexcept
{
    const double dx = (aPoint.X() - X());
    const double dy = (aPoint.Y() - Y());

    return dx*dx + dy*dy;
}

}//namespace GPlatform
