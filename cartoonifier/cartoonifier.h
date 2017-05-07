#ifndef CARTOONIFIER_H
#define CARTOONIFIER_H
#include <iostream>
#include <opencv2/highgui.hpp>
#include "imageUtils/imageutils.h"

using namespace cv;

class Cartoonifier
{
public:
    Cartoonifier();
    bool setInputImage(std::string filename);
    void setInputImage(Mat img);
    const Mat getInputMat() const;
    void cartoonifyImage(bool sketchMode, bool alienMode, bool evilMode, int debugType);
    void paintingProcess();
    void alienProcess();
    const Mat getLastResult() const;
    void resetResult();
    void sketchProcess();
    void evilProcess();
    Mat getEvil();
    Mat getSketch();
    ~Cartoonifier();
private:
    Mat image;
    Mat result;
    ImageUtils imageUtils;
private:
    // Draw an anti-aliased face outline, so the user knows where to put their face.
    void drawFaceStickFigure(Mat dst);
    void changeFacialSkinColor(Mat smallImgBGR, Mat bigEdges, int debugType);
    void removePepperNoise(Mat &mask);
};

#endif // CARTOONIFIER_H