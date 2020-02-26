#pragma once
#include <vector>

#include "Module.hpp"

#include "Interface.hpp"
#include "Utils.hpp"
#include "Surface.hpp"

class VGui : public Module {
public:
    Interface* enginevgui = nullptr;

    void SetCoverColor(Color c) {coverColor = c;};

    bool canDrawThisFrame = true;
    
private:
    Color coverColor;
    int coverTexture = 0;
public:
    // CEngineVGui::Paint
    DECL_DETOUR(Paint, int mode);

    bool Init() override;
    void Shutdown() override;
    const char* Name() override { return MODULE("engine"); }
};

extern VGui* vgui;