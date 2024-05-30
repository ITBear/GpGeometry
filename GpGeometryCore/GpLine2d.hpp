#pragma once

#include "GpPoint2d.hpp"

namespace GPlatform {

class GpLine2d
{
public:
    CLASS_DD(GpLine2d)

public:
    constexpr inline                    GpLine2d        (void) noexcept;
    constexpr inline                    GpLine2d        (const GpLine2d& aLine) noexcept;
    constexpr inline                    GpLine2d        (GpLine2d&& aLine) noexcept;
    constexpr inline                    GpLine2d        (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd) noexcept;
    constexpr inline                    GpLine2d        (const double       aStartX,
                                                         const double       aStartY,
                                                         const double       aEndX,
                                                         const double       aEndY) noexcept;
#if  (__cplusplus >= CPP_VERSION_20)
    constexpr                           ~GpLine2d       (void) noexcept = default;
#else
                                        ~GpLine2d       (void) noexcept = default;
#endif// #if  (__cplusplus >= CPP_VERSION_20)

    constexpr inline void               Reset           (void) noexcept;

    constexpr inline GpLine2d&          operator=       (const GpLine2d& aLine) noexcept;
    constexpr inline GpLine2d&          operator=       (GpLine2d&& aLine) noexcept;
    [[nodiscard]] constexpr inline bool operator==      (const GpLine2d& aLine) const noexcept;

    constexpr const GpPoint2d&          Start           (void) const noexcept {return iStart;}
    constexpr GpPoint2d&                Start           (void) noexcept {return iStart;}
    constexpr const GpPoint2d&          End             (void) const noexcept {return iEnd;}
    constexpr GpPoint2d&                End             (void) noexcept {return iEnd;}

    constexpr inline GpLine2d&          SetStart        (const GpPoint2d& aStart) noexcept;
    constexpr inline GpLine2d&          SetEnd          (const GpPoint2d& aEnd) noexcept;
    constexpr inline GpLine2d&          Set             (const GpPoint2d& aStart,
                                                         const GpPoint2d& aEnd) noexcept;
    constexpr inline GpLine2d&          Set             (const GpLine2d& aLine) noexcept;
    constexpr inline GpLine2d&          Sub             (const GpPoint2d& aA,
                                                         const GpPoint2d& aB) noexcept;
    constexpr inline GpLine2d&          Sub             (const double aAX,
                                                         const double aAY,
                                                         const double aBX,
                                                         const double aBY) noexcept;
    constexpr inline GpLine2d&          Mul             (const double aValue) noexcept;

