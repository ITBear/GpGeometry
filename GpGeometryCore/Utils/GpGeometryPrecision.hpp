#pragma once

#include "../GpGeometryCore_global.hpp"

namespace GPlatform {

class GpGeometryPrecision
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpGeometryPrecision)

public:
    static constexpr double     SEqualDelta (void) noexcept {return 0.00000001;}
};

}//namespace GPlatform
