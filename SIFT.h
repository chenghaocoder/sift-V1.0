#ifndef SIFT_H
#define SIFT_H

// std
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include "math.h"
#include <cmath>
// opencv
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/flann/flann.hpp"

namespace SIFT {
    struct Keypoint {
        double theta;
        double scale;
        int o, s;
        double r, c;
        double descriptor[128];
    };
    typedef std::vector<Keypoint> Keypoints;

    void extract(const cv::Mat &img, Keypoints &keypoints);

    void match(const Keypoints &src1, const Keypoints &src2, Keypoints &match1, Keypoints &match2, int max_pairs = 15);

    cv::Mat linkPoints(const cv::Mat &img1, const Keypoints &match1, const cv::Mat &img2, const Keypoints &match2);
}

#endif // SIFT_H
