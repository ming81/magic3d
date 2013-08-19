#include "StdAfx.h"
#include "Scan3DUI.h"
#include "../Common/ResourceManager.h"
#include "../Common/AppManager.h"

namespace MagicApp
{
    Scan3DUI::Scan3DUI()
    {
    }

    Scan3DUI::~Scan3DUI()
    {
    }

    void Scan3DUI::Setup()
    {
        MagicCore::ResourceManager::GetSingleton()->LoadResource("../../Media/Scan3D", "FileSystem", "Scan3D");
        mRoot = MyGUI::LayoutManager::getInstance().loadLayout("Scan3D.layout");
        mRoot.at(0)->findWidget("But_Scan")->castType<MyGUI::Button>()->eventMouseButtonClick += MyGUI::newDelegate(this, &Scan3DUI::Scan);
        mRoot.at(0)->findWidget("But_Back")->castType<MyGUI::Button>()->eventMouseButtonClick += MyGUI::newDelegate(this, &Scan3DUI::BackToHomepage);
    }

    void Scan3DUI::Shutdown()
    {
        MyGUI::LayoutManager::getInstance().unloadLayout(mRoot);
        mRoot.clear();
        MagicCore::ResourceManager::GetSingleton()->UnloadResource("Scan3D");
    }

    void Scan3DUI::Scan(MyGUI::Widget* pSender)
    {

    }
    
    void Scan3DUI::BackToHomepage(MyGUI::Widget* pSender)
    {
        MagicCore::AppManager::GetSingleton()->SwitchCurrentApp("Homepage");
    }
}