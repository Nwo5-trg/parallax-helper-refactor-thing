#include "NumberRequestPopup.hpp"
#include "Utils.hpp"

bool NumberRequestPopup::init(CallbackType callback)
{
    //make this reusable later
    float popupWidth = 300;
    float popupHeight = 200;

    if (!Popup::init(popupWidth,popupHeight,"GJ_square02.png")) return false;
    m_closeBtn->setVisible(false);
    setTitle("Change Layer Group ID");

    m_callback = std::move(callback);


    auto descriptionBackground = NineSlice::create("square02b_001.png");
    descriptionBackground->setColor(ccBLACK);
    descriptionBackground->setOpacity(44);
    descriptionBackground->setAnchorPoint({0.5f,1.0f});

    auto descriptionTextArea = RichTextArea::create(
        "Put in a value to change the group ID of this layer.\n"
        "This will also replace the previous ID in any object that already has it.",
        "chatFont.fnt",
        0.75f,
        popupWidth-(ph::constants::PADDING*4)
    ); 
    descriptionTextArea->setAlignment(CCTextAlignment::kCCTextAlignmentCenter);

    descriptionBackground->setPosition({popupWidth/2,popupHeight-40.0f});
    descriptionBackground->setContentSize({popupWidth-(ph::constants::PADDING*2),descriptionTextArea->getContentHeight()+(ph::constants::PADDING*2)});

    descriptionTextArea->setAnchorPoint({0.5f,0.0f});
    descriptionTextArea->setPosition(descriptionBackground->getContentWidth()/2,ph::constants::PADDING);

    //descriptionTextArea->setPosition({popupWidth/2.0f,popupHeight-45.0f});
    m_mainLayer->addChild(descriptionBackground);
    descriptionBackground->addChild(descriptionTextArea);

    //create the actual input for the number
    //add arrows later
    m_numberInput = CustomNumberInput::create(70.0f);
    m_numberInput->setLayoutOptions(
        AnchorLayoutOptions::create()
        ->setAnchor(Anchor::Bottom)
        ->setOffset({0.0f,70.0f})
    );
    m_numberInput->setTypeInt(false);
    m_numberInput->enableArrows();
    m_mainLayer->addChild(m_numberInput);

    auto closeButtonMenu = ph::utils::createTwoButtonMenu(
        [this](bool isBtn2){
            if(m_callback)
                m_callback(this,isBtn2);
            
            this->onClose(this);
        }
    );
    m_mainLayer->addChild(closeButtonMenu);

    m_mainLayer->updateLayout();

    return true;
}

NumberRequestPopup* NumberRequestPopup::create(CallbackType callback) {
    auto ret = new NumberRequestPopup();
    if (ret->init(std::move(callback))) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}
