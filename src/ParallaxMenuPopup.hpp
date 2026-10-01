#pragma once
#include <Geode/Geode.hpp>
#include <alphalaneous.alphas-ui-pack/include/API.hpp>
#include "utils/CustomNumberInput.hpp"
#include "ParallaxSetup.hpp"

using namespace geode::prelude;
using namespace alpha::prelude;

class ParallaxMenuPopup : public geode::Popup {
public:
    static ParallaxMenuPopup* create();

    ParallaxSetup* getSelectedSetup();
    void scrollToLayerIndex(int index);
    
    ~ParallaxMenuPopup();
protected:
    ParallaxSetupList m_parallaxSetupList;

    //layer list label
    Label* m_layerListLabel = nullptr;
    //layer list menus
    Button* m_addLayerButton = nullptr;
    Button* m_sortButton = nullptr;
    //setup actions
    Button* m_findCenterButton = nullptr;
    Button* m_findSetupButton = nullptr;
    Button* m_cleanSetupButton = nullptr;
    Button* m_deleteSetupButton = nullptr;
    //layer list
    NineSlice* m_layerListBackground = nullptr;
    CCMenu* m_layerListMenu = nullptr;
    AdvancedScrollLayer* m_scrollLayer = nullptr;
    AdvancedScrollBar* m_layerListScrollBar = nullptr;
    Label* m_layerListHint = nullptr;
    //setup switcher
    Button* m_setupSwitcherPrevButton = nullptr;
    Button* m_setupSwitcherNextButton = nullptr;
    Label* m_setupSelectorLabel = nullptr;
    //duration input
    CustomNumberInput* m_durationInput = nullptr;

    int m_selectedSetupIndex = 0;

    //allows for reuse of nodes to avoid crashes when deleting them
    int m_nextLayerListNode = 0;

    ListenerHandle* m_upListener = nullptr;
    ListenerHandle* m_downListener = nullptr;

    static constexpr float POPUP_WIDTH = 430;
    static constexpr float POPUP_HEIGHT = 290;

    static constexpr float PAD_AMOUNT = 10;
    static constexpr float LAYER_LIST_WIDTH = 230.0f;
    static constexpr float LAYER_LIST_HEIGHT = 240.0f;

    static constexpr float LAYER_LIST_X = POPUP_WIDTH-PAD_AMOUNT;

    static constexpr float LAYER_NODE_HEIGHT = 40.0f;
    static constexpr float LAYER_LIST_SCROLL_LAYER_HEIGHT = 260.0f;

    static constexpr float SETUP_SWITCHER_WIDTH = 90;
    static constexpr float SETUP_SWITCHER_HEIGHT = 20;
    static constexpr float SETUP_SWITCHER_BUTTON_SCALE = 0.8f;

    static constexpr float SETUP_OPTIONS_BACKGROUND_WIDTH = 170.0f;
    static constexpr float SETUP_OPTIONS_WIDTH = SETUP_OPTIONS_BACKGROUND_WIDTH-(2*PAD_AMOUNT);

    static constexpr float DURATION_INPUT_SCALE = 0.5f;

    static constexpr float SETUP_ACTION_BUTTON_SIZE = 33.0f;
    static constexpr float ACTION_BUTTON_SCALE = 0.75f;

    bool init();
    void initDevButtons();//this one can be commented out to hide the dev buttons
    void initSetupSwitcher();
    void initInfoButtons();
    void initLayerList();

    //callbacks
    void onAddLayerButton(CCObject *);
    void onCleanupTriggersButton(CCObject *);
    void onDeleteSetupButton(CCObject *);
    void onFindCenterButton(CCObject *);
    void onCreateSetupButton(CCObject *);
    void onFindSetupInEditorButton(CCObject *);
    void onMakeDurationInfiniteButton(CCObject *);
    void onDuplicateAndLayerButton(CCObject *);
    void onCreateQuickGradientButton(CCObject *);

    //layer list methods
    void loadSetupLayerList(ParallaxSetup* setup);
    void addLayerNodeToList(ParallaxSetupLayer* layer);//node: this does NOT update the layout
    size_t getFocusedLayer();//returns SIZE_MAX if no layer is selected
    void changeFocusedLayer(int indexOffset);

    void updateAllUI();

    //the current setup can probably be passed into a lot of these so it only has to be gotten once

    void updateSetupActionButtons();
    void updateLayerListHint();
    void updateSetupSelector();
    void updateSetupDurationInput();//this only really needs to be called when switching setups
};