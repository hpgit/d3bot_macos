//
// Created by Hwangpil Park on 2018-12-22.
//

#include "opencv_test.h"
#include <vector>
#include <opencv2/opencv.hpp>
#include <boost/python.hpp>
#include <ApplicationServices/ApplicationServices.h>

BOOST_PYTHON_MODULE(opencv)
{
    boost::python::def("opencv_test", opencv_test);
}

cv::Mat cvMatFromCGImage(CGImageRef &image, int cols, int rows)
{
    CGColorSpaceRef colorSpace = CGImageGetColorSpace(image);

    cv::Mat cvMat(rows, cols, CV_8UC4); // 8 bits per component, 4 channels (color channels + alpha)

    CGContextRef contextRef = CGBitmapContextCreate(cvMat.data,                 // Pointer to  data
                                                (size_t)cols,                       // Width of bitmap
                                                (size_t)rows,                       // Height of bitmap
                                                8,                          // Bits per component
                                                cvMat.step[0],              // Bytes per row
                                                colorSpace,                 // Colorspace
                                                kCGImageAlphaNoneSkipLast | kCGBitmapByteOrderDefault); // Bitmap info flags

    CGContextDrawImage(contextRef, CGRectMake(0, 0, cols, rows), image);
    CGContextRelease(contextRef);

    return cvMat;
}

void opencv_test()
{
    CGRect rect;
    rect.origin.x = 1;
    rect.origin.y = 1;
    rect.size.width = 30;
    rect.size.height = 30;
    CGImageRef testimg = CGDisplayCreateImageForRect(CGMainDisplayID(), rect);
    cv::Mat testmat = cvMatFromCGImage(testimg, 30, 30);
    cv::imwrite("test.png", testmat);

    std::vector<cv::Mat> imgs;
    imgs.push_back(cv::imread("left.JPG"));
    imgs.push_back(cv::imread("right.JPG"));

    cv::Mat pano;

    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create();
    cv::Stitcher::Status status = stitcher->stitch(imgs, pano);
    cv::imwrite("result.JPG", pano);
}

