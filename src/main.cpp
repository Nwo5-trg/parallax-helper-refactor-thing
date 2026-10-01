#include <Geode/modify/EditorUI.hpp>
#include <Geode/Geode.hpp>
#include "ParallaxMenuPopup.hpp"

using namespace geode::prelude;

class $modify(MyEditorUI, EditorUI) {
	bool init(LevelEditorLayer* p0) {
		if (!EditorUI::init(p0)) return false;

		if (auto menu = this->getChildByID("editor-buttons-menu")) {

			auto btn = Button::createWithSprite("parallaxMenuButton.png"_spr, [this](Button*) {
				ParallaxMenuPopup::create()->show();
			});

			btn->setContentSize({40, 40});

			menu->addChild(btn);
			menu->updateLayout();

			//add it to uiItems so it gets hidden on playtest
			m_uiItems->addObject(btn);
		}

		return true;
	}
};