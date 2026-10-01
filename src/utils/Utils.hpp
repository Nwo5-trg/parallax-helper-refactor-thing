#pragma once

#include <Geode/Geode.hpp>
#include "Constants.hpp"

namespace ph::utils {
    enum class LayerSortingType{
    	ByDepth,
    	ByGroup
    };
    
    inline LayerSortingType getSortingType(){
    	return LayerSortingType(std::clamp(
            Mod::get()->getSavedValue<int>(ph::constants::SELECTED_SORTING_ID, 0), 0, 1
        ));
    }

    inline void enableNode(Button* item){
        item->setEnabled(true);
        item->setColor(ccWHITE);
        item->setOpacity(255);
    }
    inline void disableNode(Button* item){
        item->setEnabled(false);
        item->setColor(ph::constants::DISABLED_COLOR);
        item->setOpacity(ph::constants::DISABLED_ALPHA);
    }

    CCMenu* createTwoButtonMenu(std::function<void(bool)> callback, ZStringView btn1Title = "Cancel", ZStringView btn2Title = "Confirm");
};