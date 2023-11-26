#include <memory> //make_shared 쓰기 위해

#include "gtest/gtest.h"

#include "ImageProjector/include/ImageProjector/image_projector.hpp"


/**
* Design choices:
*
* s[u,v,1]^T = K * [R|t] * [X,Y,Z,1]^T
*
* 1. ImageProjector must be a function
* 2. The following inputs must be given : 3D point's location (x, y, z), Extrinsic matrix, Intrinsic matrix
*     2.1 x, y, z should be given a s double
*     2.2 Components of extrinsic matrix (Rotation, Translation) should be given double
*     2.3 Components of intrinsic matrix (fx, fy, cx, cy) should be given double
* 3. ImageProjector will output [u,v] as pixel locations.
*     3.1 u,v should be represented as double
*/

TEST(Image_Projector, constructor)
{
    //test1. class 생성 -> 성공
    // ImageProjector instance();

    //객체 생성
    // const auto instance = std::make_shared<ImageProjector>();
    // EXPECT_NE(instance, nullptr); //not equal
    //더이상 유효하지 않은 test니까 제거

    //test2. input을 어떻게 줄지 (초기화? 처음부터?)
    //image project를 할 때 입력은 필수적이라고 생각하기 때문에 바로 instance 만드는게 자연스러울 것 같다!
    // instance->initialize(point3D, extrinsic, intrinsic); 방법 제외
    constexpr Landmark3DPosition point3D = {1.0, 0.0, 0.0};
    constexpr IntrinsicMatrix intrinsic = {1.0, 1.0, 320.0, 240.0};
    const ExtrinsicMatrix extrinsic = {Eigen::Matrix3d::Identity(), Eigen::Vector3d{0.0, 0.0, 0.0}};

    // const auto projector = std::make_shared<ImageProjector>(point3D, intrinsic, extrinsic);
    // EXPECT_NE(projector, nullptr);

    //projector가 생성자이기 때문에 결과를 받으려면 추가 함수가 필요하다
    //왜 class로 했지? 함수로 만들면 바로 값 받을 수 있는데!
    //test3. 함수로 바꾸자!
    const auto projected_points = project_points(point3D, intrinsic, extrinsic);

    //원하는 값이 나오는지 확인
    constexpr ProjectedPoints uv_gt = {1.0, 1.0}; //지금은 임의로 넣었지만, 나중에는 실제로 계산해서 나와야하는 값을 지정해준다
    EXPECT_EQ(projected_points.u, uv_gt.u);
    EXPECT_EQ(projected_points.v, uv_gt.v);

    //사용자가 어떻게 사용할지 정의가 내려졌으니 이제 구현을 하면된다.
    //이 경우 project_points 함수 안에 계산식을 구현하면 된다

    //결과
    //1. 유저가 원하는대로 코드를 구현했다
    //2. 설계 방법도 알려줬다
    //3. 코드가 설계한대로 돌아간다 -> 안정성 보장
}

