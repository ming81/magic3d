#pragma once
#include "../Common/AppBase.h"
#include "FaceBeautificationAppUI.h"
#include <vector>

namespace MagicApp
{
    class FaceFeaturePoint
    {
    public:
        enum FeatureType
        {
            FT_None = 0,
            FT_Left_Brow,
            FT_Right_Brow,
            FT_Left_Eye,
            FT_Right_Eye,
            FT_Mouse,
            FT_Nose,
            FT_Border
        };

        FaceFeaturePoint();
        
        void Load();
        void Save();
        bool Select(int hid, int wid);
        void MoveTo(int hid, int wid);
        void Get(std::vector<int>& posList);

        ~FaceFeaturePoint();

    private:
        int mSelectIndex;
        FeatureType mSelectType;
        std::vector<int> mLeftBrowFPs;
        std::vector<int> mRightBrowFPs;
        std::vector<int> mLeftEyeFPs;
        std::vector<int> mRightEyeFPs;
        std::vector<int> mNoseFPs;
        std::vector<int> mMouseFPs;
        std::vector<int> mBorderFPs;
    };

    class FaceBeautificationApp : public MagicCore::AppBase
    {
    public:
        enum MouseMode
        {
            MM_View,
            MM_Move_Origin_Feature
        };

        FaceBeautificationApp();
        ~FaceBeautificationApp();

        virtual bool Enter(void);
        virtual bool Update(float timeElapsed);
        virtual bool Exit(void);
        virtual bool MouseMoved( const OIS::MouseEvent &arg );
        virtual bool MousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool MouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
        virtual bool KeyPressed( const OIS::KeyEvent &arg );
        virtual void WindowResized( Ogre::RenderWindow* rw );

        bool OpenImage(void);
        void LoadFeaturePoint();
        void MoveOriginFeaturePoint();
        void SaveFeaturePoint();

    private:
        void SetupScene(void);
        void ShutdownScene(void);
        void UpdateLeftDisplayImage(std::vector<int>* markIndex);
        cv::Mat ResizeInputImageToCanvas(const cv::Mat& img) const;

    private:
        FaceBeautificationAppUI mUI;
        cv::Mat mImage;
        cv::Mat mLeftDisplayImage;
        FaceFeaturePoint mOriginFPs;
        bool mFeaturePointSelected;
        MouseMode mMouseMode;
    };

    

}