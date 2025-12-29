#include "HookManager.hpp"

#include <ranges>

/*
Disables any hooks and un-caches any stored addresses
*/
Amethyst::HookManager::~HookManager()
{
    for (auto hook : std::ranges::reverse_view(mHooks)) {
        *hook = {};
    }

    for (auto midHook : std::ranges::reverse_view(mMidHooks)) {
        *midHook = {};
    }

    mHooks.clear();
    mMidHooks.clear();
    mFuncHashToOriginalAddress.clear();
}