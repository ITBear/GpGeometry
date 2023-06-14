#pragma once

#include "../GpGeometryCore_global.hpp"

namespace GPlatform {

class GpGeometrySpartialAlgo
{
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpGeometrySpartialAlgo)

public:
    inline static std::optional<std::array<size_t, 2>>
                                        SCalcIdxsBounds (const double   aFromBegin,
                                                         const double   aFromEnd,
                                                         const double   aOfBegin,
                                                         const double   aOfEnd,
                                                         const size_t   aResolution) noexcept;

    inline static std::vector<size_t>   SBounds2DToIdxs (const std::array<size_t, 2>&   aBoundsX,
                                                         const std::array<size_t, 2>&   aBoundsY,
                                                         const size_t                   aResolution);
};

std::optional<std::array<size_t, 2>>    GpGeometrySpartialAlgo::SCalcIdxsBounds
(
    const double    aFromBegin,
    const double    aFromEnd,
    const double    aOfBegin,
    const double    aOfEnd,
    const size_t    aResolution
) noexcept
{
    const double    step    = NumOps::SAbs(aFromEnd - aFromBegin) / double(aResolution);
    double          a       = aOfBegin - aFromBegin;
    double          b       = aOfEnd   - aFromBegin;

    const double idxAd = std::floor(a/step);
    const double idxBd = std::floor(b/step);

    if (   ((idxAd < 0.0) && (idxBd < 0.0))
        || ((idxAd >= double(aResolution)) && (idxBd >= double(aResolution))))
    {
        return std::nullopt;
    }

    const size_t idxA = size_t(NumOps::SClamp(0.0, double(aResolution-1), idxAd));
    const size_t idxB = size_t(NumOps::SClamp(0.0, double(aResolution-1), idxBd));

    const auto r = NumOps::SMinMax(idxA, idxB);

    return std::array<size_t, 2>
    {
        std::get<0>(r),
        std::get<1>(r)
    };
}

std::vector<size_t> GpGeometrySpartialAlgo::SBounds2DToIdxs
(
    const std::array<size_t, 2>&    aBoundsX,
    const std::array<size_t, 2>&    aBoundsY,
    const size_t                    aResolution
)
{
    const size_t beginX = aBoundsX[0];
    const size_t endX   = aBoundsX[1];

    const size_t beginY = aBoundsY[0];
    const size_t endY   = aBoundsY[1];

    std::vector<size_t> res;
    size_t              k = 0;

    res.resize((endY - beginY + 1)*(endX - beginX + 1));

    for (size_t idY = beginY; idY <= endY; idY++)
    {
        for (size_t idX = beginX; idX <= endX; idX++)
        {
            res[k++] = idY*aResolution + idX;
        }
    }

    return res;
}

}//namespace GPlatform
