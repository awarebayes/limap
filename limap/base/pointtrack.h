#ifndef LIMAP_BASE_POINTTRACK_H
#define LIMAP_BASE_POINTTRACK_H

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <cmath>
#include <set>
#include <map>

namespace py = pybind11;

#include "util/types.h"
#include "base/camera_view.h"
#include "base/linebase.h"
#include "base/infinite_line.h"

namespace limap {

struct Point2d {
    Point2d() {}
    Point2d(V2D p_, int point3D_id_ = -1): p(p_), point3D_id(point3D_id_) {}
    Point2d(py::dict dict) {
        ASSIGN_PYDICT_ITEM(dict, p, V2D)
        ASSIGN_PYDICT_ITEM(dict, point3D_id, int)
    }
    py::dict as_dict() const {
        py::dict output;
        output["p"] = p;
        output["point3D_id"] = point3D_id;
        return output;
    }
    V2D p;
    int point3D_id = -1;
};

class PointTrack {
public:
    PointTrack() {}
    PointTrack(const PointTrack& track);
    PointTrack(const V3D& p_, const int& point_id_, const std::vector<int>& image_id_list_, const std::vector<int>& p2d_id_list_, const std::vector<V2D> p2d_list_): p(p_), point_id(point_id_), image_id_list(image_id_list_), p2d_id_list(p2d_id_list_), p2d_list(p2d_list_) {}
    py::dict as_dict() const;
    PointTrack(py::dict dict);
    
    V3D p;
    int point_id;
    std::vector<int> image_id_list;
    std::vector<int> p2d_id_list;
    std::vector<V2D> p2d_list;

    size_t count_images() const { return image_id_list.size(); }
};

} // namespace limap

#endif
