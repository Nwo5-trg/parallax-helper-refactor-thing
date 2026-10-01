#pragma once

#include <Geode/Geode.hpp>
#include "CustomNumberInput.hpp"

class NumberRequestPopup : public geode::Popup {
protected:
    using CallbackType = geode::Function<void(NumberRequestPopup*,bool)>;
    CallbackType m_callback;

    bool init(CallbackType callback);
public:
    CustomNumberInput* m_numberInput = nullptr;

    static NumberRequestPopup* create(CallbackType callback);
};