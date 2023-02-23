#include "SIFT.h"
// opencv
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main() {
    cv::Mat img = cv::imread("./images/5.jpeg", 0);
    cv::Mat img_ = cv::imread("./images/5_.jpeg", 0);

    if (img.data == nullptr || img_.data == nullptr) {
        std::cout << "影像读取失败！" << std::endl;
    } else {
        std::cout << img.rows << "," << img.cols << std::endl;
        std::cout << img_.rows << "," << img_.cols << std::endl;
    }

    cv::imshow("1", img);
    cv::imshow("1_", img_);
//    cv::waitKey(0);

    SIFT::Keypoints keypoints, keypoints_;
    SIFT::extract(img, keypoints);
    SIFT::extract(img_, keypoints_);

    SIFT::Keypoints m1, m2;
    SIFT::match(keypoints, keypoints_, m1, m2);
    cv::Mat res = SIFT::linkPoints(img, m1, img_, m2);
    cv::imshow("result", res);
    cv::waitKey(0);

    return 0;
}
