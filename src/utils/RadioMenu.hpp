#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;
  
class RadioMenu : public CCMenu {
public:
    int m_selectedIndex = 0;

    static RadioMenu* create(const cocos2d::CCSize &size);

    int addEntry(ZStringView labelText);
    void selectEntry(int entryID);

    void untoggleAll();

protected:
    CCMenu* m_menu = nullptr;

    static constexpr float ENTRY_HEIGHT = 22.0f;

    bool init(const cocos2d::CCSize &size);
};

class RadioMenuEntry : public CCMenu {
public:
    RadioMenu* m_parent = nullptr;
    CCMenuItemToggler* m_checkbox = nullptr;
    int m_index = -1;

    static RadioMenuEntry* create(const cocos2d::CCSize &size, ZStringView labelText);
protected:
    bool init(const cocos2d::CCSize &size, ZStringView labelText);
};