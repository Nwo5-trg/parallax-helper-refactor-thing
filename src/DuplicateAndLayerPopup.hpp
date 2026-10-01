#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include "utils/CustomNumberInput.hpp"

class DuplicateAndLayerPopup : public geode::Popup {
protected:
    using CallbackType = geode::Function<void(float,float,int)>;
    CallbackType m_onConfirmCallback;

    CustomNumberInput* m_layerCountInput = nullptr;
    CustomNumberInput* m_rangeInput0 = nullptr;
    CustomNumberInput* m_rangeInput1 = nullptr;

    bool init(CallbackType onConfirmCallback);

public:
    static DuplicateAndLayerPopup* create(CallbackType onConfirmCallback);//function input is range min, range max, count
};
