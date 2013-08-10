#pragma once
#include "PointCloud3D.h"

namespace MagicDGP
{
    class Parser
    {
    public:
        Parser();
        ~Parser();

        Point3DSet* ParsePointSet(std::string fileName);
    };
}