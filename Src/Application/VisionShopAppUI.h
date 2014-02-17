#pragma once
#include "MyGUI.h"
#include "opencv2/opencv.hpp"

namespace MagicApp
{
    class VisionShopAppUI
    {
    public:
        VisionShopAppUI();
        ~VisionShopAppUI();

        void Setup();
        void Shutdown();

        void UpdateImageTexture(const cv::Mat& image);

    private:
        void OpenImage(MyGUI::Widget* pSender);
        void SaveImage(MyGUI::Widget* pSender);
        void ImageResizing(MyGUI::Widget* pSender);
        void DoImageResizing(MyGUI::Widget* pSender);
        void BackHome(MyGUI::Widget* pSender);
        void Contact(MyGUI::Widget* pSender);

    private:
        MyGUI::VectorWidgetPtr mRoot;
        MyGUI::ITexture* mpImageTexture;
    };
}