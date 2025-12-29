/**
 * LRCScroll.h
 * (c) 2026 Bimal Poudel <@anytizer:github>
 */

#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H

#include <QWidget>
#include <QDomDocument>
#include <QString>

#include "ToolPlugin.h"
#include "ToolPluginView.h"

using lmms::ToolPlugin;
using lmms::gui::PluginView;

namespace lmms
{
    class LRCScroll : public ToolPlugin
    {
        public:
            LRCScroll();
            ~LRCScroll();

            QString nodeName() const override;
			void saveSettings(QDomDocument&, QDomElement&) override {}
			void loadSettings(const QDomElement&) override {}

			PluginView* instantiateView(QWidget*) override;
    };
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H