#pragma once
#include "Ogre.h"
#include "../DGP/PointCloud3D.h"
#include "../DGP/Mesh3D.h"
#include "../DGP/HomoMatrix4.h"
#include <string>

namespace MagicCore
{
    class RenderSystem
    {
    private:
        static RenderSystem* mpRenderSys;
        RenderSystem(void);
    public:
        static RenderSystem* GetSingleton(void);
        void Init(void);
        void Update(void);

        Ogre::RenderWindow* GetRenderWindow(void);
        Ogre::SceneManager* GetSceneManager(void);
        Ogre::Camera*       GetMainCamera(void);
        void SetupCameraDefaultParameter();

        virtual ~RenderSystem(void);

        void RenderPoint3DSet(std::string psName, std::string psMaterialName, const MagicDGP::Point3DSet* pPS);
        void RenderPoint3DSet(std::string psName, std::string psMaterialName, const MagicDGP::Point3DSet* pPS, const MagicDGP::HomoMatrix4& transform);
        void RenderLineSegments(std::string lsName, std::string materialName, const std::vector<MagicDGP::Vector3>& startPos, const std::vector<MagicDGP::Vector3>& endPos);
        void RenderMesh3D(std::string meshName, std::string materialName, const MagicDGP::Mesh3D* pMesh);
        void RenderBlendMesh3D(std::string meshName, std::string materialName, const MagicDGP::Mesh3D* pMesh, float alpha);
        void HideRenderingObject(std::string psName);

    private:
        Ogre::Root*    mpRoot;
        Ogre::Camera*  mpMainCam;
        Ogre::RenderWindow* mpRenderWin;
        Ogre::SceneManager* mpSceneMgr;
    };
}

