#pragma once

#include <Eigen/Dense>

class math_util
{
public:
    struct PoseDesc
    {
        // ZYX欧拉角顺序
        double x = 0;
        double y = 0;
        double z = 0;
        double rx = 0;
        double ry = 0;
        double rz = 0;
    };
    struct Pose3D
    {
        //传入desc会得到Tdb
        Eigen::Isometry3d T;

        Pose3D(const PoseDesc &desc) : Pose3D(desc.x, desc.y, desc.z,
                                              desc.rx, desc.ry, desc.rz)
        {
        }

        Pose3D(const Eigen::Isometry3d &T)
        {
            this->T = T;
        }

        Pose3D(double x, double y, double z,
               double rx, double ry, double rz)
        {
            using namespace Eigen;
            T = Eigen::Isometry3d::Identity();
            Matrix3d Rx = AngleAxisd(rx * M_PI / 180.0, Vector3d::UnitX()).toRotationMatrix();
            Matrix3d Ry = AngleAxisd(ry * M_PI / 180.0, Vector3d::UnitY()).toRotationMatrix();
            Matrix3d Rz = AngleAxisd(rz * M_PI / 180.0, Vector3d::UnitZ()).toRotationMatrix();

            T.linear() = Rz * Ry * Rx;
            T.translation() = Eigen::Vector3d(x, y, z);
        }

        PoseDesc to_desc() const
        {
            PoseDesc desc;
            Eigen::Vector3d t = T.translation();
            desc.x = t.x();
            desc.y = t.y();
            desc.z = t.z();

            Eigen::Vector3d euler = T.rotation().eulerAngles(2, 1, 0);

            desc.rz = euler[0] * 180.0 / M_PI; // Z
            desc.ry = euler[1] * 180.0 / M_PI; // Y
            desc.rx = euler[2] * 180.0 / M_PI; // X
            return desc;
        }
    };
    // 获取转换矩阵 Tbw (base -> world)
    // Tzw world坐标系下的zero点(0,0,0)
    // Tzb base坐标系下的zero点(?,?,?),假设这两个点是一样的
    // TbwTzb = Tzw
    // Tbw = TzwTzb^{-1}
    // -- Tzw 世界坐标系在世界坐标系下当然是原点,Tzw = I
    // Tbw = Tzb^{-1}
    static Eigen::Isometry3d get_Tbw(const Pose3D &Tzb)
    {
        return Tzb.T.inverse();
    }

    // 获取转换矩阵 Twb (world -> base)
    // Twb = Tzb
    static Eigen::Isometry3d get_Twb(const Pose3D &Tzb)
    {
        return Tzb.T;
    }

private:
    math_util() = default;
    ~math_util() = default;
};