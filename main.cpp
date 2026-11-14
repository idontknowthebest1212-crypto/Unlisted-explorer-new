#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(UnlistedExplorerMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) {
            log::warn("Unlisted Explorer: could not find the bottom menu.");
            return true;
        }

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(UnlistedExplorerMenuLayer::onUnlistedExplorer)
        );

        if (!button) {
            log::warn("Unlisted Explorer: could not create the menu button.");
            return true;
        }

        button->setID("unlisted-explorer-button"_spr);
        menu->addChild(button);
        menu->updateLayout();
        return true;
    }

    void onUnlistedExplorer(CCObject*) {
        FLAlertLayer::create(
            "Unlisted Explorer",
            "Welcome to <cg>Unlisted Explorer</c>!\\n\\n"
            "This is the initial mod setup. Creator lookup, level discovery, "
            "and profile-comment access still need to be implemented.\\n\\n"
            "The mod can only display information that Geometry Dash's servers "
            "make publicly accessible; it cannot retrieve private or server-hidden data.",
            "OK"
        )->show();
    }
};
