#include <iostream>
#include <cmath>

#include <Eigen/Dense>
#include <Eigen/Geometry> //for Angle-axis
#include "Eigen/src/Geometry/Quaternion.h"

int main()
{
    //eigen matrix initialization
    //method 1
    Eigen::Matrix<double, 2, 3> matrix23_double;
    matrix23_double << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;

    //method 2
    Eigen::Matrix3d martix33_double = Eigen::Matrix3d::Zero(); //double 3x3 matrix

    //method 3
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;

    //eigen vector initialization
    Eigen::Vector3d vec = {1.0, 2.0, 3.0};

    Eigen::Vector3d vec_zeros = Eigen::Vector3d::Zero();

    //eigen matrix element access
    Eigen::Matrix3d mat33;
    mat33 << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;

    for(int row = 0; row < mat33.rows(); ++row)
    {
        for(int col = 0; col < mat33.cols(); ++col)
        {
            std::cout << mat33(row, col) << "\n";
        }
    }

    //eigen angle-axis
    //rotate 45 degrees along z axis
    Eigen::AngleAxisd rotation_vector(M_PI/4.0, Eigen::Vector3d(0.0, 0.0, 1.0));

    std::cout << "rotation vector = " << std::endl;
    std::cout << rotation_vector.matrix() << std::endl;
    std::cout << std::endl;

    Eigen::Vector3d vector(1.0, 0.0, 0.0);
    Eigen::Vector3d rotated_vector = rotation_vector * vector;

    std::cout << "rotated vector = " << std::endl;
    std::cout << rotated_vector.transpose() << std::endl;

    //Eigen Quaternion
    Eigen::AngleAxisd rotation_vector2(M_PI/4, Eigen::Vector3d(0.0, 0.0, 1.0));
    Eigen::Quaterniond quat = Eigen::Quaterniond(rotation_vector2);
    Eigen::Vector3d vector2(1.0, 0.0, 0.0);

    std::cout << "quanternion = " << quat.coeffs().transpose() << std::endl;
    std::cout << std::endl;

    std::cout << "rotated vector = " << (quat * vector2).transpose() << std::endl;

    return 0;
}


