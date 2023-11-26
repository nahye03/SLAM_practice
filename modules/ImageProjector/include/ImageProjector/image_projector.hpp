#ifndef SVSLAM_CLASS_HPP
#define SVSLAM_CLASS_HPP

#include <tuple>
#define USING_EASY_PROFILER
#include "easy/profiler.h"
#include "spdlog/spdlog.h"
#include "Eigen/Dense"

struct Landmark3DPosition
{
    double x;
    double y;
    double z;
};

struct IntrinsicMatrix
{
    double fx;
    double fy;
    double cx;
    double cy;
};


struct ExtrinsicMatrix
{
    Eigen::Matrix3d rotartion_matrix;
    Eigen::Vector3d translation;
};

struct ProjectedPoints
{
    double u;
    double v;
};

ProjectedPoints project_points(const Landmark3DPosition& point3D, const IntrinsicMatrix& intrinsics, const ExtrinsicMatrix& extrinsics)
{
    return ProjectedPoints{};
}

// class ImageProjector
// {
// public:
//     // ImageProjector(const Eigen::Vector3d& point3D, const Eigen::Matrix3d& intrinsicMartrix, const Eigen::Matrix<double,3,4>& extrinsicMatrix);
//     //Matrix3d는 뭐든지 다 받을 수 있다 -> 3x3 rotation matrix가 들어와도 intrinsic이라고 생각 -> 위험성이 있는 코드
//     //실제로 쓸때는 좀더 정교하게 만들어주는 게 좋다 -> struct로 감싸준다
//     //모듈들의 input, output에서는 가장 primitive한 값이 오고가는게 호환성이 좋다 -> 매개변수 설정에 Eigen 들어가는거 안좋다
//     //struct를 만들고 아래와 같이 사용
//     ImageProjector(const Landmark3DPosition& point3D, const IntrinsicMatrix& intrinsicMatrix, const ExtrinsicMatrix& extrinsicMatrix){
//         std::ignore = point3D;
//         std::ignore = intrinsicMatrix;
//         std::ignore = extrinsicMatrix;
//     };

// private:
// };

#endif  // SVSLAM_CLASS_HPP
