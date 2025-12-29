#pragma once

class DimensionBrightnessRamp {
public:
    float mBrightnessRamp[16];

public:
    virtual ~DimensionBrightnessRamp() = default;
    virtual void buildBrightnessRamp();
    virtual float getBaseAmbientValue();

    DimensionBrightnessRamp();
};