    static constexpr inline GeometryTypes::IntersectLine2dResT
                                        SIntersectMinX  (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::IntersectLine2dResT
                                        SIntersectMaxX  (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::IntersectLine2dResT
                                        SIntersectMinY  (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::IntersectLine2dResT
                                        SIntersectMaxY  (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;

    static constexpr inline GeometryTypes::TrimLine2dResT
                                        STrimMinX       (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::TrimLine2dResT
                                        STrimMaxX       (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::TrimLine2dResT
                                        STrimMinY       (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::TrimLine2dResT
                                        STrimMaxY       (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aValue) noexcept;
    static constexpr inline GeometryTypes::TrimLine2dResT
                                        STrim           (const GpPoint2d&   aStart,
                                                         const GpPoint2d&   aEnd,
                                                         const double       aMinX,
                                                         const double       aMinY,
                                                         const double       aMaxX,
                                                         const double       aMaxY) noexcept;

    static constexpr inline GeometryTypes::TrimLine2dResT
                                        SIntersectToTrim(const GpPoint2d&                           aStart,
                                                         const GpPoint2d&                           aEnd,
                                                         const GeometryTypes::IntersectLine2dResT&  aIntersectRes);

    static constexpr GeometryTypes::Point2dOptT
                                        SIntersect      (const GpLine2d& aLineA,
                                                         const GpLine2d& aLineB) noexcept;
    static constexpr GeometryTypes::Point2dOptT
                                        SIntersect      (const double aLineA_StartX,
                                                         const double aLineA_StartY,
                                                         const double aLineA_EndX,
                                                         const double aLineA_EndY,
                                                         const double aLineB_StartX,
                                                         const double aLineB_StartY,
                                                         const double aLineB_EndX,
                                                         const double aLineB_EndY) noexcept;

    static constexpr GpPoint2d          SMiddle         (const GpLine2d& aLine) noexcept;
    static constexpr GpPoint2d          SMiddle         (const GpPoint2d& aA,
                                                         const GpPoint2d& aB) noexcept;

private:
    GpPoint2d                           iStart;
    GpPoint2d                           iEnd;
};

constexpr GpLine2d::GpLine2d (void) noexcept
{
}

constexpr GpLine2d::GpLine2d (const GpLine2d& aLine) noexcept:
iStart(aLine.iStart),
iEnd(aLine.iEnd)
{
}

constexpr GpLine2d::GpLine2d (GpLine2d&& aLine) noexcept:
iStart(std::move(aLine.iStart)),
iEnd(std::move(aLine.iEnd))
{
}

constexpr GpLine2d::GpLine2d
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd
) noexcept:
iStart(aStart),
iEnd(aEnd)
{
}

constexpr GpLine2d::GpLine2d
(
    const double aStartX,
    const double aStartY,
    const double aEndX,
    const double aEndY
) noexcept:
iStart(aStartX, aStartY),
iEnd(aEndX, aEndY)
{
}

constexpr void  GpLine2d::Reset (void) noexcept
{
    iStart.Reset();
    iEnd.Reset();
}

constexpr GpLine2d& GpLine2d::operator= (const GpLine2d& aLine) noexcept
{
    Set(aLine);
    return *this;
}

constexpr GpLine2d& GpLine2d::operator= (GpLine2d&& aLine) noexcept
{
    Set(std::move(aLine));
    return *this;
}

constexpr bool  GpLine2d::operator== (const GpLine2d& aLine) const noexcept
{
    return (iStart == aLine.iStart) && (iEnd == aLine.iEnd);
}

constexpr GpLine2d& GpLine2d::SetStart (const GpPoint2d& aStart) noexcept
{
    iStart = aStart;
    return *this;
}

constexpr GpLine2d& GpLine2d::SetEnd (const GpPoint2d& aEnd) noexcept
{
    iEnd = aEnd;
    return *this;
}

constexpr GpLine2d& GpLine2d::Set
(
    const GpPoint2d& aStart,
    const GpPoint2d& aEnd
) noexcept
{
    SetStart(aStart);
    SetEnd(aEnd);

    return *this;
}

constexpr GpLine2d& GpLine2d::Set (const GpLine2d& aLine) noexcept
{
    iStart  = aLine.iStart;
    iEnd    = aLine.iEnd;

    return *this;
}

constexpr GpLine2d& GpLine2d::Sub
(
    const GpPoint2d& aA,
    const GpPoint2d& aB
) noexcept
{
    return Sub
    (
        aA.X(),
        aA.Y(),
        aB.X(),
        aB.Y()
    );
}

constexpr GpLine2d& GpLine2d::Sub
(
    const double    aAX,
    const double    aAY,
    const double    aBX,
    const double    aBY
) noexcept
{
    iStart.Reset();
    iEnd.SetX(aBX - aAX);
    iEnd.SetY(aBY - aAY);

    return *this;
}

constexpr GpLine2d& GpLine2d::Mul (const double aValue) noexcept
{
    iStart.Mul(aValue);
    iEnd.Mul(aValue);

    return *this;
}

constexpr GeometryTypes::IntersectLine2dResT    GpLine2d::SIntersectMinX
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const double startK     = aStart.X() - aValue;
    const double endK       = aEnd.X() - aValue;
    const double otherStart = aStart.Y();
    const double otherEnd   = aEnd.Y();

    if (startK > 0.0)
    {
        if (endK < 0.0)
        {
            const double k = NumOps::SAbs(startK / (endK - startK));

            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE,
                GpPoint2d
                (
                    aValue,
                    otherStart + (otherEnd - otherStart)*k
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    } else if (startK < 0.0)
    {
        if (endK > 0.0)
        {
            const double k = NumOps::SAbs(endK / (startK - endK));

            return
            {
                GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE,
                GpPoint2d
                (
                    aValue,
                    otherEnd + (otherStart - otherEnd)*k
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        }
    } else//(startK == 0.0)
    {
        if (endK < 0.0)
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    }
}

constexpr GeometryTypes::IntersectLine2dResT    GpLine2d::SIntersectMaxX
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const double startK     = aStart.X() - aValue;
    const double endK       = aEnd.X() - aValue;
    const double otherStart = aStart.Y();
    const double otherEnd   = aEnd.Y();

    if (startK > 0.0)
    {
        if (endK < 0.0)
        {
            const double k = NumOps::SAbs(endK / (startK - endK));

            return
            {
                GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE,
                GpPoint2d
                (
                    aValue,
                    otherEnd + (otherStart - otherEnd)*k
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        }
    } else if (startK < 0.0)
    {
        if (endK > 0.0)
        {
            const double k = NumOps::SAbs(startK / (endK - startK));

            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE,
                GpPoint2d
                (
                    aValue,
                    otherStart + (otherEnd - otherStart)*k
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    } else//(startK == 0.0)
    {
        if (endK > 0.0)
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    }
}

constexpr GeometryTypes::IntersectLine2dResT    GpLine2d::SIntersectMinY
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const double startK     = aStart.Y() - aValue;
    const double endK       = aEnd.Y() - aValue;
    const double otherStart = aStart.X();
    const double otherEnd   = aEnd.X();

    if (startK > 0.0)
    {
        if (endK < 0.0)
        {
            const double k = NumOps::SAbs(startK / (endK - startK));

            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE,
                GpPoint2d
                (
                    otherStart + (otherEnd - otherStart)*k,
                    aValue
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }

    } else if (startK < 0.0)
    {
        if (endK > 0.0)
        {
            const double k = NumOps::SAbs(endK / (startK - endK));

            return
            {
                GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE,
                GpPoint2d
                (
                    otherEnd + (otherStart - otherEnd)*k,
                    aValue
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        }
    } else//(startK == 0.0)
    {
        if (endK < 0.0)
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    }
}

constexpr GeometryTypes::IntersectLine2dResT    GpLine2d::SIntersectMaxY
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const double startK     = aStart.Y() - aValue;
    const double endK       = aEnd.Y() - aValue;
    const double otherStart = aStart.X();
    const double otherEnd   = aEnd.X();

    if (startK > 0.0)
    {
        if (endK < 0.0)
        {
            const double k = NumOps::SAbs(endK / (startK - endK));

            return
            {
                GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE,
                GpPoint2d
                (
                    otherEnd + (otherStart - otherEnd)*k,
                    aValue
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        }
    } else if (startK < 0.0)
    {
        if (endK > 0.0)
        {
            const double k = NumOps::SAbs(startK / (endK - startK));

            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE,
                GpPoint2d
                (
                    otherStart + (otherEnd - otherStart)*k,
                    aValue
                )
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    } else//(startK == 0.0)
    {
        if (endK > 0.0)
        {
            return
            {
                GeometryTypes::IntersectState::NOT_INTERSECTED,
                GpPoint2d()
            };
        } else
        {
            return
            {
                GeometryTypes::IntersectState::A_INSIDE_B_INSIDE,
                GpPoint2d()
            };
        }
    }
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::STrimMinX
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const GeometryTypes::IntersectLine2dResT intersectRes = SIntersectMinX
    (
        aStart,
        aEnd,
        aValue
    );

    return SIntersectToTrim(aStart, aEnd, intersectRes);
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::STrimMaxX
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const GeometryTypes::IntersectLine2dResT intersectRes = SIntersectMaxX
    (
        aStart,
        aEnd,
        aValue
    );

    return SIntersectToTrim(aStart, aEnd, intersectRes);
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::STrimMinY
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const GeometryTypes::IntersectLine2dResT intersectRes = SIntersectMinY
    (
        aStart,
        aEnd,
        aValue
    );

    return SIntersectToTrim(aStart, aEnd, intersectRes);
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::STrimMaxY
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aValue
) noexcept
{
    const GeometryTypes::IntersectLine2dResT intersectRes = SIntersectMaxY
    (
        aStart,
        aEnd,
        aValue
    );

    return SIntersectToTrim(aStart, aEnd, intersectRes);
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::STrim
(
    const GpPoint2d&    aStart,
    const GpPoint2d&    aEnd,
    const double        aMinX,
    const double        aMinY,
    const double        aMaxX,
    const double        aMaxY
) noexcept
{
    GeometryTypes::TrimLine2dResT res = STrimMinX(aStart, aEnd, aMinX);

    if (res.has_value() == false)
    {
        return res;
    }

    GpLine2d resLine = res.value();

    res = STrimMinY(resLine.Start(), resLine.End(), aMinY);

    if (res.has_value() == false)
    {
        return res;
    }

    resLine = res.value();

    res = STrimMaxX(resLine.Start(), resLine.End(), aMaxX);

    if (res.has_value() == false)
    {
        return res;
    }

    resLine = res.value();

    res = STrimMaxY(resLine.Start(), resLine.End(), aMaxY);

    return res;
}

constexpr GeometryTypes::TrimLine2dResT GpLine2d::SIntersectToTrim
(
    const GpPoint2d&                            aStart,
    const GpPoint2d&                            aEnd,
    const GeometryTypes::IntersectLine2dResT&   aIntersectRes
)
{
    const GeometryTypes::IntersectState intersectState = std::get<0>(aIntersectRes);

    switch (intersectState)
    {
        case GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE:
        {
            return GpLine2d(aStart, std::get<1>(aIntersectRes));
        } break;
        case GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE:
        {
            return GpLine2d(std::get<1>(aIntersectRes), aEnd);
        } break;
        case GeometryTypes::IntersectState::A_INSIDE_B_INSIDE:
        {
            return GpLine2d(aStart, aEnd);
        } break;
        case GeometryTypes::IntersectState::NOT_INTERSECTED:
        {
            return std::nullopt;
        } break;
    }

    return {};
}

constexpr GeometryTypes::Point2dOptT    GpLine2d::SIntersect
(
    const GpLine2d& aLineA,
    const GpLine2d& aLineB
) noexcept
{
    const GpPoint2d& startA = aLineA.Start();
    const GpPoint2d& endA   = aLineA.End();
    const GpPoint2d& startB = aLineB.Start();
    const GpPoint2d& endB   = aLineB.End();

    return  GpLine2d::SIntersect
    (
        startA.X(),
        startA.Y(),
        endA.X(),
        endA.Y(),
        startB.X(),
        startB.Y(),
        endB.X(),
        endB.Y()
    );
}

constexpr GeometryTypes::Point2dOptT    GpLine2d::SIntersect
(
    const double aLineA_StartX,
    const double aLineA_StartY,
    const double aLineA_EndX,
    const double aLineA_EndY,
    const double aLineB_StartX,
    const double aLineB_StartY,
    const double aLineB_EndX,
    const double aLineB_EndY
) noexcept
{
    //Line length vectors
    GpPoint2d dirA(aLineA_EndX, aLineA_EndY);
    GpPoint2d dirB(aLineB_EndX, aLineB_EndY);

    dirA.Sub(aLineA_StartX, aLineA_StartY);
    dirB.Sub(aLineB_StartX, aLineB_StartY);

    //Line equations
    const double a1 = -dirA.Y();
    const double b1 = +dirA.X();
    const double d1 = -(a1*aLineA_StartX + b1*aLineA_StartY);

    const double a2 = -dirB.Y();
    const double b2 = +dirB.X();
    const double d2 = -(a2*aLineB_StartX + b2*aLineB_StartY);

    //Calculate Ks
    const double a_k_start  = a2*aLineA_StartX + b2*aLineA_StartY + d2;
    const double a_k_end    = a2*aLineA_EndX + b2*aLineA_EndY + d2;

    const double b_k_start  = a1*aLineB_StartX + b1*aLineB_StartY + d1;
    const double b_k_end    = a1*aLineB_EndX + b1*aLineB_EndY + d1;

    //Check if k`s have same sign. If the same then no intersect
    if ((a_k_start * a_k_end > 0.0) ||
        (b_k_start * b_k_end > 0.0))
    {
        return std::nullopt;
    }

    if (   (fabs(a_k_start) < GpGeometryPrecision::SEqualDelta())
        && (fabs(a_k_end) < GpGeometryPrecision::SEqualDelta())
        && (fabs(b_k_start) < GpGeometryPrecision::SEqualDelta())
        && (fabs(b_k_end) < GpGeometryPrecision::SEqualDelta()))
    {
        return std::nullopt;
    }

    if (fabs(a_k_start - a_k_end) < GpGeometryPrecision::SEqualDelta())
    {
        return std::nullopt;
    }

    const double u = a_k_start / (a_k_start - a_k_end);

    GpPoint2d intersectPoint(dirA);

    intersectPoint
        .Mul(u)
        .Add(aLineA_StartX, aLineA_StartY);

    return intersectPoint;
}

constexpr GpPoint2d GpLine2d::SMiddle (const GpLine2d& aLine) noexcept
{
    return SMiddle(aLine.Start(), aLine.End());
}

constexpr GpPoint2d GpLine2d::SMiddle
(
    const GpPoint2d& aA,
    const GpPoint2d& aB
) noexcept
{
    GpPoint2d dir(aB);
    dir.Sub(aA).Mul(0.5);

    return aA + dir;
}

}// namespace GPlatform
