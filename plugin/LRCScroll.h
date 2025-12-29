#ifndef LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H
#define LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H

#include <QWidget>
#include <QDomDocument>
#include <QTextCursor>
#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QPushButton>
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

        private slots:
            void insertElapsed();
            
        private:
            
            Q_OBJECT
            
            QPlainTextEdit *editor;
            QPushButton *btn;
            QElapsedTimer timer;
    
            QString getCurrentLine(QTextCursor cursor);
    };
}

#endif // LMMS_PLUGINS_LRCSCROLL_LRCSCROLL_H