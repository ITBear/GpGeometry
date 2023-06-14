#include "GpGeometryIntersectAlgo2d.hpp"

//#include <boost/geometry.hpp>
//#include <boost/geometry/geometries/point_xy.hpp>
//#include <boost/geometry/geometries/polygon.hpp>
//#include <boost/geometry/geometries/box.hpp>

//#include <list>
//#include <iostream>

namespace GPlatform {

/*GpPolyline2d::C::Vec::Val GpGeometryIntersectAlgo2d::STrimByInfLine
(
    const GpPolyline2d&                 aPolyline,
    GeometryTypes::IntersectLine2dFnT   aIntersectFn
)
{
    const std::vector<GpPoint2d>&   srcPoints      = aPolyline.Points();
    const size_t                    srcPointsCount = srcPoints.size();

    THROW_COND_GP
    (
        srcPointsCount >= 2,
        "Points count must be >= 2"_sv
    );

    //Collect trimmed lines
    bool isAllInside = true;
    std::list<std::tuple<size_t, GpPoint2d, GeometryTypes::IntersectState>> trimPoints;
    {
        for (size_t pointId = 0; pointId < (srcPointsCount-1); pointId++)
        {
            const GpPoint2d& p1 = srcPoints[pointId + 0];
            const GpPoint2d& p2 = srcPoints[pointId + 1];

            const GeometryTypes::IntersectLine2dResT    intersectRes    = aIntersectFn(p1, p2);
            const GeometryTypes::IntersectState         intersectState  = std::get<0>(intersectRes);

            switch (intersectState)
            {
                case GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE:
                {
                    trimPoints.push_front({pointId + 0, std::get<1>(intersectRes), intersectState});
                    isAllInside = false;
                } break;
                case GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE:
                {
                    trimPoints.push_front({pointId + 1, std::get<1>(intersectRes), intersectState});
                    isAllInside = false;
                } break;
                case GeometryTypes::IntersectState::A_INSIDE_B_INSIDE:
                {
                    //NOP
                } break;
                case GeometryTypes::IntersectState::NOT_INTERSECTED:
                {
                    isAllInside = false;
                } break;
            }
        }
    }

    if (isAllInside)
    {
        return {aPolyline};
    }

    GpPolyline2d::C::Vec::Val res;

    while (!trimPoints.empty())
    {
        const auto[intersectPointId, intersectPoint, intersectState] = std::move(trimPoints.front());
        trimPoints.pop_front();

        GpPolyline2d            trimmedPolygon;
        std::vector<GpPoint2d>& trimmedPolygonPoints = trimmedPolygon.Points();

        trimmedPolygonPoints.emplace_back(intersectPoint);
        //trimmedPolygonPoints.emplace_back(srcPoints[intersectPointId]);

        if (intersectState == GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE)
        {
            for (size_t pointId = intersectPointId; pointId > 0; pointId--)
            {
                //Add point
                trimmedPolygonPoints.emplace_back(srcPoints[pointId]);

                //Search for next point in trimm
                auto trimmPointIter = std::find_if
                (
                    trimPoints.begin(),
                    trimPoints.end(),
                    [&pointId](const auto& aElement)->bool
                    {
                        const auto&[__ePointId, __intersectPoint, __intersectState] = aElement;

                        return     (pointId == __ePointId)
                                && (__intersectState == GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE);
                    }
                );

                if (trimmPointIter != trimPoints.end())
                {
                    trimmedPolygonPoints.emplace_back(std::get<1>(*trimmPointIter));
                    trimPoints.erase(trimmPointIter);
                    break;
                } else
                {
                    if (pointId == 0)
                    {
                        pointId = srcPointsCount;
                    }
                }
            }
        } else//intersectState == GeometryTypes::IntersectState::B_INSIDE_A_OUTSIDE
        {
            for (ssize_t pointId = ssize_t(intersectPointId); pointId >= 0; pointId++)
            {
                //Add point
                trimmedPolygonPoints.emplace_back(srcPoints[size_t(pointId)]);

                //Search for next point in trimm
                auto trimmPointIter = std::find_if
                (
                    trimPoints.begin(),
                    trimPoints.end(),
                    [&pointId](const auto& aElement)->bool
                    {
                        const auto&[__ePointId, __intersectPoint, __intersectState] = aElement;

                        return     (pointId == ssize_t(__ePointId))
                                && (__intersectState == GeometryTypes::IntersectState::A_INSIDE_B_OUTSIDE);
                    }
                );

                if (trimmPointIter != trimPoints.end())
                {
                    trimmedPolygonPoints.emplace_back(std::get<1>(*trimmPointIter));
                    trimPoints.erase(trimmPointIter);
                    break;
                } else
                {
                    if (pointId == ssize_t(srcPointsCount) - 1)
                    {
                        pointId = -1;
                    }
                }
            }
        }

        trimmedPolygonPoints.emplace_back(intersectPoint);
        res.emplace_back(std::move(trimmedPolygon));
    }

    return res;
}*/

/*GpPolyline2d::C::Vec::Val GpGeometryIntersectAlgo2d::STrimByAabbEdge
(
    const GpPolyline2d&     aPolyline,
    const GpAabb2d&         aAabb,
    const GpAabb2d::Edge    aAabbEdge
)
{
    GeometryTypes::IntersectLine2dFnT   intersectFn;

    switch (aAabbEdge)
    {
        case GpAabb2d::Edge::X_NEG:
        {
            intersectFn = [&aAabb](const GpPoint2d& aPointA, const GpPoint2d& aPointB) -> GeometryTypes::IntersectLine2dResT
            {
                return aAabb.IntersectE<GpAabb2d::Edge::X_NEG>(aPointA, aPointB);
            };
        } break;
        case GpAabb2d::Edge::X_POS:
        {
            intersectFn = [&aAabb](const GpPoint2d& aPointA, const GpPoint2d& aPointB) -> GeometryTypes::IntersectLine2dResT
            {
                return aAabb.IntersectE<GpAabb2d::Edge::X_POS>(aPointA, aPointB);
            };
        } break;
        case GpAabb2d::Edge::Y_NEG:
        {
            intersectFn = [&aAabb](const GpPoint2d& aPointA, const GpPoint2d& aPointB) -> GeometryTypes::IntersectLine2dResT
            {
                return aAabb.IntersectE<GpAabb2d::Edge::Y_NEG>(aPointA, aPointB);
            };
        } break;
        case GpAabb2d::Edge::Y_POS:
        {
            intersectFn = [&aAabb](const GpPoint2d& aPointA, const GpPoint2d& aPointB) -> GeometryTypes::IntersectLine2dResT
            {
                return aAabb.IntersectE<GpAabb2d::Edge::Y_POS>(aPointA, aPointB);
            };
        } break;
    }

    return STrimByInfLine
    (
        aPolyline,
        intersectFn
    );
}*/

/*GpPolyline2d::C::Vec::Val GpGeometryIntersectAlgo2d::STrimByAabb
(
    const GpPolyline2d& aPolyline,
    const GpAabb2d&     aAabb
)
{
    using PointT    = boost::geometry::model::d2::point_xy<double>;
    using PolygonT  = boost::geometry::model::polygon<PointT>;
    using BoxT      = boost::geometry::model::box<PointT>;

    PolygonT polygon;

    // Define exterior ring
    for (aPolyline.)
    std::vector<PointT> ;
    std::vector<PointT> hole_points;
    {
        point_type(0, 0),
        point_type(0, 5),
        point_type(5, 5),
        point_type(5, 0),
        point_type(0, 0) // Closing point
    };

    // Define a hole (interior ring)
    std::vector<PointT> hole_points {
        point_type(1, 1),
        point_type(1, 4),
        point_type(4, 4),
        point_type(4, 1),
        point_type(1, 1) // Closing point
    };

    // Create polygon
    polygon_type poly;
    boost::geometry::append(poly, exterior_points);
    boost::geometry::append(poly.inners(), hole_points);

    // Check if polygon is valid
    std::string message;
    if (!boost::geometry::is_valid(poly, message)) {
        std::cout << "Invalid polygon: " << message << std::endl;
        return -1;
    }

    polygon.

       boost::geometry::read_wkt(
           "POLYGON((0 0,0 5,5 5,5 0,0 0))", poly);

       // Define a box (AABB)
       box_type box(point_type(2, 2), point_type(7, 7));

       // Check intersection
       if (boost::geometry::intersects(box, poly)) {
           std::cout << "Intersection exists!" << std::endl;
       } else {
           std::cout << "No intersection." << std::endl;
       }

    GpPolyline2d::C::Vec::Val currentPolygons = {aPolyline};
    GpPolyline2d::C::Vec::Val tmpPolygons;

    for (const GpAabb2d::Edge edge: {GpAabb2d::Edge::X_NEG, GpAabb2d::Edge::X_POS, GpAabb2d::Edge::Y_NEG, GpAabb2d::Edge::Y_POS})
    {
        for (const GpPolyline2d& polygon: currentPolygons)
        {
            auto newPolygons = STrimByAabbEdge(polygon, aAabb, edge);

            tmpPolygons.reserve(tmpPolygons.size() + newPolygons.size());
            std::move(newPolygons.begin(), newPolygons.end(), std::back_inserter(tmpPolygons));
        }

        currentPolygons = std::move(tmpPolygons);
        tmpPolygons.clear();
    }

    return currentPolygons;
}
*/

}//namespace GPlatform
