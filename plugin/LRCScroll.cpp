/**
 * LRCScroll.cpp
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_CPP
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_CPP

#include <QWidget>

#include "LRCScroll.h"
#include "LRCScrollView.h"

#include "embed.h"
#include "plugin_export.h"

#include "ToolPluginView.h"

using lmms::ToolPlugin;
using lmms::gui::PluginView;
using lmms::gui::LRCScrollView;

namespace lmms
{
    extern "C"
    {
        Plugin::Descriptor PLUGIN_EXPORT lrcscroll_plugin_descriptor = {
            LMMS_STRINGIFY(PLUGIN_NAME),
            "LRCScroll",
            QT_TRANSLATE_NOOP("PluginBrowser", "LRCScroll"),
            "Bimal Poudel <anytizer@users.noreply.github.com>",
            0x0100,
            Plugin::Type::Tool,
            new PluginPixmapLoader("logo"),
            nullptr,
            nullptr,
        };

        PLUGIN_EXPORT Plugin* lmms_plugin_main(Model*, void*)
        {
            return new LRCScroll();
        }

    } // extern "C"

    LRCScroll::LRCScroll(): ToolPlugin(&lrcscroll_plugin_descriptor, nullptr)
    {
    }

    LRCScroll::~LRCScroll()
    {
    }

    QString LRCScroll::nodeName() const
    {
        return lrcscroll_plugin_descriptor.name;
    }

    PluginView* LRCScroll::instantiateView(QWidget*)
    {
        return new LRCScrollView(this);
    }
} // namespace lmms


#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_CPP
