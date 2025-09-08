#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = (b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
    Fixed d2 = (c.x() - b.x()) * (point.y() - b.y()) - (c.y() - b.y()) * (point.x() - b.x());
    Fixed d3 = (a.x() - c.x()) * (point.y() - c.y()) - (a.y() - c.y()) * (point.x() - c.x());

    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    else if ((d1 > 0 && d2 > 0 && d3 >0) || (d1 < 0 && d2 < 0 && d3 <0))
        return true;
    return false;
}
