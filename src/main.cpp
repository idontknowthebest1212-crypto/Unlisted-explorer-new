#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(UnlistedExplorerMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto button = CCMenuItemExt::createSpriteExtra(
            CCSprite::createWithSpriteFrameName("GJ_searchBtn_001.png"),
            [](CCMenuItem*) {
                FLAlertLayer::create(
                    "Unlisted Explorer",
                    "Welcome to Unlisted Explorer!",
                    "OK"
                )->show();
            }
        );

        button->setID("unlisted-explorer-button"_spr);

        if (auto menu = this->getChildByID("bottom-menu")) {
            menu->addChild(button);
            menu->updateLayout();
        }

        return true;
    }
};
