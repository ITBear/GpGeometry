#pragma once

#include "GpPoint2d.hpp"

namespace GPlatform {

class GpPolyline2d
{
public:
    CLASS_DD(GpPolyline2d)

public:
    inline                          GpPolyline2d    (void) noexcept;
    inline                          GpPolyline2d    (const GpPolyline2d& aPolyline);
    inline                          GpPolyline2d    (GpPolyline2d&& aPolyline) noexcept;
    inline                          GpPolyline2d    (std::vector<GpPoint2d> aPoints) noexcept;
                                    ~GpPolyline2d   (void) noexcept = default;

    inline void                     Reset           (void) noexcept;
    const std::vector<GpPoint2d>&   Points          (void) const noexcept {return iPoints;}
    std::vector<GpPoint2d>&         Points          (void) noexcept {return iPoints;}

    inline GpPolyline2d&            operator=       (const GpPolyline2d& aPolyline) noexcept;
    inline GpPolyline2d&            operator=       (GpPolyline2d&& aPolyline) noexcept;

    inline GpPolyline2d&            Set             (const GpPolyline2d& aPolyline);
    inline GpPolyline2d&            Set             (GpPolyline2d&& aPolyline) noexcept;
    inline GpPolyline2d&            Set             (std::vector<GpPoint2d> aPoints) noexcept;

private:
    std::vector<GpPoint2d>          iPoints;
};

GpPolyline2d::GpPolyline2d (void) noexcept
{
}

GpPolyline2d::GpPolyline2d (const GpPolyline2d& aPolyline):
iPoints(aPolyline.iPoints)
{
}

GpPolyline2d::GpPolyline2d (GpPolyline2d&& aPolyline) noexcept:
iPoints(std::move(aPolyline.iPoints))
{
}

GpPolyline2d::GpPolyline2d (std::vector<GpPoint2d> aPoints) noexcept:
iPoints(std::move(aPoints))
{
}

void    GpPolyline2d::Reset (void) noexcept
{
    iPoints.clear();
}

GpPolyline2d&   GpPolyline2d::operator= (const GpPolyline2d& aPolyline) noexcept
{
    Set(aPolyline);
    return *this;
}

GpPolyline2d&   GpPolyline2d::operator= (GpPolyline2d&& aPolyline) noexcept
{
    Set(std::move(aPolyline));
    return *this;
}

GpPolyline2d&   GpPolyline2d::Set (const GpPolyline2d& aPolyline)
{
    iPoints = aPolyline.iPoints;

    return *this;
}

GpPolyline2d&   GpPolyline2d::Set (GpPolyline2d&& aPolyline) noexcept
{
    iPoints = std::move(aPolyline.iPoints);

    return *this;
}

GpPolyline2d&   GpPolyline2d::Set (std::vector<GpPoint2d> aPoints) noexcept
{
    iPoints = std::move(aPoints);

    return *this;
}

}//namespace GPlatform
